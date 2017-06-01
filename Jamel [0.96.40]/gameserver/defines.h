#include <stdio.h>
void LoadIni();

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

#define GS_MAX_ON (0x005133E8)								//////////Max Users/////////

#define GS_LVL_UP_MG (0x00462AF7)							/////////////////////////////
#define GS_LVL_UP_NORMAL (0x00462B0E)						////////Level UP POINTS//////
															/////////////////////////////
//Game Configs
#define GS_RING1 (0x00458C98+3)								//////////////////////////
#define GS_RING2 (0x00458CA1+3)								//////////////////////////
#define GS_RING3 (0x00458CAA+3)								//Aneis de Transformação//
#define GS_RING4 (0x00458CB3+3)								//Aneis de Transformação//
#define GS_RING5 (0x00458CBC+3)								//////////////////////////
#define GS_RING6 (0x00458CC5+3)								//////////////////////////
																
#define BC_DROP  (0x0049B1F8+1)								///////////////////////////////
#define BC_GROUP (0x0049B1FA+1)								//Configurações do Drop da BC//
															///////////////////////////////

#define GS_ORB1 (0x00457E3F+1)								////////////////////////////
#define GS_ORB2 (0x00457E70+1)								////////////////////////////
#define GS_ORB3 (0x00457EA1+1)								////////////////////////////
#define GS_ORB4 (0x00457ED2+1)								//Orbs of Summons das Elfs//
#define GS_ORB5 (0x00457F03+1)								////////////////////////////
#define GS_ORB6 (0x00457F34+1)								////////////////////////////
#define GS_ORB7 (0x00457F65+1)								////////////////////////////

#define GS_CHAOS_MIX_10 (0x0044926D)						/////////////////////////////
#define GS_CHAOS_MIX_11 (0x0044927C)						/////////Items+10+11/////////
#define GS_CHAOS_WINMIN (0x0044A27A)						/////////Asas Min-Max////////
#define GS_CHAOS_WINMAX (0x0044A286)						/////////////////////////////

//Sucesso das Joias
#define GS_SOULNOLUCK (0x0047A069+3)						//Rate da soul Sem Luck
#define GS_SOULLUCK (0x00479F8A+3)							//Rate da soul com luck
#define GS_LIFERATE (0x0047A678+3)							//Rate da Life

/*///////////////////Aqui serão definidas as configurações dos GOLDEN MOBS,/////////////
/Serão definidos, O Mob, o Level Dos Items que vão Dropar do Mesmo, o Grupo/////////////
/////////////////////////////e o ID e tambem os Mapas aonde Eles Nasceram/////////////*/
//Golden Mobs Config

#define GOLDMOB1       (0x004097FC+2)						//Golden Budge Dragon
#define GB1ITEMLEVEL   (0x00409826+3)						//Level do Item que vai Dropar
#define GB1ITEMGROUP   (0x0040982D+1)						//Grupo do Item que vai dropar
#define GB1ITEMNUMBER  (0x0040982F+1)						//Numero do Item que vai dropar

#define GOLDMOB2       (0x00409972+2)						//Golden Goblin
#define GB2ITEMLEVEL   (0x004099AB+3)						//Level do Item que vai Dropar
#define GB2ITEMGROUP   (0x004099B2+1)						//Grupo do Item que vai dropar
#define GB2ITEMNUMBER  (0x004099B4+1)						//Numero do Item que vai dropar

#define GOLDMOB3       (0x0040989E+2)						//Golden Lizard King
#define GB3ITEMLEVEL   (0x004098C8+3)						//Level do Item que vai Dropar
#define GB3ITEMGROUP   (0x004098CF+1)						//Grupo do Item que vai dropar
#define GB3ITEMNUMBER  (0x004098D1+1)						//Numero do Item que vai dropar

#define GOLDMOB4       (0x00409A14+2)						//Golden Dragon
#define GB4ITEMLEVEL   (0x00409A4D+3)						//Level do Item que vai Dropar
#define GB4ITEMGROUP   (0x00409A54+1)						//Grupo do Item que vai dropar
#define GB4ITEMNUMBER  (0x00409A56+1)						//Numero do Item que vai dropar

#define GOLDMOB5       (0x00409AB6+2)						//Golden Dercon
#define GB5ITEMLEVEL   (0x00409AEF+3)						//Level do Item que vai Dropar
#define GB5ITEMGROUP   (0x00409AF6+1)						//Grupo do Item que vai dropar
#define GB5ITEMNUMBER  (0x00409AF8+1)						//Numero do Item que vai dropar

#define GOLDMOB6	   (0x00409B58+2)						//Golden Tabtalos
#define GB6ITEMLEVEL   (0x00409B91+3)						//Level do Item que vai Dropar
#define GB6ITEMGROUP   (0x00409B98+1)						//Grupo do Item que vai dropar
#define GB6ITEMNUMBER  (0x00409B9A+1)						//Numero do Item que vai dropar

#define gObjNick 0x6A


#define LogAdd ((void(*) (BYTE,char*,...))0x00403C01)

bool GoIni();

