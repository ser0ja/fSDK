// Created file "Lib\src\MMC\X64\ndmgrpriv"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_ITaskView, 0x9ff7a05c, 0xe7b9, 0x11d2, 0x88, 0x3c, 0x00, 0xc0, 0x4f, 0x72, 0xc7, 0x17);

