// Created file "Lib\src\GdiPlus\X64\imagingguds"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(FormatIDImageInformation, 0xe5836cbe, 0x5eef, 0x4f1d, 0xac, 0xde, 0xae, 0x4c, 0x43, 0xb6, 0x08, 0xce);

