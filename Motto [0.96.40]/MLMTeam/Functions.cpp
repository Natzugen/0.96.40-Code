
#include "Functions.h"
#include "StdAfx.h"
#include "User.h"
#include "GameServer.h"
#include "SQL.h"
#include "Struct.h"

SQL * MSSQL = new SQL;


void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset){
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset -(dwJmpOffset+5);
}

int gObjGetInt(DWORD aIndex, int Type)
{
	DWORD gObj = (aIndex * gObjSize + gObjOffset);
	return *LPWORD(gObj+Type);
}

void ServerMsgSend(DWORD wId, int Type, char Sender[20], const char* Message, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments, Message);
	vsprintf(szBuffer, Message, pArguments);
	va_end(pArguments);
	BYTE*Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	if (Type)*(Packet+2) = 0x02;
	else *(Packet+2) = 0x00;
	memcpy((Packet+3), Sender, strlen(Sender));
	memcpy((Packet+13), szBuffer, strlen(szBuffer));
	int Len = (strlen(szBuffer) + 0x13);
	*(Packet+1) = Len;
	for(int i = gObjStart; i < gObjEnd; i++)
		if (gObjGetInt(i,gObjConnected) == 3)
			DataSend(i,Packet,Len);
	free(Packet);
}

void SystemResets(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	unsigned char z = MSSQL->GetFieldInt("MuOnline.dbo.Character","resets","WHERE AccountID = '%s'",gObj->AccountID);
	char Connect[137]; // 128 + gObj->Name - %s
	if(z > configs.c_SisIni.ResetsA)
	{
		false;
	}
	else if(z < configs.c_SisIni.ResetsA)
	{
		CloseClient(aIndex);
	}
}

void SetConnection(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	unsigned char x = MSSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",gObj->AccountID);
	char Connect[137]; // 128 + gObj->Name - %s
	sprintf_s(Connect,configs.c_Notice1.ConnectNotice2,gObj->Name);
	GCServerMsgStringSend(Connect,aIndex,0);
	if(x = 0)
	{
		return;
	}
	if(x > 0)
	{
		OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
		gObj->m_wExprienceRate = 100 * configs.expvip;
		gObj->m_wDropRate =  100 * configs.dropvip;
	}
}

//SetByte
void SetByte(DWORD dwOffset, BYTE btValue){
	*(BYTE*)(dwOffset) = btValue;
}
//Enviar dados para todos
void DataSendAll(unsigned char* Packet, int Length)
{
	for (int i=6400; i<7400; i++)
		if(gObjIsConnected(i))
			DataSend(i, Packet, Length);
}
// Função Name
void gObjGetChar(DWORD aIndex,DWORD Type,DWORD Size, char * nick)
{
	if(Size == 0) Size = 10;
	
	memcpy(nick,(char*)(gObjOffset+(gObjSize * aIndex)+Type),Size);
}