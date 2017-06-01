#include "ChatCore.h"

static char Message[200];


void GMCMoveAll(int aIndex,char* msg)
{
	int TargetMap, TargetX, TargetY = 0;
	
	for(int i = 0; i < 10; i++)
	{
		if(msg[i] > 47 && msg[i] < 58)
		{
			sscanf((char*)msg[i],"%d %d %d",
				&TargetMap, &TargetX, &TargetY);

			i = 10;
		}
	}

	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			gObjTeleport(i,TargetMap,TargetX,TargetY);
			Sleep(10);
		}
	}
	LogAddExCmd(true,"[GM %s][MoveAllCommand] Moved Players to %d %d %d",gObj[aIndex].Name,TargetMap,TargetX,TargetY);
}