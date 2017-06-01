#ifndef OBJECTSTRUCT_H
#define OBJECTSTRUCT_H
/*------------------------------------------------------------------*/
#define OBJECT_POINTER(aIndex) ((aIndex * OBJECT_SIZE) + OBJECT_BASE)
#define OBJECT_TABINDEX(lpObj) ((lpObj - OBJECT_BASE) / OBJECT_SIZE)
#define OBJECT_BASE		0x4CEE778
#define OBJECT_SIZE		0x0D0C
#define OBJECT_START	4800
#define OBJECT_END		5800
#define ITEM_SIZE		0x0084

struct ITEMSTRUCT
{
	/*Start + Size*/
	/*0x0   +  0x4*/ unsigned long m_Number;
	/*0x4   +  0x1*/ char m_Serial;
	/*0x4   +  0x2*/ unsigned short m_Type;
	/*0x6	+  0x2*/ unsigned short m_Level;
	/*0x9	+  0x1*/ unsigned char m_Part;
	/*0xA	+  0x1*/ unsigned char m_Class;
	/*0xB	+  0x1*/ bool m_TwoHand;
	/*0xC	+  0x1*/ unsigned char m_AttackSpeed;
	/*0xD	+  0x1*/ unsigned char m_WalkSpeed;
	/*0xE	+  0x2*/ unsigned short m_DamageMin;
	/*0x10	+  0x2*/ unsigned short m_DamagaMax;
	/*0x12	+  0x1*/ unsigned char m_SuccessfulBlocking;
	/*0x13	+  0x2*/ unsigned short m_Defense;
	/*0x15	+  0x2*/ unsigned short m_MagicDefense;
	/*0x17	+  0x1*/ unsigned char m_Speed;
	/*0x18	+ 0x6C*/ unsigned char m_Filler0x18[0x6C];	
};

struct OBJECTSTRUCT
{
	/*Start + Size*/
	/*0x0   +  0x4*/	int aIndex;	// Player Index
	/*0x4   +  0x4*/	int Connected; // Player Connect Status (0 -> Off | 1 -> ServerScreen | 2 -> CharScreen | 3 -> Playing)
	/*0x8	+ 0x57*/	unsigned char m_Filler0x8[0x57]; // Unknown Bytes
	/*0x5F  +  0xB*/	char AccountID[0xB]; // Player AccountID
	/*0x6A  +  0xB*/	char Name[0xB];	// Player Name
	/*0x75  +  0xE*/	unsigned char m_Filler0x75[0xE]; // Unknown Bytes
	/*0x83	+  0x1*/	unsigned char Class;
	/*0x84	+  0x1*/	unsigned char DbClass;
	/*0x85	+  0x1*/	unsigned char Skin;
	/*0x86  +  0x2*/	unsigned short Level; // Player Level
	/*0x88  +  0x4*/	unsigned int LevelUpPoint; // Player Level Up Points Remaining
	/*0x8C	+  0x4*/	unsigned long Experience; // Player Experience
	/*0x90	+  0x4*/	unsigned long ExperienceMax; // Player Max Experience (Before Leveling Up)
	/*0x94  +  0x4*/	unsigned int Money;	// Player Zen
	/*0x98  +  0x2*/	short Strength; // Player Str
	/*0x9A  +  0x2*/	short Dexterity; // Player Agi
	/*0x9C  +  0x2*/	short Vitality;	// Player Vit
	/*0x9E  +  0x2*/	short Energy; // Player Ene
	/*0xA0	+  0x4*/	float Life; // Player Life
	/*0xA4	+  0x4*/	float LifeMax; // Player Max Life (Before Leveling Up)
	/*0xA8	+  0x4*/	int AddLife; // ??
	/*0xAC  +  0x4*/	float FillLife; // ??
	/*0xB0	+  0x4*/	float FillLifeMax; // ??
	/*0xB4	+ 0x18*/	unsigned char m_Filler0xB4[0x18]; // Unknown Bytes
	/*0xCC	+  0x1*/	char PkCount;
	/*0xCD	+  0x1*/	char PkLevel;
	/*0xCE  +  0x4*/	int PkTime;
	/*0x170 +  0x1*/	char CtlCode;
	/*0xD2  +  0x2*/	unsigned char m_Filler0xD2[0x2];
	/*0xD4  +  0x2*/	unsigned short X;
	/*0xD6  +  0x2*/	unsigned short Y;
	/*0xD8	+  0x1*/	unsigned char Dir;
	/*0xD9	+  0x1*/	unsigned char MapNumber;
	/*0xDA	+0x1AA*/	unsigned char m_Filler0xDA[0x1AA]; // Unknown Bytes
	/*0x280 +  0x2*/    unsigned short m_wExprienceRate; // Exp Calc
	/*0x282 +  0x2*/	unsigned short m_wDropRate;
	/*0x284 +  0x2*/	short ShopNumber;
	/*0x286 +0x99E*/	unsigned char m_Filler0x286[0x99E];
	/*0xC24 +  0x4*/	ITEMSTRUCT * pInventory; // Player Inventory ( * ITEMSTRUCT)
	/*0xC28 +  0x4*/	unsigned char * pInventoryMap;
	/*0xC2C +  0x4*/	char * pInventoryCount;
	/*0xC30 +  0x1*/	char pTransaction;
	/*0xC31 +  0x4*/	ITEMSTRUCT * Inventory1;
	/*0xC35 +  0x4*/	unsigned char * InventoryMap1;
	/*0xC39 +  0x1*/	char InventoryCount1;
	/*0xC3A	+  0x4*/	ITEMSTRUCT * Inventory2;
	/*0xC3E	+  0x4*/	unsigned char * InventoryMap2;
	/*0xC42 +  0x1*/	char InventoryCount2;
	/*0xC43	+  0x4*/	ITEMSTRUCT * Trade;
	/*0xC47 +  0x4*/	unsigned char TradeMap;
	/*0xC4B +  0x4*/	int TradeMoney;
	/*0xC4F +  0x1*/	unsigned char TradeOk;
	/*0xC50 + 0xBC*/	unsigned char m_Filler0xC50[0xBC]; // Unknown Bytes
	/*Final 0x0D0C*/
};
/*------------------------------------------------------------------*/
#endif//OBJECTSTRUCT_H