#ifndef USER_H
#define USER_H

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
	/*0x0*/ /*|0x4|*/	int aIndex;
	/*0x4*/ /*|0x4|*/	int Connected;
	/*0x8*/	/*|0x0C|*/	char unk1[12];
	/*0x14*/ /*|0x10|*/ char Ip_addr[16];
	/*0x24*/ /*|0x3D|*/ char unk2[59];
	/*0x5F*/ /*|0xB|*/	char AccountID[0xB]; // Player AccountID novo comando
	/*0x6A*/ /*|0xB|*/	char Name[0xB];	// Player Name novo comando
	/*0x75*/ /*|0x11|*/  char unk3[14];
	/*0x83*/ /*|0x1|*/   unsigned char Class;
	/*0x84*/ /*|0x1|*/	 unsigned char DbClass;
	/*0x85*/ /*|0x1|*/	 unsigned char ChangeUP;
	/*0x86*/ /*|0x2|*/	unsigned short Level; // Player Level
	/*0x88*/ /*|0x4|*/	unsigned int LevelUpPoint; // Player Level Up Points Remaining
	/*0x8C*/ /*|0x4|*/	unsigned long Experience; // Player Experience
	/*0x90*/ /*|0x4|*/   unsigned long NextExp;
	/*0x94*/ /*|0x4|*/	unsigned int Money;	// Player Zen
	/*0x98*/ /*|0x2|*/	short Strength; // Player Str
	/*0x9A*/ /*|0x2|*/	short Dexterity; // Player Agi
	/*0x9C*/ /*|0x2|*/	short Vitality;	// Player Vit
	/*0x9E*/ /*|0x2|*/	short Energy; // Player Ene
	/*0xA0*/ /*|0x4|*/   float Life;
	/*0xA4*/ /*|0x4|*/   float MaxLife;
	/*0xA8*/ /*|0x8|*/	 char unk4[8];
	/*0xB0*/ /*|0x4|*/   float Mana;
	/*0xB4*/ /*|0x4|*/   float MaxMana;
	/*0xB8*/ /*|0x4|*/	int Stamina;
	/*0xBC*/ /*|0x4|*/  int MaxStamina;
	/*0xC0*/ /*|0x4|*/  int MaxStamina2;
	/*0xC4*/ /*|0x16|*/	 char unk5[8];
	/*0xCC*/ /*|0x1|*/ char PK_Count;
    /*0xCD*/ /*|0x1|*/ char PK_Level;
	/*0xD0*/ /*|0x4|*/ int PK_Time;
	/*0xD4*/ /*|0x2|*/  short X;
	/*0xD6*/ /*|0x2|*/  short Y;
	/*0xD8*/ /*|0x1|*/  unsigned char Dir;
	/*0xD9*/ /*|0x1|*/  unsigned char MapNumber;
	/*0xDA*/ /*|0xC|*/  char unk7[12];
	/*0xE6*/ /*|0x2|*/  short StartX;
	/*0xE8*/ /*|0x2|*/  short StartY;
	/*0xEA*/ /*|0x2|*/  short m_OldX;
	/*0xEC*/ /*|0x2|*/  short m_OldY;
	/*0xEE*/ /*|0x97|*/	char unk8[130]; 
	/*0x170*//*|0x1|*/  char CtlCode;
	/*0xC50*/ /*|0xBC|*/	unsigned char m_Filler0xC50[0xBC]; // Unknown Bytes
	/*0x280*/ /*|0x2|*/    unsigned short m_wExprienceRate; // Exp Calc
	/*0x282*/ /*|0x2|*/	unsigned short m_wDropRate;
	/*NEAR ALL MUCH 0x171 */ char unk9[2739];
	/*<thisrel this+0x27C>*/ /*|0x4|*/ int m_Change;

	/*0xC28*//*ALL*/ char ALL[212];
	/*Final 0x0D0C*/

	char VipLevel;
	char CtlCodeEx;
	char ShopNumberEx;
	
	unsigned int Resets;
	unsigned int Resetao;
	unsigned int Creditos;
	unsigned int Golds;
	unsigned int Maxbau;

	unsigned int MRdia;
	unsigned int MRsem;
	unsigned int MRmes;

	unsigned int Rdia;
	unsigned int Rsem;
	unsigned int Rmes;
};
#endif