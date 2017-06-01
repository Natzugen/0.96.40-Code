//===========================================================
// Development : MLM Team
// Coded : By Motto & MLM Team
// Versão : 0.97.04
// Protocol : Chs/Kor
//===========================================================

#include <windows.h>
#include "StdAfx.h"
#include "Struct.h"
#include "SQL.h"
#include "GameServer.h"
#include "Functions.h"
#include "Customs.h"
#include "User.h"
#include "Global.h"
#include "mapas.h"
#include "Defines.h"
#include <rpc.h>
#include <rpcdce.h>
#pragma comment(lib, "rpcrt4.lib")

SQL * GSSQL = new SQL;

bool MLMProtocolCore(BYTE protoNum,unsigned char* aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial);