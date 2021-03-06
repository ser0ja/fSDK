// Created file "Lib\src\Uuid\i_urlmon"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IMonikerProp, 0xa5ca5f7f, 0x1847, 0x4d87, 0x9c, 0x5b, 0x91, 0x85, 0x09, 0xf7, 0x51, 0x1d);

