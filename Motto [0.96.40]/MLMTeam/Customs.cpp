//===========================================================
// Development : MLM Team
// Coded : By Motto & MLM Team
// Versão : 0.97.04
// Arquivo : Arquivo das Customs e Funções
//===========================================================

#include "Customs.h"
#include <string.h>
#include <windows.h>

//GameServer Config
bool UDPORT (char*ini)
{
DWORD Port;
Port = GetPrivateProfileInt("Inicio","UDP_Port",60006,ini);
*(unsigned int*) UDP_Port = Port;
return 1;
}

bool MaxUsers (char*ini)
{
DWORD MaxUsers;
MaxUsers = GetPrivateProfileInt("Inicio","MaxUsuarios",20,ini);
*(unsigned int*) GS_MAX_ON = MaxUsers;
return 1;
}

bool LvlPoints (char*ini)
{
BYTE LvlPoints;
LvlPoints = GetPrivateProfileInt("Inicio","UpPointsDkDwElf",5,ini);
*(unsigned char*) GS_LVL_UP_NORMAL = LvlPoints;

LvlPoints = GetPrivateProfileInt("Inicio","UpPointsMg",7,ini);
*(unsigned char*) GS_LVL_UP_MG = LvlPoints;
return 1;
}

bool MaxLevel (char*ini)
{
DWORD MaxLevel;
MaxLevel = GetPrivateProfileInt("Inicio","LevelMaximo",350,ini);
*(unsigned int*) GS_MAX_LEVEL1 = MaxLevel;
*(unsigned int*) GS_MAX_LEVEL2 = MaxLevel;
*(unsigned int*) GS_MAX_LEVEL3 = MaxLevel;
return 1;
}

bool ManaShield (char*ini)
{
BYTE Shield;
Shield = GetPrivateProfileInt("Inicio","ManaAbsorve",10,ini);
*(unsigned char*) GS_MS1 = Shield;

Shield = GetPrivateProfileInt("Inicio","ManaAgility",80,ini);
*(unsigned char*) GS_MS2 = Shield;

Shield = GetPrivateProfileInt("Inicio","ManaEnergy",200,ini);
*(unsigned char*) GS_MS3 = Shield;

Shield = GetPrivateProfileInt("Inicio","ManaDurability",60,ini);
*(unsigned char*) GS_MS4 = Shield;

Shield = GetPrivateProfileInt("Inicio","ManaDurabilityPerEnergy",40,ini);
*(unsigned char*) GS_MS5 = Shield;
return 1;
}
//========================
//Anéis de Transformação
//========================
bool TransformRing (char*ini)
{
DWORD Ring;
Ring = GetPrivateProfileInt("Inicio","TransformRing1",2,ini);
*(unsigned int*) GS_RING1 = Ring;

Ring = GetPrivateProfileInt("Inicio","TransformRing2",7,ini);
*(unsigned int*) GS_RING2 = Ring;

Ring = GetPrivateProfileInt("Inicio","TransformRing3",14,ini);
*(unsigned int*) GS_RING3 = Ring;

Ring = GetPrivateProfileInt("Inicio","TransformRing4",8,ini);
*(unsigned int*) GS_RING4 = Ring;

Ring = GetPrivateProfileInt("Inicio","TransformRing5",9,ini);
*(unsigned int*) GS_RING5 = Ring;

Ring = GetPrivateProfileInt("Inicio","TransformRing6",41,ini);
*(unsigned int*) GS_RING6 = Ring;
return 1;
}

bool ChaosMix (char*ini)
{
BYTE ChaosMix;
ChaosMix = GetPrivateProfileInt("Inicio","MixRate10",100,ini);
*(unsigned char*) GS_CHAOS_MIX_10 = ChaosMix;

ChaosMix = GetPrivateProfileInt("Inicio","MixRate11",100,ini);
*(unsigned char*) GS_CHAOS_MIX_11 = ChaosMix;

ChaosMix = GetPrivateProfileInt("Inicio","WingMixMin",1,ini);
*(unsigned char*) GS_CHAOS_WINMIN = ChaosMix;

ChaosMix = GetPrivateProfileInt("Inicio","WingMixMax",100,ini);
*(unsigned char*) GS_CHAOS_WINMAX = ChaosMix;
return 1;
}

bool OrbsSummon (char*ini)
{
BYTE Orb;
Orb = GetPrivateProfileInt("Inicio","OrbSummon0",26,ini);
*(unsigned char*) GS_ORB0 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon1",32,ini);
*(unsigned char*) GS_ORB1 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon2",21,ini);
*(unsigned char*) GS_ORB2 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon3",20,ini);
*(unsigned char*) GS_ORB3 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon4",10,ini);
*(unsigned char*) GS_ORB4 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon5",150,ini);
*(unsigned char*) GS_ORB5 = Orb;

Orb = GetPrivateProfileInt("Inicio","OrbSummon6",151,ini);
*(unsigned char*) GS_ORB6 = Orb;
return 1;
}
//============================================
//Prêmio BC
//============================================
bool BcDropIni (char*ini)
{
BYTE Bc;
Bc = GetPrivateProfileInt("Inicio","BcDropId",15,ini);
*(unsigned char*) BC_DROP = Bc;

Bc = GetPrivateProfileInt("Inicio","BcDropGroup",12,ini);
*(unsigned char*) BC_GROUP = Bc;
return 1;
}
//============================================
//SucessRate
//============================================
bool JowelsSucessRate (char*ini)
{
BYTE Rate;
Rate = GetPrivateProfileInt("Inicio","SoulRate",0,ini);
*(unsigned char*) GS_SOULNOLUCK = Rate;

Rate = GetPrivateProfileInt("Inicio","SoulLuckRate",100,ini);
*(unsigned char*) GS_SOULLUCK = Rate;

Rate = GetPrivateProfileInt("Inicio","LifeRate",100,ini);
*(unsigned char*) GS_LIFERATE = Rate;
return 1;
}
//============================================
//Preço das Jóias
//============================================
bool JewelPrices (char*ini)
{
DWORD JowelPrices;
JowelPrices = GetPrivateProfileInt("Inicio","ChaosPrice",810000,ini);
*(unsigned int*) GS_CHAOS_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","BlessPrice",9000000,ini);
*(unsigned int*) GS_BLESS_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","SoulPrice",6000000,ini);
*(unsigned int*) GS_SOUL_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","LifePrice",45000000,ini);
*(unsigned int*) GS_LIFE_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","CreationPrice",36000000,ini);
*(unsigned int*) GS_CREATION_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","DinorantPrice",960000,ini);
*(unsigned int*) GS_DINO_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","FruitPrice",33000000,ini);
*(unsigned int*) GS_FRUIT_PRICE = JowelPrices;

JowelPrices = GetPrivateProfileInt("Inicio","FatherPrice",180000,ini);
*(unsigned int*) GS_FATHER_PRICE = JowelPrices;
return 1;
}
//============================================
//MaxZen Bau
//============================================
bool MaxZen (char*ini)
{
	DWORD MaxZ;
	MaxZ = GetPrivateProfileInt("Inicio","MaxZenVault",100000000,ini);
	*(unsigned int*) MAX_ZEN_BAU1 = MaxZ;
	*(unsigned int*) MAX_ZEN_BAU2 = MaxZ;
	*(unsigned int*) MAX_ZEN_BAU3 = MaxZ;
	return 1;
}
//============================================
//MaxZen Inventory
//============================================
bool MaxInv (char*ini)
{
	DWORD MaxI;
	MaxI = GetPrivateProfileInt("Inicio","MaxZenInventory",100000000,ini);
	*(unsigned int*) MAX_ZEN_INV = MaxI;
	return 1;
}
//============================================
//NON-PK
//============================================
bool Non_PK (char*ini)
{
	BYTE PK;
	PK = GetPrivateProfileInt("GameServerInfo","NonPK",1,ini);
	*(unsigned char*) GS_NON_PK1 = PK;
	*(unsigned char*) GS_NON_PK2 = PK;
	*(unsigned char*) GS_NON_PK3 = PK;
	*(unsigned char*) GS_NON_PK4 = PK;
	return 1;
}
//============================================
//SetPriceZen
//============================================
bool SetZen (char*ini)
{
	BYTE SPzen;
	SPzen = GetPrivateProfileInt("Inicio","ItemPriceZen",40,ini);
	*(unsigned int*) GS_SET_ZEN = SPzen;
	return 1;
}
//============================================
//DefenceSucessRate
//============================================
bool DefRate (char*ini)
{
	BYTE DSRate;
	DSRate = GetPrivateProfileInt("Inicio","DefSucessRate",10,ini);
	*(unsigned int*) GS_DEF_RATE = DSRate;
	return 1;
}
//============================================
//ExcellentAttackRate
//============================================
bool ExRate (char*ini)
{
	BYTE AtRate;
	AtRate = GetPrivateProfileInt("Inicio","ExcAttackRate",10,ini);
	*(unsigned int*) GS_EXC_ATK_RATE = AtRate;
	return 1;
}
bool MLMini()
{
	//char a[255];
	char aini[] = "..\\MLMData\\MLMCustoms.ini" ;
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
rResultado = JewelPrices ( aini );
rResultado = MaxZen ( aini );
rResultado = MaxInv ( aini );
rResultado = Non_PK ( aini );
rResultado = SetZen ( aini );
rResultado = DefRate ( aini );
rResultado = ExRate ( aini );
	return 1;
	MessageBoxA(NULL,"Customs.das","Carrgada",MB_OK);
}