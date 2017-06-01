#include "StdAfx.h"

void VIP(short aIndex)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	int SYSVIP = GetPrivateProfileInt("- CUSTOMS -", "_SISTEMA VIP - STATUS", 1, CHRISTYAN);
	int EXPVIP = GetPrivateProfileInt("- CUSTOMS -", "_SISTEMA VIP - EXP", 10000, CHRISTYAN);
	int DROPVIP = GetPrivateProfileInt("- CUSTOMS -", "_SISTEMA VIP - DROP", 100, CHRISTYAN);
	if(SYSVIP == 0)
	{
		return;
	}
	else if(GetFieldInt("MuOnline.dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",gObj->AccountID) == 0)
	{
		return;
	}
	else
	{
		gObj->m_wExprienceRate += EXPVIP;
		gObj->m_wDropRate += DROPVIP;
	}
}