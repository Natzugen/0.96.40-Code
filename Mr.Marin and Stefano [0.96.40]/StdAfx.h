#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib,"user32.lib")


#include "User.h"
#include "Item.h"
#include "GameServer.h"
#include "Utilidades.h"
#include "Struct.h"
#include "MsgSend.h"
#include "SQL.h"
#include "ChatCore.h"
#include "Logger.h"


#pragma warning(disable : 4010)
#pragma warning(disable : 4101)
#pragma warning(disable : 4311)
#pragma warning(disable : 4312)
#pragma warning(disable : 4482)
#pragma warning(disable : 4700)
#pragma warning(disable : 4996)
#pragma warning(disable : 4244 4715 4717)

typedef enum{
	Preto = 1,
	Vermelho = 2,
	Verde = 3,
	Azul = 4,
	Vermelho2 = 5,
	Azul2 = 6,
	Rosa = 7}LogColors;

typedef struct
{
	unsigned char Enc;
	unsigned char Size;
	unsigned char Type;
	unsigned char MsgType;
	char		Notice[256];
} GCSERVERMSGSTRUCT;

typedef struct
{
	unsigned char Enc;	// 0x00
	unsigned char Size;	// 0x01
	unsigned char Type;	// 0x02
	char Sender[10];	// 0x03
	char Notice[256];	// 0x0D
}GCPOSTMSGSTRUCT;


typedef struct
{
	unsigned char Enc;	// 0x00
	unsigned char Size; // 0x01
	unsigned char Type; // 0x02
	char chatid[10];	// 0x03
	char chatmsg[60];	// 0x0D
}CGCHATDATA;


typedef enum
{
	Dll = 0,
	Cmd = 1,
	Npc = 2,
	Sql = 3,
	MAX_LOG_TYPE = 4,
}LOG_TYPES;

void InitializeWindow();