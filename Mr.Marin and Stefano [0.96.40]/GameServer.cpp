#include "GameServer.h"

OBJECTSTRUCT gObj[OBJECT_END];
SQL * GSQL = new SQL();

static char Exec[1024];

void HookNewOBJECTSTRUCT()
{
	for(int i = 0x401000; i < 0x508FFF; i++)
	{
		if( *(DWORD*)i >= OBJECT_BASE && *(DWORD*)i <= OBJECT_BASE+OBJECT_SIZE )
		{
			int Rest = *(DWORD*)i - OBJECT_BASE;
			*(DWORD*)i = (DWORD)&gObj + Rest;
		}
		if( *(WORD*)i == OBJECT_SIZE )
		{
			if(*(BYTE*)(i - 2) == 0x69)
			{
				*(WORD*)i = sizeof(OBJECTSTRUCT);
			}
		}
	}
}

void GCServerMsgStringSend(char *szMsg, int aIndex, BYTE type)
{
	GCSERVERMSGSTRUCT pMsg;

	pMsg.Enc = 0xC1;
	pMsg.Type = 0x0D;
	pMsg.MsgType = type;
	strcpy(pMsg.Notice,szMsg);
	pMsg.Size = 4+(strlen(pMsg.Notice)+1);

	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.Size);
}

void SetConnection(int aIndex)
{
	char Connect[137]; // 128 + gObj->Name - %s
	sprintf_s(Connect,configs.ConnectNotice,gObj[aIndex].Name);
	GCServerMsgStringSend(Connect,aIndex,0);
	gObj[aIndex].CtlCodeEx = GetSQL(1,aIndex);
	gObj[aIndex].VipLevel = GetSQL(0,aIndex);
	gObj[aIndex].Resets = GetSQL(2,aIndex);
}


int GetSQL(unsigned char Type, int aIndex)
{
	switch ( Type )
	{
	case 0:		// VIP Info
		return GSQL->GetFieldInt("dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",gObj[aIndex].AccountID);
		break;
	case 1:		// CtlCodeEx
		return GSQL->GetFieldInt("dbo.Character","CtlCode","WHERE Name = '%s'",gObj[aIndex].Name);
		break;
	case 2:		// Resets
		return GSQL->GetFieldInt("dbo.Character","Resets","WHERE Name = '%s'",gObj[aIndex].Name);
		break;
	case 3:		// Credits
		return GSQL->GetFieldInt("dbo.MEMB_INFO","Credits","WHERE memb___id = '%s'",gObj[aIndex].AccountID);
		break;
	default:
		return -1;
	}
}

void SetSQL(unsigned char Type, int aIndex)
{	
	switch ( Type )
	{
	case 0:		// VIP Info
		goto _SetSQLError;
		break;
	case 1:		// CtlCodeEx
		goto _SetSQLError;
		break;
	case 2:		// Resets
		sprintf_s(Exec,"UPDATE dbo.Character SET Resets = '%d' WHERE Name = '%s'",gObj[aIndex].Resets,gObj[aIndex].Name);
		break;
	case 3:
		sprintf_s(Exec,"UPDATE dbo.MEMB_INFO SET Credits = '%d' WHERE memb___id = '%s'",gObj[aIndex].Credits,gObj[aIndex].AccountID);
		break;
	default:
		goto _SetSQLError;
	}
	GSQL->Exec(Exec);
	return;

_SetSQLError:
	MsgBox("SetSQL(Type,aIndex)","int Type - Valor fora do limite (%d)",Type);
}