#include "StdAfx.h"
#include "Include.h"
GS_MESSAGE gs_msg;

void GS_MESSAGE::MessageSendServer(char * Texto,...){
	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
	if(gObj->Connected == PLAYER_PLAYING)
	ServerMsgSend(Texto, i, 0);
	}
}
void GS_MESSAGE::MessageSendMap(char Map, char * Texto, ...){
	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
	if(gObj->Connected == 3)
	{
	if(gObj->MapNumber == Map)
	{
	ServerMsgSend(Texto,i,0);
	}
	}
	}
}
void GS_MESSAGE::ChatSendGuild (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex){//Verde
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x40;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
	if (gs_func.gObjGetInt(i,gObjConnected) == 3)
	DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}
void GS_MESSAGE::ChatSendParty (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex){//Azul
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x7E;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
	if (gs_func.gObjGetInt(i,gObjConnected) == 3)
	DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}
void GS_MESSAGE::ChatSendWhisper (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex){//Amarelo
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+14;
	Buffer[2]=0x02;
	strncpy((char*)&Buffer[3],Nome,10);
	strncpy((char*)&Buffer[13],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
	if (gs_func.gObjGetInt(i,gObjConnected) == 3)
	DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}