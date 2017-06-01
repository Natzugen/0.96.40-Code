#include "Struct.h"
#include "StdAfx.h"
#include "Defines.h"
#include "Global.h"

GS_STRUCT configs;

void Carrega()
{
	// SQL CONNECTION
	GetPrivateProfileString("SQLCONNECTION","SQLAccount","sa",configs.sql.access,strlen(configs.sql.access),MLMCUS1);
	GetPrivateProfileString("SQLCONNECTION","SQLPassword","sa",configs.sql.dbpass,strlen(configs.sql.dbpass),MLMCUS1);
	GetPrivateProfileString("SQLCONNECTION","SQLDataBase","MuOnline",configs.sql.dbpass,strlen(configs.sql.dbname),MLMCUS1);
	GetPrivateProfileString("SQLCONNECTION","SQLServer","127.0.0.1",configs.sql.server,strlen(configs.sql.server),MLMCUS1);

	// ConnectNotice
	configs.c_Notice1.Active = GetPrivateProfileInt("MENSAGEM","ActiveNotice",1,MLMMESS);
	if(configs.c_Notice1.Active > 0)
	{
		GetPrivateProfileString("MENSAGEM","ConnectNotice","Bem Vindo ao MLMServer 97D",configs.c_Notice1.ConnectNotice,150,MLMMESS);
		GetPrivateProfileString("MENSAGEM","ConnectNotice2","Bem Vindo %s ao MLMServer 97D! Divirta-se!",configs.c_Notice1.ConnectNotice2,150,MLMMESS);
	}
	// NPC Reset
	configs.c_Reset.ResetActive = GetPrivateProfileInt("NPC","NPCReset",1,MLMNPC);
	if(configs.c_Reset.ResetActive > 0)
	{
		configs.c_Reset.ResetMode = GetPrivateProfileInt("NPC","NPCResetMode",0,MLMNPC);
		configs.c_Reset.ResetLevelFree = GetPrivateProfileInt("NPC","NPCResetLevelFree",0,MLMNPC);
		configs.c_Reset.ResetPriceFree = GetPrivateProfileInt("NPC","NPCResetPriceFree",0,MLMNPC);
		configs.c_Reset.ResetPontosFree = GetPrivateProfileInt("NPC","NPCResetPontosFree",0,MLMNPC);
		configs.c_Reset.ResetLevelVip = GetPrivateProfileInt("NPC","NPCResetLevelVip",0,MLMNPC);
		configs.c_Reset.ResetPriceVip = GetPrivateProfileInt("NPC","NPCResetPriceVip",0,MLMNPC);
		configs.c_Reset.ResetPontosVip = GetPrivateProfileInt("NPC","NPCResetPontosVip",0,MLMNPC);
	}
	// NPC PkClear
	configs.c_PkClear.PkClearActive = GetPrivateProfileInt("NPC","NPCPKClear",0,MLMNPC);
	if(configs.c_PkClear.PkClearActive > 0)
	{
		configs.c_PkClear.PkClearZenFree = GetPrivateProfileInt("NPC","PKClearZenFree",0,MLMNPC);
		configs.c_PkClear.PkClearZenVip = GetPrivateProfileInt("NPC","PKClearVipZenVip",0,MLMNPC);
	}
	// Post
	configs.c_Post.PostActive = GetPrivateProfileInt("COMANDOS","PostActive",0,MLMCOM);
	if(configs.c_Post.PostActive > 0)
	{
		configs.c_Post.PostLevel = GetPrivateProfileInt("COMANDOS","PostLevel",0,MLMCOM);
		configs.c_Post.PostReset = GetPrivateProfileInt("COMANDOS","PostReset",0,MLMCOM);
		configs.c_Post.PostTime = GetPrivateProfileInt("COMANDOS","PostTime",0,MLMCOM);
		configs.c_Post.PostZenReq = GetPrivateProfileInt("COMANDOS","PostZenReq",0,MLMCOM);
	}
	// add
	configs.c_Add.AddActive = GetPrivateProfileInt("COMANDOS","AddActive",0,MLMCOM);
	if(configs.c_Add.AddActive > 0)
	{
		configs.c_Add.AddLevel = GetPrivateProfileInt("COMANDOS","AddLevel",0,MLMCOM);
		configs.c_Add.AddMaxPoint = GetPrivateProfileInt("COMANDOS","AddMaxPoints",0,MLMCOM);
		configs.c_Add.AddPrice = GetPrivateProfileInt("COMANDOS","AddZenReq",0,MLMCOM);
	}
	// Reload
	configs.c_Reload.Active = GetPrivateProfileInt("COMANDOS","ReloadActive",0,MLMCOM);
	if(configs.c_Reload.Active > 0)
	{
		configs.c_Reload.OnlyGM = GetPrivateProfileInt("COMANDOS","ReloadCode",8,MLMCOM);
	}
	// Moves Devias2
	configs.c_MoveD2.Active = GetPrivateProfileInt("MOVES","MoveDevias2",0,MLMMOV);
	if(configs.c_MoveD2.Active > 0)
	{
		configs.c_MoveD2.MinLevel = GetPrivateProfileInt("MOVES","Devias2Level",0,MLMMOV);
		configs.c_MoveD2.Price = GetPrivateProfileInt("MOVES","Devias2ZenReq",0,MLMMOV);
	}
	// Move Devias3
	configs.c_D3Move.Active = GetPrivateProfileInt("MOVES","MoveDevias3",0,MLMMOV);
	if(configs.c_D3Move.Active > 0)
	{
		configs.c_D3Move.MinLevel = GetPrivateProfileInt("MOVES","Devias3Level",0,MLMMOV);
		configs.c_D3Move.Price = GetPrivateProfileInt("MOVES","Devias3ZenReq",0,MLMMOV);
	}
	// Move Atlans2
	configs.c_A2Move.Active = GetPrivateProfileInt("MOVES","MoveAtlans2",0,MLMMOV);
	if(configs.c_A2Move.Active > 0)
	{
		configs.c_A2Move.MinLevel = GetPrivateProfileInt("MOVES","Atlans2Level",0,MLMMOV);
		configs.c_A2Move.Price = GetPrivateProfileInt("MOVES","Atlans2ZenReq",0,MLMMOV);
	}
	// Move Atlans3
	configs.c_A3Move.Active = GetPrivateProfileInt("MOVES","MoveAtlans3",0,MLMMOV);
	if(configs.c_A3Move.Active > 0)
	{
		configs.c_A3Move.MinLevel = GetPrivateProfileInt("MOVES","Atlans3Level",0,MLMMOV);
		configs.c_A3Move.Price = GetPrivateProfileInt("MOVES","Atlans3ZenReq",0,MLMMOV);
	}
	//Move Tarkan2
	configs.c_T2Move.Active = GetPrivateProfileInt("MOVES","MoveTarkan2",0,MLMMOV);
	if(configs.c_T2Move.Active > 0)
	{
		configs.c_T2Move.MinLevel = GetPrivateProfileInt("MOVES","Tarkan2Level",0,MLMMOV);
		configs.c_T2Move.Price = GetPrivateProfileInt("MOVES","Tarkan2ZenReq",0,MLMMOV);
	}
	//Move Icarus
	configs.c_IcaMove.Active = GetPrivateProfileInt("MOVES","MoveIcarus",0,MLMMOV);
	if(configs.c_IcaMove.Active > 0)
	{
		configs.c_IcaMove.MinLevel = GetPrivateProfileInt("MOVES","IcarusLevel",0,MLMMOV);
		configs.c_IcaMove.Price = GetPrivateProfileInt("MOVES","IcarusZenReq",0,MLMMOV);
	}
	//Move Valley
	configs.c_ValeMove.Active = GetPrivateProfileInt("MOVES","MoveValley",0,MLMMOV);
	if(configs.c_ValeMove.Active > 0)
	{
		configs.c_ValeMove.MinLevel = GetPrivateProfileInt("MOVES","ValleyLevel",0,MLMMOV);
		configs.c_ValeMove.Price = GetPrivateProfileInt("MOVES","ValleyZenReq",0,MLMMOV);
	}
	//Move DareDevil
	configs.c_DareMove.Active = GetPrivateProfileInt("MOVES","MoveDare",0,MLMMOV);
	if(configs.c_DareMove.Active > 0)
	{
		configs.c_DareMove.Vip = GetPrivateProfileInt("MOVES","DareVips",0,MLMMOV);
		configs.c_DareMove.MinLevel = GetPrivateProfileInt("MOVES","DareLevel",0,MLMMOV);
		configs.c_DareMove.Price = GetPrivateProfileInt("MOVES","DareZenReq",0,MLMMOV);
	}
	// PkSet
	configs.c_PkSet.Active = GetPrivateProfileInt("COMANDOS","PkSetActive",0,MLMCOM);
	if(configs.c_PkSet.Active > 0)
	{
		configs.c_PkSet.CodeS = GetPrivateProfileInt("COMANDOS","PkSetCode",8,MLMCOM);
	}
	// Site
	configs.c_Site.Active = GetPrivateProfileInt("COMANDOS","SiteActive",0,MLMCOM);
	if(configs.c_Site.Active > 0)
	{
		GetPrivateProfileString("MENSAGEM","SiteMessage","www.mlmteam.dahora.net",Site,100,MLMMESS);
	}
	// Hora
	configs.c_Hora.Active = GetPrivateProfileInt("COMANDOS","HoraActive",0,MLMCOM);
	// Skin
	configs.c_Skin.Active = GetPrivateProfileInt("COMANDOS","SkinActive",0,MLMCOM);
	if(configs.c_Skin.Active > 0)
	{
		configs.c_Skin.CodeS = GetPrivateProfileInt("COMANDOS","SkinCode",8,MLMCOM);
	}
	//Ban
	configs.c_Ban.Active = GetPrivateProfileInt("COMANDOS","BanActive",0,MLMCOM);
	if(configs.c_Ban.Active > 0)
	{
		configs.c_Ban.CodeS = GetPrivateProfileInt("COMANDOS","BanCode",8,MLMCOM);
	}
	//UnBan
	configs.c_UnBan.Active = GetPrivateProfileInt("COMANDOS","UnBanActive",0,MLMCOM);
	if(configs.c_UnBan.Active > 0)
	{
		configs.c_UnBan.CodeS = GetPrivateProfileInt("COMANDOS","UnBanCode",8,MLMCOM);
	}
	//MoveAll
	configs.MoveAllCmd = GetPrivateProfileInt("COMANDOS","MoveAllActive",500,MLMCOM);
	// Sistema de Resets
	configs.c_SisIni.Active = GetPrivateProfileInt("SYSTEM","RSystemActive",0,MLMSIS);
	if(configs.c_SisIni.Active > 0)
	{
		configs.c_SisIni.ResetsA = GetPrivateProfileInt("SYSTEM","RSystemResets",0,MLMSIS);
	}
	//vip system
	configs.expvip = GetPrivateProfileInt("SYSTEM","ExperienciaVip",100,MLMSIS);
	configs.dropvip = GetPrivateProfileInt("SYSTEM","DropVip",100,MLMSIS);
}