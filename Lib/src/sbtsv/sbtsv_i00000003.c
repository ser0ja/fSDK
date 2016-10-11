// Created file "Lib\src\sbtsv\sbtsv_i"

typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        extern const GUID name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

DEFINE_GUID(IID_ITsSbPlugin, 0x48cd7406, 0xcaab, 0x465f, 0xa5, 0xd6, 0xba, 0xa8, 0x63, 0xb9, 0xea, 0x4f);

DEFINE_GUID(IID_ITsSbResourcePlugin, 0x7633f4e7, 0x8a10, 0x49a1, 0x84, 0x13, 0xe4, 0x78, 0x30, 0x01, 0xb7, 0x0e);

DEFINE_GUID(IID_ITsSbLoadBalancing, 0x24329274, 0x9eb7, 0x11dc, 0xae, 0x98, 0xf2, 0xb4, 0x56, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbPlacement, 0xb937a478, 0x9eb6, 0x11dc, 0x83, 0x77, 0xd5, 0xb0, 0x56, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbOrchestration, 0x64fc1172, 0x9eb7, 0x11dc, 0x8b, 0x00, 0x3a, 0xba, 0x56, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbEnvironment, 0x8c87f7f7, 0xbf51, 0x4a5c, 0x87, 0xbf, 0x8e, 0x94, 0xfb, 0x6e, 0x22, 0x56);

DEFINE_GUID(IID_ITsSbLoadBalanceResult, 0x24fdb7ac, 0xfea6, 0x11dc, 0x96, 0x72, 0x9a, 0x89, 0x56, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbTarget, 0xe85e10ea, 0xdb0b, 0x4752, 0xb4, 0x56, 0x5f, 0xd5, 0x84, 0x09, 0x01, 0xc0);

DEFINE_GUID(IID_ITsSbSession, 0x1ef3d5cf, 0x8fbb, 0x4a5a, 0xab, 0x4a, 0x7f, 0x85, 0xb2, 0x18, 0xbd, 0x8d);

DEFINE_GUID(IID_ITsSbResourceNotification, 0x65d3e85a, 0xc39b, 0x11dc, 0xb9, 0x2d, 0x3c, 0xd2, 0x55, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbPropertySet, 0x5c025171, 0xbb1e, 0x4baf, 0xa2, 0x12, 0x6d, 0x5e, 0x97, 0x74, 0xb3, 0x3b);

DEFINE_GUID(IID_ITsSbPluginPropertySet, 0x95006e34, 0x7eff, 0x4b6c, 0xbb, 0x40, 0x49, 0xa4, 0xfd, 0xa7, 0xce, 0xa6);

DEFINE_GUID(IID_ITsSbClientConnectionPropertySet, 0xe51995b0, 0x46d6, 0x11dd, 0xaa, 0x21, 0xce, 0xdc, 0x55, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbTargetPropertySet, 0xf7bda5d6, 0x994c, 0x4e11, 0xa0, 0x79, 0x27, 0x63, 0xb6, 0x18, 0x30, 0xac);

DEFINE_GUID(IID_ITsSbEnvironmentPropertySet, 0xd0d1bf7e, 0x7acf, 0x11dd, 0xa2, 0x43, 0xe5, 0x11, 0x56, 0xd8, 0x95, 0x93);

DEFINE_GUID(IID_ITsSbBaseNotifySink, 0x808a6537, 0x1282, 0x4989, 0x9e, 0x09, 0xf4, 0x39, 0x38, 0xb7, 0x17, 0x22);

DEFINE_GUID(IID_ITsSbPluginNotifySink, 0x44dfe30b, 0xc3be, 0x40f5, 0xbf, 0x82, 0x7a, 0x95, 0xbb, 0x79, 0x5a, 0xdf);

DEFINE_GUID(IID_ITsSbTargetNotifySink, 0x2be69924, 0xddf2, 0x44b9, 0xab, 0x92, 0x2c, 0x27, 0xae, 0xfb, 0x43, 0x79);

DEFINE_GUID(IID_ITsSbSessionNotifySink, 0xa821601f, 0xd822, 0x4fe2, 0xa2, 0xa3, 0xcd, 0x4b, 0x00, 0x65, 0x2a, 0x1a);

DEFINE_GUID(IID_ITsSbLoadBalancingNotifySink, 0x7f3fdb2f, 0xc8dc, 0x4873, 0xa6, 0x00, 0x85, 0x80, 0x78, 0x7b, 0xaa, 0x64);

DEFINE_GUID(IID_ITsSbPlacementNotifySink, 0x3a2da1d1, 0x1ad9, 0x4248, 0xac, 0x21, 0x13, 0xbb, 0xc2, 0x73, 0xdd, 0x42);

DEFINE_GUID(IID_ITsSbOrchestrationNotifySink, 0x36c37d61, 0x926b, 0x442f, 0xbc, 0xa5, 0x11, 0x8c, 0x6d, 0x50, 0xdc, 0xf2);

DEFINE_GUID(IID_ITsSbClientConnection, 0xda852238, 0x59c8, 0x481f, 0x99, 0x6b, 0x30, 0x13, 0x88, 0xd4, 0x96, 0xd3);

DEFINE_GUID(IID_ITsSbProvider, 0x67199246, 0xf3a4, 0x4035, 0xa1, 0xf2, 0xbe, 0x2f, 0x16, 0xaf, 0xb1, 0xaf);

DEFINE_GUID(IID_ITsSbResourcePluginStore, 0x03aba8da, 0x3fdf, 0x4c3f, 0x93, 0x04, 0x78, 0x42, 0x43, 0x0c, 0xc6, 0x06);

DEFINE_GUID(IID_ITsSbGlobalStore, 0xd521ad43, 0x7123, 0x49a2, 0x86, 0x22, 0x88, 0x71, 0xa1, 0x47, 0x43, 0x9e);
