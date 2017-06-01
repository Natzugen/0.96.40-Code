// Extruturas dos Arquivos (.h)

struct SQL_CONNECTION
{
	char server[256];
	char dbname[256];
	char access[256];
	char dbpass[255];
};

struct CON_NOTICE
{
	unsigned char Active;
	char ConnectNotice[150];
	char ConnectNotice2[150];
};

struct NPC_RESET
{
	int ResetActive;
	int ResetMode;
	int ResetLevelFree;
	unsigned int ResetPriceFree;
	int ResetPontosFree;
	int ResetLevelVip;
	unsigned int ResetPriceVip;
	int ResetPontosVip;
};

struct NPC_PKCLEAR
{
	int PkClearActive;
	unsigned int PkClearZenFree;
	unsigned int PkClearZenVip;
};

struct CMD_POST
{
	int PostActive;
	int PostLevel;
	int PostReset;
	unsigned int PostZenReq;
	int PostTime;
};

struct CMD_ADD
{
	int AddActive;
	int AddLevel;
	int AddMaxPoint;
	unsigned int AddPrice;
};

struct CMD_RELOAD
{
	int Active;
	unsigned char OnlyGM;
};

struct CMD_MOVED2
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_D3MOV
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_A2MOV
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_A3MOV
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_T2MOV
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_ICAMOV
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_VALLEY
{
	int Active;
	int MinLevel;
	unsigned int Price;
};

struct CMD_DARMOV
{
	int  Active;
	int Vip;
	int MinLevel;
	unsigned int Price;
};

struct CMD_PKSET
{
	int Active;
	unsigned char CodeS;
};

struct CMD_SITE
{
	int Active;
	char texto;
};

struct CMD_HORA
{
	int Active;
	unsigned int Price;
};

struct CMD_SKIN
{
	int Active;
	int CodeS;
};

struct CMD_BAN
{
	int Active;
	unsigned char CodeS;
};

struct CMD_UNBAN
{
	int Active;
	unsigned char CodeS;
};

struct SIS_INIV
{
	int Active;
	int ResetsA;
};

struct GS_STRUCT
{
	SQL_CONNECTION sql;
	CON_NOTICE c_Notice1;
	NPC_RESET c_Reset;
	NPC_PKCLEAR c_PkClear;
	CMD_POST c_Post;
	CMD_ADD c_Add;
	CMD_RELOAD c_Reload;
	CMD_MOVED2 c_MoveD2;
	CMD_D3MOV c_D3Move;
	CMD_A2MOV c_A2Move;
	CMD_A3MOV c_A3Move;
	CMD_T2MOV c_T2Move;
	CMD_ICAMOV c_IcaMove;
	CMD_VALLEY c_ValeMove;
	CMD_DARMOV c_DareMove;
	CMD_PKSET c_PkSet;
	CMD_SITE c_Site;
	CMD_HORA c_Hora;
	CMD_SKIN c_Skin;
	CMD_BAN c_Ban;
	CMD_UNBAN c_UnBan;
	SIS_INIV c_SisIni;
	int MoveAllCmd;
	int expvip;
	int dropvip;
};

extern GS_STRUCT configs;

void Carrega();