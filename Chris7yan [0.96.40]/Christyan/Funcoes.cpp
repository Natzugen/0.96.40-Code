#include "StdAfx.h"

void ProtocolCore(BYTE protoNum, LPBYTE aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial)
{
	switch(protoNum)
	{
	case 0x00: 
		ChatDataSend(aIndex, aRecv); 
	break; 
	case 0x03:
		VIP(aIndex);
		GCServerMsgStringSend(ConnectServ, aIndex, 0);
	break;
	}
	DataRecv(protoNum, aRecv, aLen, aIndex, Encrypt, Serial);
}

void HookThis(DWORD OriginalOffset, DWORD DestOffset)
{
	DWORD OldProtect = 0; 
	VirtualProtect((LPVOID)(OriginalOffset+1), 4, PROCESS_ALL_ACCESS, &OldProtect); 
	*(DWORD*)(OriginalOffset+1) = (DWORD)(DestOffset)-(OriginalOffset +5); 
	VirtualProtect((LPVOID)(OriginalOffset+1), 4, OldProtect, NULL);
}

void MessageSendServer(char * Texto,...)
{
	for(int i = 4800; i < 5800; i++)
	{
		OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
		if(gObj->Connected == 3)
			ServerMsgSend(Texto, i, 0);
	}
}

void MessageSendMap(char Map, char * Texto, ...)
{
	for(int i = 4800; i < 5800; i++)
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

void ChatSendGuild (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{//Verde
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x40;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
		if (gObj->Connected == 3)
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}

void ChatSendParty (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{//Azul
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x7E;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
		if (gObj->Connected == 3)
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}

void ChatSendWhisper (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex)
{//Amarelo
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+14;
	Buffer[2]=0x02;
	strncpy((char*)&Buffer[3],Nome,10);
	strncpy((char*)&Buffer[13],Mensagem,Len);
	for(int i = 4800; i < 5800; i++)
		if (gObj->Connected == 3)
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
}