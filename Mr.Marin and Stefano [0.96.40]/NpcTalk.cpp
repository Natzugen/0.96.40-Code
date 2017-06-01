#include "GameServer.h"
#include "User.h"

static char Message[200];

bool NpcTalkEx(int aIndex, int nIndex)
{
	unsigned short Class = gObj[nIndex].Class;
	if(configs.NpcSpeak[gObj[nIndex].Class] > 0)
	{
		GetMsg(configs.NpcSpeak[Class],Message,200);
		Send.Normal(aIndex,Message);
	}

#pragma region Shops com Level
	if(configs.useShopAccess != 0 && gObj[nIndex].Class >= 230 && gObj[nIndex].Class < 255)
	{
		if(gObj[nIndex].ShopNumberEx == 0)
		{
			switch ( Class )
			{
			case 251:
				gObj[nIndex].ShopNumberEx = 0;
				break;
			case 255:
				gObj[nIndex].ShopNumberEx = 1;
				break;
			case 254:
				gObj[nIndex].ShopNumberEx = 2;
				break;
			case 250:
				gObj[nIndex].ShopNumberEx = 3;
				break;
			case 248:
				gObj[nIndex].ShopNumberEx = 4;
				break;
			case 239:
			case 253:
				gObj[nIndex].ShopNumberEx = 5;
				break;
			case 244:
				gObj[nIndex].ShopNumberEx = 6;
				break;
			case 245:
				gObj[nIndex].ShopNumberEx = 7;
				break;
			case 246:
				gObj[nIndex].ShopNumberEx = 8;
				break;
			case 243:
				gObj[nIndex].ShopNumberEx = 9;
				break;
			case 242:
				gObj[nIndex].ShopNumberEx = 10;
				break;
			case 230:
				gObj[nIndex].ShopNumberEx = 11;
				break;
			case 232:
				gObj[nIndex].ShopNumberEx = 12;
				break;
			default:
				gObj[nIndex].ShopNumberEx = -1;
			}
		}
		if(gObj[nIndex].ShopNumberEx >= 0)
		{
			int ShopLevel = configs.ShopAccess[gObj[nIndex].ShopNumberEx];
			if(ShopLevel != 0)
			{
				if(ShopLevel >= 32)
				{
					if(!isGM(aIndex))
					{
						GetMsg(0,Message,200);
						Send.Normal(aIndex,Message,gObj[aIndex].Name);
						return true;
					}
				}
				else
				{
					if(gObj[aIndex].VipLevel < ShopLevel)
					{
						GetMsg(1,Message,200);
						Send.Normal(aIndex,Message,gObj[aIndex].Name,ShopLevel);
						return true;
					}
				}
			}
			else
				return false;
		}
	}
#pragma endregion

#pragma region NPC de PkClear
	if(configs.n_pkc.Active >= 0							&&
		configs.n_pkc.Class == gObj[nIndex].Class			&&
		configs.n_pkc.coords[MAP] == gObj[nIndex].MapNumber &&
		configs.n_pkc.coords[POSX] == gObj[nIndex].X		&&
		configs.n_pkc.coords[POSY] == gObj[nIndex].Y)
	{
		NPCPkClear(aIndex);
		return true;
	}
#pragma endregion
#pragma region NPC de Reset
	if( configs.n_res.Active >= 0					&&
		gObj[nIndex].Class == configs.n_res.Class	&&
		gObj[nIndex].X == configs.n_res.coords[POSX]&&
		gObj[nIndex].Y == configs.n_res.coords[POSY]&&
		gObj[nIndex].MapNumber == configs.n_res.coords[MAP])
	{
		NPCReset(aIndex);
		return true;
	}
#pragma endregion

	return false;
}


void NPCPkClear(int aIndex)
{
	int Price = configs.n_pkc.price * gObj[aIndex].PkLevel;
	if(gObj[aIndex].PkLevel <= 3)
	{
		GetMsg(7,Message,200);
		Send.Normal(aIndex,Message);
	}
	else if(gObj[aIndex].Money < Price)
	{
		GetMsg(4,Message,200);
		Send.Normal(aIndex,Message,(Price - gObj[aIndex].Money));
	}
	else if(gObj[aIndex].Level < configs.n_pkc.minLevel)
	{
		GetMsg(4,Message,200);
		Send.Normal(aIndex,Message,(configs.n_pkc.minLevel - gObj[aIndex].Level));
	}
	else
	{
		gObj[aIndex].Money -= Price;
		gObj[aIndex].PkLevel = 3;
		gObj[aIndex].PkTime = 0;
		gObj[aIndex].PkCount = 0;

		GCMoneySend(aIndex, gObj[aIndex].Money);
		GCPkLevelSend(aIndex,3);
		GetMsg(9,Message,200);
		Send.Normal(aIndex,Message);
	}
}


void NPCReset(int aIndex)
{
	OBJECTSTRUCT * lpObj = &gObj[aIndex];
	unsigned int Multiplier = 1;
	unsigned int VipLevel = lpObj->VipLevel;
	if(configs.n_res.zMode == 1)
		Multiplier = lpObj->Resets;

	if(lpObj->Level < configs.n_res.rLevel[VipLevel])
	{
		GetMsg(11,Message,200);
		Send.Normal(aIndex,Message,(configs.n_res.rLevel[VipLevel] - lpObj->Level));
		return;
	}
	else if(lpObj->Money < configs.n_res.rPrice[VipLevel] * Multiplier)
	{
		GetMsg(12,Message,200);
		Send.Normal(aIndex,Message,
			(configs.n_res.rPrice[VipLevel] * Multiplier - lpObj->Money));
	}
	else
	{
		lpObj->Level = 1;
		lpObj->Money -= configs.n_res.rPrice[VipLevel] * Multiplier;
		if(configs.n_res.rMode == 1)
		{
			BYTE ClassCode = (BYTE)lpObj->Class/16;
			lpObj->Strength = configs.n_res.t_stats[VipLevel][ClassCode][STR];
			lpObj->Dexterity = configs.n_res.t_stats[VipLevel][ClassCode][AGI];
			lpObj->Energy = configs.n_res.t_stats[VipLevel][ClassCode][ENE];
			lpObj->Vitality = configs.n_res.t_stats[VipLevel][ClassCode][VIT];
		}

		if(configs.n_res.pMode == 0)
		{
			lpObj->LevelUpPoint = configs.n_res.rPoint[VipLevel];
		}
		else if(configs.n_res.pMode == 1)
		{
			lpObj->LevelUpPoint += configs.n_res.rPoint[VipLevel];
		}
		else
		{
			lpObj->LevelUpPoint = configs.n_res.rPoint[VipLevel] * lpObj->Resets;
		}
		lpObj->Resets = lpObj->Resets + 1;

		SetSQL(2,aIndex);

		gObjCloseSet(aIndex,1);
	}
}