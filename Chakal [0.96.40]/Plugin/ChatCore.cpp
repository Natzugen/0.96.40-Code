#include "StdAfx.h"
#include "Include.h"
static char msN[256];

void CHAT_COMMANDS::GameServerInfo(int aIndex){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(gObj->MapNumber == 0 && gObj->StartX == 125 && gObj->StartY == 125) // Teste ;D
	{
		ServerMsgSend("Local Proibido para o uso do Comando.",aIndex,1);
		return;
	}
		ServerMsgSend(PROJETONOME,aIndex,1); // 1 = Azul canto da tela // 0 = Meio da tela amarela
		ServerMsgSend(CRITICALTEAM,aIndex,1);
		ServerMsgSend(DESENVOLVIDO,aIndex,1);
}
void CHAT_COMMANDS::PostCmd(short aIndex, char *msg){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(stricmp(&this->PostAtivo[0], "NAO") == 0)
	{
		sprintf_s(msN,"[%s] Comando Desabilitado. Consulte um Admin.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if (strlen(msg) < 1)
	{
		sprintf_s(msN,"[%s] Usa-se: /%s <msg>.",gObj->Name,this->PostSintax);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(this->PostVip == 1)
	{
		if(gObj->VipLevel < ContaVipSimples)
		{
		sprintf_s(msN,"[%s] Comando exclusivo apenas para Vip.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
		}
	}
	if(gObj->Resets < this->PostReset)
	{
		sprintf_s(msN,"[%s] Faltam %d Reset's para usar o comando.",gObj->Name,(this->PostReset - gObj->Resets));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(gObj->Level < this->PostLevel)
	{
		sprintf_s(msN,"[%s] Faltam %d Level's para usar o comando.",gObj->Name,(this->PostLevel - gObj->Level));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(gObj->Money < this->PostDinhero)
	{
		sprintf_s(msN,"[%s] Faltam %d Zen's para usar o comando.",gObj->Name,(this->PostDinhero - gObj->Money));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	char Message[200];
	sprintf(Message,this->PostFormato,msg);
	if(this->PostCor == PostAzul)
	{
		gs_msg.ChatSendParty(gObj->Name,Message,aIndex);
	}
	if(this->PostCor == PostVerde)
	{
		gs_msg.ChatSendGuild(gObj->Name,Message,aIndex);
	}
	if(this->PostCor == PostAmarelo)
	{
		gs_msg.ChatSendWhisper(gObj->Name,Message,aIndex);
	}
	gObj->Money -= this->PostDinhero;
	GCMoneySend(aIndex,gObj->Money);
}
void CHAT_COMMANDS::AddPontosCmd(int aIndex, LPCSTR lpBuffer, int Status){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int Pontos = atoi(lpBuffer);
	if(stricmp(&this->AddAtivo[0], "NAO") == 0)
	{
		sprintf_s(msN,"[%s] Comando Desabilitado. Consulte um Admin.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(strlen(lpBuffer) < 1)
	{
		sprintf_s(msN,"[%s] Usa-se: /<add tipo> <pontos>",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(this->AddLevel > gObj->Level)
	{
		sprintf_s(msN,"[%s] Faltam %d Level's para usar o comando.",gObj->Name,(this->AddLevel - gObj->Level));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(this->AddDinhero > gObj->Money)
	{
		sprintf_s(msN,"[%s] Faltam %d Zen's para usar o comando.",gObj->Name,(this->AddDinhero - gObj->Money));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(Pontos > gObj->LevelUpPoint)
	{
		sprintf_s(msN,"[%s] Voce não tem esses Pontos. Faltam %d.",gObj->Name,(Pontos - gObj->LevelUpPoint));
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(this->AddMaxPontos <= Pontos)
	{
		sprintf_s(msN,"[%s] Maximo de pontos a adicionar = [%d]",gObj->Name,Pontos,this->AddMaxPontos);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	else
	{
	     gObj->Money -= this->AddDinhero;
	     gObj->LevelUpPoint -= Pontos;

	    if(Status == 1)
	    {
			if((gObj->Strength + Pontos) >= this->MaxAddStatus)
			{
				sprintf_s(msN,"[%s] Não Pode adicionar [%d] Pontos,ira passar do limite [%d]. ",gObj->Name,Pontos,this->MaxAddStatus);
	            ServerMsgSend(msN,aIndex,1);
				return;
			}
			else
			{
				gObj->Strength += Pontos;
			}
	    }
		else if(Status == 2)
	    {
			if((gObj->Dexterity + Pontos) >= this->MaxAddStatus)
			{
				sprintf_s(msN,"[%s] Não Pode adicionar [%d] Pontos,ira passar do limite [%d]. ",gObj->Name,Pontos,this->MaxAddStatus);
	            ServerMsgSend(msN,aIndex,1);
				return;
			}
			else
			{
				gObj->Dexterity += Pontos;
			}
	    }
		else if(Status == 3)
	    {
			if((gObj->Vitality + Pontos) >= this->MaxAddStatus)
			{
				sprintf_s(msN,"[%s] Não Pode adicionar [%d] Pontos,ira passar do limite [%d]. ",gObj->Name,Pontos,this->MaxAddStatus);
	            ServerMsgSend(msN,aIndex,1);
				return;
			}
			else
			{
				gObj->Vitality += Pontos;
			}
	    }
		else if(Status == 4)
	    {
			if((gObj->Energy + Pontos) >= this->MaxAddStatus)
			{
				sprintf_s(msN,"[%s] Não Pode adicionar [%d] Pontos,ira passar do limite [%d]. ",gObj->Name,Pontos,this->MaxAddStatus);
	            ServerMsgSend(msN,aIndex,1);
				return;
			}
			else
			{
				gObj->Energy += Pontos;
			}
		}
		GCMoneySend(aIndex,gObj->Money);
		sprintf_s(msN,"[%s] Adicionou [%d] Pontos. Relogue-se para atualizar.",gObj->Name,Pontos);
		ServerMsgSend(msN,aIndex,1);
	}
}
void CHAT_COMMANDS::ExitCmd(int aIndex,unsigned int Tipo){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if(stricmp(&this->ExitAtivo[0], "NAO") == 0)
	{
		sprintf_s(msN,"[%s] Comando Desabilitado. Consulte um Admin.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(Tipo == 1)
	{
		sprintf_s(msN,"[%s] Saindo do Jogo...",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		CloseClient(aIndex);
	}
	else if(Tipo == 2)
	{
		sprintf_s(msN,"[%s] Selecionando Personagem...",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		gObjCloseSet(aIndex,1);
	}
	else if(Tipo == 3)
	{
		sprintf_s(msN,"[%s] Selecionando o Servidor...",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		gObjCloseSet(aIndex,2);
	}
}
void CHAT_COMMANDS::ReloadCmd(short aIndex, char *msg){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int reload = atoi(msg);
	if(stricmp(&this->ReloadAtivo[0], "NAO") == 0)
	{
		sprintf_s(msN,"[%s] Comando Desabilitado. Consulte um Admin.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(gs_func.VerificarGM(aIndex) == false)
	{
		sprintf_s(msN,"[%s] Comando exclusivo apenas para GameMaster.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	if(strlen(msg) <= 1)
	{
		sprintf_s(msN,"[%s] Voce digitou mau o comando.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
		sprintf_s(msN,"[%s] Sintaxe do comando /%s <nº>.",gObj->Name,this->ReloadSintax);
		ServerMsgSend(msN,aIndex,1);
		sprintf_s(msN,"[%s] <nº 0> Configurações do plugin.dll.",gObj->Name,this->ReloadSintax);
		ServerMsgSend(msN,aIndex,1);
		sprintf_s(msN,"[%s] <nº 1> Configurações do Monster Position.",gObj->Name,this->ReloadSintax);
		ServerMsgSend(msN,aIndex,1);
		sprintf_s(msN,"[%s] <nº 2> Configurações do Shops.",gObj->Name,this->ReloadSintax);
		ServerMsgSend(msN,aIndex,1);
		sprintf_s(msN,"[%s] <nº 3> Configurações Options do GameServer.",gObj->Name,this->ReloadSintax);
		ServerMsgSend(msN,aIndex,1);
		return;
	}
	switch(reload)
	{
	case 0:
		gs_func.GameCustoms();
		gs_cmd.Settings();
		sprintf_s(msN,"[%s] Plugin.dll recarregada com sucesso.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
	break;
	case 1:
		AllMonsterReload();
		sprintf_s(msN,"[%s] Monstros recarregados com sucesso.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
	break;
	case 2:
		ShopReload();
		sprintf_s(msN,"[%s] Shops(0 - 10).txt recarregados com sucesso.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
	break;
	case 3:
		ConfigReload();
		sprintf_s(msN,"[%s] Configuracoes recarregadas com sucesso.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
	break;
	default:
		sprintf_s(msN,"[%s] Opção não existente.",gObj->Name);
		ServerMsgSend(msN,aIndex,1);
	break;
	}
}
void CHAT_COMMANDS::ChatRecv(short aIndex, LPBYTE aRecv){
	char GameServerInfo[]		= "serverinfo";

	if(!memcmp(aRecv,GameServerInfo,strlen(GameServerInfo)))
	{
		this->GameServerInfo(aIndex);
	}
	else if(!memcmp(aRecv,this->PostSintax,strlen(this->PostSintax)))
	{
		this->PostCmd(aIndex,(char*)(aRecv+strlen(this->PostSintax)));
	}
	else if(!memcmp(aRecv,this->ForSintax,strlen(this->ForSintax)))
	{
		this->AddPontosCmd(aIndex,(char*)(aRecv+strlen(this->ForSintax)),1);
	}
	else if(!memcmp(aRecv,this->AgiSintax,strlen(this->AgiSintax)))
	{
		this->AddPontosCmd(aIndex,(char*)(aRecv+strlen(this->AgiSintax)),2);
	}
	else if(!memcmp(aRecv,this->VitSintax,strlen(this->VitSintax)))
	{
		this->AddPontosCmd(aIndex,(char*)(aRecv+strlen(this->VitSintax)),3);
	}
	else if(!memcmp(aRecv,this->EneSintax,strlen(this->EneSintax)))
	{
		this->AddPontosCmd(aIndex,(char*)(aRecv+strlen(this->EneSintax)),4);
	}
	else if(!memcmp(aRecv,this->ExitSintax,strlen(this->ExitSintax)))
    {
		this->ExitCmd(aIndex,1);
	}
	else if(!memcmp(aRecv,this->CharSintax,strlen(this->CharSintax)))
    {
		this->ExitCmd(aIndex,2);
	}
	else if(!memcmp(aRecv,this->SListSintax,strlen(this->SListSintax)))
    {
		this->ExitCmd(aIndex,3);
	}
	else if(!memcmp(aRecv,this->ReloadSintax,strlen(this->ReloadSintax)))
	{
		this->ReloadCmd(aIndex,(char*)(aRecv+strlen(this->ReloadSintax)));
	}
}