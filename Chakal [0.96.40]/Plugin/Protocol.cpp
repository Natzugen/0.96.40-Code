#include "StdAfx.h"
#include "Include.h"
void ProtocolCoreEx(BYTE protoNum,LPBYTE aRecv,DWORD aLen,short aIndex,DWORD Encrypt,int Serial)
{
	switch( protoNum )
	{
	case CHAT_RECV:
		gs_cmd.ChatRecv(aIndex,(LPBYTE)(aRecv+14));
		break;
	case CHAT_WISP:
		break;
	case ENTER_MAP:
		in_game.InGame(aIndex);
		break;
	case NPC_CLICK:
		break;
	}
	return DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
}