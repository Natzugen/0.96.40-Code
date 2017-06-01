#include "StdAfx.h"
#include "defines.h"
#include "gameserver.h"
#include "utilites.h"
#include <stdio.h>
#include <windows.h>
#include "global.h"


//==================================
//Comando para mensagem Global
//==================================
void ChatGlobal(DWORD PlayerID,char * msg)
{
	gObj_GetNick(PlayerID, Character);
	int IsPost = GetPrivateProfileInt("Comandos","SwitchPost",1,".\\gameserver.ini");
	int Level = GetPrivateProfileInt("Comandos","PostLevel",100,".\\gameserver.ini");
	if (IsPost == 0)
	{
		GCServerMsgStringSend("O administrador desativou o comando.",PlayerID,1);
		return;
	}
	if (!strcmpi("/Post",msg))
	{
		GCServerMsgStringSend("Sintaxe:/post <msg>",PlayerID,1);
		return;
	}
	if (strlen(msg) < 1)
	{
		GCServerMsgStringSend("Sintaxe:/post <msg>",PlayerID,1);
		return;
	}

	if ((int)gObj_GetLevel(PlayerID) < Level)
	{
		GCServerMsgStringSend("Você não possui level suficiente para usar o comando.",PlayerID,1);
		return;
	}
	char Nick[11];
	gObjGetChar(PlayerID,gObjNick,10,Nick);
	char Message[200];
	sprintf(Message,"[GLOBAL] %s",msg);
	ServerMsgSend(PlayerID,1,Nick,Message);
}
//================================================== =================
//========================= Comando Horas ===========================
//================================================== =================
void ChatTime(DWORD PlayerID)
{
time_t tim=time(NULL);
tm *now=localtime(&tim);

char dateStr [11];
char timeStr [9];
char WeekStr [30];

sprintf_s(dateStr, "%02d/%02d/%04d", now->tm_mday, now->tm_mon+1, now->tm_year+1900);
sprintf_s(timeStr, "%02d:%02d", now->tm_hour, now->tm_min);

int iDWeek = now->tm_wday;

if (iDWeek == 0) {
sprintf(WeekStr, "Domingo");
} else if (iDWeek == 1) {
sprintf(WeekStr, "Segunda-feira");
} else if (iDWeek == 2) {
sprintf(WeekStr, "Terça-feira");
} else if (iDWeek == 3) {
sprintf(WeekStr, "Quarta-feira");
} else if (iDWeek == 4) {
sprintf(WeekStr, "Quinta-feira");
} else if (iDWeek == 5) {
sprintf(WeekStr, "Sexta-feira");
} else if (iDWeek == 6) {
sprintf(WeekStr, "Sábado");
}

char OutputSuccess[200];
sprintf_s(OutputSuccess, "Hoje é %s - %s, %s!", dateStr, timeStr, WeekStr); 
GCServerMsgStringSend(OutputSuccess, PlayerID, 1);
}
//===========================================================================================
// Comando Sair.
//===========================================================================================
void ChatSair(DWORD PlayerID,char* msg)
{
	int IsQuit = GetPrivateProfileInt("Comandos","ComandoExit",0,".\\gameserver.ini");
	if(IsQuit == 0)
	{
		GCServerMsgStringSend("O comando não esta ativado.",PlayerID,1);
		return;
	}

	if(!strcmp("/exit",msg))
	{
		GCServerMsgStringSend("Você saiu do jogo.",PlayerID,1);
		return;
	}

	CloseClient(PlayerID);
}
void ChatDataSend(DWORD gObjId,LPBYTE Protocol)
{
	//POST
	char ComandoPost[] = "/post";
	if(!memcmp(&Protocol[13],ComandoPost,strlen(ComandoPost)))
	{
	ChatGlobal(gObjId,( char*)Protocol+13+strlen(ComandoPost));
	}
	//HORA
	char ComandoHoras[] = "/hora";
	if(!memcmp(&Protocol[13],ComandoHoras,strlen(ComandoHoras))) 
	{
	ChatTime(gObjId);
	}
	//Exit
	char ComandoExit[] = "/exit";
	if(!memcmp(&Protocol[13],ComandoExit,strlen(ComandoExit)))
	{
	ChatSair(gObjId,( char*)Protocol+13+strlen(ComandoExit));
	}
}