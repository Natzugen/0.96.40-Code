#include "User.h"
#include "Defines.h"
#include "SQL.h"
#include "Struct.h"
#include "StdAfx.h"
#include <windows.h>
#include <stdio.h>

SQL * NSQL = new SQL;

static char Buffer[2048];
static char QuerySelectVip[200];

void PKClear(OBJECTSTRUCT* lpObj, OBJECTSTRUCT * lpNpc) {
	int IsPKClear = GetPrivateProfileIntA("NPC", "NPCPKClear", 1, MLMNPC);
	unsigned int PKClearZenReq = GetPrivateProfileIntA("NPC", "PKClearZenReq", 50, MLMNPC);
	PKClearZenReq = PKClearZenReq * lpObj->PK_Level;

	if (!IsPKClear) { return; }
	if (lpObj->PK_Level < 4) {
		ChatNpc(lpNpc, "Você não é PK!", lpObj->m_Index);
		//GCServerMsgStringSend("You are not PK!", lpObj->m_Index, 1);
		return;
	}
	if(lpObj->Money < PKClearZenReq) {
		char tmp[100];
		sprintf(tmp, "Falta %d kk de zen para você limpar seu PK!", (PKClearZenReq - lpObj->Money));
		ChatNpc(lpNpc, tmp, lpObj->m_Index);
		//GCServerMsgStringSend(tmp, lpObj->m_Index, 1);
		return;
	}
	lpObj->Money -= PKClearZenReq;
	lpObj->PK_Level = 3;
	//GCServerMsgStringSend("Wuola! You have cleared your PK.", lpObj->m_Index, 1);
	ChatNpc(lpNpc, "Pronto! Seu PK foi limpo com sucesso!", lpObj->m_Index);
	GCPKLevelSend(lpObj->m_Index,3);
	GCMoneySend(lpObj->m_Index, lpObj->Money);
}

//=====================================
// NPC de Reset 100% MLM Team
//=====================================
void ResetNPC(OBJECTSTRUCT* lpObj, OBJECTSTRUCT * lpNpc)
{
	char tmp[100];
	unsigned char i = NSQL->GetFieldInt("MuOnline.dbo.Character","resets","WHERE Name = '%s'",lpObj->Name);
	unsigned char isVip = NSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",lpObj->AccountID);

	if(isVip == 0)
	{
	if (lpObj->Level < configs.c_Reset.ResetLevelFree)
	{
		sprintf(tmp, "[FREE]Você não possui level necessário, falta %d level para resetar", configs.c_Reset.ResetLevelFree - lpObj->Level);
		ChatNpc(lpNpc, tmp, lpObj->m_Index);
		return;
	}
	if (lpObj->Money < configs.c_Reset.ResetPriceFree)
	{
		sprintf(tmp, "[FREE]Você não possui zen necessário, falta %d zen para resetar", (configs.c_Reset.ResetPriceFree - lpObj->Money));
		ChatNpc(lpNpc, tmp, lpObj->m_Index);
		return;
	}
	if (configs.c_Reset.ResetMode == 1)
	{
		sprintf_s(Buffer,"UPDATE MuOnline.dbo.Character SET resets = resets + 1 WHERE Name = '%s'",lpObj->Name);
		lpObj->Level = 1;
		lpObj->Experience = 0;
		lpObj->Money -= configs.c_Reset.ResetPriceFree;
		lpObj->LevelUpPoint += configs.c_Reset.ResetPontosFree;
		GCMoneySend(lpObj->m_Index,lpObj->Money);
	}
	if (configs.c_Reset.ResetMode == 2)
	{
		sprintf_s(Buffer,"UPDATE MuOnline.dbo.Character SET resets = resets + 1 WHERE Name = '%s'",lpObj->Name);
		lpObj->Level = 1;
		lpObj->Experience = 0;
		lpObj->Money -= configs.c_Reset.ResetPriceFree;
		lpObj->LevelUpPoint += configs.c_Reset.ResetPontosFree * i;
		lpObj->Strength = 20;
		lpObj->Dexterity = 20;
		lpObj->Vitality = 20;
		lpObj->Energy = 20;
		GCMoneySend(lpObj->m_Index,lpObj->Money);
	}
	}
	else if(isVip > 0)
	{
		if (lpObj->Level < configs.c_Reset.ResetLevelVip)
	{
		sprintf(tmp, "[FREE]Você não possui level necessário, falta %d level para resetar", configs.c_Reset.ResetLevelVip - lpObj->Level);
		ChatNpc(lpNpc, tmp, lpObj->m_Index);
		return;
	}
		if (lpObj->Money < configs.c_Reset.ResetPriceVip)
	{
		sprintf(tmp, "[FREE]Você não possui zen necessário, falta %d zen para resetar", (configs.c_Reset.ResetPriceVip - lpObj->Money));
		ChatNpc(lpNpc, tmp, lpObj->m_Index);
		return;
	}
	if (configs.c_Reset.ResetMode == 1)
	{
		sprintf_s(Buffer,"UPDATE MuOnline.dbo.Character SET resets = resets + 1 WHERE Name = '%s'",lpObj->Name);
		lpObj->Level = 1;
		lpObj->Experience = 0;
		lpObj->Money -= configs.c_Reset.ResetPriceVip;
		lpObj->LevelUpPoint += configs.c_Reset.ResetPontosVip;
		GCMoneySend(lpObj->m_Index,lpObj->Money);
	}
	if (configs.c_Reset.ResetMode == 2)
	{
		sprintf_s(Buffer,"UPDATE MuOnline.dbo.Character SET resets = resets + 1 WHERE Name = '%s'",lpObj->Name);
		lpObj->Level = 1;
		lpObj->Experience = 0;
		lpObj->Money -= configs.c_Reset.ResetPriceVip;
		lpObj->LevelUpPoint += configs.c_Reset.ResetPontosVip * i;
		lpObj->Strength = 20;
		lpObj->Dexterity = 20;
		lpObj->Vitality = 20;
		lpObj->Energy = 20;
		GCMoneySend(lpObj->m_Index,lpObj->Money);
	}
	}
	NSQL->Exec(Buffer);
	ChatNpc(lpNpc, "Você foi resetado com sucesso!! Deslogando..", lpObj->m_Index);
	gObjCloseSet(lpObj->m_Index,1);
}
void NPCTalk(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObj) {
	switch (lpNpc->Class) {
		case 234:  {
			PKClear(lpObj, lpNpc); return;
			break;
				   }
		case 249: {
			ResetNPC(lpObj, lpNpc); return;
			break;
				  }
	}

	NpcTalkEx(lpNpc, lpObj);
}