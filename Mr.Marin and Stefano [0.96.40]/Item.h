#ifndef _ITEM_H_
#define _ITEM_H_

#define ITEMID(group,index) (group*512+index)


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

#endif