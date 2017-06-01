#ifndef PROTOCOL_H
#define PROTOCOL_H

#define CHAT_RECV 0x00
#define CHAT_WISP 0x02
#define ENTER_MAP 0x03
#define NPC_CLICK 0x30

void ProtocolCoreEx(BYTE protoNum,LPBYTE aRecv,DWORD aLen,short aIndex,DWORD Encrypt,int Serial);

#endif