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
    m_BgCreatures.resize(0);

    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_IC_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_IC_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_IC_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_IC_HAS_BEGUN;

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
            GetBGObject(BG_IC_GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01)->RemoveFromWorld();

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
    DoorOpen(BG_IC_GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01);

    sLog.outError("Isle Of Conquest: StartingEventOpenDoors");
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
    /*data << uint32(4862) << uint32(1000);
    data << uint32(5196) << uint32(0);
    data << uint32(5194) << uint32(0);
    data << uint32(4857) << uint32(0);
    data << uint32(4584) << uint32(0);
    data << uint32(4315) << uint32(0);
    data << uint32(4312) << uint32(0);
    data << uint32(4309) << uint32(1);
    data << uint32(4306) << uint32(0);
    data << uint32(4304) << uint32(1);
    data << uint32(4301) << uint32(0);
    data << uint32(4298) << uint32(1);
    data << uint32(4294) << uint32(0);
    data << uint32(4226) << uint32(256);
    data << uint32(4221) << uint32(1);
    data << uint32(4229) << uint32(0);
    data << uint32(4440) << uint32(0);
    data << uint32(4348) << uint32(0);
    data << uint32(4346) << uint32(0);
    data << uint32(3610) << uint32(1);
    data << uint32(1943) << uint32(0);
    data << uint32(1941) << uint32(0);
    data << uint32(4343) << uint32(0);
    data << uint32(4340) << uint32(0);
    data << uint32(4327) << uint32(1);
    data << uint32(4324) << uint32(0);
    data << uint32(4320) << uint32(0);
    data << uint32(4318) << uint32(1);
    data << uint32(5071) << uint32(6);
    data << uint32(4062) << uint32(0);
    data << uint32(3601) << uint32(0);
    data << uint32(3327) << uint32(0);
    data << uint32(4023) << uint32(0);
    data << uint32(4021) << uint32(0);
    data << uint32(3191) << uint32(4);
    data << uint32(2263) << uint32(0);
    data << uint32(2259) << uint32(0);
    data << uint32(5037) << uint32(6);
    data << uint32(4864) << uint32(100);
    data << uint32(4863) << uint32(300);
    data << uint32(4354) << uint32(0);
    data << uint32(4375) << uint32(0);
    data << uint32(4314) << uint32(0);
    data << uint32(4313) << uint32(1);
    data << uint32(4311) << uint32(0);
    data << uint32(4310) << uint32(0);
    data << uint32(4308) << uint32(0);
    data << uint32(4307) << uint32(0);
    data << uint32(4305) << uint32(0);
    data << uint32(4303) << uint32(0);
    data << uint32(4302) << uint32(0);
    data << uint32(4300) << uint32(0);
    data << uint32(4299) << uint32(0);
    data << uint32(4297) << uint32(0);
    data << uint32(4296) << uint32(0);
    data << uint32(4293) << uint32(1);
    data << uint32(4227) << uint32(287);
    data << uint32(4222) << uint32(1);
    data << uint32(4131) << uint32(60);
    data << uint32(4228) << uint32(0);
    data << uint32(4230) << uint32(0);
    data << uint32(4439) << uint32(0);
    data << uint32(5195) << uint32(0);
    data << uint32(5193) << uint32(0);
    data << uint32(5192) << uint32(0);
    data << uint32(2565) << uint32(142);
    data << uint32(4025) << uint32(0);
    data << uint32(4024) << uint32(0);
    data << uint32(4022) << uint32(0);
    data << uint32(4020) << uint32(0);
    data << uint32(2264) << uint32(0);
    data << uint32(2262) << uint32(0);
    data << uint32(2261) << uint32(0);
    data << uint32(4347) << uint32(0);
    data << uint32(4345) << uint32(1);
    data << uint32(4344) << uint32(0);
    data << uint32(4342) << uint32(0);
    data << uint32(4341) << uint32(0);
    data << uint32(4339) << uint32(1);
    data << uint32(4328) << uint32(1);
    data << uint32(4326) << uint32(1);
    data << uint32(4325) << uint32(0);
    data << uint32(4323) << uint32(0);
    data << uint32(4322) << uint32(0);
    data << uint32(4321) << uint32(0);
    data << uint32(4319) << uint32(1);
    data << uint32(4317) << uint32(1);
    data << uint32(4273) << uint32(1);
    data << uint32(3426) << uint32(3);
    data << uint32(2851) << uint32(0);
    data << uint32(3710) << uint32(0);
    data << uint32(3600) << uint32(0);
    data << uint32(3695) << uint32(0);
    data << uint32(2260) << uint32(0);
    data << uint32(3901) << uint32(3);
    data << uint32(3826) << uint32(1);
    data << uint32(3801) << uint32(0);
    data << uint32(1942) << uint32(0);
    data << uint32(3085) << uint32(379);*/

}

bool BattlegroundIC::SetupBattleground()
{
    for (uint8 i = 0; i < GAMEOBJECT_MAX_SPAWNS; i++)
    {
        if (!AddObject(i,BG_IC_ObjEntries[i],
            BG_IC_ObjSpawnlocs[i][0],BG_IC_ObjSpawnlocs[i][1],
            BG_IC_ObjSpawnlocs[i][2],BG_IC_ObjSpawnlocs[i][3],
            0,0,0,0,RESPAWN_ONE_DAY))
        {
            sLog.outError("Isle of Conquest: There was an error spawning gameobject %u",BG_IC_ObjEntries[i]);
            return false;      
        }
    }  

    return true;
}

/*void BattlegroundIC::SpawnLeader(uint32 teamid)
{
    if (teamid == ALLIANCE)
        AddCreature(34924, 0, ALLIANCE, 307.03f, -833.04f, 48.91f, 6.23f, 10*MINUTE);
    else
        AddCreature(34922, 1, HORDE, 1264.42f, -766.80f, 48.91f, 3.28f, 10*MINUTE);
}*/

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

void BattlegroundIC::EndBattleground(uint32 winner)
{
    Battleground::EndBattleground(winner);
}

void BattlegroundIC::EventPlayerClickedOnFlag(Player * /*source*/, GameObject* /*target_obj*/)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}
