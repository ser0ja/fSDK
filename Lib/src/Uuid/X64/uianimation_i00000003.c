// Created file "Lib\src\Uuid\X64\uianimation_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_IUIAnimationManager, 0x9169896c, 0xac8d, 0x4e7d, 0x94, 0xe5, 0x67, 0xfa, 0x4d, 0xc2, 0xf2, 0xe8);
