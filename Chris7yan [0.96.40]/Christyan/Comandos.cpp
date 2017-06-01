#include "StdAfx.h"

void COMANDO_LIMPARPK(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(ATIVEPK == 0)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Comando desabilitado.", aIndex);
		return;
	}
	else if(gObj->Level < LEVELPK)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui level suficiente para usar o comando.", aIndex);
		return;
	}
	else if(gObj->Money < PRICEPK)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui zen suficiente para usar o comando.", aIndex);
		return;
	}
	else if(gObj->PkLevel <= 3)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não e um Player Killer.", aIndex);
		return;
	}
	else
	{
		gObj->PkLevel = 3;
		gObj->PkTime = 0;
		gObj->PkCount = 0;
		gObj->Money -= PRICEPK;
		GCPkLevelSend(aIndex, gObj->PkLevel);
		GCMoneySend(aIndex, gObj->Money);
		ChatSendWhisper(gObj->Name, "Player Killer, Você foi perdoado.", aIndex);
	}
}

void COMANDO_SAIR(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(ATIVEEXIT == 0)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Comando desabilitado.", aIndex);
		return;
	}
	else if(gObj->Level < LEVELEXIT)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui level suficiente para usar o comando.", aIndex);
		return;
	}
	else if(gObj->Money < PRICEEXIT)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui zen suficiente para usar o comando.", aIndex);
		return;
	}
	else
	{
		gObj->Money -= PRICEEXIT;
		ChatSendWhisper(gObj->Name, "Saindo do jogo...", aIndex);
		CloseClient(aIndex);
	}
}

void COMANDO_HORAS(DWORD aIndex)
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	time_t tim = time(0);
	tm * now = localtime(&tim);

	char OutputSuccess[200];
	char dateStr [11];
	char timeStr [9];
	char WeekStr [30];
	int iDWeek = now->tm_wday;

	if(ATIVETIME == 0)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Comando desabilitado.", aIndex);
		return;
	}
	else if(gObj->Level < LEVELTIME)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui level suficiente para usar o comando.", aIndex);
		return;
	}
	else if(gObj->Money < PRICETIME)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui zen suficiente para usar o comando.", aIndex);
		return;
	}
	else
	{
	if (iDWeek == 0)
	{
		sprintf(WeekStr, "Domingo");
	}
	else if (iDWeek == 1)
	{
		sprintf(WeekStr, "Segunda-feira");
	}
	else if (iDWeek == 2)
	{
		sprintf(WeekStr, "Terça-feira");
	}
	else if (iDWeek == 3)
	{
		sprintf(WeekStr, "Quarta-feira");
	}
	else if (iDWeek == 4)
	{
		sprintf(WeekStr, "Quinta-feira");
	}
	else if (iDWeek == 5)
	{
		sprintf(WeekStr, "Sexta-feira");
	}
	else if (iDWeek == 6)
	{
		sprintf(WeekStr, "Sábado");
	}
	gObj->Money -= PRICETIME;
	sprintf(dateStr, "%02d/%02d/%04d", now->tm_mday, now->tm_mon+1, now->tm_year+1900);
	sprintf(timeStr, "%02d:%02d", now->tm_hour, now->tm_min);
	sprintf_s(OutputSuccess, "Hoje é %s - %s, %s!", dateStr, timeStr, WeekStr); 
	ChatSendWhisper(gObj->Name, OutputSuccess, aIndex);
	}
}

void COMANDO_ZEN(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(ATIVEZEN == 0)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Comando desabilitado.", aIndex);
		return;
	}
	else if(gObj->Level < LEVELZEN)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui level suficiente para usar o comando.", aIndex);
		return;
	}
	else
	{
		gObj->Money += ZENADD;
		GCMoneySend(aIndex, gObj->Money);
		ChatSendWhisper(gObj->Name, "Acaba de ser adicionado 100kk ao seu inventario.", aIndex);
	}
}

void COMANDO_RESETAR(int aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(ATIVERESET == 0)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Comando desabilitado.", aIndex);
		return;
	}
	else if(gObj->Level < LEVELRESET)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui level suficiente para usar o comando.", aIndex);
		return;
	}
	else if(gObj->Money < PRICERESET)
	{
		ChatSendGuild(gObj->Name, "Desculpe, Você não possui zen suficiente para usar o comando.", aIndex);
		return;
	}
	else
	{
		gObj->Level = 1;
		gObj->Experience = 0;
		gObj->Money -= PRICERESET;
		gObjTeleport(aIndex,0,125,125);
		GCLevelUpMsgSend(aIndex, gObj->Level);
		GCMoneySend(aIndex, gObj->Money);
		Exec("UPDATE Character SET Resets = Resets+1 WHERE Name = '%s'",gObj->AccountID);
		ChatSendWhisper(gObj->Name, "Seu reset foi efetuado com sucesso.", aIndex);
	}
}

void ChatDataSend(DWORD aIndex, LPBYTE Protocol) 
{
	if(_stricmp(reinterpret_cast<char*>(&Protocol[13]), reinterpret_cast<char*>("/")) == 0)
	{
		return;
	}
	else
	{
		if(_stricmp(reinterpret_cast<char*>(&Protocol[14]), reinterpret_cast<char*>(StringPk)) == 0)	
		{
			COMANDO_LIMPARPK(aIndex);
		}
		else if(_stricmp(reinterpret_cast<char*>(&Protocol[14]), reinterpret_cast<char*>(StringExit)) == 0)
		{
			COMANDO_SAIR(aIndex);
		}
		else if(_stricmp(reinterpret_cast<char*>(&Protocol[14]), reinterpret_cast<char*>(StringTime)) == 0)
		{
			COMANDO_HORAS(aIndex);
		}
		else if(_stricmp(reinterpret_cast<char*>(&Protocol[14]), reinterpret_cast<char*>(StringZen)) == 0)
		{
			COMANDO_ZEN(aIndex);
		}
		else if(_stricmp(reinterpret_cast<char*>(&Protocol[14]), reinterpret_cast<char*>(StringReset)) == 0)
		{
			COMANDO_RESETAR(aIndex);
		}
	}
}