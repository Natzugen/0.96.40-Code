#ifndef FUNCOES_H
#define FUNCOES_H
void ProtocolCore(BYTE protoNum, LPBYTE aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial);
void HookThis(DWORD OriginalOffset, DWORD DestOffset);
void MessageSendServer(char * Texto,...);
void MessageSendMap(char Map, char * Texto,...);
void ChatSendGuild (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Verde
void ChatSendParty (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Azul
void ChatSendWhisper (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Amarelo
#endif//FUNCOES_H