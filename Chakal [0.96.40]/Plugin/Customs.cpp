#include "StdAfx.h"
#include "Include.h"
static char NpcSay[500];

void GS_FUNCTIONS::GameCustoms(){
	DWORD dwTmp ; BYTE cTemp ;
	DWORD *offset = (DWORD*)(0x00509058);
	GetPrivateProfileString(GAMESERVER,"Fala do npc guarda","Seja Bem Vindo.",NpcSay,50,CFG_GAMESERVER);
	memset(&offset[0],0,50);
	memcpy(&offset[0],NpcSay,strlen(NpcSay));

	// -- Server Infos
	dwTmp = GetPrivateProfileIntA(GAMESERVER, "Porta UDP",60006,CFG_GAMESERVER);
	*(unsigned int *) UDP_Port  = dwTmp ;

	dwTmp = GetPrivateProfileInt(GAMESERVER,"Level maximo",1000,CFG_GAMESERVER);
    *(unsigned int*) GS_MAX_LEVEL1 = dwTmp;
    *(unsigned int*) GS_MAX_LEVEL2 = dwTmp;
    *(unsigned int*) GS_MAX_LEVEL3 = dwTmp;

	cTemp = GetPrivateProfileInt(GAMESERVER,"GameServer 0 pvp / 1 não pvp",0,CFG_GAMESERVER);
	*(unsigned char*) GS_NON_PVP1 = cTemp;
	*(unsigned char*) GS_NON_PVP2 = cTemp;
	*(unsigned char*) GS_NON_PVP3 = cTemp;
	*(unsigned char*) GS_NON_PVP4 = cTemp;

	dwTmp = GetPrivateProfileInt(GAMESERVER,"Numero maximo de jogadores",200,CFG_GAMESERVER);
    *(unsigned int*) GS_MAX_ONLINE = dwTmp;

	dwTmp = GetPrivateProfileInt(GAMESERVER, "Drop rate de items excelentes",60006,CFG_GAMESERVER);
	*(unsigned int*) GS_EXE_DROP_RATE  = dwTmp;

	float ZenDivider = GetPrivateProfileIntA(GAMESERVER,"ZenDivider",100.0,CFG_GAMESERVER);
	*(float*)(0x005090A0) = ZenDivider;

	cTemp = GetPrivateProfileInt(GAMESERVER,"Pontos por level normal",5,CFG_GAMESERVER);
	*(unsigned char*) GS_LVL_UP_NORMAL = cTemp;

	cTemp = GetPrivateProfileInt(GAMESERVER,"Pontos por level magic gladiador",7,CFG_GAMESERVER);
	*(unsigned char*) GS_LVL_UP_MG = cTemp;
	// -- Joias Rate
	cTemp = GetPrivateProfileInt(JOIASRATE,"Chance de Sucesso da jewel of souls em items sem luck",75,CFG_GAMESERVER);
	*(unsigned char*)GS_SOUL_RATE = cTemp;
	cTemp = GetPrivateProfileInt(JOIASRATE,"Chance de Sucesso da jewel of souls em items com luck",100,CFG_GAMESERVER);
	*(unsigned char*)GS_SOUL_LUCK_RATE = cTemp;
	cTemp = GetPrivateProfileInt(JOIASRATE,"Chance de Sucesso da jewel of life em items",75,CFG_GAMESERVER);
	*(unsigned char*)GS_LIFE_RATE = cTemp;
	// -- Chaos Machine Mixes
	cTemp = GetPrivateProfileInt(CHAOSRATE,"Chance de sucesso ao upar item para +10",100,CFG_GAMESERVER);
	*(unsigned char*)GS_CHAOS_MIX_10 = cTemp;
	cTemp = GetPrivateProfileInt(CHAOSRATE,"Chance de sucesso ao upar item para +11",100,CFG_GAMESERVER);
	*(unsigned char*)GS_CHAOS_MIX_11 = cTemp;
	cTemp = GetPrivateProfileInt(CHAOSRATE,"Chance de sucesso minimo ao criar asa",1,CFG_GAMESERVER);
	*(unsigned char*)GS_CHAOS_WINMIN = cTemp;
	cTemp = GetPrivateProfileInt(CHAOSRATE,"Chance de sucesso maximo ao Criar asa",100,CFG_GAMESERVER);
	*(unsigned char*)GS_CHAOS_WINMAX = cTemp;
	// --> Preço das Jóias
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of bless",9000000,CFG_GAMESERVER);
	*(unsigned int *) GS_BLESS_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of soul",6000000,CFG_GAMESERVER);
	*(unsigned int *) GS_SOUL_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of chaos",810000,CFG_GAMESERVER);
	*(unsigned int *) GS_CHAOS_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of life",45000000,CFG_GAMESERVER);
	*(unsigned int *) GS_LIFE_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of creation",36000000,CFG_GAMESERVER);
	*(unsigned int *) GS_CREATION_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of dinorant",960000,CFG_GAMESERVER);
	*(unsigned int *) GS_DINO_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of fruit",33000000,CFG_GAMESERVER);
	*(unsigned int *) GS_FRUIT_PRICE  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(JOIASPREÇOS, "Preço da jewel of father",180000,CFG_GAMESERVER);
	*(unsigned int *) GS_FATHER_PRICE  = dwTmp ;
	// -- Anéis de Transformação
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Budge Dragon >",2,CFG_GAMESERVER);
	*(unsigned int *) GS_RING1  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Giant >",7,CFG_GAMESERVER);
	*(unsigned int *) GS_RING2  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Skeleton Warrior >",14,CFG_GAMESERVER);
	*(unsigned int *) GS_RING3  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Poison Bull >",8,CFG_GAMESERVER);
	*(unsigned int *) GS_RING4  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Thunder Lich >",9,CFG_GAMESERVER);
	*(unsigned int *) GS_RING5  = dwTmp ;
	dwTmp = GetPrivateProfileIntA(RINGSTRANSFORM, "Monstro do anel de transformação < Death Cow >",41,CFG_GAMESERVER);
	*(unsigned int *) GS_RING6  = dwTmp ;
	// -- Orbs Summon Elf
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf invocação orb < Goblin >",26,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB1 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf invocação orb < Stone Golem >",32,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB2 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf invocação orb < Assassin >",21,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB3 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf invocação orb < Elite Yeti >",20,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB4 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf invocação orb < Dark Knight >",10,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB5 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf Invocação orb < Bali >",150,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB6 = cTemp;
	cTemp = GetPrivateProfileInt(ORBSSUMMONELF,"Elf Invocação orb < Soldier >",151,CFG_GAMESERVER);
	*(unsigned char*)GS_ORB7 = cTemp;
}