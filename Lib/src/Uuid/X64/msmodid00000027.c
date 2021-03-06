// Created file "Lib\src\Uuid\X64\msmodid"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(WSKLIB_WSK_CLIENT_MODULEID, 0x00000018, 0x0001, 0x0000, 0xf6, 0xcc, 0xc6, 0x47, 0xb4, 0x99, 0x51, 0x43);

