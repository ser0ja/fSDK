// Created file "Lib\src\Uuid\i_msfeeds"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IFeedEvents, 0xabf35c99, 0x0681, 0x47ea, 0x9a, 0x8c, 0x14, 0x36, 0xa3, 0x75, 0xa9, 0x9e);

