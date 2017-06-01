#ifndef GAMESERVER_H
#define GAMESERVER_H

#define gObjSize		0x0D0C
#define gObjOffset		0x4CEE778
#define gObjConnected	0x4
#define gObjCtl			0x170

#define OBJECT_BASE		0x4CEE778
#define OBJECT_SIZE		0x0D0C

#define OBJECT_START	4800
#define OBJECT_END		5800
#define OBJECT_MIN		0x12C0
#define OBJECT_MAX		0x15E0

#define OBJECT_POINTER(aIndex) ((aIndex * OBJECT_SIZE) + OBJECT_BASE)
#define OBJECT_TABINDEX(lpObj) ((lpObj - OBJECT_BASE) / OBJECT_SIZE)

#define ITEM_SIZE	0x0084

#define TradeEx							((void(*) (LPBYTE aRecv, int aIndex)) 0x0041D3B0)
#define DataRecv						((void(*)(BYTE, PBYTE, DWORD, DWORD, ...)) 0x00414180)
#define DataSend						((void(*)(DWORD aIndex, PBYTE Packet, DWORD Size)) 0x00440240)
#define LogAddFunc						((void(*)(unsigned char Color,char * Text, ...))0x00402400)
#define GCPkLevelSend					((void(*)(DWORD aIndex,BYTE PkLevel))0x00401D7F)
#define CMAPMoneyItemDrop				((void(*)(DWORD Money,DWORD x, DWORD y))0x00490560)
#define gObjDel							((short(*)(DWORD aIndex))0x00460640)
#define GCMoneySend						((void(*)(DWORD aIndex, DWORD Money))0x4185C0)
#define ItemSerialCreateSend			((int(*)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD)) 0x004121E0)
#define gObjTeleport					((void(*)(int aIndex, int MapNumber, int X, int Y))0x0040181B)
#define ChatNpc							((void(*) (OBJECTSTRUCT * lpNpc, char * Msg, int senduser)) 0x0040147E)
#define gEventMonsterItemDrop			((int(*)(BYTE *,BYTE*))0x0040A670)
#define gObjMonsterTopHitDamageUser		((DWORD(*)(BYTE*MonsterAddress))0x00404D70)
#define GCLevelUpMsgSend				((void(*)(int, unsigned char))0x00417AB0)
#define gObjCloseSet					((void(*)(DWORD aIndex, DWORD flag))0x00401A28)
#define ItemGetNumberMake				((WORD(*)(DWORD, DWORD)) 0x00401F4B)
#define AllMonsterReload				((void(*)()) 0x0048BA40)
#define ShopReload						((void(*) ()) 0x00484FA0)
#define MonsReload						((void(*) ()) 0x004026A3)
#define ConfigReload					((void(*) ()) 0x0048C2E0)
#define ServerMsgSend					((void(*)(char * Texto, DWORD PlayerID, int tipo)) 0x0040167C)
#define GCServerMsgStringSend			((void(*)(char * Text, DWORD PlayerID, int Type)) 0x00416430)
#define CloseClient						((void(*)(int)) 0x00440E90)

enum PLAYER_STATUS {
	PLAYER_EMPTY		= 0,
	PLAYER_CONNECTED	= 1,
	PLAYER_LOGGED		= 2,
	PLAYER_PLAYING		= 3
};

enum OBJECT_TYPE {
	OBJECT_EMPTY	    = -1,
	OBJECT_MONSTER	    = 2,
	OBJECT_USER		    = 1,
	OBJECT_NPC		    = 3
};

enum DB_CLASS_CODES {
	DB_DARK_WIZARD		= 0,
	DB_SOUL_MASTER		= 1,

	DB_DARK_KNIGHT		= 16,
	DB_BLADE_KNIGHT		= 17,

	DB_FAIRY_ELF		= 32,
	DB_MUSE_ELF			= 33,

	DB_MAGIC_GLADIATOR	= 48,
};
enum PLAYER_WARDROBE {
	WEAPON_01	= 0,
	WEAPON_02	= 1,
	HELMET		= 2,
	ARMOR		= 3,
	PANTS		= 4,
	GLOVES		= 5,
	BOOTS		= 6,
	WINGS		= 7,
	GUARDIAN	= 8,
	PENDANT		= 9,
	RING_01		= 10,
	RING_02		= 11,
};
typedef enum{
	PostAzul		= 0,
	PostVerde		= 1,
	PostAmarelo		= 2
};
typedef enum{
	ContaFree		= 0,
	ContaVipSimples	= 1,
	ContaVipPremium	= 2
};
typedef enum{
	Preto			= 1,
	Vermelho		= 2,
	Verde			= 3,
	Azul			= 4,
	Vermelho2		= 5,
	Azul2			= 6,
	Rosa			= 7
}LogColors;

#endif