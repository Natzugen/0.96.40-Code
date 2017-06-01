#ifndef SETTING_H
#define SETTING_H
#include "StdAfx.h"

class CHAT_COMMANDS
{
public:
	void ChatRecv(short aIndex,LPBYTE aRecv);
	void GameServerInfo(int aIndex);
	void PostCmd(short aIndex,char * msg);
	void AddPontosCmd(int aIndex,LPCSTR lpBuffer,int Stat);
	void ExitCmd(int aIndex,unsigned int Tipo);
	void ReloadCmd(short aIndex,char * msg);

	char PostAtivo[100];
	char PostSintax[50];
	char PostFormato[50];
	unsigned int PostVip;
	unsigned int PostDinhero;
	unsigned int PostLevel;
	unsigned int PostCor;
	unsigned int PostReset;

	char AddAtivo[100];
	char ForSintax[50];
	char AgiSintax[50];
	char EneSintax[50];
	char VitSintax[50];
	unsigned int AddLevel;
	unsigned int AddDinhero;
	unsigned int AddMaxPontos;
	unsigned int MaxAddStatus;

	char ExitAtivo[100];
	char ExitSintax[50];
	char CharSintax[50];
	char SListSintax[50];

	char ReloadAtivo[100];
	char ReloadSintax[50];

	char ServerNome[160];
	char ConnectNotice[160];
	char ConnectNoticeGM[160];


	char SistemaVipAtivo[100];
	unsigned int VipSimplesExp;
	unsigned int VipSimplesDrop;
	unsigned int VipPremiumExp;
	unsigned int VipPremiumDrop;
	char UsuarioFree[200];
	char UsuarioVipSimples[200];
	char UsuarioVipPremium[200];

	char ReplayNoticiaAtivo[100];
	unsigned int ReplayNoticiaIn;
	char ReplayNoticia01[200];
	char ReplayNoticia02[200];
	char ReplayNoticia03[200];
	char ReplayNoticia04[200];

	void Settings();
};
extern CHAT_COMMANDS gs_cmd;

#endif


