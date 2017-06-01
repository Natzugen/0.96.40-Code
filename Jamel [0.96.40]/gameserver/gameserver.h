#include "StdAfx.h"

void LoadConfigs();

#include <stdio.h>
#include <windows.h>


#define GCMoneySend (aIndex,10000)
#define MoneySend ((void(*) (DWORD, int)) 0x004185C0)
#define GCServerMsgStringSend ((void(*)(char * Texto, DWORD PlayerID, int tipo)) 0x0040167C)//00416430
#define DataRecv ((void(*)(BYTE, PBYTE, DWORD, DWORD, ...)) 0x00414180)
#define DataSend ((void(*)(DWORD PlayerID, PBYTE Packet, DWORD Size)) 0x00440240)
#define LogAddFunc ((void(*)(char * Texto,int Tipo)) 0x0044C7E0)
#define CloseClient ((void(*)(DWORD))0x0040103C)
#define gObj_Write ((bool(*) (int)) 0x0040BAF4)
#define gObjIsConnected ((bool(*) (int)) 0x0040B390)
#define gObjConnected 0x4
#define AINDEX_MIN 2500
#define AINDEX_MAX 3500
#define gObjSize 0x0D0C
#define gObjOffset 0x4CEE778
#define gObjmIndex 0x0
#define gObjAccountId 0x64
#define gObjLogin 0x6F
#define gObjLvl 0x86
#define gObjZen 0x5F
#define gObjMoney 0xB4
#define gObj_isonline 0x4
#define gObjName 0x6A
/*Strength 0x98
Agility 0x9A
Vitality 0x9C
Energy 0x9E
LevelUpPoint 0x88*/