#include "StdAfx.h"

void ChatRecv(DWORD aIndex,LPBYTE Protocol);
bool CommandSwitch(DWORD aIndex,LPBYTE Protocol,BYTE CmdIndex);

void LoadCmdConfigs();

void CommandPost(int aIndex, char * msg);
void CommandAdd(int aIndex,char Type, LPBYTE msg);
void CommandPkClear(int aIndex);
void GMCMoveAll(int aIndex,char* msg);