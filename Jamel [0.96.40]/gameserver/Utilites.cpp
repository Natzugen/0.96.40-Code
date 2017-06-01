#include "StdAfx.h"
#include "Utilites.h"
#include "gameserver.h"
#include "defines.h"

void LogLine(char *formatstring, ...){

	va_list args;
	va_start(args, formatstring);
	char msg[0x1770];
	memset(msg, 0, sizeof(msg));
	FILE *logfile = fopen("..\\LOG\\XtcTeam.log","a+");
	_vsnprintf(msg, sizeof(msg), formatstring, args);
	fputs(msg, logfile);
	fclose(logfile);
}
void ToHex(unsigned char * out, unsigned char * data, int c_len){
	string s,t;
	char cBuff[5001];
	c_len = c_len & 0xff;
	memset(cBuff, 0, 5000);
	for(int i=0;i<c_len;i++){
		wsprintf(cBuff+(i*3),"%02X,",data[i]);
	}
	strcat(cBuff, "\r\n");
	memcpy(out,cBuff,(c_len*3)+2);
}
void gObjGetChar(DWORD gObjId,DWORD Type,DWORD Size, char * nick)
{
	if(Size == 0) Size = 10;
	
	memcpy(nick,(char*)(gObjOffset+(gObjSize * gObjId)+Type),Size);
}

int gObjGetInt(DWORD aIndex, int Type)
{
	DWORD gObj = (aIndex * gObjSize + gObjOffset);
	return *LPWORD(gObj+Type);
}

//Enviar dados para todos
void DataSendAll(unsigned char* Packet, int Length)
{
	for (int i=6400; i<7400; i++)
		if(gObjIsConnected(i))
			DataSend(i, Packet, Length);
}

//pegar login
void gObj_GetLogin ( WORD gObjId , char * login )
{
	memcpy ( login , (char*)( gObjOffset + ( gObjSize * gObjId) + gObjLogin ) , 10 );
}
//Enviar mensagem para server
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
	for(int i = 4800; i < 5800; i++)
		if (gObjGetInt(i,gObjConnected) == 3)
			DataSend(i,Packet,Len);
	free(Packet);
}


//Pegar Nick do Char
void gObj_GetNick(DWORD gObjId,char*nick)
{//Copia para variavel [nick] o nome do char.
memcpy(nick,(char*)(gObjOffset +(gObjSize*gObjId)+gObjNick),10);
}

//Pegar level do char
WORD gObj_GetLevel(DWORD PlayerID)
{
BYTE *Player=(BYTE*)GetPlayerAddress(PlayerID);
WORD level=0;
memcpy(&level,Player+gObjLvl,sizeof(WORD));
return level;
}

//Definir o Char
void *GetPlayerAddress(unsigned int PlayerID)
{//Retorna Offset do inicio do gObjStruct adicionado na multiplica do char pelo tamanhdo do gObjStruct
return(void*)(gObjOffset+(PlayerID*gObjSize));
}
