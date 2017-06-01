#include "StdAfx.h"

void SystemResets(int aIndex);
void SetConnection(int aIndex);

#define gObjSize		0x0D0C
#define gObjOffset		0x4CEE778
#define gObjConnected	0x4

#define gObjStart	4800
#define gObjEnd		5800

#define DataRecv ((void(*)(BYTE, PBYTE, DWORD, DWORD, ...)) 0x00414180)
#define DataSend ((void(*)(DWORD aIndex, PBYTE Packet, DWORD Size)) 0x00440240)
#define LogAddFunc ((void(*)(unsigned char Color,char * Text, ...))0x00402400)
#define gObjIsConnected ((bool(*) (int)) 0x0040B390)
#define gObjTeleport ((void(*) (int, int, int, int, int))0x0040181B)
#define CloseClient ((void(*)(DWORD))0x0040103C)
#define gObjViewportListProtocolCreate		((void(*)(OBJECTSTRUCT*))0x00474E40)
#define gObjSize 0x0D0C
#define gObjOffset 0x4CEE778
#define gObjLupp			0x88
#define gObjmIndex			0x0
#define gObjExp				0x8C
#define gObjExpM			0x90