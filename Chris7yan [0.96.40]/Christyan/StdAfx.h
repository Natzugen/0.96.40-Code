#pragma once

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define CHRISTYAN ".\\Christyan.ini"

#include <Windows.h>
#include <sdkddkver.h>
#include <stdio.h>
#include <string.h>
#include "SQLApi.h"
#include "Customs.h"
#include "Console.h"
#include "SQLServer.h"
#include "Settings.h"
#include "Christyan.h"
#include "Funcoes.h"
#include "ObjectStruct.h"
#include "Global.h"
#include "Comandos.h"
#include "Vip.h"
#include "Fixs.h"

typedef enum
{
	BLACK			= 0,
	BLUE			= 1,
	GREEN			= 2,
	CYAN			= 3,
	RED				= 4,
	MAGENTA			= 5,
	BROWN			= 6,
	LIGHTGREY		= 7,
	DARKGREY		= 8,
	LIGHTBLUE		= 9,
	LIGHTGREEN		= 10,
	LIGHTCYAN		= 11,
	LIGHTRED		= 12,
	LIGHTMAGENTA	= 13,
	YELLOW			= 14,
	WHITE			= 15
};