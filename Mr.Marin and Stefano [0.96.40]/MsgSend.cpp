#include "MsgSend.h"
#include "GameServer.h"
MESSAGE_SEND Send;

void MESSAGE_SEND::Normal(int aIndex, char * Message,...)
{
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	GCServerMsgStringSend(Msg,aIndex,1);
}

void MESSAGE_SEND::NormalMap(char Map, char * Message,...)
{
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			if(gObj[i].MapNumber == Map)
			{
				GCServerMsgStringSend(Msg,i,1);
			}
		}
	}
}

void MESSAGE_SEND::NormalAll(char *Message, ...)
{
	
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			GCServerMsgStringSend(Msg,i,1);
		}
	}
}

void MESSAGE_SEND::Announce(int aIndex, char *Message,...)
{
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	GCServerMsgStringSend(Msg,aIndex,1);
}

void MESSAGE_SEND::AnnounceMap(char Map, char *Message, ...)
{
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			if(gObj[i].MapNumber == Map)
			{
				GCServerMsgStringSend(Msg,i,0);
			}
		}
	}
}

void MESSAGE_SEND::AnnounceAll(char *Message, ...)
{
	char Msg[200];
	va_list pArguments;
    va_start(pArguments, Message);
    vsprintf(Msg, Message, pArguments);
    va_end(pArguments);

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			GCServerMsgStringSend(Msg,i,0);
		}
	}
}

void MESSAGE_SEND::Post(int aIndex,char* Message, ...)
{
	char szBuffer[243];
	GCPOSTMSGSTRUCT lpMsg;

	va_list pArguments;
	va_start(pArguments, Message);
	vsprintf(szBuffer, Message, pArguments);
	va_end(pArguments);

	lpMsg.Enc = 0xC1;
	lpMsg.Type = 0x2;
	strcpy(lpMsg.Sender,gObj[aIndex].Name);
	strcpy(lpMsg.Notice,szBuffer);
	lpMsg.Size = 0x13+strlen(lpMsg.Notice);

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			DataSend(i,(LPBYTE)&lpMsg,lpMsg.Size);
		}
	}
}