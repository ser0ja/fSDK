// Created file "Lib\src\Uuid\X64\i_dxtrans"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_DXTScale, 0x555278e2, 0x05db, 0x11d1, 0x88, 0x3a, 0x3c, 0x8b, 0x00, 0xc1, 0x00, 0x00);
