// Created file "Lib\src\Uuid\netconp_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_INetConnectionManagerEvents, 0xc08956ba, 0x1cd3, 0x11d1, 0xb1, 0xc5, 0x00, 0x80, 0x5f, 0xc1, 0x27, 0x0e);

