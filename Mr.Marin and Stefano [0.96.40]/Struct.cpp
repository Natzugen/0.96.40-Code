#include "Struct.h"
#include <windows.h>
#include <stdio.h>

GSCONFIGS configs;
bool Load()
{
	char SECTION[16];
	char String[20];
#pragma region Carrega configs do SQL
	{
		sprintf_s(SECTION,"SQL");
		GetPrivateProfileStringA(SECTION,"Account","sa",configs.sql.User,64,PATH_CONFIGS);
		GetPrivateProfileStringA(SECTION,"Password","sa",configs.sql.Pass,64,PATH_CONFIGS);
		GetPrivateProfileStringA(SECTION,"DataBase","MuOnline",configs.sql.DbName,30,PATH_CONFIGS);
		GetPrivateProfileStringA(SECTION,"Server","127.0.0.1",configs.sql.Server,128,PATH_CONFIGS);
	}
#pragma endregion
#pragma region Carrega Configs básicas
	{
		sprintf_s(SECTION,"GAMESERVER");
		GetPrivateProfileString(SECTION,"ConnectNotice","Bem vindo %s",configs.ConnectNotice,128,PATH_CONFIGS);
		configs.isLogAdd[0] = GetPrivateProfileInt(SECTION,"AddDllLog",1,PATH_CONFIGS);
		configs.isLogAdd[1] = GetPrivateProfileInt(SECTION,"AddCmdLog",1,PATH_CONFIGS);
		configs.isLogAdd[2] = GetPrivateProfileInt(SECTION,"AddNpcLog",1,PATH_CONFIGS);
		configs.isLogAdd[3] = GetPrivateProfileInt(SECTION,"AddSqlLog",1,PATH_CONFIGS);
	}
#pragma endregion
#pragma region Carrega configs dos Shops
	{
		sprintf_s(SECTION,"ShopLevelConfig");
		configs.useShopAccess = GetPrivateProfileInt(SECTION,"Active",1,PATH_NPCS);
		if(configs.useShopAccess != 0)
		{
			for(int i = 0; i < MAX_SHOPS; i++)
			{
				sprintf_s(String,"Shop%d",i);
				configs.ShopAccess[i] = GetPrivateProfileInt(SECTION,String,0,PATH_NPCS);
			}
		}
	}
#pragma endregion
#pragma region Carrega Falas dos NPCs
	{
		sprintf_s(SECTION,"NpcTalk");
		configs.useNpcSpeak = GetPrivateProfileInt(SECTION,"Active",1,PATH_MSGS);
		if(configs.useNpcSpeak != 0)
		{
			for(int i = 0; i < MAX_NPCID; i++)
			{
				sprintf_s(String,"Npc%d",i);
				int is = GetPrivateProfileInt(SECTION,String,0,PATH_MSGS);
				if(is != 0)
				{
					configs.NpcSpeak[i] = is;
				}
			}
		}
	}
#pragma endregion
#pragma region Carrega o NPC de PkCLear
	{
		sprintf_s(SECTION,"PKCLEAR");
		configs.n_pkc.Active = GetPrivateProfileInt(SECTION,"Active",1,PATH_NPCS);
		if(configs.n_pkc.Active != 0)
		{
			configs.n_pkc.minLevel = GetPrivateProfileInt(SECTION,"Level",0,PATH_NPCS);
			configs.n_pkc.price = GetPrivateProfileInt(SECTION,"Price",0,PATH_NPCS);
			configs.n_pkc.coords[POSX] = GetPrivateProfileInt(SECTION,"NpcX",0,PATH_NPCS);
			configs.n_pkc.coords[POSY] = GetPrivateProfileInt(SECTION,"NpcY",0,PATH_NPCS);
			configs.n_pkc.coords[MAP] = GetPrivateProfileInt(SECTION,"NpcMap",0,PATH_NPCS);
			configs.n_pkc.Class = GetPrivateProfileInt(SECTION,"NpcClass",0,PATH_NPCS);
		}
	}
#pragma endregion
#pragma region Carrega o NPC de Reset
	{
		sprintf_s(SECTION,"RESET");
		configs.n_res.Active = GetPrivateProfileInt(SECTION,"Active",0,PATH_NPCS);
		if(configs.n_res.Active != 0)
		{
			char Temp[26];
			configs.n_res.Class = GetPrivateProfileInt(SECTION,"NpcClass",0,PATH_NPCS);
			configs.n_res.coords[MAP] = GetPrivateProfileInt(SECTION,"NpcMap",0,PATH_NPCS);
			configs.n_res.coords[POSX] = GetPrivateProfileInt(SECTION,"NpcX",0,PATH_NPCS);
			configs.n_res.coords[POSY] = GetPrivateProfileInt(SECTION,"NpcY",0,PATH_NPCS);
			configs.n_res.Types = GetPrivateProfileInt(SECTION,"Types",0,PATH_NPCS);
			configs.n_res.rMode = GetPrivateProfileInt(SECTION,"ResetType",0,PATH_NPCS);
			configs.n_res.zMode = GetPrivateProfileInt(SECTION,"PriceType",0,PATH_NPCS);
			configs.n_res.pMode = GetPrivateProfileInt(SECTION,"PointType",0,PATH_NPCS);
			for(int i = 0; i < configs.n_res.Types; i++)
			{
				sprintf_s(String,"ResetPrice%d",i);
				configs.n_res.rPrice[i] = GetPrivateProfileInt(SECTION,String,0,PATH_NPCS);

				sprintf_s(String,"ResetLevel%d",i);
				configs.n_res.rLevel[i] = GetPrivateProfileInt(SECTION,String,400,PATH_NPCS);

				sprintf_s(String,"ResetPoints%d",i);
				configs.n_res.rPoint[i] = GetPrivateProfileInt(SECTION,String,0,PATH_NPCS);

				sprintf_s(String,"ResetedStatDW%d",i);
				GetPrivateProfileStringA(SECTION,String,"0 0 0 0",Temp,26,PATH_NPCS);
				sscanf_s(Temp,"%d %d %d %d",
					&configs.n_res.t_stats[i][DW][STR],
					&configs.n_res.t_stats[i][DW][AGI],
					&configs.n_res.t_stats[i][DW][VIT],
					&configs.n_res.t_stats[i][DW][ENE]);

				sprintf_s(String,"ResetedStatDK%d",i);
				GetPrivateProfileStringA(SECTION,String,"0 0 0 0",Temp,26,PATH_NPCS);
				sscanf_s(Temp,"%d %d %d %d",
					&configs.n_res.t_stats[i][DK][STR],
					&configs.n_res.t_stats[i][DK][AGI],
					&configs.n_res.t_stats[i][DK][VIT],
					&configs.n_res.t_stats[i][DK][ENE]);
				
				sprintf_s(String,"ResetedStatELF%d",i);
				GetPrivateProfileStringA(SECTION,String,"0 0 0 0",Temp,26,PATH_NPCS);
				sscanf_s(Temp,"%d %d %d %d",
					&configs.n_res.t_stats[i][ELF][STR],
					&configs.n_res.t_stats[i][ELF][AGI],
					&configs.n_res.t_stats[i][ELF][VIT],
					&configs.n_res.t_stats[i][ELF][ENE]);
				
				sprintf_s(String,"ResetedStatMG%d",i);
				GetPrivateProfileStringA(SECTION,String,"0 0 0 0",Temp,26,PATH_NPCS);
				sscanf_s(Temp,"%d %d %d %d",
					&configs.n_res.t_stats[i][MG][STR],
					&configs.n_res.t_stats[i][MG][AGI],
					&configs.n_res.t_stats[i][MG][VIT],
					&configs.n_res.t_stats[i][MG][ENE]);
			}
		}
	}
#pragma endregion
#pragma region Carrega Configs do GS
	{
		int MaxLevel = GetPrivateProfileInt("GAMESERVER","MaxLevel",350,PATH_CONFIGS);
		if(MaxLevel > 32766 || MaxLevel < 1) MaxLevel = 350;
		*(WORD*)MaxLevel1 = (BYTE)MaxLevel;
		*(WORD*)MaxLevel2 = (BYTE)MaxLevel;
		*(WORD*)MaxLevel3 = (BYTE)MaxLevel;
		*(WORD*)MaxLevel4 = (BYTE)MaxLevel;
		// End Max Level ^^
		*(DWORD*)UDPPort = GetPrivateProfileInt("GAMESERVER","UDPPort",60006,PATH_CONFIGS);
		// End UDP Port ^^
		sprintf_s(SECTION,"RINGS");
		*(DWORD*)TRing1 = GetPrivateProfileInt(SECTION,"TransformRing1",2,PATH_CONFIGS);
		*(DWORD*)TRing2 = GetPrivateProfileInt(SECTION,"TransformRing2",7,PATH_CONFIGS);
		*(DWORD*)TRing3 = GetPrivateProfileInt(SECTION,"TransformRing3",14,PATH_CONFIGS);
		*(DWORD*)TRing4 = GetPrivateProfileInt(SECTION,"TransformRing4",8,PATH_CONFIGS);
		*(DWORD*)TRing5 = GetPrivateProfileInt(SECTION,"TransformRing5",9,PATH_CONFIGS);
		*(DWORD*)TRing6 = GetPrivateProfileInt(SECTION,"TransformRing6",41,PATH_CONFIGS);
		// End Transform Rings ^^	
		sprintf_s(SECTION,"POTIONS");
		*(BYTE*)Potions1 = (BYTE)GetPrivateProfileInt(SECTION,"AppleRegenRate",10,PATH_CONFIGS);
		*(BYTE*)Potions2 = (BYTE)GetPrivateProfileInt(SECTION,"SmallHpRegenRate",20,PATH_CONFIGS);
		*(BYTE*)Potions3 = (BYTE)GetPrivateProfileInt(SECTION,"MedHpRegenRate",30,PATH_CONFIGS);
		*(BYTE*)Potions4 = (BYTE)GetPrivateProfileInt(SECTION,"LargeHpRegenRate",40,PATH_CONFIGS);
		*(BYTE*)Potions5 = (BYTE)GetPrivateProfileInt(SECTION,"SmallMpRegenRate",20,PATH_CONFIGS);
		*(BYTE*)Potions6 = (BYTE)GetPrivateProfileInt(SECTION,"MedMpRegenRate",30,PATH_CONFIGS);
		*(BYTE*)Potions7 = (BYTE)GetPrivateProfileInt(SECTION,"LargeMpRegenRate",40,PATH_CONFIGS);
		// End Potions ^^
		sprintf_s(SECTION,"PRICES");
		*(DWORD*)Prices1 = GetPrivateProfileInt(SECTION,"Fruits",330000000,PATH_CONFIGS);
		*(DWORD*)Prices2 = GetPrivateProfileInt(SECTION,"BlueFeather",180000,PATH_CONFIGS);
		*(DWORD*)Prices3 = GetPrivateProfileInt(SECTION,"Dinorant",960000,PATH_CONFIGS);
		*(DWORD*)Prices4 = GetPrivateProfileInt(SECTION,"JewelofChaos",810000,PATH_CONFIGS);
		*(DWORD*)Prices5 = GetPrivateProfileInt(SECTION,"JewelofSoul",6000000,PATH_CONFIGS);
		*(DWORD*)Prices6 = GetPrivateProfileInt(SECTION,"JewelofBless",9000000,PATH_CONFIGS);
		*(DWORD*)Prices7 = GetPrivateProfileInt(SECTION,"JewelofCreation",36000000,PATH_CONFIGS);
		*(DWORD*)Prices8 = GetPrivateProfileInt(SECTION,"JewelofLife",45000000,PATH_CONFIGS);
		// End Prices ^^
	}
#pragma endregion
	return true;
}

void GetMsg(int MsgNumber, char * Return, unsigned short Size)
{
	char Msg[8];
	sprintf_s(Msg,"Msg%d",MsgNumber);
	GetPrivateProfileString("Messages",Msg," ",Return,Size,PATH_MSGS);
}

bool GetCmd(int CmdNumber, char * Return, unsigned short Size)
{
	char Cmd[8];
	sprintf_s(Cmd,"isCmd%d",CmdNumber);
	if(GetPrivateProfileInt("Commands",Cmd,1,PATH_CMDS) != 0)
	{
		sprintf_s(Cmd,"Cmd%d",CmdNumber);
		GetPrivateProfileStringA("Commands",Cmd," ",Return,Size,PATH_CMDS);
		return true;
	}
	else
		return false;
}