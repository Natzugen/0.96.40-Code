#include "ChatCore.h"

#define MAX_CMDS 8

void ChatRecv(DWORD aIndex,LPBYTE Protocol)
{
	if((char)Protocol[13] == '/')
	{
		char Cmd[12];
		char Message[200];
		char Range = 0;
		if((char)Protocol[14] == 'g' && (char)Protocol[15] == 'm')
		{
			if(!isGM(aIndex))
			{
				GetMsg(8,Message,200);
				Send.Normal(aIndex,Message);
				return;
			}
			else
				Range = 64;
		}
		for(char i = 0 + Range; i < MAX_CMDS + Range; i++)
		{
			if(GetCmd(i,Cmd,12))
			{
				if(!memcmp(&Protocol[13],Cmd,strlen(Cmd)))
				{
					char Add = strlen(Cmd) + 14;
					if(!CommandSwitch(aIndex,Protocol+Add,i))
					{
						GetMsg(2,Message,200);
						Send.Normal(aIndex,Message);
						return;
					}
				}
			}
		}
		if(!memcmp(&Protocol[13],"/serverinfo",11))
		{
			Send.Announce(aIndex,"GameServer 0.97D por Mr.MariN");
			Send.Announce(aIndex,"Baseado em Source Code Vazado");
			Send.Announce(aIndex,"na internet, espalhado por Hellboy");
			Send.Announce(aIndex,"Respeitem os coders de verdade!");
		}
	}
}

bool CommandSwitch(DWORD aIndex,BYTE * Protocol,BYTE CmdIndex)
{
	switch ( CmdIndex )
	{
	case 0: // /post
		{
			CommandPost(aIndex,(char*)Protocol);
			return true;
		}
		break;
	case 1: // /addstr
		{
			CommandAdd(aIndex,0,Protocol);
			return true;
		}
		break;
	case 2: // /addagi
		{
			CommandAdd(aIndex,1,Protocol);
			return true;
		}
		break;
	case 3: // /addvit
		{
			CommandAdd(aIndex,2,Protocol);
			return true;
		}
		break;
	case 4: // /addene
		{
			CommandAdd(aIndex,3,Protocol);
			return true;
		}
	case 5: // /pkclear
		{
			CommandPkClear(aIndex);
			return true;
		}
		break;
	case 64: // /gmreload
		{
			Load();
			return true;
		}
	case 65: // /gmmoveall
		{
			GMCMoveAll(aIndex,(char*)Protocol);
			return true;
		}
		break;
	default:
		return false;
	}
}