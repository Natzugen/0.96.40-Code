#include "StdAfx.h"

#define OBJECT_BASE		0x4CEE778
#define OBJECT_SIZE		0x0D0C

#define OBJECT_START	4800
#define OBJECT_END		5800

#define OBJECT_POINTER(aIndex) ((aIndex * OBJECT_SIZE) + OBJECT_BASE)
#define OBJECT_TABINDEX(lpObj) ((lpObj - OBJECT_BASE) / OBJECT_SIZE)

#define ITEM_SIZE	0x0084	// Referencia em 0x00482630


#define DataRecv ((void(*)(BYTE, PBYTE, DWORD, DWORD, ...)) 0x00414180)
#define DataSend ((void(*)(DWORD aIndex, PBYTE Packet, DWORD Size)) 0x00440240)
#define LogAddFunc ((void(*)(unsigned char Color,char * Text, ...))0x00402400)
#define GCPkLevelSend ((void(*)(DWORD aIndex,BYTE PkLevel))0x00401D7F)
#define CMAPMoneyItemDrop ((void(*)(DWORD Money,DWORD x, DWORD y))0x00490560)
#define gObjDel ((short(*)(DWORD aIndex))0x00460640)
#define GCMoneySend ((void(*)(DWORD aIndex, DWORD Money))0x4185C0)
#define ItemSerialCreateSend ((int(*)(int aIndex, BYTE Map, BYTE PosX, BYTE PosY, int ItemID,\
	BYTE level, BYTE dur, BYTE Op1, BYTE Op2, BYTE Op3, int KillerIndex, BYTE Exc))0x004020C7)
#define gObjTeleport ((void(*)(int aIndex, int MapNumber, int X, int Y))0x0040181B)

#define gObjCloseSet ((void(*)(DWORD aIndex, DWORD flag))0x00401A28)
/*gObjCloseSet -> 0 -> Fecha o Main | 1 -> Vai para SelectChar | 2 -> Vai para ServerList */

void HookNewOBJECTSTRUCT();

void SetConnection(int aIndex);

void GCServerMsgStringSend(char *szMsg, int aIndex, BYTE type);

bool NpcTalkEx(int aIndex, int nIndex);

int GetSQL(unsigned char Type, int aIndex);
void SetSQL(unsigned char Type, int aIndex);

#pragma region Funções de NPCs

void NPCPkClear(int aIndex);
void NPCReset(int aIndex);

#pragma endregion


#pragma region Pesquisas
/*
0045C682  |. 69C9 68DB0400  IMUL ECX,ECX,4DB68			//-> MapC Size (0x4DB68)
0045C688  |. 81C1 784C3506  ADD ECX,GameServ.06354C78	//-> MapC Init (0x6354C78)


ItemSerialCreateSend:
int __cdecl sub_4121E0(int a1, char a2, char a3, char a4, int a5, unsigned __int8 a6, unsigned __int8 a7, char a8, char a9, char a10, __int16 a11, unsigned __int8 a12)

Inicia em 0x4121E0
Jump From 0x4020C7

ItemSerialCreateSend ((int(*)( 12 args ))0x004020C7)

unsigned int aIndex, unsigned char Map, unsigned char PosX, unsigned char PosY, unsigned int ItemID, char level, unsigned char dur, char Op1, char Op2, char Op3, unsigned int KillerIndex, char Exc

*/
#pragma endregion