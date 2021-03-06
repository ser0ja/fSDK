// Created file "Lib\src\Uuid\i_imgutil"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(CLSID_CoDitherToRGB8, 0xa860ce50, 0x3910, 0x11d0, 0x86, 0xfc, 0x00, 0xa0, 0xc9, 0x13, 0xf7, 0x50);

