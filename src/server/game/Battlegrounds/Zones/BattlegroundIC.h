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
    GO_BRAZIER_4 = 195424,

    GO_REFINERY_BANNER = 195343,

    GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01 = 195491
};

#define GAMEOBJECT_MAX_SPAWNS BG_IC_GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01+1

enum BG_IC_GOs
{
    BG_IC_GO_ALLIANCE_BANNER = 0,

    BG_IC_GO_ALLIANCE_GATE_1, 
    BG_IC_GO_ALLIANCE_GATE_2,
    BG_IC_GO_ALLIANCE_GATE_3,

    BG_IC_GO_BENCH_1,
    BG_IC_GO_BENCH_2,
    BG_IC_GO_BENCH_3,
    BG_IC_GO_BENCH_4,
    BG_IC_GO_BENCH_5,

    BG_IC_GO_BONFIRE_1,
    BG_IC_GO_BONFIRE_2,
    BG_IC_GO_BONFIRE_3,
    BG_IC_GO_BONFIRE_4,
    BG_IC_GO_BONFIRE_5,
    BG_IC_GO_BONFIRE_6,

    BG_IC_GO_BRAZIER_1,
    BG_IC_GO_BRAZIER_2,
    BG_IC_GO_BRAZIER_3,
    BG_IC_GO_BRAZIER_4,

    BG_IC_GO_CHAIR_1, 
    BG_IC_GO_CHAIR_2,
    BG_IC_GO_CHAIR_3_1,
    BG_IC_GO_CHAIR_4, 
    BG_IC_GO_CHAIR_5, 
    BG_IC_GO_CHAIR_6_1, 
    BG_IC_GO_CHAIR_7,
    BG_IC_GO_CHAIR_3_2,
    BG_IC_GO_CHAIR_6_2,
    BG_IC_GO_CHAIR_8_1,
    BG_IC_GO_CHAIR_8_2,
    BG_IC_GO_CHAIR_9,

    BG_IC_GO_DOCKS_BANNER,

    BG_IC_GO_DOODAD_HU_PORTCULLIS01_1, 
    BG_IC_GO_DOODAD_HU_PORTCULLIS01_2,

    BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01, 

    BG_IC_GO_DOODAD_PORTCULLISACTIVE01,

    BG_IC_GO_DOODAD_PORTCULLISACTIVE02,

    BG_IC_GO_DOODAD_VR_PORTCULLIS01_1,
    BG_IC_GO_DOODAD_VR_PORTCULLIS01_2, 

    BG_IC_GO_FLAGPOLE_1_1,
    BG_IC_GO_FLAGPOLE_2_1, 
    BG_IC_GO_FLAGPOLE_2_2,
    BG_IC_GO_FLAGPOLE_1_2, 
    BG_IC_GO_FLAGPOLE_1_3, 
    BG_IC_GO_FLAGPOLE_1_4, 
    BG_IC_GO_FLAGPOLE_1_5,

    BG_IC_GO_HANGAR_BANNER,

    BG_IC_GO_HORDE_BANNER, 

    BG_IC_GO_HORDE_GATE_1, 
    BG_IC_GO_HORDE_GATE_2, 
    BG_IC_GO_HORDE_GATE_3, 

    BG_IC_GO_HORDE_KEEP_PORTCULLIS,
    
    BG_IC_GO_QUARRY_BANNER,

    BG_IC_GO_SEAFORIUM_BOMBS_1, 
    BG_IC_GO_SEAFORIUM_BOMBS_2,

    BG_IC_GO_STOVE_1_1, 
    BG_IC_GO_STOVE_2_1, 
    BG_IC_GO_STOVE_1_2, 
    BG_IC_GO_STOVE_2_2,

    BG_IC_GO_TELEPORTER_1_1, 
    BG_IC_GO_TELEPORTER_1_2,
    BG_IC_GO_TELEPORTER_2_1, 
    BG_IC_GO_TELEPORTER_3_1, 
    BG_IC_GO_TELEPORTER_2_2, 
    BG_IC_GO_TELEPORTER_4_1, 
    BG_IC_GO_TELEPORTER_3_2,
    BG_IC_GO_TELEPORTER_3_3, 
    BG_IC_GO_TELEPORTER_4_2,
    BG_IC_GO_TELEPORTER_4_3,
    BG_IC_GO_TELEPORTER_1_3,
    BG_IC_GO_TELEPORTER_2_3, 
    
    BG_IC_GO_TELEPORTER_EFFECTS_A_1,
    BG_IC_GO_TELEPORTER_EFFECTS_A_2, 
    BG_IC_GO_TELEPORTER_EFFECTS_A_3, 
    BG_IC_GO_TELEPORTER_EFFECTS_A_4,
    BG_IC_GO_TELEPORTER_EFFECTS_A_5,
    BG_IC_GO_TELEPORTER_EFFECTS_A_6, 
    
    BG_IC_GO_TELEPORTER_EFFECTS_H_1,
    BG_IC_GO_TELEPORTER_EFFECTS_H_2, 
    BG_IC_GO_TELEPORTER_EFFECTS_H_3,
    BG_IC_GO_TELEPORTER_EFFECTS_H_4,
    BG_IC_GO_TELEPORTER_EFFECTS_H_5, 
    BG_IC_GO_TELEPORTER_EFFECTS_H_6, 

    BG_IC_GO_WORKSHOP_BANNER,

    BG_IC_GO_REFINERY_BANNER,

    BG_IC_GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01
};

const uint32 BG_IC_ObjEntries[GAMEOBJECT_MAX_SPAWNS] =
{
    GO_ALLIANCE_BANNER, // 1

    GO_ALLIANCE_GATE_1, // 2
    GO_ALLIANCE_GATE_2, // 3
    GO_ALLIANCE_GATE_3, // 4

    /*
    GO_ALLIANCE_GUNSHIP_PORTAL, // 5
    GO_ALLIANCE_GUNSHIP_PORTAL, // 6
    GO_ALLIANCE_GUNSHIP_PORTAL, // 7

    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 8
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 9
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 10
    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS, // 11
    */

    GO_BENCH_1, // 5
    GO_BENCH_2, // 6
    GO_BENCH_3, // 7
    GO_BENCH_4, // 8
    GO_BENCH_5, // 9

    GO_BONFIRE_1, // 10
    GO_BONFIRE_2, // 11
    GO_BONFIRE_3, // 12
    GO_BONFIRE_4, // 13
    GO_BONFIRE_5, // 14
    GO_BONFIRE_6, // 15

    GO_BRAZIER_1, // 16
    GO_BRAZIER_2, // 17
    GO_BRAZIER_3, // 18
    GO_BRAZIER_4, // 19

    GO_CHAIR_1, // 20
    GO_CHAIR_2, // 21
    GO_CHAIR_3, // 22
    GO_CHAIR_4, // 23
    GO_CHAIR_5, // 24
    GO_CHAIR_6, // 25
    GO_CHAIR_7, // 26
    GO_CHAIR_3, // 27
    GO_CHAIR_6, // 28
    GO_CHAIR_8, // 29
    GO_CHAIR_8, // 30
    GO_CHAIR_9, // 31

    GO_DOCKS_BANNER, // 32

    GO_DOODAD_HU_PORTCULLIS01,  // 33
    GO_DOODAD_HU_PORTCULLIS01,  // 34

    GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01,  // 35

    GO_DOODAD_PORTCULLISACTIVE01,  // 36

    GO_DOODAD_PORTCULLISACTIVE02, // 37

    GO_DOODAD_VR_PORTCULLIS01, // 38
    GO_DOODAD_VR_PORTCULLIS01, // 39

    GO_FLAGPOLE_1, // 40
    GO_FLAGPOLE_2, // 41
    GO_FLAGPOLE_2, // 42
    GO_FLAGPOLE_1, // 43
    GO_FLAGPOLE_1, // 44
    GO_FLAGPOLE_1, // 45
    GO_FLAGPOLE_1, // 46

    /*
    GO_GUNSHIP_PORTAL_1, // 53
    GO_GUNSHIP_PORTAL_2, // 54
    GO_GUNSHIP_PORTAL_1, // 55
    GO_GUNSHIP_PORTAL_1, // 56
    GO_GUNSHIP_PORTAL_1, // 57
    */

    GO_HANGAR_BANNER, // 47

    GO_HORDE_BANNER, // 48

    GO_HORDE_GATE_1, // 49 | Main door
    GO_HORDE_GATE_2, // 50 
    GO_HORDE_GATE_3, // 51

    /*
    GO_HORDE_GUNSHIP_PORTAL, // 63

    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 64
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 65
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 66
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 67
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 68
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 69
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 70
    GO_HORDE_GUNSHIP_PORTAL_EFFECTS, // 71
    */

    GO_HORDE_KEEP_PORTCULLIS, // 52
    
    GO_QUARRY_BANNER, // 53

    GO_SEAFORIUM_BOMBS, // 54
    GO_SEAFORIUM_BOMBS, // 55

    GO_STOVE_1, // 56
    GO_STOVE_2, // 57
    GO_STOVE_1, // 58
    GO_STOVE_2, // 59

    GO_TELEPORTER_1, // 60
    GO_TELEPORTER_1, // 61
    GO_TELEPORTER_2, // 62
    GO_TELEPORTER_3, // 63
    GO_TELEPORTER_2, // 64
    GO_TELEPORTER_4, // 65
    GO_TELEPORTER_3, // 66
    GO_TELEPORTER_3, // 67
    GO_TELEPORTER_4, // 68
    GO_TELEPORTER_4, // 69
    GO_TELEPORTER_1, // 70
    GO_TELEPORTER_2, // 71
    
    GO_TELEPORTER_EFFECTS_A, // 72
    GO_TELEPORTER_EFFECTS_A, // 73
    GO_TELEPORTER_EFFECTS_A, // 74
    GO_TELEPORTER_EFFECTS_A, // 75
    GO_TELEPORTER_EFFECTS_A, // 76
    GO_TELEPORTER_EFFECTS_A, // 77
    
    GO_TELEPORTER_EFFECTS_H, // 78
    GO_TELEPORTER_EFFECTS_H, // 79
    GO_TELEPORTER_EFFECTS_H, // 80
    GO_TELEPORTER_EFFECTS_H, // 81
    GO_TELEPORTER_EFFECTS_H, // 82
    GO_TELEPORTER_EFFECTS_H, // 83

    GO_WORKSHOP_BANNER, // 84

    GO_REFINERY_BANNER, // 85

    GO_DOOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01 // 86
};

const float BG_IC_ObjSpawnlocs[GAMEOBJECT_MAX_SPAWNS][4] =
{
    {299.153f,-784.589f,48.9162f,-0.157079f}, // Alliance Banner

    {351.615f,-762.75f,48.9162f,-1.5708f}, // Alliance Gate
    {351.024f,-903.326f,48.9247f,1.5708f}, // Alliance Gate
    {413.479f,-833.95f,48.5238f,3.14159f}, // Alliance Gate

    // This is spawned when the hangar is captured
    /*
    {827.958f,-994.467f,134.071f,0.0f}, // Alliance Gunship Portal
    {738.613f,-1106.58f,134.745f,2.54818f}, // Alliance Gunship Portal
    {672.283f,-1156.99f,133.706f,1.37881f}, // Alliance Gunship Portal

    {827.962f,-994.476f,134.07f,3.14159f}, // Alliance Gunship Portal Effects
    {839.227f,-1188.85f,278.93f,3.91978f}, // Alliance Gunship Portal Effects
    {672.264f,-1157.03f,133.706f,3.14159f}, // Alliance Gunship Portal Effects
    {738.795f,-1106.75f,134.743f,3.14159f}, // Alliance Gunship Portal Effects
    */

    {834.208f,-461.826f,22.3067f,1.5708f}, // Bench
    {826.153f,-461.985f,22.5149f,1.5708f}, // Bench
    {817.446f,-470.47f,25.372f,-1.56207f}, // Bench
    {827.001f,-474.415f,25.372f,1.57952f}, // Bench
    {819.264f,-461.961f,22.7614f,1.57952f}, // Bench
    
    {1162.91f,-734.578f,48.8948f,-2.9845f}, // Bonfire
    {1282.34f,-799.762f,87.1357f,-3.13286f}, // Bonfire
    {1358.06f,-732.178f,87.1606f,-3.13284f}, // Bonfire
    {1281.76f,-732.844f,87.1574f,-3.13246f}, // Bonfire
    {1358.81f,-797.899f,87.2953f,3.13312f}, // Bonfire
    {1162.21f,-790.543f,48.9162f,2.27765f}, // Bonfire
    
    {1262.21f,-751.358f,48.8133f,2.26893f}, // Brazier
    {1262.58f,-781.861f,48.8132f,2.04203f}, // Brazier
    {223.818f,-839.352f,60.7917f,1.09083f}, // Brazier
    {224.277f,-822.77f,60.7917f,2.06822f}, // Brazier

    {632.876f,-282.461f,5.45364f,-0.851094f}, // Chair
    {635.796f,-276.295f,5.48659f,-3.03273f}, // Chair
    {762.245f,-444.795f,22.8526f,-1.98095f}, // Chair
    {632.156f,-304.503f,5.4879f,1.15603f}, // Chair
    {643.86f,-270.204f,5.48898f,2.36903f}, // Chair
    {902.234f,-455.508f,18.3935f,-1.00356f}, // Chair
    {810.237f,-461.2f,25.4627f,1.5708f}, // Chair
    {1117.19f,-365.674f,18.8456f,0.968657f}, // Chair
    {1066.19f,-337.214f,18.8225f,0.453785f}, // Chair
    {798.324f,-444.951f,22.5601f,-1.02102f}, // Chair
    {1081.81f,-358.637f,18.5531f,1.92859f}, // Chair
    {814.931f,-470.816f,33.6373f,-3.12412f}, // Chair

    {726.385f,-360.205f,17.8153f,-1.62316f}, // Docks Banner

    {401.024f,-780.724f,49.9482f,-2.52896f}, // Doodad_HU_Portcullis01
    {399.802f,-885.208f,50.1939f,2.516f}, // Doodad_HU_Portcullis01

    {413.479f,-833.95f,48.5238f,3.14159f}, // Doodad_ND_Human_Gate_ClosedFX_Door01

    {-832.595f,51.4109f,-0.0261791f, 0.0f}, // Doodad_PortcullisActive01

    {273.033f,-832.199f,51.4109f,-0.0261791f}, // Doodad_PortcullisActive02

    {1156.89f,-843.998f,48.6322f,0.732934f}, // Doodad_VR_Portcullis01
    {1157.05f,-682.36f,48.6322f,-0.829132f}, // Doodad_VR_Portcullis01

    {-400.809f,37.6253f,-1.76278f}, // Flagpole
    {1284.76f,-705.668f,48.9163f,-3.08918f}, // Flagpole
    {299.153f,-784.589f,48.9162f,-0.157079f}, // Flagpole
    {726.385f,-360.205f,17.8153f,-1.6057f}, // Flagpole
    {807.78f,-1000.07f,132.381f,-1.91986f}, // Flagpole
    {776.229f,-804.283f,6.45052f,1.6057f}, // Flagpole
    {251.016f,-1159.32f,17.2376f,-2.25147f}, // Flagpole

    // {374.14f,-820.467f,48.9162f,-0.899281f}, // Great Feast
    /*
    {839.242f,-1188.83f,278.93f,3.91978f}, // Gunship Portal
    {663.394f,-1252.59f,288.892f,3.18979f}, // Gunship Portal
    {1125.53f,-598.052f,201.667f,1.97711f}, // Gunship Portal
    {1472.64f,-786.956f,191.414f,6.15762f}, // Gunship Portal
    {1458.37f,-730.522f,190.091f,0.398611f}, // Gunship Portal
    */

    {807.78f,-1000.07f,132.381f,-1.93732f}, // Hangar Banner
    {1284.76f,-705.668f,48.9163f,-3.08918f}, // Horde Banner

    {1150.9f,-762.606f,47.5077f,3.14159f}, // Horde Gate
    {1218.74f,-851.155f,48.2533f,-1.5708f}, // Horde Gate
    {1217.9f,-676.948f,47.6341f,1.5708f}, // Horde Gate

    // This is spawned when the hangar is captured
    /*
    {827.922f,-993.325f,134.197f,3.14159f}, // Horde Gunship Portal
    
    {663.373f,-1252.56f,288.891f,3.18979f}, // Horde Gunship Portal Effects
    {666.134f,-1262.39f,289.365f,3.24939f},  // Horde Gunship Portal Effects
    {739.014f,-1106.66f,134.755f,3.14159f}, // Horde Gunship Portal Effects
    {672.087f,-1156.79f,133.706f,3.14159f}, // Horde Gunship Portal Effects
    {827.924f,-993.299f,134.2f,3.14159f}, // Horde Gunship Portal Effects
    {673.861f,-1286.67f,290.061f,3.32091f}, // Horde Gunship Portal Effects
    {668.571f,-1270.32f,289.659f,3.28327f}, // Horde Gunship Portal Effects
    {684.257f,-1363.85f,289.922f,2.90662f}, // Horde Gunship Portal Effects
    */

    {1283.05f,-765.878f,50.8297f,-3.13286f}, // Horde Keep Portcullis

    {251.016f,-1159.32f,17.2376f,-2.25147f}, // Quarry Banner

    {785.509f,-864.715f,13.3993f,2.47837f}, // Seaforium Bombs
    {750.601f,-864.597f,13.4754f,1.93731f}, // Seaforium Bombs

    {903.291f,-457.345f,18.1356f,2.23402f}, // Stove
    {761.462f,-446.684f,22.5602f,0.244344f}, // Stove
    {1068.13f,-336.373f,18.5647f,-2.59181f}, // Stove
    {1118.32f,-363.969f,18.5532f,-3.08918f}, // Stove

    {1143.25f,-779.599f,48.629f,1.64061f}, // Teleporter
    {1236.53f,-669.415f,48.2729f,0.104719f}, // Teleporter
    {1233.27f,-844.526f,48.8824f,-0.0174525f}, // Teleporter
    {311.92f,-913.972f,48.8159f,3.08918f}, // Teleporter
    {1235.53f,-683.872f,49.304f,-3.08918f}, // Teleporter
    {397.089f,-859.382f,48.8993f,1.64061f}, // Teleporter
    {324.635f,-749.128f,49.3602f,0.0174525f}, // Teleporter
    {425.675f,-857.09f,48.5104f,-1.6057f}, // Teleporter
    {323.54f,-888.361f,48.9197f,0.0349063f}, // Teleporter
    {326.285f,-777.366f,49.0208f,3.12412f}, // Teleporter
    {1235.09f,-857.898f,48.9163f,3.07177f}, // Teleporter
    {1158.76f,-746.182f,48.6277f,-1.51844f}, // Teleporter

    {425.686f,-857.092f,48.51f,-1.62316f}, // Teleporter Effects (Alliance)
    {324.634f,-749.148f,49.359f,0.0174525f}, // Teleporter Effects (Alliance)
    {311.911f,-913.986f,48.8157f,3.08918f}, // Teleporter Effects (Alliance)
    {326.266f,-777.347f,49.0215f,3.12412f}, // Teleporter Effects (Alliance)
    {323.55f,-888.347f,48.9198f,0.0174525f}, // Teleporter Effects (Alliance)
    {397.116f,-859.378f,48.8989f,1.64061f}, // Teleporter Effects (Alliance)

    {1143.25f,-779.623f,48.6291f,1.62316f}, // Teleporter Effects (Horde)
    {1158.64f,-746.148f,48.6277f,-1.50098f}, // Teleporter Effects (Horde)
    {1233.25f,-844.573f,48.8836f,0.0174525f}, // Teleporter Effects (Horde)
    {1235.07f,-857.957f,48.9163f,3.05433f}, // Teleporter Effects (Horde)
    {1236.46f,-669.344f,48.2684f,0.087266f}, // Teleporter Effects (Horde)
    {1235.6f,-683.806f,49.3028f,-3.07177f}, // Teleporter Effects (Horde)

    {776.229f,-804.283f,6.45052f,1.6057f}, // Workshop Banner

    {1269.5f,-400.809f,37.6253f,-1.76278f}, // Refinery Banner

    {1150.9f,-762.606f,47.0f,3.14159f} // Doodad_ND_WinterOrc_Wall_GateFX_Door01 -> this was not sniffed because I only had alliance sniffs
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

        void FillInitialWorldStates(WorldPacket& data);
    private:
        uint32 closeFortressDoors;
        bool doorsClosed;
};
#endif
