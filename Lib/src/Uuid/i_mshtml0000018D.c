// Created file "Lib\src\Uuid\i_mshtml"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_Scriptlet, 0xae24fdae, 0x03c6, 0x11d1, 0x8b, 0x76, 0x00, 0x80, 0xc7, 0x44, 0xf3, 0x89);

