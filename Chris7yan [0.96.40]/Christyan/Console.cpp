#include "StdAfx.h"

void Console()
{
	AllocConsole();
	SetConsoleTitle("GameServer v.97D ~ 0.96.40 [ Powered By Christyan Barbosa Fernandes Soares ]");
	SetConsoleText(WHITE, "");
	SetConsoleText(WHITE, "##################################################################\n");
	SetConsoleText(WHITE, "########### Christyan Project 2010 - v.97d And 0.96.40 ###########\n");
	SetConsoleText(WHITE, "##################################################################\n");
	SetConsoleText(WHITE, "\n\n");
}
void SetConsoleText(unsigned short color, char* Format, ...)
{
    char Message[1024];
    DWORD dwBytesWritten;
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    va_list pArguments;
    va_start(pArguments, Format);
    vsprintf(Message, Format, pArguments);
    va_end(pArguments);
    WriteFile(Handle, Message, strlen(Message), &dwBytesWritten, NULL);
	SetConsoleTextAttribute(Handle,color);
}