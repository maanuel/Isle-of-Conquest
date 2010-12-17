/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Player.h"
#include "Battleground.h"
#include "BattlegroundIC.h"
#include "Language.h"

BattlegroundIC::BattlegroundIC()
{
    m_BgObjects.resize(GAMEOBJECT_MAX_SPAWNS);
    m_BgCreatures.resize(NPCS_MAX_SPAWNS);

    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_IC_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_IC_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_IC_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_IC_HAS_BEGUN;

    for (uint8 i = 0; i < 2; i++)
        factionReinforcements[i] = 300;

    for (uint8 i = 0; i < BG_IC_MAXDOOR; i++)
        GateStatus[i] = BG_IC_GATE_OK;

    closeFortressDoors = 20000; // the doors are closed again... in a special way
    doorsClosed = false;
}

BattlegroundIC::~BattlegroundIC()
{

}

void BattlegroundIC::Update(uint32 diff)
{
    Battleground::Update(diff);

    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!doorsClosed)
    {
        if (closeFortressDoors <= diff)
        {
            //DoorClose(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01);
            //DoorClose(BG_IC_GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01);

            GetBGObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01)->RemoveFromWorld();

            GetBGObject(BG_IC_GO_ALLIANCE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
            GetBGObject(BG_IC_GO_HORDE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door

            doorsClosed = true;
        } else closeFortressDoors -= diff;
    }
    
}

void BattlegroundIC::StartingEventCloseDoors()
{
    // Show Full Gate Displays
    GetBGObject(BG_IC_GO_ALLIANCE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(BG_IC_GO_ALLIANCE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(BG_IC_GO_HORDE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
    GetBGObject(BG_IC_GO_HORDE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
}

void BattlegroundIC::StartingEventOpenDoors()
{
    //after 20 seconds they should be despawned
    DoorOpen(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01);
    DoorOpen(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01);
}

void BattlegroundIC::AddPlayer(Player *plr)
{
    Battleground::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundICScore* sc = new BattlegroundICScore;

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattlegroundIC::RemovePlayer(Player* /*plr*/,uint64 /*guid*/)
{

}

void BattlegroundIC::HandleAreaTrigger(Player * /*Source*/, uint32 /*Trigger*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundIC::UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor)
{

    std::map<uint64, BattlegroundScore*>::iterator itr = m_PlayerScores.find(Source->GetGUID());

    if (itr == m_PlayerScores.end())                         // player not found...
        return;

    Battleground::UpdatePlayerScore(Source,type,value, doAddHonor);
}

void BattlegroundIC::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(BG_IC_ALLIANCE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_HORDE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_ALLIANCE_RENFORT) << uint32(factionReinforcements[TEAM_ALLIANCE]);
    data << uint32(BG_IC_HORDE_RENFORT) << uint32(factionReinforcements[TEAM_HORDE]);

    for (uint8 i = 1; i < 7; i++)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry,(GateStatus[GetGateIDFromEntry(BG_IC_ObjSpawnlocs[i].entry)] == BG_IC_GATE_DESTROYED ? true : false));
        sLog.outError("FillInitWorldStates: Updating WorldState %u, WorldState %u, door entry %u",i,uws, BG_IC_ObjSpawnlocs[i].entry);  
        data << uint32(uws) << uint32(1);
    }

    //for (uint8 i = 0 ; i < BG_IC_DYNAMIC_NODES_COUNT ; i++)
    //    data << uint32(m_IC_NodeData[i].worldstate[m_IC_NodeData[i].current]) << uint32(1);
}

bool BattlegroundIC::SetupBattleground()
{
    for (uint8 i = 0; i < GAMEOBJECT_MAX_SPAWNS; i++)
    {
        if (!AddObject(BG_IC_ObjSpawnlocs[i].type,BG_IC_ObjSpawnlocs[i].entry,
            BG_IC_ObjSpawnlocs[i].x,BG_IC_ObjSpawnlocs[i].y,
            BG_IC_ObjSpawnlocs[i].z,BG_IC_ObjSpawnlocs[i].o,
            0,0,0,0,RESPAWN_ONE_DAY))
        {
            sLog.outError("Isle of Conquest: There was an error spawning gameobject %u",BG_IC_ObjSpawnlocs[i].entry);
            return false;      
        }
    } 

    for (uint8 i = 0; i < NPCS_MAX_SPAWNS; i++)
    {
        if (!AddCreature(BG_IC_NpcSpawnlocs[i].entry,BG_IC_NpcSpawnlocs[i].type,BG_IC_NpcSpawnlocs[i].team,
            BG_IC_NpcSpawnlocs[i].x,BG_IC_NpcSpawnlocs[i].y,
            BG_IC_NpcSpawnlocs[i].z,BG_IC_NpcSpawnlocs[i].o,
            RESPAWN_ONE_DAY))
        {
            sLog.outError("Isle of Conquest: There was an error spawning creature %u",BG_IC_NpcSpawnlocs[i].entry);
            return false;      
        }
    }  

    /*for (uint8 i = 1; i < 7; i++)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry,false);
        sLog.outError("Updating WorldState %u, WorldState %u",i,uws);
        UpdateWorldState(uws,1);        
    }*/

    return true;
}

void BattlegroundIC::HandleKillUnit(Creature *unit, Player * /*killer*/)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
       return;

    /*uint32 entry = unit->GetEntry();
    if (entry == 34924)
    {
        RewardHonorToTeam(500,HORDE);
        EndBattleground(HORDE);
    }
    else if (entry == 34922)
    {
        RewardHonorToTeam(500,ALLIANCE);
        EndBattleground(ALLIANCE);
    }*/
}

void BattlegroundIC::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
     
    factionReinforcements[player->GetTeamId()] -= 1;

    UpdateWorldState((player->GetTeamId() == TEAM_ALLIANCE ? BG_IC_ALLIANCE_RENFORT : BG_IC_HORDE_RENFORT), factionReinforcements[player->GetTeamId()]);

    // we must end the battleground
    if (factionReinforcements[player->GetTeamId()] < 1)
        EndBattleground(killer->GetTeamId());
}

void BattlegroundIC::EndBattleground(uint32 winner)
{
    Battleground::EndBattleground(winner);
}

void BattlegroundIC::EventPlayerClickedOnFlag(Player * /*source*/, GameObject* /*target_obj*/)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundIC::EventPlayerDamagedGO(Player* /*plr*/, GameObject* go, uint8 hitType, uint32 destroyedEvent)
{
    if (!go || !go->GetGOInfo())
        return;
    
    switch(hitType)
    {
        case BG_OBJECT_DMG_HIT_TYPE_JUST_DAMAGED://under attack
            //SendWarningToAll(LANG_BG_IC_IS_UNDER_ATTACK, go->GetGOInfo()->name);
            break;
        case BG_OBJECT_DMG_HIT_TYPE_DAMAGED:
            break;
        case BG_OBJECT_DMG_HIT_TYPE_JUST_HIGH_DAMAGED:
            /*{
                uint32 i = GetGateIDFromDestroyEventID(destroyedEvent);
                //GateStatus[i] = BG_IC_GATE_DAMAGED;
                uint32 uws = GetWorldStateFromGateID(i);
                if (uws)
                    UpdateWorldState(uws, GateStatus[i]);
                break;
            }*/
        case BG_OBJECT_DMG_HIT_TYPE_HIGH_DAMAGED:
            break;
        case BG_OBJECT_DMG_HIT_TYPE_JUST_DESTROYED://handled at DestroyGate()
            GateStatus[GetGateIDFromEntry(go->GetEntry())] = BG_IC_GATE_DESTROYED;
            uint32 uws = GetWorldStateFromGateEntry(go->GetEntry(), true);
            if (uws)
                UpdateWorldState(uws, GateStatus[GetGateIDFromEntry(go->GetEntry())]);
            //SendWarningToAll(LANG_BG_IC_WAS_DESTROYED, go->GetGOInfo()->name);
            break;
    }
}
