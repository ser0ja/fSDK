// Created file "Lib\src\Uuid\X64\i_openservice"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(LIBID_IEOpenServiceObjects, 0x41a67fbc, 0x3179, 0x4fdf, 0x9e, 0x9a, 0x1b, 0x62, 0xb9, 0x08, 0xbf, 0xec);

