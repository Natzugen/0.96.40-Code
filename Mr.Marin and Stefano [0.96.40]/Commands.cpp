#include "ChatCore.h"

static char Message[200];
void LoadCmdConfigs()
{
	char SECTION[32];
	// POST
	if(GetCmd(0,SECTION,32))
	{
		sprintf_s(SECTION,"POST");
		configs.c_post.price = GetPrivateProfileInt(SECTION,"Price",0,PATH_CMDS);
		configs.c_post.minLevel = GetPrivateProfileInt(SECTION,"Level",0,PATH_CMDS);
		GetPrivateProfileStringA(SECTION,"Format","[POST]: %s",configs.c_post.format,20,PATH_CMDS);
	}
	if(GetCmd(1,SECTION,32))
	{
		sprintf_s(SECTION,"ADD");
		configs.c_add.price = GetPrivateProfileInt(SECTION,"Price",0,PATH_CMDS);
		configs.c_add.maxPoint = GetPrivateProfileInt(SECTION,"Level",0,PATH_CMDS);
	}
	if(GetCmd(5,SECTION,32))
	{
		sprintf_s(SECTION,"PKCLEAR");
		configs.c_pkc.price = GetPrivateProfileInt(SECTION,"Price",0,PATH_CMDS);
		configs.c_pkc.minLevel = GetPrivateProfileInt(SECTION,"Level",0,PATH_CMDS);
		configs.c_pkc.isGM = GetPrivateProfileInt(SECTION,"GM",0,PATH_CMDS);
	}
}

void CommandPost(int aIndex, char * msg)
{
	if(gObj[aIndex].Level < configs.c_post.minLevel)
	{
		GetMsg(3,Message,200);
		Send.Normal(aIndex,Message,(configs.c_post.minLevel - gObj[aIndex].Level));
	}
	else if(gObj[aIndex].Money < configs.c_post.price)
	{
		GetMsg(4,Message,200);
		Send.Normal(aIndex,Message,(configs.c_post.price - gObj[aIndex].Money));
	}
	else
	{
		gObj[aIndex].Money -= configs.c_post.price;
		sprintf_s(Message,configs.c_post.format,msg);
		Send.Post(aIndex,Message);
		GCMoneySend(aIndex,gObj[aIndex].Money);
		LogAddExCmd(true,"[POST][%s][%s]: %s",gObj[aIndex].AccountID,gObj[aIndex].Name,msg);
	}
}

void CommandAdd(int aIndex,char Type, LPBYTE msg)
{
	if(msg[0] < 48 || msg[0] > 57)
		return;
	
	char Types[4][9] = {"STRENGTH","AGILITY","VITALITY","ENERGY"};

	unsigned int Points = atoi((char*)msg);

	if(gObj[aIndex].LevelUpPoint < Points)
	{
		GetMsg(5,Message,200);
		Send.Normal(aIndex,Message,(Points - gObj[aIndex].LevelUpPoint));
	}
	else if(gObj[aIndex].Level < configs.c_add.minLevel)
	{
		GetMsg(3,Message,200);
		Send.Normal(aIndex,Message,(configs.c_add.minLevel - gObj[aIndex].Level));
	}
	else if(gObj[aIndex].Money < configs.c_add.price)
	{
		GetMsg(4,Message,200);
		Send.Normal(aIndex,Message,(configs.c_add.price - gObj[aIndex].Money));
	}
	else
	{
		gObj[aIndex].Money -= configs.c_add.price;
		gObj[aIndex].LevelUpPoint -= Points;
		switch( Type )
		{
		case 0: // str
			gObj[aIndex].Strength += Points;
			break;
		case 1: // agi
			gObj[aIndex].Dexterity += Points;
			break;
		case 2: // vit
			gObj[aIndex].Vitality += Points;
			break;
		case 3: // ene
			gObj[aIndex].Energy += Points;
			break;
		}

		GetMsg(6,Message,200);
		Send.Normal(aIndex,Message,Points,Types[Type]);
		GCMoneySend(aIndex,gObj[aIndex].Money);
		sprintf_s(Message,"[ADD][%s][%s][%s]: %d Pontos",Types[Type],gObj[aIndex].AccountID,gObj[aIndex].Name,Points);
		LogAddExCmd(true,Message);

	}
}

void CommandPkClear(int aIndex)
{
	int Price = configs.c_pkc.price * gObj[aIndex].PkLevel;
	if(!isGM(aIndex) && configs.c_pkc.isGM > 0)
	{
		GetMsg(8,Message,200);
		Send.Normal(aIndex,Message);
	}
	else if(gObj[aIndex].PkLevel <= 3)
	{
		GetMsg(7,Message,200);
		Send.Normal(aIndex,Message);
	}
	else if(gObj[aIndex].Money < Price)
	{
		GetMsg(4,Message,200);
		Send.Normal(aIndex,Message,(Price - gObj[aIndex].Money));
	}
	else if(gObj[aIndex].Level < configs.c_pkc.minLevel)
	{
		GetMsg(3,Message,200);
		Send.Normal(aIndex,Message,(configs.c_pkc.minLevel - gObj[aIndex].Level));
	}
	else
	{
		gObj[aIndex].Money -= Price;

		gObj[aIndex].PkLevel = 3;
		gObj[aIndex].PkCount = 0;
		gObj[aIndex].PkTime = 0;

		GCPkLevelSend(aIndex,3);

		GetMsg(9,Message,200);
		Send.Normal(aIndex,Message);
		GCMoneySend(aIndex,gObj[aIndex].Money);
	}
	LogAddExCmd(true,"[PKCLEAR][%s][%s] Result = %s",gObj[aIndex].AccountID,gObj[aIndex].Name,Message);
}