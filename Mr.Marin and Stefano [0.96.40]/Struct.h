
bool Load();

#define MAX_SHOPS 14

#define MAX_NPCID 300

struct SQLDATA
{
	char Server[128];
	char DbName[30];
	char User[64];
	char Pass[64];
};


struct CMD_POST
{
	char format[20];
	unsigned int price;
	unsigned short minLevel;
};

struct CMD_ADD
{
	unsigned int price;
	unsigned short minLevel;
	unsigned short maxPoint;
};

struct CMD_PKCLEAR
{
	unsigned int price;
	unsigned short minLevel;
	unsigned char isGM;
};

struct NPC_PKCLEAR
{
	unsigned char Active;
	unsigned int price;
	unsigned short minLevel;
	unsigned short Class;
	unsigned char coords[3];
};

struct NPC_RESET
{
	unsigned char Active;
	unsigned short Class;
	unsigned char coords[3];
	unsigned char Types;
	unsigned char pMode;
	unsigned char rMode;
	unsigned char zMode;
	unsigned short t_stats[11][4][4];
	unsigned short rLevel[11];
	unsigned short rPoint[11];
	unsigned int rPrice[11];
};

struct GSCONFIGS
{
	CMD_POST c_post;
	CMD_ADD c_add;
	CMD_PKCLEAR c_pkc;

	NPC_PKCLEAR n_pkc;
	NPC_RESET n_res;
	char ConnectNotice[128];
	SQLDATA sql;

	short gTime_Sec;
	short gTime_Min;
	short gTime_Hour;

	char isLogAdd[5];

	unsigned char ShopAccess[15];
	unsigned char useShopAccess;

	short NpcSpeak[300]; // Até 300 NPCs
	unsigned char useNpcSpeak;
};

extern GSCONFIGS configs;

#define PATH_CONFIGS ".\\Configs\\GameServer.ini"
#define PATH_NPCS ".\\Configs\\NpcConfigs.ini"
#define PATH_MSGS ".\\Configs\\Messages.ini"
#define PATH_CMDS ".\\Configs\\Commands.ini"


void GetMsg(int MsgNumber, char * Return, unsigned short Size);
bool GetCmd(int CmdNumber, char * Return, unsigned short Size);
bool GetTalk(int NpcNumber, char * Return, unsigned short Size);

enum coords
{
	MAP = 0,
	POSX = 1,
	POSY = 2
};
enum TYPES
{
	DW = 0,
	DK = 1,
	ELF = 2,
	MG = 3,
	STR = 0,
	AGI = 1,
	VIT = 2,
	ENE = 3
};

/*MaxLevel = WORD ~>	0x0041701F (0x15E = 350)*/
#define MaxLevel1	0x0041701F
#define MaxLevel2	0x00459BA5
#define MaxLevel3	0x00462A35
#define MaxLevel4	0x0048A2AA
/*UDP Port = DWORD ~>	0x0048A099 (0xEA66 = 60006)*/
#define UDPPort		0x0048A099
/*Transform Rings = DWORDs:
				Budge Dragon ~> 0x00458C9B (0x2)
				Giant		 ~> 0x00458CA4 (0x7)
				Skeleton	 ~> 0x00458CAD (0xE)
				Poison Bull	 ~> 0x00458CB6 (0x8)
				Thunder Lich ~> 0x00458CBF (0x9)
				Death Cow	 ~> 0x00458CC8 (0x29) */
#define TRing1		0x00458C9B
#define TRing2		0x00458CA4
#define TRing3		0x00458CAD
#define TRing4		0x00458CB6
#define TRing5		0x00458CBF
#define TRing6		0x00458CC8
/*Potions Regen percentage = BYTEs:
				Apple		 ~> 0x00427E37 (0x0A ~ 10)
				Small HP	 ~> 0x00427E60 (0x14 ~ 20)
				Medium HP	 ~> 0x00427E89 (0x1E ~ 30)
				Large HP	 ~> 0x00427EB2 (0x28 ~ 40)
				Small MP	 ~> 0x00428008 (0x14 ~ 20)
				Medium MP	 ~> 0x00428047 (0x1E ~ 30)
				Large MP	 ~> 0x00428086 (0x28 ~ 40) */
#define Potions1	0x00427E37
#define Potions2	0x00427E60
#define Potions3	0x00427E89
#define Potions4	0x00427EB2
#define Potions5	0x00428008
#define Potions6	0x00428047
#define Potions7	0x00428086
/*Item Price Changes = DWORDS:
				FruitPrices		~> 0x004800A6 (0x1F78A40 ~ 33.000.000)
				Blue Feather	~> 0x004800C1 (0x002BF20 ~ 180.000)
				Dinorant		~> 0x004800DB (0x00EA600 ~ 960.000)
				Jewel of Chaos  ~> 0x00480056 (0x00C5C10 ~ 810.000)
				Jewel of Soul	~> 0x0048003B (0x05B8D80 ~ 6.000.000)
				Jewel of Bless	~> 0x00480021 (0x0895440 ~ 9.000.000)
				J. of Creation	~> 0x0048008B (0x2255100 ~ 36.000.000)
				Jewel of Life	~> 0x00480071 (0x2AEA540 ~ 45.000.000)*/
#define Prices1		0x004800A6
#define Prices2		0x004800C1
#define Prices3		0x004800DB
#define Prices4		0x00480056
#define Prices5		0x0048003B
#define Prices6		0x00480021
#define Prices7		0x0048008B
#define Prices8		0x00480071