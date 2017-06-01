#include "StdAfx.h"
#include "Include.h"

CHAT_COMMANDS gs_cmd;

void CHAT_COMMANDS::Settings(){

	GetPrivateProfileString(GAMESERVER,"Nome do servidor","[MU] Imperial Crusaders",gs_cmd.ServerNome,160,CFG_GAMESERVER);
	GetPrivateProfileString(GAMESERVER,"Noticia de conexão","Bem Vindo %s. Tenha um Bom Jogo",gs_cmd.ConnectNotice,160,CFG_GAMESERVER);
	GetPrivateProfileString(GAMESERVER,"Noticia de conexão de GM/ADM","[ADMIN] %s Online",gs_cmd.ConnectNoticeGM,160,CFG_GAMESERVER);

	GetPrivateProfileString(POSTCOMMAND,"Ativar comando </post>","SIM",this->PostAtivo,100,CFG_GAMESERVER);
	GetPrivateProfileString(POSTCOMMAND,"Sintax do Comando </post>","post",this->PostSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(POSTCOMMAND,"Formato ao exibir o comando </post>","[POST]%s",this->PostFormato,50,CFG_GAMESERVER);
	this->PostVip = GetPrivateProfileInt(POSTCOMMAND,"Ativar comando </post> exclusivo pra vip",1,CFG_GAMESERVER);
	this->PostDinhero = GetPrivateProfileInt(POSTCOMMAND,"Zen minimo para usar o comando </post>",5000,CFG_GAMESERVER);
	this->PostLevel = GetPrivateProfileInt(POSTCOMMAND,"Level minimo para usar o comando </post>",15,CFG_GAMESERVER);
	this->PostReset = GetPrivateProfileInt(POSTCOMMAND,"Reset minimo para usar o comando </post>",1,CFG_GAMESERVER);
	this->PostCor = GetPrivateProfileInt(POSTCOMMAND,"Cor do comando </post>",1,CFG_GAMESERVER);

	GetPrivateProfileString(ADDCOMMAND,"Ativar comando </addxxx>","SIM",this->AddAtivo,100,CFG_GAMESERVER);
	GetPrivateProfileString(ADDCOMMAND,"Sintax do Comando </addfor>","for",this->ForSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(ADDCOMMAND,"Sintax do Comando </addagi>","agi",this->AgiSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(ADDCOMMAND,"Sintax do Comando </addvit>","vit",this->VitSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(ADDCOMMAND,"Sintax do Comando </addene>","ene",this->EneSintax,50,CFG_GAMESERVER);
	this->AddDinhero = GetPrivateProfileInt(ADDCOMMAND,"Zen minimo para usar o comando </addxx>",5000,CFG_GAMESERVER);
	this->AddLevel = GetPrivateProfileInt(ADDCOMMAND,"Level minimo para usar o comando </addxx>",15,CFG_GAMESERVER);
	this->AddMaxPontos = GetPrivateProfileInt(ADDCOMMAND,"Maximo de pontos a adicionar </addxx>",32700,CFG_GAMESERVER);
	this->MaxAddStatus = GetPrivateProfileInt(ADDCOMMAND,"Quantidade maxima de pontos em status </addxx>",32767,CFG_GAMESERVER);

	GetPrivateProfileString(SAIRCOMMAND,"Ativar comando </sair>","SIM",this->ExitAtivo,100,CFG_GAMESERVER);
	GetPrivateProfileString(SAIRCOMMAND,"Sintax do comando </sair>","sair",this->ExitSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(SAIRCOMMAND,"Sintax do comando </selectchar>","selectchar",this->CharSintax,50,CFG_GAMESERVER);
	GetPrivateProfileString(SAIRCOMMAND,"Sintax do comando </servlist>","servlist",this->SListSintax,50,CFG_GAMESERVER);

	GetPrivateProfileString(GAMEMASTER,"Ativar comando </reload>","SIM",this->ReloadAtivo,100,CFG_GAMESERVER);
	GetPrivateProfileString(GAMEMASTER,"Sintax do Comando </reload>","reload",this->ReloadSintax,50,CFG_GAMESERVER);

	GetPrivateProfileString(SISTEMAVIP,"Ativar sistema vip Premium","SIM",this->SistemaVipAtivo,100,CFG_GAMESERVER);
	this->VipPremiumExp = GetPrivateProfileInt(SISTEMAVIP,"ExpRate para usuarios vip simples",5000,CFG_GAMESERVER);
	this->VipSimplesDrop = GetPrivateProfileInt(SISTEMAVIP,"DropRate para usuarios vip simples",5000,CFG_GAMESERVER);
	this->VipPremiumExp = GetPrivateProfileInt(SISTEMAVIP,"ExpRate para usuarios vip Premium",5000,CFG_GAMESERVER);
	this->VipPremiumDrop = GetPrivateProfileInt(SISTEMAVIP,"DropRate para usuarios vip Premium",5000,CFG_GAMESERVER);

	GetPrivateProfileString(SISTEMANOTICIA,"Ativar sistema de noticia","SIM",this->ReplayNoticiaAtivo,100,CFG_GAMESERVER);
	this->ReplayNoticiaIn = GetPrivateProfileInt(SISTEMANOTICIA,"Intervalo em minutos da noticia",1,CFG_GAMESERVER);
	GetPrivateProfileString(SISTEMANOTICIA,"Noticia Linha nº<01>","Se utilizar hacker,Seus chars serão bloqueados",this->ReplayNoticia01,200,CFG_GAMESERVER);
	GetPrivateProfileString(SISTEMANOTICIA,"Noticia Linha nº<02>","Nossa lista de char bloqueados está aumentado",this->ReplayNoticia02,200,CFG_GAMESERVER);
	GetPrivateProfileString(SISTEMANOTICIA,"Noticia Linha nº<03>","Não faça parte dela,Denucie em nosso site",this->ReplayNoticia03,200,CFG_GAMESERVER);
	GetPrivateProfileString(SISTEMANOTICIA,"Noticia Linha nº<04>","www.clgames.com.br Denucie agora mesmo",this->ReplayNoticia04,200,CFG_GAMESERVER);
}