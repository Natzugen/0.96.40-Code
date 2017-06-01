#ifndef OFFSETS_H
#define OFFSETS_H

// -- Taxa de Drop de Item Excelente
#define GS_EXE_DROP_RATE (0x00409C26)

// -- Porta UDP do GameServer
#define UDP_Port (0x0048A098+1)	

// -- Offsets de Configuração dos aneis de Transformação
#define GS_RING1 (0x00458C98+3)								
#define GS_RING2 (0x00458CA1+3)							
#define GS_RING3 (0x00458CAA+3)								
#define GS_RING4 (0x00458CB3+3)								
#define GS_RING5 (0x00458CBC+3)								
#define GS_RING6 (0x00458CC5+3)								

// -- Taxa de Sucesso da Chaos Machine
#define GS_CHAOS_MIX_10 (0x0044926D)
#define GS_CHAOS_MIX_11 (0x0044927C)
#define GS_CHAOS_WINMIN (0x0044A27A)
#define GS_CHAOS_WINMAX (0x0044A286)

// -- Pontos por level upado
#define GS_LVL_UP_MG     (0x00462AF7)
#define GS_LVL_UP_NORMAL (0x00462B0E)

// -- Level Maximo no GameServer
#define GS_MAX_LEVEL1 (0x00459BA2+3)
#define GS_MAX_LEVEL2 (0x00462A33+2)
#define GS_MAX_LEVEL3 (0x00496D93+1)

// -- Taxas de Sucesso das Joias
#define GS_SOUL_RATE (0x0047A069+3)				
#define GS_SOUL_LUCK_RATE   (0x00479F8A+3)					
#define GS_LIFE_RATE   (0x0047A678+3)						

// -- Maximo de Usuarios Online
#define GS_MAX_ONLINE (0x005133E8)

// -- Prêmio do BC
#define BC_DROP  (0x0049B1F8+1)
#define BC_GROUP (0x0049B1FA+1)

// -- Offsets de Configuração do ManaShield
#define GS_MS1 (0x00458794+3)								
#define GS_MS2 (0x00458779+1)								
#define GS_MS3 (0x0045878D+1)								
#define GS_MS4 (0x004587B3+2)								
#define GS_MS5 (0x004587AC+1)	

// -- Offsets das Orbs das Elfs
#define GS_ORB1 (0x00457E3F+1)								
#define GS_ORB2 (0x00457E70+1)							
#define GS_ORB3 (0x00457EA1+1)								
#define GS_ORB4 (0x00457ED2+1)								
#define GS_ORB5 (0x00457F03+1)								
#define GS_ORB6 (0x00457F34+1)								
#define GS_ORB7 (0x00457F65+1)

// -- Potions Regen percentage
#define GS_POTIONS1	0x00427E37
#define GS_POTIONS2	0x00427E60
#define GS_POTIONS3	0x00427E89
#define GS_POTIONS4	0x00427EB2
#define GS_POTIONS5	0x00428008
#define GS_POTIONS6	0x00428047
#define GS_POTIONS7	0x00428086

// -- Preço das Joias
#define GS_BLESS_PRICE (0x0048001E+3)
#define GS_SOUL_PRICE (0x00480038+3)
#define GS_CHAOS_PRICE (0x00480053+3)
#define GS_LIFE_PRICE (0x0048006E+3)
#define GS_CREATION_PRICE (0x00480088+3)
#define GS_DINO_PRICE (0x004800D8+3)
#define GS_FRUIT_PRICE (0x004800A3+3)
#define GS_FATHER_PRICE (0x004800BE+3)

// -- Maximo Zen Inventory
#define MAX_ZEN_INV (0x0041E40C+3)

// -- Maximo Zen Bau
#define MAX_ZEN_BAU1 (0x00422DA1+3)
#define MAX_ZEN_BAU2 (0x00422E97+3)
#define MAX_ZEN_BAU3 (0x00422DCD+2)

// -- Non-PVP
#define GS_NON_PVP1 (0x0048C586+1)
#define GS_NON_PVP2 (0x0048C783+1)
#define GS_NON_PVP3 (0x0048C980+1)
#define GS_NON_PVP4 (0x0048CA98+1)

#endif