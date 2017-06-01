#include "StdAfx.h"
#include "Include.h"
STRUCT_INGAME in_game;
static char Connect[500];

void STRUCT_INGAME::PlayerConnect(int aIndex)
{
	mssql_Conn.CLtGetSQL(aIndex);
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	sprintf(Connect,gs_cmd.ConnectNotice,gObj->Name);
	ServerMsgSend(Connect,aIndex,0);
	LogAddFunc(Vermelho,"Conta: [%s] Char: [%s] Conectou-se ao Servidor",gObj->AccountID,gObj->Name);
}
void STRUCT_INGAME::GameMasterConn(int aIndex){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(gs_func.VerificarGM(aIndex) == true){
	sprintf(Connect,gs_cmd.ConnectNoticeGM,gObj->Name);
	gs_msg.MessageSendServer(Connect);
	}
}
void STRUCT_INGAME::VipPremium(int aIndex){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(stricmp(&gs_cmd.SistemaVipAtivo[0], "NAO") == 0)
	return;
	{
	if(gObj->VipLevel == ContaFree)
	{
		sprintf(Connect,"[%s] Você é um usuario Free: Bom Jogo.",gObj->Name);
		ServerMsgSend(Connect,aIndex,1);
	}
	else if(gObj->VipLevel == ContaVipSimples)
	{
		gObj->m_wExprienceRate += gs_cmd.VipSimplesExp;
		gObj->m_wDropRate += gs_cmd.VipSimplesDrop;
		sprintf(Connect,"[%s] Você é um usuario Vip: Exp e Drop elevados, Bom Jogo.",gObj->Name);
		ServerMsgSend(Connect,aIndex,1);
	}
	else if(gObj->VipLevel == ContaVipPremium)
	{
		gObj->m_wExprienceRate += gs_cmd.VipPremiumExp;
		gObj->m_wDropRate += gs_cmd.VipPremiumDrop;
		sprintf(Connect,"[%s] Você é um usuario S.vip: Exp e Drop elevados, Bom Jogo.",gObj->Name);
		ServerMsgSend(Connect,aIndex,1);
	}
	}
}
void STRUCT_INGAME::InGame(int aIndex){
	in_game.PlayerConnect(aIndex);
	in_game.GameMasterConn(aIndex);
	in_game.VipPremium(aIndex);
}
void ReplayNocicia(){
	if(stricmp(&gs_cmd.ReplayNoticiaAtivo[0], "NAO") == 0)
	return;
	{
		sprintf_s(Connect,"%s",gs_cmd.ReplayNoticia01);
		gs_msg.MessageSendServer(Connect);
		sprintf_s(Connect,"%s",gs_cmd.ReplayNoticia02);
		gs_msg.MessageSendServer(Connect);
		sprintf_s(Connect,"%s",gs_cmd.ReplayNoticia03);
		gs_msg.MessageSendServer(Connect);
		sprintf_s(Connect,"%s",gs_cmd.ReplayNoticia04);
		gs_msg.MessageSendServer(Connect);
	}
	Sleep(gs_cmd.ReplayNoticiaIn * 60000);
	ReplayNocicia();
}