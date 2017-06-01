//===========================================================
// Development : MLM Team
// Coded : By Motto & MLM Team
// Versão : 0.97.04
// Arquivo : Arquivo das Customs e Funções
//===========================================================

#include <stdio.h>

void LoadMess();
//==================================================================================
//Preço das Jóias
//Essas funções farão com que o preço das Jóias
//sejam mudados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_CHAOS_PRICE	(0x00480053+3)
#define GS_SOUL_PRICE	(0x00480038+3)
#define GS_BLESS_PRICE	(0x0048001E+3)
#define GS_LIFE_PRICE	(0x0048006E+3)
#define GS_CREATION_PRICE	(0x00480088+3)
#define GS_FATHER_PRICE (0x004800BE+3)
#define GS_FRUIT_PRICE (0x004800A3+3)
#define GS_DINO_PRICE (0x004800D8+3)

//GameServer Config
#define GS_MAX_LEVEL1 (0x00459BA2+3)						////////////////////////
#define GS_MAX_LEVEL2 (0x00462A33+2)						//Max Level GameServer//
#define GS_MAX_LEVEL3 (0x00496D93+1)						////////////////////////

#define UDP_Port (0x0048A098+1)								//Trocar Udp Port do GS

#define GS_MS1 (0x00458794+3)								///////////////////////
#define GS_MS2 (0x00458779+1)								///////////////////////
#define GS_MS3 (0x0045878D+1)								///Mana Shield do GS///
#define GS_MS4 (0x004587B3+2)								///////////////////////
#define GS_MS5 (0x004587AC+1)								///////////////////////

//==================================================================================
//MaxUsers
//Essa função define quantos usuários ficaram online e
//sejam alterados conforme as configurações que forem feitas no arquivo MLMFuncoes.ini
//==================================================================================
#define GS_MAX_ON (0x005133E7+1)

//==================================================================================
//LevelUpPoints
//Essa função fará com que os pontos ganhos por cada classe
//sejam alterados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_LVL_UP_MG (0x00462AF5+2)
#define GS_LVL_UP_NORMAL (0x00462B0C+2)

//==================================================================================
//Anéis de Transformação
//Essas funções farão com que os monstros dos Anéis de Transformação
//sejam mudados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_RING1 (0x00458C98+3)
#define GS_RING2 (0x00458CA1+3)
#define GS_RING3 (0x00458CAA+3)
#define GS_RING4 (0x00458CB3+3)
#define GS_RING5 (0x00458CBC+3)
#define GS_RING6 (0x00458CC5+3)

//==================================================================================
//Prêmio do BC
//Essa função fará com que o Prêmio do Arcanjo do BC
//sejam mudados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define BC_DROP  (0x0049B1F8+1)
#define BC_GROUP (0x0049B1FA+1)

//==================================================================================
//Orbs of Summons
//Essa função fará com que a Orbs das elfs mudem.
//sejam mudados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_ORB0 (0x00457E3F+1)
#define GS_ORB1 (0x00457E70+1)
#define GS_ORB2 (0x00457EA1+1)
#define GS_ORB3 (0x00457ED2+1)
#define GS_ORB4 (0x00457F03+1)
#define GS_ORB5 (0x00457F34+1)
#define GS_ORB6 (0x00457F65+1)

//================================================================================
//ChaosMachine MixRate
//Essa função fará com que a % de acerto na chaos machine
//seja mudada conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//================================================================================
#define GS_CHAOS_MIX_10 (0x0044926D)
#define GS_CHAOS_MIX_11 (0x0044927C)
#define GS_CHAOS_WINMIN (0x0044A27A)
#define GS_CHAOS_WINMAX (0x0044A286)

//=================================================================================
//Sucess Rate
//Essa função fará com que o sucesso da jóia determinada
//seja mudada conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//=================================================================================
#define GS_SOULNOLUCK (0x0047A069+3)
#define GS_SOULLUCK (0x00479F8A+3)
#define GS_LIFERATE (0x0047A678+3)

//==================================================================================
//MaxZen Bau
//Essa função fará com que o limite de zen no bau
//sejam mudados conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define MAX_ZEN_BAU1 (0x00422DA1+3)
#define MAX_ZEN_BAU2 (0x00422E97+3)
#define MAX_ZEN_BAU3 (0x00422DCD+2)

//==================================================================================
//NON-PK
//Essa função fará com que o server seja Non-PVP e
//será mudado conforme as configurações que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_NON_PK1 (0x0048C586+1)
#define GS_NON_PK2 (0x0048C783+1)
#define GS_NON_PK3 (0x0048C980+1)
#define GS_NON_PK4 (0x0048CA98+1)

//==================================================================================
//MaxZenInventory
//Essa função fará com que o limite de zen no inventário
//seja mudado conforma eas configuraçoes que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define MAX_ZEN_INV (0x0041E40C+3)

//==================================================================================
//SetPriceZen
//------
//seja mudado conforma eas configuraçoes que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_SET_ZEN (0x0048150C+1)

//==================================================================================
//DefenceSucessRate
//------
//seja mudado conforma eas configuraçoes que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_DEF_RATE (0x004814CC+1)

//==================================================================================
//ExcellentAttackRate
//------
//seja mudado conforma eas configuraçoes que forem feitas no arquivo MLMCustoms.ini
//==================================================================================
#define GS_EXC_ATK_RATE (0x0048156D+1)

#define LogAdd ((void(*)(BYTE,char*,...))
bool MLMini();