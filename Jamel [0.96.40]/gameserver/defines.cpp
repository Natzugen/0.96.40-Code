#include "gameserver.h"
#include "StdAfx.h"
#include "global.h"
#include "defines.h"
#include <string.h>

char XtcTeamIni[] = ".\\gameserver.ini";
void LoadIni()
{
	SMDfile = fopen(XtcTeamIni,"rb");
	if (SMDfile!=0)
	{
		fclose(SMDfile);
		GetPrivateProfileString("Configs","ConnectNotice","Sejam Bem Vindos", ConnectNotice,50,XtcTeamIni);
	}
	else
	{
		char msg[400];
		sprintf(msg,"%s não encontrado. O GameServer não pode ser iniciado.",XtcTeamIni);
		MessageBox(NULL,msg,"gameserver.dll",NULL);
		::ExitProcess(0);
	}
}

//GameServer Config
bool UDPORT (char*ini)
{
DWORD Port;
Port = GetPrivateProfileInt("Configs","UdpPort",60006,ini);
*(unsigned int*) UDP_Port = Port;
return 1;
}

bool MaxUsers (char*ini)
{
DWORD MaxUsers;
MaxUsers = GetPrivateProfileInt("Configs","MaxPlayers",20,ini);
*(unsigned int*) GS_MAX_ON = MaxUsers;
return 1;
}

bool LvlPoints (char*ini)
{
BYTE LvlPoints;
LvlPoints = GetPrivateProfileInt("Configs","ElfDkDwUpPoints",5,ini);
*(unsigned char*) GS_LVL_UP_NORMAL = LvlPoints;

LvlPoints = GetPrivateProfileInt("Configs","MgUpPoints",7,ini);
*(unsigned char*) GS_LVL_UP_MG = LvlPoints;
return 1;
}

bool MaxLevel (char*ini)
{
DWORD MaxLevel;
MaxLevel = GetPrivateProfileInt("Configs","MaxLevel",1000,ini);
*(unsigned int*) GS_MAX_LEVEL1 = MaxLevel;
*(unsigned int*) GS_MAX_LEVEL2 = MaxLevel;
*(unsigned int*) GS_MAX_LEVEL3 = MaxLevel;
return 1;
}

bool ManaShield (char*ini)
{
BYTE Shield;
Shield = GetPrivateProfileInt("Configs","ManaShieldAbsorbStart",10,ini);
*(unsigned char*) GS_MS1 = Shield;

Shield = GetPrivateProfileInt("Configs","ManaShieldStatPerAgility",80,ini);
*(unsigned char*) GS_MS2 = Shield;

Shield = GetPrivateProfileInt("Configs","ManaShieldStatsPerEnergy",200,ini);
*(unsigned char*) GS_MS3 = Shield;

Shield = GetPrivateProfileInt("Configs","ManaShieldDurabilityStart",60,ini);
*(unsigned char*) GS_MS4 = Shield;

Shield = GetPrivateProfileInt("Configs","ManaShieldDurabilityPerEnergy",40,ini);
*(unsigned char*) GS_MS5 = Shield;
return 1;
}

//Game Configs
bool TransformRing (char*ini)
{
DWORD Ring;
Ring = GetPrivateProfileInt("Configs","TransformRing1",2,ini);
*(unsigned int*) GS_RING1 = Ring;

Ring = GetPrivateProfileInt("Configs","TransformRing2",7,ini);
*(unsigned int*) GS_RING2 = Ring;

Ring = GetPrivateProfileInt("Configs","TransformRing3",14,ini);
*(unsigned int*) GS_RING3 = Ring;

Ring = GetPrivateProfileInt("Configs","TransformRing4",8,ini);
*(unsigned int*) GS_RING4 = Ring;

Ring = GetPrivateProfileInt("Configs","TransformRing5",9,ini);
*(unsigned int*) GS_RING5 = Ring;

Ring = GetPrivateProfileInt("Configs","TransformRing6",41,ini);
*(unsigned int*) GS_RING6 = Ring;
return 1;
}

bool ChaosMix (char*ini)
{
BYTE ChaosMix;
ChaosMix = GetPrivateProfileInt("Configs","Mix10Items",100,ini);
*(unsigned char*) GS_CHAOS_MIX_10 = ChaosMix;

ChaosMix = GetPrivateProfileInt("Configs","Mix11Items",100,ini);
*(unsigned char*) GS_CHAOS_MIX_11 = ChaosMix;

ChaosMix = GetPrivateProfileInt("Configs","WingMixMin",1,ini);
*(unsigned char*) GS_CHAOS_WINMIN = ChaosMix;

ChaosMix = GetPrivateProfileInt("Configs","WingMixMax",100,ini);
*(unsigned char*) GS_CHAOS_WINMAX = ChaosMix;
return 1;
}

bool OrbsSummon (char*ini)
{
BYTE Orb;
Orb = GetPrivateProfileInt("Configs","OrbSummon1",26,ini);
*(unsigned char*) GS_ORB1 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon2",32,ini);
*(unsigned char*) GS_ORB2 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon3",21,ini);
*(unsigned char*) GS_ORB3 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon4",20,ini);
*(unsigned char*) GS_ORB4 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon5",10,ini);
*(unsigned char*) GS_ORB5 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon6",150,ini);
*(unsigned char*) GS_ORB6 = Orb;

Orb = GetPrivateProfileInt("Configs","OrbSummon7",151,ini);
*(unsigned char*) GS_ORB7 = Orb;
return 1;
}

bool BcDropIni (char*ini)
{
BYTE Bc;
Bc = GetPrivateProfileInt("Configs","BC_Drop_Item",15,ini);
*(unsigned char*) BC_DROP = Bc;

Bc = GetPrivateProfileInt("Configs","BC_Drop_Group",12,ini);
*(unsigned char*) BC_GROUP = Bc;
return 1;
}

bool JowelsSucessRate (char*ini)
{
BYTE Rate;
Rate = GetPrivateProfileInt("Configs","SoulSemLuckRate",0,ini);
*(unsigned char*) GS_SOULNOLUCK = Rate;

Rate = GetPrivateProfileInt("Configs","SoulComLuckRate",100,ini);
*(unsigned char*) GS_SOULLUCK = Rate;

Rate = GetPrivateProfileInt("Configs","LifeRate",100,ini);
*(unsigned char*) GS_LIFERATE = Rate;
return 1;
}

bool GoIni()
{
//char a[255];
char aini[] = ".\\gameserver.ini";
bool rResultado;
rResultado = UDPORT ( aini );
rResultado = MaxUsers ( aini );
rResultado = MaxLevel ( aini );
rResultado = LvlPoints ( aini );
rResultado = ManaShield ( aini );
rResultado = TransformRing ( aini );
rResultado = ChaosMix ( aini );
rResultado = OrbsSummon ( aini );
rResultado = BcDropIni ( aini );
rResultado = JowelsSucessRate ( aini );
return 1;
}
