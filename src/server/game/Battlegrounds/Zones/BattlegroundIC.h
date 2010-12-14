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

#ifndef __BATTLEGROUNDIC_H
#define __BATTLEGROUNDIC_H

class Battleground;

enum gameobjectsIC
{
    GO_ALLIANCE_BANNER = 195396,

    GO_ALLIANCE_GATE_1 = 195699,
    GO_ALLIANCE_GATE_2 = 195698,
    GO_ALLIANCE_GATE_3 = 195700,

    GO_ALLIANCE_GUNSHIP_PORTAL = 195320,

    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS = 195705,

    GO_BENCH_1 = 186896,
    GO_BENCH_2 = 186922,
    GO_BENCH_3 = 186899,
    GO_BENCH_4 = 186904,
    GO_BENCH_5 = 186897,

    GO_BONFIRE_1 = 195376,
    GO_BONFIRE_2 = 195208,
    GO_BONFIRE_3 = 195210,
    GO_BONFIRE_4 = 195207,
    GO_BONFIRE_5 = 195209,
    GO_BONFIRE_6 = 195377,

    GO_DOCKS_BANNER = 195157,

    GO_DOODAD_HU_PORTCULLIS01 = 195436,

    GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01 = 195703,

    GO_DOODAD_PORTCULLISACTIVE01 = 195451,

    GO_DOODAD_PORTCULLISACTIVE02 = 195452,

    GO_DOODAD_VR_PORTCULLIS01 = 195437,

    // GO_EXPLOSIVE_TRAP_V = 189321, player object?

    GO_CHAIR_1 = 195410,
    GO_CHAIR_2 = 195414,
    GO_CHAIR_3 = 160415,
    GO_CHAIR_4 = 195418,
    GO_CHAIR_5 = 195416,
    GO_CHAIR_6 = 160410,
    GO_CHAIR_7 = 160418,
    GO_CHAIR_8 = 160416,
    GO_CHAIR_9 = 160419,

    GO_FLAGPOLE_1 = 195131,
    GO_FLAGPOLE_2 = 195439,
    GO_FLAGPOLE_3 = 195131,

    GO_GREAT_FEAST = 192625,

    GO_GUNSHIP_PORTAL_1 = 195371,
    GO_GUNSHIP_PORTAL_2 = 196413,

    GO_HANGAR_BANNER = 195158,

    GO_HORDE_BANNER = 195393,

    GO_HORDE_GATE_1 = 195494,
    GO_HORDE_GATE_2 = 195496,
    GO_HORDE_GATE_3 = 195495,

    GO_HORDE_GUNSHIP_PORTAL = 195326,

    GO_HORDE_GUNSHIP_PORTAL_EFFECTS = 195706,

    GO_HORDE_KEEP_PORTCULLIS = 195223,

    GO_HUGE_SEAFORIUM_BOMB_1 = 195331,
    GO_HUGE_SEAFORIUM_BOMB_2 = 195332,
    GO_HUGE_SEAFORIUM_BOMB_3 = 195333,

    GO_QUARRY_BANNER = 195338,
    GO_REFRESHMENT_PORTAL = 186811,
    GO_SEAFORIUM_BOMBS = 195237,
    // GO_SNAKE_TRAP = 183957, player stuff?
    GO_STOVE_1 = 174863,
    GO_STOVE_2 = 160411,

    GO_TELEPORTER_1 = 195314,
    GO_TELEPORTER_2 = 195313,
    GO_TELEPORTER_3 = 195315,
    GO_TELEPORTER_4 = 195316,

    GO_TELEPORTER_EFFECTS_A = 195701,

    GO_TELEPORTER_EFFECTS_H = 195702,

    GO_WORKSHOP_BANNER = 195133,

    GO_BRAZIER_1 = 195402,
    GO_BRAZIER_2 = 195403,
    GO_BRAZIER_3 = 195425,
    GO_BRAZIER_4 = 195424
};

#define GAMEOBJECT_MAX_SPAWNS 118

const uint32 BG_IC_ObjEntries[GAMEOBJECT_MAX_SPAWNS] =
{
    GO_ALLIANCE_BANNER, // 1

    GO_ALLIANCE_GATE_1, // 2
    GO_ALLIANCE_GATE_2, // 3
    GO_ALLIANCE_GATE_3, // 4

    GO_ALLIANCE_GUNSHIP_PORTAL, // 5
    GO_ALLIANCE_GUNSHIP_PORTAL, // 6
    GO_ALLIANCE_GUNSHIP_PORTAL, // 7

    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 8
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 9
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 10
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 11

    GO_BENCH_1, // 12
    GO_BENCH_2, // 13
    GO_BENCH_3, // 14
    GO_BENCH_4, // 15
    GO_BENCH_5, // 16

    GO_BONFIRE_1, // 17
    GO_BONFIRE_2, // 18
    GO_BONFIRE_3, // 19
    GO_BONFIRE_4, // 20
    GO_BONFIRE_5, // 21
    GO_BONFIRE_6, // 22

    GO_BRAZIER_1, // 23
    GO_BRAZIER_2, // 24
    GO_BRAZIER_3, // 25
    GO_BRAZIER_4, // 26

    GO_CHAIR_1, // 27
    GO_CHAIR_2, // 28
    GO_CHAIR_3, // 29
    GO_CHAIR_4, // 30
    GO_CHAIR_5, // 31
    GO_CHAIR_6, // 32
    GO_CHAIR_7, // 33
    GO_CHAIR_3, // 34
    GO_CHAIR_6, // 35
    GO_CHAIR_8, // 36
    GO_CHAIR_8, // 37
    GO_CHAIR_9, // 38

    GO_DOCKS_BANNER,  // 39

    GO_DOODAD_HU_PORTCULLIS01,  // 40
    GO_DOODAD_HU_PORTCULLIS01,  // 41

    GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01,  // 42

    GO_DOODAD_PORTCULLISACTIVE01,  // 43

    GO_DOODAD_PORTCULLISACTIVE02,  // 44

    GO_DOODAD_VR_PORTCULLIS01,  // 45
    GO_DOODAD_VR_PORTCULLIS01, // 46

    GO_FLAGPOLE_1, // 47
    GO_FLAGPOLE_2, // 48
    GO_FLAGPOLE_2, // 49
    GO_FLAGPOLE_1, // 50
    GO_FLAGPOLE_1, // 51
    GO_FLAGPOLE_1, // 52
    GO_FLAGPOLE_1, // 53

    GO_GREAT_FEAST, // 54

    GO_GUNSHIP_PORTAL_1, // 55
    GO_GUNSHIP_PORTAL_2, // 56
    GO_GUNSHIP_PORTAL_1, // 57
    GO_GUNSHIP_PORTAL_1, // 58
    GO_GUNSHIP_PORTAL_1, // 59

    GO_HANGAR_BANNER, // 60

    GO_HORDE_BANNER, // 61

    GO_HORDE_GATE_1, // 63
    GO_HORDE_GATE_2, // 64 
    GO_HORDE_GATE_3, // 65

    GO_HORDE_GUNSHIP_PORTAL, // 66

    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 67
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 68
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 69
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 70
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 71
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 72
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 73
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 74

    GO_HORDE_KEEP_PORTCULLIS, // 75
    
    GO_HUGE_SEAFORIUM_BOMB_1, // 76
    GO_HUGE_SEAFORIUM_BOMB_1, // 77
    GO_HUGE_SEAFORIUM_BOMB_1, // 78
    GO_HUGE_SEAFORIUM_BOMB_2, // 79
    GO_HUGE_SEAFORIUM_BOMB_2, // 80
    GO_HUGE_SEAFORIUM_BOMB_2, // 81
    GO_HUGE_SEAFORIUM_BOMB_2, // 82
    GO_HUGE_SEAFORIUM_BOMB_3, // 83
    GO_HUGE_SEAFORIUM_BOMB_3, // 84
    GO_HUGE_SEAFORIUM_BOMB_3, // 85
    GO_HUGE_SEAFORIUM_BOMB_3, // 86

    GO_QUARRY_BANNER, // 87

    GO_SEAFORIUM_BOMBS, // 88
    GO_SEAFORIUM_BOMBS, // 89

    GO_STOVE_1, // 90
    GO_STOVE_2, // 91
    GO_STOVE_1, // 92
    GO_STOVE_2, // 93

    GO_TELEPORTER_1, // 94
    GO_TELEPORTER_1, // 95
    GO_TELEPORTER_2, // 96
    GO_TELEPORTER_3, // 97
    GO_TELEPORTER_2, // 98
    GO_TELEPORTER_4, // 99
    GO_TELEPORTER_3, // 100
    GO_TELEPORTER_3, // 101
    GO_TELEPORTER_4, // 102
    GO_TELEPORTER_4, // 103
    GO_TELEPORTER_1, // 104
    GO_TELEPORTER_2, // 105

   GO_TELEPORTER_EFFECTS_A, // 106
   GO_TELEPORTER_EFFECTS_A, // 107
   GO_TELEPORTER_EFFECTS_A, // 108
   GO_TELEPORTER_EFFECTS_A, // 109
   GO_TELEPORTER_EFFECTS_A, // 110
   GO_TELEPORTER_EFFECTS_A, // 111

   GO_TELEPORTER_EFFECTS_H, // 112
   GO_TELEPORTER_EFFECTS_H, // 113
   GO_TELEPORTER_EFFECTS_H, // 114
   GO_TELEPORTER_EFFECTS_H, // 115
   GO_TELEPORTER_EFFECTS_H, // 116
   GO_TELEPORTER_EFFECTS_H, // 117

   GO_WORKSHOP_BANNER // 118
};

const float BG_IC_ObjSpawnlocs[GAMEOBJECT_MAX_SPAWNS][4] =
{
    {299.153,-784.589,48.9162,-0.157079}, // Alliance Banner

    {351.615,-762.75,48.9162,-1.5708}, // Alliance Gate
    {351.024,-903.326,48.9247,1.5708}, // Alliance Gate
    {413.479,-833.95,48.5238,3.14159}, // Alliance Gate

    {827.958,-994.467,134.071,0}, // Alliance Gunship Portal
    {738.613,-1106.58,134.745,2.54818}, // Alliance Gunship Portal
    {672.283,-1156.99,133.706,1.37881}, // Alliance Gunship Portal

    {827.962,-994.476,134.07,3.14159}, // Alliance Gunship Portal Effects
    {839.227,-1188.85,278.93,3.91978}, // Alliance Gunship Portal Effects
    {672.264,-1157.03,133.706,3.14159}, // Alliance Gunship Portal Effects
    {738.795,-1106.75,134.743,3.14159}, // Alliance Gunship Portal Effects

    {834.208,-461.826,22.3067,1.5708}, // Bench
    {826.153,-461.985,22.5149,1.5708}, // Bench
    {817.446,-470.47,25.372,-1.56207}, // Bench
    {827.001,-474.415,25.372,1.57952}, // Bench
    {819.264,-461.961,22.7614,1.57952}, // Bench


    {1162.91,-734.578,48.8948,-2.9845}, // Bonfire
    {1282.34,-799.762,87.1357,-3.13286}, // Bonfire
    {1358.06,-732.178,87.1606,-3.13284}, // Bonfire
    {1281.76,-732.844,87.1574,-3.13246}, // Bonfire
    {1358.81,-797.899,87.2953,3.13312}, // Bonfire
    {1162.21,-790.543,48.9162,2.27765}, // Bonfire


    {1262.21,-751.358,48.8133,2.26893}, // Brazier
    {1262.58,-781.861,48.8132,2.04203}, // Brazier
    {223.818,-839.352,60.7917,1.09083}, // Brazier
    {224.277,-822.77,60.7917,2.06822}, // Brazier

    {632.876,-282.461,5.45364,-0.851094}, // Chair
    {635.796,-276.295,5.48659,-3.03273}, // Chair
    {762.245,-444.795,22.8526,-1.98095}, // Chair
    {632.156,-304.503,5.4879,1.15603}, // Chair
    {643.86,-270.204,5.48898,2.36903}, // Chair
    {902.234,-455.508,18.3935,-1.00356}, // Chair
    {810.237,-461.2,25.4627,1.5708}, // Chair
    {1117.19,-365.674,18.8456,0.968657}, // Chair
    {1066.19,-337.214,18.8225,0.453785}, // Chair
    {798.324,-444.951,22.5601,-1.02102}, // Chair
    {1081.81,-358.637,18.5531,1.92859}, // Chair
    {814.931,-470.816,33.6373,-3.12412}, // Chair

    {726.385,-360.205,17.8153,-1.62316}, // Docks Banner

    {401.024,-780.724,49.9482,-2.52896}, // Doodad_HU_Portcullis01
    {399.802,-885.208,50.1939,2.516}, // Doodad_HU_Portcullis01

    {413.479,-833.95,48.5238,3.14159}, // Doodad_ND_Human_Gate_ClosedFX_Door01

    {-832.595,51.4109,-0.0261791, 0}, // Doodad_PortcullisActive01

    {273.033,-832.199,51.4109,-0.0261791}, // Doodad_PortcullisActive02

    {1156.89,-843.998,48.6322,0.732934}, // Doodad_VR_Portcullis01
    {1157.05,-682.36,48.6322,-0.829132}, // Doodad_VR_Portcullis01

    {-400.809,37.6253,-1.76278}, // Flagpole
    {1284.76,-705.668,48.9163,-3.08918}, // Flagpole
    {299.153,-784.589,48.9162,-0.157079}, // Flagpole
    {726.385,-360.205,17.8153,-1.6057}, // Flagpole
    {807.78,-1000.07,132.381,-1.91986}, // Flagpole
    {776.229,-804.283,6.45052,1.6057}, // Flagpole
    {251.016,-1159.32,17.2376,-2.25147}, // Flagpole

    {374.14,-820.467,48.9162,-0.899281}, // Great Feast

    {839.242,-1188.83,278.93,3.91978}, // Gunship Portal
    {663.394,-1252.59,288.892,3.18979}, // Gunship Portal
    {1125.53,-598.052,201.667,1.97711}, // Gunship Portal
    {1472.64,-786.956,191.414,6.15762}, // Gunship Portal
    {1458.37,-730.522,190.091,0.398611}, // Gunship Portal

    {807.78,-1000.07,132.381,-1.93732}, // Hangar Banner
    {1284.76,-705.668,48.9163,-3.08918}, // Horde Banner

    {1150.9,-762.606,47.5077,3.14159}, // Horde Gate
    {1218.74,-851.155,48.2533,-1.5708}, // Horde Gate
    {1217.9,-676.948,47.6341,1.5708}, // Horde Gate

    {827.922,-993.325,134.197,3.14159}, // Horde Gunship Portal

    {663.373,-1252.56,288.891,3.18979}, // Horde Gunship Portal Effects
    {666.134,-1262.39,289.365,3.24939},  // Horde Gunship Portal Effects
    {739.014,-1106.66,134.755,3.14159}, // Horde Gunship Portal Effects
    {672.087,-1156.79,133.706,3.14159}, // Horde Gunship Portal Effects
    {827.924,-993.299,134.2,3.14159}, // Horde Gunship Portal Effects
    {673.861,-1286.67,290.061,3.32091}, // Horde Gunship Portal Effects
    {668.571,-1270.32,289.659,3.28327}, // Horde Gunship Portal Effects
    {684.257,-1363.85,289.922,2.90662}, // Horde Gunship Portal Effects

    {1283.05,-765.878,50.8297,-3.13286}, // Horde Keep Portcullis

    {1154.36,-760.619,48.6274,3.03582}, // Huge Seaforium Bomb
    {1154.2,-768.571,48.7093,2.18026},  // Huge Seaforium Bomb
    {1160.31,-758.259,48.6334,-2.74551}, // Huge Seaforium Bomb
    {300.372,-818.733,48.9162,0.785397}, // Huge Seaforium Bomb
    {302.135,-810.708,48.9162,-1.0472}, // Huge Seaforium Bomb
    {297.321,-851.321,48.9163,-0.942477},  // Huge Seaforium Bomb
    {298.104,-861.026,48.9163,-2.75761}, // Huge Seaforium Bomb
    {1268.31,-745.783,48.9188,0.785397}, // Huge Seaforium Bomb
    {1273.07,-786.573,48.9419,-0.942477}, // Huge Seaforium Bomb
    {1268.51,-738.122,48.9175,-1.0472}, // Huge Seaforium Bomb
    {1273.85,-796.278,48.9364,-2.75761}, // Huge Seaforium Bomb


    {251.016,-1159.32,17.2376,-2.25147}, // Quarry Banner

    {785.509,-864.715,13.3993,2.47837}, // Seaforium Bombs
    {750.601,-864.597,13.4754,1.93731}, // Seaforium Bombs

    {903.291,-457.345,18.1356,2.23402}, // Stove
    {761.462,-446.684,22.5602,0.244344}, // Stove
    {1068.13,-336.373,18.5647,-2.59181}, // Stove
    {1118.32,-363.969,18.5532,-3.08918}, // Stove

    {1143.25,-779.599,48.629,1.64061}, // Teleporter
    {1236.53,-669.415,48.2729,0.104719}, // Teleporter
    {1233.27,-844.526,48.8824,-0.0174525}, // Teleporter
    {311.92,-913.972,48.8159,3.08918}, // Teleporter
    {1235.53,-683.872,49.304,-3.08918}, // Teleporter
    {397.089,-859.382,48.8993,1.64061}, // Teleporter
    {324.635,-749.128,49.3602,0.0174525}, // Teleporter
    {425.675,-857.09,48.5104,-1.6057}, // Teleporter
    {323.54,-888.361,48.9197,0.0349063}, // Teleporter
    {326.285,-777.366,49.0208,3.12412}, // Teleporter
    {1235.09,-857.898,48.9163,3.07177}, // Teleporter
    {1158.76,-746.182,48.6277,-1.51844}, // Teleporter

    {425.686,-857.092,48.51,-1.62316}, // Teleporter Effects (Alliance)
    {324.634,-749.148,49.359,0.0174525}, // Teleporter Effects (Alliance)
    {311.911,-913.986,48.8157,3.08918}, // Teleporter Effects (Alliance)
    {326.266,-777.347,49.0215,3.12412}, // Teleporter Effects (Alliance)
    {323.55,-888.347,48.9198,0.0174525}, // Teleporter Effects (Alliance)
    {397.116,-859.378,48.8989,1.64061}, // Teleporter Effects (Alliance)

    {1143.25,-779.623,48.6291,1.62316}, // Teleporter Effects (Horde)
    {1158.64,-746.148,48.6277,-1.50098}, // Teleporter Effects (Horde)
    {1233.25,-844.573,48.8836,0.0174525}, // Teleporter Effects (Horde)
    {1235.07,-857.957,48.9163,3.05433}, // Teleporter Effects (Horde)
    {1236.46,-669.344,48.2684,0.087266}, // Teleporter Effects (Horde)
    {1235.6,-683.806,49.3028,-3.07177}, // Teleporter Effects (Horde)

    {776.229,-804.283,6.45052,1.6057}, // Workshop Banner
};

enum Buffs
{
    OIL_REFINERY        = 68719,
    QUARRY            = 68720
};

enum BG_IC_Objectives
{
    IC_OBJECTIVE_ASSAULT_BASE   = 245,
    IC_OBJECTIVE_DEFEND_BASE    = 246
};

class BattlegroundICScore : public BattlegroundScore
{
    public:
        BattlegroundICScore() {};
        virtual ~BattlegroundICScore() {};
};

class BattlegroundIC : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundIC();
        ~BattlegroundIC();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleground();
        void SpawnLeader(uint32 teamid);
        void HandleKillUnit(Creature *unit, Player *killer);
        void EndBattleground(uint32 winner);
        void EventPlayerClickedOnFlag(Player *source, GameObject* /*target_obj*/);

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    private:
};
#endif
