#ifndef MESSAGE__H
#define MESSAGE__H 

#define MAX_C1LEN 0xFF

class GS_MESSAGE
{
public:
	void MessageSendServer(char * Texto,...);
	void MessageSendMap(char Map, char * Texto,...);
	void ChatSendGuild (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Verde
	void ChatSendParty (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Azul
	void ChatSendWhisper (LPCSTR Nome, LPSTR Mensagem, DWORD aIndex); //Amarelo
};

extern GS_MESSAGE gs_msg;

#endif