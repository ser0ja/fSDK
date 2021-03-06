// Created file "Lib\src\Uuid\qosguid"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(GUID_QOS_FLOW_MODE, 0x5c82290a, 0x515a, 0x11d2, 0x8e, 0x58, 0x00, 0xc0, 0x4f, 0xc9, 0xbf, 0xcb);

