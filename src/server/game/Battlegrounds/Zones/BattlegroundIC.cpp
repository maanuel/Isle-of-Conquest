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

const ICNodePoint nodePointInitial[7] =
{
    {BG_IC_GO_REFINERY_BANNER,GO_REFINERY_BANNER,TEAM_NEUTRAL,NODE_TYPE_REFINERY,{GO_ALLIANCE_BANNER_REFINERY,GO_ALLIANCE_BANNER_REFINERY_CONT,GO_HORDE_BANNER_REFINERY,GO_HORDE_BANNER_REFINERY_CONT},false,0,0,{BG_IC_REFINERY_UNCONTROLLED,BG_IC_REFINERY_CONFLICT_A,BG_IC_REFINERY_CONFLICT_H,BG_IC_REFINERY_CONTROLLED_A,BG_IC_REFINERY_CONTROLLED_H},NODE_STATE_UNCONTROLLED},
    {BG_IC_GO_QUARRY_BANNER,GO_QUARRY_BANNER,TEAM_NEUTRAL,NODE_TYPE_QUARRY, {GO_ALLIANCE_BANNER_QUARRY,GO_ALLIANCE_BANNER_QUARRY_CONT,GO_HORDE_BANNER_QUARRY,GO_HORDE_BANNER_QUARRY_CONT},false,0,0,{BG_IC_QUARRY_UNCONTROLLED,BG_IC_QUARRY_CONFLICT_A,BG_IC_QUARRY_CONFLICT_H,BG_IC_QUARRY_CONTROLLED_A,BG_IC_QUARRY_CONTROLLED_H},NODE_STATE_UNCONTROLLED},
    {BG_IC_GO_DOCKS_BANNER,GO_DOCKS_BANNER,TEAM_NEUTRAL,NODE_TYPE_DOCKS, {GO_ALLIANCE_BANNER_DOCK,GO_ALLIANCE_BANNER_DOCK_CONT,GO_HORDE_BANNER_DOCK,GO_HORDE_BANNER_DOCK_CONT},false,0,0,{BG_IC_DOCKS_UNCONTROLLED, BG_IC_DOCKS_CONFLICT_A, BG_IC_DOCKS_CONFLICT_H, BG_IC_DOCKS_CONTROLLED_A,BG_IC_DOCKS_CONTROLLED_H},NODE_STATE_UNCONTROLLED},
    {BG_IC_GO_HANGAR_BANNER,GO_HANGAR_BANNER,TEAM_NEUTRAL,NODE_TYPE_HANGAR, {GO_ALLIANCE_BANNER_HANGAR,GO_ALLIANCE_BANNER_HANGAR_CONT,GO_HORDE_BANNER_HANGAR,GO_HORDE_BANNER_HANGAR_CONT},false,0,0,{BG_IC_HANGAR_UNCONTROLLED,BG_IC_HANGAR_CONFLICT_A, BG_IC_HANGAR_CONFLICT_H, BG_IC_HANGAR_CONTROLLED_A, BG_IC_HANGAR_CONTROLLED_H},NODE_STATE_UNCONTROLLED},
    {BG_IC_GO_WORKSHOP_BANNER,GO_WORKSHOP_BANNER,TEAM_NEUTRAL, NODE_TYPE_WORKSHOP, {GO_ALLIANCE_BANNER_WORKSHOP,GO_ALLIANCE_BANNER_WORKSHOP_CONT,GO_HORDE_BANNER_WORKSHOP,GO_HORDE_BANNER_WORKSHOP_CONT},false,0,0,{BG_IC_WORKSHOP_UNCONTROLLED,BG_IC_WORKSHOP_CONFLICT_A,BG_IC_WORKSHOP_CONFLICT_H,BG_IC_WORKSHOP_CONTROLLED_A,BG_IC_WORKSHOP_CONTROLLED_H},NODE_STATE_UNCONTROLLED},
    {BG_IC_GO_ALLIANCE_BANNER,GO_ALLIANCE_BANNER,TEAM_ALLIANCE,NODE_TYPE_GRAVEYARD_A, {GO_ALLIANCE_BANNER_GRAVEYARD_A,GO_ALLIANCE_BANNER_GRAVEYARD_A_CONT,GO_HORDE_BANNER_GRAVEYARD_A,GO_HORDE_BANNER_GRAVEYARD_A_CONT},false,0,0,{BG_IC_ALLIANCE_KEEP_UNCONTROLLED,BG_IC_ALLIANCE_KEEP_CONFLICT_A,BG_IC_ALLIANCE_KEEP_CONFLICT_H,BG_IC_ALLIANCE_KEEP_CONTROLLED_A,BG_IC_ALLIANCE_KEEP_CONTROLLED_H},NODE_STATE_CONTROLLED_A},
    {BG_IC_GO_HORDE_BANNER,GO_HORDE_BANNER,TEAM_HORDE,NODE_TYPE_GRAVEYARD_H, {GO_ALLIANCE_BANNER_GRAVEYARD_H,GO_ALLIANCE_BANNER_GRAVEYARD_H_CONT,GO_HORDE_BANNER_GRAVEYARD_H,GO_HORDE_BANNER_GRAVEYARD_H_CONT},false,0,0,{BG_IC_HORDE_KEEP_UNCONTROLLED,BG_IC_HORDE_KEEP_CONFLICT_A,BG_IC_HORDE_KEEP_CONFLICT_H,BG_IC_HORDE_KEEP_CONTROLLED_A,BG_IC_HORDE_KEEP_CONTROLLED_H},NODE_STATE_CONTROLLED_H},
};

BattlegroundIC::BattlegroundIC()
{
    m_BgObjects.resize(GAMEOBJECT_MAX_SPAWNS+2);

    // +8 == there can be 8 demolishers spawned at the same time, however they are not always spawned that is why i dont add them to NPCS_MAX_SPAWNS
    // +2 == there can be 2 sieges engine spawned at the same time, however they are not always spawned that is why i dont add them to NPCS_MAX_SPANWS

    m_BgCreatures.resize(NPCS_MAX_SPAWNS + 8 + 2 + 7);

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

    for (uint8 i = 0; i < 7; i++)
        nodePoint[i] =  nodePointInitial[i];


    siegeEngineWorkshopTimer = 3*60*1000;
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

    for (uint8 i = 0; i < MAX_NODE_TYPES; i++)
    {
        if (nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
        {
            if (nodePoint[i].nodeState == NODE_STATE_CONFLICT_A ||
                nodePoint[i].nodeState == NODE_STATE_CONFLICT_H)
            {
                if (siegeEngineWorkshopTimer <= diff)
                {
                    uint8 siegeType = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);

                    if (Creature* siege = GetBGCreature(siegeType)) // this always should be true
                    {
                        if (siege->isAlive())
                        {
                            if (siege->HasFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_OOC_NOT_ATTACKABLE))
                                // following sniffs the vehicle always has UNIT_FLAG_UNK_14
                                siege->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                            else
                                siege->SetHealth(siege->GetMaxHealth());
                        }
                        else
                        {
                            DelCreature(siegeType);
                            AddCreature((nodePoint[i].faction == TEAM_ALLIANCE ? NPC_SIEGE_ENGINE_A : NPC_SIEGE_ENGINE_H),siegeType,nodePoint[i].faction, 
                                BG_IC_WorkshopVehicles[4].GetPositionX(),BG_IC_WorkshopVehicles[4].GetPositionY(),
                                BG_IC_WorkshopVehicles[4].GetPositionZ(),BG_IC_WorkshopVehicles[4].GetOrientation(),
                                RESPAWN_ONE_DAY);

                            /*if (GetBGCreature(siegeType))
                            {
                                GetBGCreature(siegeType)->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                GetBGCreature(siegeType)->setFaction(BG_IC_Factions[(nodePoint[i].faction == TEAM_ALLIANCE ? 0 : 1)]);
                            }*/
                        }
                    }

                    // we need to confirm this, i am not sure if this every 3 minutes
                    for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_A : BG_IC_NPC_DEMOLISHER_4_H); i++)
                    {
                        //uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H)+i;
                        if (Creature* demolisher = GetBGCreature(i))
                        {
                            if (!demolisher->isAlive())
                            {
                                DelCreature(i);

                                if (AddCreature(NPC_DEMOLISHER,i,nodePoint->faction,
                                    BG_IC_WorkshopVehicles[i].GetPositionX(),BG_IC_WorkshopVehicles[i].GetPositionY(),
                                    BG_IC_WorkshopVehicles[i].GetPositionZ(),BG_IC_WorkshopVehicles[i].GetOrientation(),
                                    RESPAWN_ONE_DAY))
                                    GetBGCreature(i)->setFaction(BG_IC_Factions[(nodePoint[i].faction == TEAM_ALLIANCE ? 0 : 1)]);
                            }
                        }
                    }
                    siegeEngineWorkshopTimer = 60*3*1000;
                } else siegeEngineWorkshopTimer -= diff;
            }
        }

        // the point is waiting for a change on his banner
        if (nodePoint[i].needChange)
        {
            if (nodePoint[i].timer <= diff)
            {
                uint32 nextBanner = GetNextBanner(&nodePoint[i],nodePoint[i].faction,true);

                nodePoint[i].last_entry = nodePoint[i].gameobject_entry;
                nodePoint[i].gameobject_entry = nextBanner;
                // nodePoint[i].faction = the faction should be the same one...

                GameObject* banner = GetBGObject(nodePoint[i].gameobject_type);

                if (!banner) // this should never happen
                    return;
            
                float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };
            
                DelObject(nodePoint[i].gameobject_type);
                AddObject(nodePoint[i].gameobject_type,nodePoint[i].gameobject_entry,cords[0],cords[1],cords[2],cords[3],0,0,0,0,RESPAWN_ONE_DAY);

                UpdateNodeWorldState(&nodePoint[i]);
                HandleCapturedNodes(&nodePoint[i],false); 

                nodePoint[i].needChange = false;
                nodePoint[i].timer = 60000;
            } else nodePoint[i].timer -= diff;
        }
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

    DoorOpen(BG_IC_GO_DOODAD_HU_PORTCULLIS01_1);
    DoorOpen(BG_IC_GO_DOODAD_HU_PORTCULLIS01_2);
    DoorOpen(BG_IC_GO_DOODAD_VR_PORTCULLIS01_1);
    DoorOpen(BG_IC_GO_DOODAD_VR_PORTCULLIS01_2);
}

void BattlegroundIC::AddPlayer(Player *plr)
{
    Battleground::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundICScore* sc = new BattlegroundICScore;

    m_PlayerScores[plr->GetGUID()] = sc;

    if (nodePoint[NODE_TYPE_QUARRY].faction == plr->GetTeamId())
        plr->CastSpell(plr,SPELL_QUARRY,true);

    if (nodePoint[NODE_TYPE_REFINERY].faction == plr->GetTeamId())
        plr->CastSpell(plr,SPELL_OIL_REFINERY,true);
}

void BattlegroundIC::RemovePlayer(Player* plr,uint64 guid)
{
    Battleground::RemovePlayer(plr, guid);
    
    plr->RemoveAura(SPELL_QUARRY);
    plr->RemoveAura(SPELL_OIL_REFINERY);
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

    for (uint8 i = 0; i < 6; i++)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry,(GateStatus[GetGateIDFromEntry(BG_IC_ObjSpawnlocs[i].entry)] == BG_IC_GATE_DESTROYED ? true : false));
        data << uint32(uws) << uint32(1);
    }
    
    for (uint8 i = 0 ; i < MAX_NODE_TYPES ; i++)
        data << uint32(nodePoint[i].worldStates[nodePoint[i].nodeState]) << uint32(1);
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

    if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+5,BG_IC_SpiritGuidePos[5][0], BG_IC_SpiritGuidePos[5][1],BG_IC_SpiritGuidePos[5][2], BG_IC_SpiritGuidePos[5][3],ALLIANCE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+6,BG_IC_SpiritGuidePos[6][0], BG_IC_SpiritGuidePos[6][1],BG_IC_SpiritGuidePos[6][2], BG_IC_SpiritGuidePos[6][3],HORDE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+3,BG_IC_SpiritGuidePos[7][0], BG_IC_SpiritGuidePos[7][1],BG_IC_SpiritGuidePos[7][2], BG_IC_SpiritGuidePos[7][3],ALLIANCE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+4,BG_IC_SpiritGuidePos[8][0], BG_IC_SpiritGuidePos[8][1],BG_IC_SpiritGuidePos[8][2], BG_IC_SpiritGuidePos[8][3],HORDE))
    {
        sLog.outError("Failed to spawn initial spirit guide!");
        return false;
    }

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

void BattlegroundIC::RealocatePlayers(ICNodePointType nodeType)
{
    // Those who are waiting to resurrect at this node are taken to the closest own node's graveyard
    std::vector<uint64> ghost_list = m_ReviveQueue[m_BgCreatures[BG_IC_NPC_SPIRIT_GUIDE_1+nodeType-2]];
    if (!ghost_list.empty())
    {
        WorldSafeLocsEntry const *ClosestGrave = NULL;
        for (std::vector<uint64>::const_iterator itr = ghost_list.begin(); itr != ghost_list.end(); ++itr)
        {
            Player* plr = sObjectMgr.GetPlayer(*itr);
            if (!plr)
                continue;

            if (!ClosestGrave)                              // cache
                ClosestGrave = GetClosestGraveYard(plr);

            if (ClosestGrave)
                plr->TeleportTo(GetMapId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
        }
    }
}

void BattlegroundIC::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    // All the node points are iterated to find the clicked one
    for (uint8 i = 0; i < MAX_NODE_TYPES; i++)
    {
        if (nodePoint[i].gameobject_entry == target_obj->GetEntry())
        {
            // this SHOULD NEEVEER HAPPEN
            if (nodePoint[i].faction == player->GetTeamId())
                return;

            uint32 nextBanner = GetNextBanner(&nodePoint[i],player->GetTeamId(),false);

            // we set the new settings of the nodePoint
            nodePoint[i].faction = player->GetTeamId();
            nodePoint[i].last_entry = nodePoint[i].gameobject_entry;
            nodePoint[i].gameobject_entry = nextBanner;

            // this is just needed if the next banner is grey
            if (nodePoint[i].banners[1] == nextBanner || nodePoint[i].banners[3] == nextBanner)
            {
                nodePoint[i].timer = 60000; // 1 minute for last change (real faction banner)
                nodePoint[i].needChange = true;

                RealocatePlayers(nodePoint->nodeType);

                if (nodePoint[i].nodeType != NODE_TYPE_REFINERY && nodePoint[i].nodeType != NODE_TYPE_QUARRY)
                    if (m_BgCreatures[BG_IC_NPC_SPIRIT_GUIDE_1+(nodePoint[i].nodeType)-2])
                    {
                        DelCreature(BG_IC_NPC_SPIRIT_GUIDE_1+(nodePoint[i].nodeType)-2);
                        sLog.outError("Spirit Guide: Removing");
                    }
            } else if (nextBanner == nodePoint[i].banners[0] || nextBanner == nodePoint[i].banners[2]) // if we are going to spawn the definitve faction banner, we dont need the timer anymore
            {
                nodePoint[i].timer = 60000;
                nodePoint[i].needChange = false;
                HandleCapturedNodes(&nodePoint[i],true); 
            }

            GameObject* banner = GetBGObject(nodePoint[i].gameobject_type);

            if (!banner) // this should never happen
                return;
            
            float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };
            
            DelObject(nodePoint[i].gameobject_type);
            AddObject(nodePoint[i].gameobject_type,nodePoint[i].gameobject_entry,cords[0],cords[1],cords[2],cords[3],0,0,0,0,RESPAWN_ONE_DAY);

            if (nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
            {
                DelObject(BG_IC_GO_SEAFORIUM_BOMBS_1);
                DelObject(BG_IC_GO_SEAFORIUM_BOMBS_2);
            }

            UpdateNodeWorldState(&nodePoint[i]);
            // we dont need iterating if we are here
            // If the needChange bool was set true, we will handle the rest in the Update Map function.
            return;      
        }
    }
}

void BattlegroundIC::UpdateNodeWorldState(ICNodePoint* nodePoint)
{
    //updating worldstate
    if (nodePoint->gameobject_entry == nodePoint->banners[0])
        nodePoint->nodeState = NODE_STATE_CONTROLLED_A;
    else if (nodePoint->gameobject_entry == nodePoint->banners[1])
        nodePoint->nodeState = NODE_STATE_CONFLICT_A;
    else if (nodePoint->gameobject_entry == nodePoint->banners[2])
        nodePoint->nodeState = NODE_STATE_CONTROLLED_H;
    else if (nodePoint->gameobject_entry == nodePoint->banners[3])
        nodePoint->nodeState = NODE_STATE_CONFLICT_H;

    uint32 worldstate = nodePoint->worldStates[nodePoint->nodeState];

    // with this we are sure we dont bug the client
    for (uint8 i = 0; i < 4; i++)
        UpdateWorldState(nodePoint->worldStates[i],0);

    UpdateWorldState(worldstate,1);
}

uint32 BattlegroundIC::GetNextBanner(ICNodePoint* nodePoint, uint32 team, bool returnDefinitve)
{
    // this is only used in the update map function
    if (returnDefinitve)
        // here is a special case, here we must return the definitve faction banner after the grey banner was spawned 1 minute
        return nodePoint->banners[(team == TEAM_ALLIANCE ? 0 : 2)];

    // there were no changes, this point has never been captured by any faction or at least clicked
    if (nodePoint->last_entry == 0)
        // 1 returns the CONTESTED ALLIANCE BANNER, 3 returns the HORDE one
        return nodePoint->banners[(team == TEAM_ALLIANCE ? 1 : 3)];

    // If the actual banner is the definitive faction banner, we must return the grey banner of the player's faction
    if (nodePoint->gameobject_entry == nodePoint->banners[0] || nodePoint->gameobject_entry == nodePoint->banners[2])
        return nodePoint->banners[(team == TEAM_ALLIANCE ? 1 : 3)];

    // If the actual banner is the grey faction banner, we must return the previous banner
    if (nodePoint->gameobject_entry == nodePoint->banners[1] || nodePoint->banners[3])
        return nodePoint->last_entry;
   
    // we should never be here...
    sLog.outError("Isle Of Conquest: Unexpected return in GetNextBanner function");
    return 0;
}

void BattlegroundIC::HandleCapturedNodes(ICNodePoint* nodePoint, bool recapture)
{
    if(nodePoint->nodeType != NODE_TYPE_REFINERY && nodePoint->nodeType != NODE_TYPE_QUARRY)
        if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+nodePoint->nodeType-2, 
                                       BG_IC_SpiritGuidePos[nodePoint->nodeType][0], BG_IC_SpiritGuidePos[nodePoint->nodeType][1], 
                                       BG_IC_SpiritGuidePos[nodePoint->nodeType][2], BG_IC_SpiritGuidePos[nodePoint->nodeType][3], 
                                       (nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE)))
            sLog.outError("Failed to spawn spirit guide! point: %u, team: %u,", nodePoint->nodeType, nodePoint->faction);

    switch(nodePoint->gameobject_type)
    {
    case BG_IC_GO_QUARRY_BANNER:
        RemoveAuraOnTeam(SPELL_QUARRY,(nodePoint->faction == TEAM_ALLIANCE ? HORDE : ALLIANCE));
        CastSpellOnTeam(SPELL_QUARRY,(nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE));
        break;
    case BG_IC_GO_REFINERY_BANNER:
        RemoveAuraOnTeam(SPELL_OIL_REFINERY,(nodePoint->faction == TEAM_ALLIANCE ? HORDE : ALLIANCE));
        CastSpellOnTeam(SPELL_OIL_REFINERY,(nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE));
        break;
    case BG_IC_GO_WORKSHOP_BANNER:
        {
            if (siegeEngineWorkshopTimer < 3*60*1000)
                siegeEngineWorkshopTimer = 3*60*1000;

            if (!recapture)
            {
                // we must del opposing faction vehicles when the node is captured (unused ones)
                for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_H : BG_IC_NPC_DEMOLISHER_1_A); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_H : BG_IC_NPC_DEMOLISHER_4_A); i++)
                {
                    //uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_H : BG_IC_NPC_DEMOLISHER_1_A)+i;
                    if (Creature* demolisher = GetBGCreature(i))
                    {
                        if (Vehicle* vehicleDemolisher = demolisher->GetVehicleKit())
                        {
                            if (!vehicleDemolisher->GetPassenger(0) &&
                                !vehicleDemolisher->GetPassenger(1) &&
                                !vehicleDemolisher->GetPassenger(2))
                                DelCreature(i);
                        }
                    }
                }

                for (uint8 i = 0; i < 4; i++)
                {
                    uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H)+i;

                    if (AddCreature(NPC_DEMOLISHER,type,nodePoint->faction,
                        BG_IC_WorkshopVehicles[i].GetPositionX(),BG_IC_WorkshopVehicles[i].GetPositionY(),
                        BG_IC_WorkshopVehicles[i].GetPositionZ(),BG_IC_WorkshopVehicles[i].GetOrientation(),
                        RESPAWN_ONE_DAY))
                        GetBGCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                }
            
                // we check if the opossing siege engine is in use
                int8 enemySiege = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_H : BG_IC_NPC_SIEGE_ENGINE_A);

                if (Creature* siegeEngine = GetBGCreature(enemySiege))
                {
                    if (Vehicle* vehicleSiege = siegeEngine->GetVehicleKit())
                    {
                        if (!vehicleSiege->GetPassenger(0) && 
                            !vehicleSiege->GetPassenger(1) &&
                            !vehicleSiege->GetPassenger(2) &&
                            !vehicleSiege->GetPassenger(3))
                            DelCreature(enemySiege);
                    }
                }

                uint8 siegeType = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);
                AddCreature((nodePoint->faction == TEAM_ALLIANCE ? NPC_SIEGE_ENGINE_A : NPC_SIEGE_ENGINE_H),siegeType,nodePoint->faction, 
                    BG_IC_WorkshopVehicles[4].GetPositionX(),BG_IC_WorkshopVehicles[4].GetPositionY(),
                    BG_IC_WorkshopVehicles[4].GetPositionZ(),BG_IC_WorkshopVehicles[4].GetOrientation(),
                    RESPAWN_ONE_DAY);

                if (Creature* siegeEngine = GetBGCreature(siegeType))
                {
                    siegeEngine->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    siegeEngine->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                }
            }
            for (uint8 i = 0; i < 2; i++)
            {
                AddObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i,GO_SEAFORIUM_BOMBS,
                workshopBombs[i].GetPositionX(),workshopBombs[i].GetPositionY(),
                workshopBombs[i].GetPositionZ(),workshopBombs[i].GetOrientation(),
                0,0,0,0,10);

                if (GameObject* seaforiumBombs = GetBGObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i))
                {
                    seaforiumBombs->SetRespawnTime(10);
                    seaforiumBombs->SetUInt32Value(GAMEOBJECT_FACTION,BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                }
            }
            break;
        }
    default:
        break;
    }
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

WorldSafeLocsEntry const* BattlegroundIC::GetClosestGraveYard(Player* player)
{
    BattlegroundTeamId teamIndex = GetTeamIndexByTeamId(player->GetTeam());

    // Is there any occupied node for this team?
    std::vector<uint8> nodes;
    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
        if (nodePoint[i].faction == player->GetTeamId())
            nodes.push_back(i);

    WorldSafeLocsEntry const* good_entry = NULL;
    // If so, select the closest node to place ghost on
    if (!nodes.empty())
    {
        float plr_x = player->GetPositionX();
        float plr_y = player->GetPositionY();

        float mindist = 999999.0f;
        for (uint8 i = 0; i < nodes.size(); ++i)
        {
            WorldSafeLocsEntry const*entry = sWorldSafeLocsStore.LookupEntry(BG_IC_GraveyardIds[nodes[i]]);
            if (!entry)
                continue;
            float dist = (entry->x - plr_x)*(entry->x - plr_x)+(entry->y - plr_y)*(entry->y - plr_y);
            if (mindist > dist)
            {
                mindist = dist;
                good_entry = entry;
            }
        }
        nodes.clear();
    }
    // If not, place ghost on starting location
    if (!good_entry)
        good_entry = sWorldSafeLocsStore.LookupEntry(BG_IC_GraveyardIds[teamIndex+MAX_NODE_TYPES]);

    return good_entry;
}