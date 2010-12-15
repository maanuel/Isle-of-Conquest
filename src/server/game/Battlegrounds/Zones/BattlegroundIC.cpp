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
    /*m_BgCreatures.resize(2);
    m_BgObjects.resize(5);*/
    //TODO FIX ME!
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_WS_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_WS_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_WS_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_WS_HAS_BEGUN;
}

BattlegroundIC::~BattlegroundIC()
{

}

void BattlegroundIC::Update(uint32 diff)
{
    Battleground::Update(diff);
}

void BattlegroundIC::StartingEventCloseDoors()
{
}

void BattlegroundIC::StartingEventOpenDoors()
{
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

    // Show Full Gate Displays
    GetBGObject(1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(50)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
    GetBGObject(51)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door

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
