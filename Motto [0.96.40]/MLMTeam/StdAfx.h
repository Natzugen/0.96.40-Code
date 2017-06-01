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
#pragma comment(lib,"ws2_32.lib")
using namespace std;

static HMENU MyMenu;
static DWORD OldProtect;
static UINT_PTR MyMenuTimerID;
static UINT_PTR cPluginsTimer;

static HWND cWND;
static HINSTANCE hInst;

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

