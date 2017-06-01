#include <stdio.h>
#include <windows.h>
#include "Global.h"
#include "User.h"
#include "Struct.h"
#include "SQL.h"
#include "StdAfx.h"
#include "GameServer.h"
#include "Functions.h"
#include "Customs.h"

SQL * CSQL = new SQL; 

static char Buffer[2048];
static char MyMsg[200];
static char QuerySelectVip[200];

//================================================
// Info
//================================================
void ChatInfo(DWORD aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	GCServerMsgStringSend("MLMServer 97D Ultimate Free [MLM Team]", aIndex, 1);
	LogAddFunc(Rosa,"[DLL LOG][COMANDO INFO] [ID = %d][Acc = %s] Char %s usou este comando",gObj->m_Index,gObj->AccountID,gObj->Name);
}
//================================================
// Post
//================================================
void ChatGlobal(short aIndex,char * msg)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Mensagem[200];
	unsigned char resi = CSQL->GetFieldInt("MuOnline.dbo.Character","resets","WHERE Name = '%s'",gObj->Name);
	if(configs.c_Post.PostActive == 0)
	{
		GCServerMsgStringSend("[POST] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	else if(gObj->Level < configs.c_Post.PostLevel)
	{
		sprintf(Mensagem,"%s Falta %d level para você poder postar!",gObj->Name,(configs.c_Post.PostLevel - gObj->Level));
		GCServerMsgStringSend(Mensagem,aIndex,1);
	}
	else if(resi < configs.c_Post.PostReset)
	{
		sprintf(Mensagem,"%s Falta %d resets para você poder postar!",gObj->Name,(configs.c_Post.PostReset - resi));
		GCServerMsgStringSend(Mensagem,aIndex,1);
	}
	else if(gObj->Money <configs.c_Post.PostZenReq)
	{
		sprintf(Mensagem,"%s Falta %d de zen para você postar!",gObj->Name,(configs.c_Post.PostZenReq - gObj->Money));
		GCServerMsgStringSend(Mensagem,aIndex,1);
	}
	else
	{
	gObj->Money -= configs.c_Post.PostZenReq;
	GCMoneySend(gObj->m_Index,gObj->Money);
	sprintf_s(Mensagem,200,"[GLOBAL]:%s ",msg);
	ServerMsgSend(aIndex,1,gObj->Name,Mensagem);
	}
}
//================================================
//Comando para ver Golds da acc
//================================================
void ChatMyGold(int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char MyGold[200];
	int GGolds = CSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","gold","WHERE Memb___id = '%s'",gObj->AccountID);
	{
		sprintf(MyGold,"Você possui %d Golds",GGolds);
		GCServerMsgStringSend(MyGold,aIndex,1);
		LogAddFunc(Vermelho,"[DLL LOG][COMANDO MYGOLD] [ID = %d][Acc = %s] Char %s usou este comando",gObj->m_Index,gObj->AccountID,gObj->Name);
	}
}
//================================================
// ADD
//================================================
void ChatAddStats(DWORD aIndex, LPCSTR lpBuffer, DWORD tipo)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Mensage[200];
	int ActiveAdd = configs.c_Add.AddActive;
	int LevelAdd = configs.c_Add.AddLevel;
	int PointAdd = configs.c_Add.AddMaxPoint;
	unsigned PriceAdd = configs.c_Add.AddPrice;
	int points = atoi(lpBuffer);

	if(ActiveAdd < 1)
	{
		GCServerMsgStringSend("[ADD]Comando Desativado pelo Administrador!",aIndex,1);
		return;
	}
	if(gObj->Level < LevelAdd)
	{
		sprintf(Mensage,"[ADD]Você não possui level suficiente, falta %d para usar o comando.",LevelAdd - gObj->Level);
		GCServerMsgStringSend(Mensage,aIndex,1);
	}
	if(points > PointAdd)
	{
		sprintf(Mensage,"[ADD]Você está tentando adicionar mais que o limite de [%d]pontos",PointAdd);
		GCServerMsgStringSend(Mensage,aIndex,1);
	}
	if(gObj->Money < PriceAdd)
	{
		sprintf(Mensage,"[ADD]Zen insufiiente , falta %d para usar o comando",PriceAdd - gObj->Money);
		GCServerMsgStringSend(Mensage,aIndex,1);
	}
	gObj->Money -= PriceAdd;
	gObj->LevelUpPoint -= points;

	if(tipo == 0)
		gObj->Strength += points;
	else if (tipo == 1)
		gObj->Dexterity += points;
	else if (tipo == 2)
		gObj->Vitality += points;
	else if (tipo == 3)
		gObj->Energy += points;

	GCServerMsgStringSend("Pontos Adicionados com Sucesso,Relogue-se.",aIndex,1);
	LogAddFunc(Vermelho,"[DLL LOG][COMANDO ADD] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
}
//================================================
//Comando move Devias2
//================================================
void ChatMoveDevias2(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Levela = configs.c_MoveD2.MinLevel;
	unsigned int Pricea = configs.c_MoveD2.Price;

	if(configs.c_MoveD2.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levela > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_MoveD2.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Pricea > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_MoveD2.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_MoveD2.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 2,gObj->X = 23,gObj->Y = 27,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Devias2!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//================================================
//Comando move Devias3
//================================================
void ChatMoveDevias3(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Levelz = configs.c_D3Move.MinLevel;
	unsigned int Pricez = configs.c_D3Move.Price;

	if(configs.c_D3Move.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levelz > gObj->Level)
	{
		GCServerMsgStringSend("[MOVE] Você não tem o zen necessário para usar o comando!",gObj->m_Index,1);
		return;
	}
	if(Pricez > gObj->Money)
	{
		GCServerMsgStringSend("[MOVE] Você não tem o zen necessário para usar o comando!",gObj->m_Index,1);
		return;
	}
	else
	{
		gObj->Money -= configs.c_D3Move.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 2,gObj->X = 224,gObj->Y = 231,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Devias3!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move Atlans2
//===========================================================================================
void ChatMoveAtlans2(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Leveli = configs.c_A2Move.MinLevel;
	unsigned int Pricei = configs.c_A2Move.Price;

	if(configs.c_A2Move.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Leveli > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_A2Move.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Pricei > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_A2Move.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_A2Move.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 7,gObj->X = 225,gObj->Y = 53,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Atlans2!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move Atlans2
//===========================================================================================
void ChatMoveAtlans3(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Levelc = configs.c_A3Move.MinLevel;
	unsigned int Pricec = configs.c_A3Move.Price;

	if(configs.c_A3Move.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levelc > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_A3Move.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Pricec > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_A3Move.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_A3Move.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 7,gObj->X = 62,gObj->Y = 163,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Atlans3!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move Tarkan2
//===========================================================================================
void ChatMoveTarkan2(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Levela = configs.c_T2Move.MinLevel;
	unsigned int Pricea = configs.c_T2Move.Price;

	if(configs.c_MoveD2.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levela > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_T2Move.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Pricea > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_T2Move.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_T2Move.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 8,gObj->X = 96,gObj->Y = 143,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Tarkan2!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move Icarus
//===========================================================================================
void ChatMoveIcarus(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Levelq = configs.c_IcaMove.MinLevel;
	unsigned int Priceq = configs.c_IcaMove.Price;

	if(configs.c_IcaMove.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levelq > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_IcaMove.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Priceq > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_IcaMove.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_IcaMove.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 10,gObj->X = 14,gObj->Y = 13,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a Icarus!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move Valley
//===========================================================================================
void ChatMoveValley(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	int Leveld = configs.c_ValeMove.MinLevel;
	unsigned int Priced = configs.c_ValeMove.Price;

	if(configs.c_ValeMove.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Leveld > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_ValeMove.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Priced > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_ValeMove.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_ValeMove.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 10,gObj->X = 88,gObj->Y = 31,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a ValleyofLoren!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Move DareDevil
//===========================================================================================
void ChatMoveDare(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	char Message[200];
	unsigned char isVip = CSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",gObj->AccountID);
	int Levelf = configs.c_DareMove.MinLevel;
	unsigned int Pricef = configs.c_DareMove.Price;

	if(configs.c_ValeMove.Active < 1)
	{
		GCServerMsgStringSend("[MOVE] Comando desabilitado pelo Administrador!!",gObj->m_Index,1);
		return;
	}
	if(isVip < configs.c_DareMove.Active)
	{
		GCServerMsgStringSend("[MOVE] Mover para este mapa apenas VIPs",gObj->m_Index,1);
		return;
	}
	if(gObj->PK_Level > 4)
	{
		GCServerMsgStringSend("[MOVE] Pks não podem mover!",gObj->m_Index,1);
		return;
	}
	if(Levelf > gObj->Level)
	{
		sprintf(Message,"Falta %d level para você mover!.",configs.c_DareMove.MinLevel - gObj->Level);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	if(Pricef > gObj->Money)
	{
		sprintf(Message,"Falta %d zen para você mover!.",configs.c_DareMove.Price - gObj->Money);
		GCServerMsgStringSend(Message,aIndex,1);
	}
	else
	{
		gObj->Money -= configs.c_DareMove.Price;
		gObjTeleport(aIndex,gObj->MapNumber = 18,gObj->X = 60,gObj->Y = 11,gObj->Dir);
		GCMoneySend(gObj->m_Index,gObj->Money);
		GCServerMsgStringSend("Você foi movido com Sucesso a DareDevil!!",aIndex,1);
		LogAddFunc(Verde,"[DLL LOG][MOVE] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Sair.
//===========================================================================================
void ChatSair(DWORD PlayerID,char* msg)
{
	int IsQuit = GetPrivateProfileInt("COMANDOS","SairActive",0,"..\\MLMData\\MLMComandos.ini");
	if(IsQuit == 0)
	{
		GCServerMsgStringSend("O comando não esta ativado.",PlayerID,1);
		return;
	}

	if(!strcmp("/sair",msg))
	{
		GCServerMsgStringSend("Você saiu do jogo.",PlayerID,1);
		return;
	}

	CloseClient(PlayerID);
}
//===========================================================================================
// Comando Reload.
//===========================================================================================
void ChatReload(DWORD aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	unsigned char isGM = CSQL->GetFieldInt("MuOnline.dbo.Character","CtlCode","WHERE Name = '%s'",gObj->Name);
	int Ativaxa = configs.c_Reload.Active;
	unsigned char CodeReload = configs.c_Reload.OnlyGM;

	if(Ativaxa < 1)
	{
		GCServerMsgStringSend("[RELOAD] Comando desativado pelo Administrador",aIndex,1);
		return;
	}
	if(isGM < configs.c_Reload.OnlyGM)
	{
		GCServerMsgStringSend("[RELOAD] Você não é Administrador.",aIndex,1);
		return;
	}
	else
	{
			MLMini();
			Carrega();
	}
			GCServerMsgStringSend("MLMCustoms.ini carregado com sucesso",aIndex,1);
			GCServerMsgStringSend("MLMComandos.ini carregado com sucesso",aIndex,1);
			GCServerMsgStringSend("MLMNpcs.ini carregado com sucesso",aIndex,1);
			GCServerMsgStringSend("MLMMensagem.ini carregado com sucesso",aIndex,1);
			GCServerMsgStringSend("MLMMoves.ini carregado com sucesso",aIndex,1);
}
//===========================================================================================
// Comando PkSet
//===========================================================================================
void ChatPkSet(DWORD aIndex,char* nick)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	unsigned char isGM = CSQL->GetFieldInt("MuOnline.dbo.Character","CtlCode","WHERE Name = '%s'",gObj->Name);
	int PKActive = configs.c_PkSet.Active;

	if(PKActive < 1)
	{
		GCServerMsgStringSend("[PKSET]Comando desativado pelo Administrador",aIndex,1);
		return;
	}
	if(isGM < configs.c_PkSet.CodeS)
	{
		GCServerMsgStringSend("[PKSET] Você não é Administrador.",aIndex,1);
		return;
	}
	else
	{
		if(nick == gObj->Name)
			gObj->PK_Level += 1;

		GCPKLevelSend(gObj->m_Index,gObj->PK_Level);
		GCServerMsgStringSend("[PKSET]Comando Usado. char Definido ganhou +1 de PK!",aIndex,1);
		LogAddFunc(Vermelho,"[DLL LOG][PKSET] [ID = %d][Acc = %s] Char %s usou este comando!",aIndex,gObj->AccountID,gObj->Name);
	}
}
//===========================================================================================
// Comando Site
//===========================================================================================
void ChatSite(DWORD aIndex)
{
	GCServerMsgStringSend(Site, aIndex,0);
}
//===========================================================================================
// Comando Hora
//===========================================================================================
void ChatTime(DWORD PlayerID)
{
	int HoraAtiva = configs.c_Hora.Active;

	if(HoraAtiva < 1)
	{
		GCServerMsgStringSend("[HORA] Comando desativado pelo administrador!",PlayerID,1);
		return;
	}
	else
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
}
//===========================================================================================
// Comando MoveAll
//===========================================================================================
void MoveAllGMCmd(int aIndex)
{
	if(configs.MoveAllCmd = 0)
	{
		GCServerMsgStringSend("Comando Desativo",aIndex,1);
		return;
	}
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	unsigned char isGM = CSQL->GetFieldInt("MuOnline.dbo.Character","CtlCode","WHERE Name = '%s'",gObj->Name);
	if(isGM < 8)
	{
		GCServerMsgStringSend("Seu Personagem não é GameMaster",aIndex,1);
		return;
	}
	else
	{
		for(int i=4800; i<5600 && i!=aIndex; i++)
		{
			gObjTeleport(aIndex,gObj->MapNumber,gObj->X,gObj->Y,gObj->Dir);
		}
		sprintf_s(MyMsg,"GM [%s] Todos Personagens Movidos com Sucesso",gObj->Name);
		GCServerMsgStringSend(MyMsg,aIndex,1);
	}
}
//===========================================================================================
// Comando Invisible
//===========================================================================================
//==============================================================================
void ChatDataSend(DWORD aIndex,LPBYTE Protocol)
{
	char ComandoMyGolds[] = "/mygold";
	if(!memcmp(&Protocol[13],ComandoMyGolds,strlen(ComandoMyGolds)))
	{
		ChatMyGold(aIndex);
	}
	//Comando info
	char ComandoInfo[] = "/info";
	if(!memcmp(&Protocol[13],ComandoInfo,strlen(ComandoInfo)))
	{
		ChatInfo(aIndex);
	}
	// Comando Post
	char ComandoPost[] = "/post";
	if(!memcmp(&Protocol[13],ComandoPost,strlen(ComandoPost)))
	{
	ChatGlobal(aIndex,( char*)Protocol+13+strlen(ComandoPost));
	}
	//Comando MoveDevias2
	char ComandoMoveDevias2[] = "/move devias2";
	if(!memcmp(&Protocol[13],ComandoMoveDevias2,strlen(ComandoMoveDevias2)))
	{
		ChatMoveDevias2(aIndex);
	}
	//Comando MoveDevias3
	char ComandoMoveDevias3[] = "/move devias3";
	if(!memcmp(&Protocol[13],ComandoMoveDevias3,strlen(ComandoMoveDevias3)))
	{
		ChatMoveDevias3(aIndex);
	}
	//Comando MoveAtlans2
	char ComandoMoveAtlans2[] = "/move atlans2";
	if(!memcmp(&Protocol[13],ComandoMoveAtlans2,strlen(ComandoMoveAtlans2)))
	{
		ChatMoveAtlans2(aIndex);
	}
	//Comando MoveAtlans3
	char ComandoMoveAtlans3[] = "/move atlans3";
	if(!memcmp(&Protocol[13],ComandoMoveAtlans3,strlen(ComandoMoveAtlans3)))
	{
		ChatMoveAtlans3(aIndex);
	}
	//Comando MoveTarkan2
	char ComandoMoveTarkan2[] = "/move tarkan2";
	if(!memcmp(&Protocol[13],ComandoMoveTarkan2,strlen(ComandoMoveTarkan2)))
	{
		ChatMoveTarkan2(aIndex);
	}
	//Comando MoveIcarus
	char ComandoMoveIcarus[] = "/move icarus";
	if(!memcmp(&Protocol[13],ComandoMoveIcarus,strlen(ComandoMoveIcarus)))
	{
		ChatMoveIcarus(aIndex);
	}
	//Comando MoveValley
	char ComandoMoveValley[] = "/move valleyofloren";
	if(!memcmp(&Protocol[13],ComandoMoveValley,strlen(ComandoMoveValley)))
	{
		ChatMoveValley(aIndex);
	}
	//Comando MoveDareDevil
	char ComandoMoveDare[] = "/move daredevil";
	if(!memcmp(&Protocol[13],ComandoMoveDare,strlen(ComandoMoveDare)))
	{
		ChatMoveDare(aIndex);
	}
	//Comando sair
	char ComandoExit[] = "/sair";
	if(!memcmp(&Protocol[13],ComandoExit,strlen(ComandoExit)))
	{
	ChatSair(aIndex,( char*)Protocol+13+strlen(ComandoExit));
	}
	//Comando Reload
	char ComandoReload[] = "/reload";
	if(!memcmp(&Protocol[13],ComandoReload,strlen(ComandoReload)))
	{
		ChatReload(aIndex);
	}
	//Comando Add
	char StrCmd[] = "/str";
	if(!memcmp(&Protocol[13],StrCmd,strlen(StrCmd)))
	{
	ChatAddStats(aIndex,(char*)Protocol+13+strlen(StrCmd), 0);
	}
	char AgiCmd[] = "/agi";
	if(!memcmp(&Protocol[13],AgiCmd,strlen(AgiCmd)))
	{
	ChatAddStats(aIndex,(char*)Protocol+13+strlen(AgiCmd), 1);
	}
	char VitCmd[] = "/vit";
	if(!memcmp(&Protocol[13],VitCmd,strlen(VitCmd)))
	{
	ChatAddStats(aIndex,(char*)Protocol+13+strlen(VitCmd), 2);
	}
	char EneCmd[] = "/ene";
	if(!memcmp(&Protocol[13],EneCmd,strlen(EneCmd)))
	{
	ChatAddStats(aIndex,(char*)Protocol+13+strlen(EneCmd), 3);
	}
	//Comando pkset
	char ComandoPkSet[] = "/pkset";
	if(!memcmp(&Protocol[13],ComandoPkSet,strlen(ComandoPkSet)))
	{
		ChatPkSet(aIndex,(char*)Protocol+13+strlen(ComandoPkSet));
	}
	//Comando site
	char ComandoSite[] = "/site";
	if(!memcmp(&Protocol[13],ComandoSite,strlen(ComandoSite)))
	{
		ChatSite(aIndex);
	}
	//Comando Hora
	char ComandoHoras[] = "/hora";
	if(!memcmp(&Protocol[13],ComandoHoras,strlen(ComandoHoras))) 
	{
	ChatTime(aIndex);
	}
	//Comando MoveAll
	char MoveAll[] = "/moveall";
	if(!memcmp(&Protocol[13],MoveAll,strlen(MoveAll)))
	{
	MoveAllGMCmd(aIndex);
	}
	*/
}