__int64 sub_1400216C0()
{
    char* v0; // rbx
    __int64 v1; // rcx
    int v2; // eax
    int v3; // r9d
    char* v4; // rcx
    int v5; // edx
    __int64 v6; // rdx
    float v7; // xmm0_4
    int v8; // eax
    _QWORD* v9; // rax
    char* v10; // rdx
    __int64 v11; // rcx
    float v12; // xmm0_4
    int v13; // eax
    _QWORD* v14; // rax
    char* v15; // rdx
    __int64 v16; // rcx
    float v17; // xmm0_4
    int v18; // eax
    _QWORD* v19; // rax
    __int128 v20; // xmm0
    const char* v21; // rdx
    __int64 v22; // r8
    _QWORD* v23; // rax
    char* v24; // rdx
    __int64 v25; // rcx
    float v26; // xmm0_4
    int v27; // eax
    _QWORD* v28; // rax
    int v29; // ebx
    int v30; // edx
    float* v31; // rax
    struct tagPOINT* p_Point; // r9
    _QWORD* v33; // rax
    const char* v34; // rdx
    char* v35; // rdx
    __int64 v36; // rcx
    float v37; // xmm0_4
    int v38; // eax
    char* v39; // rbx
    int v40; // eax
    int v41; // r9d
    char* v42; // rdx
    __int64 v43; // rcx
    float v44; // xmm0_4
    int v45; // eax
    __int128 v47; // [rsp+48h] [rbp+7h] BYREF
    float v48; // [rsp+58h] [rbp+17h] BYREF
    struct tagPOINT Point; // [rsp+60h] [rbp+1Fh] BYREF
    char Buffer[16]; // [rsp+68h] [rbp+27h] BYREF

    byte_140033048 = 1;
    Point = 0;
    sub_140007CD0("[AlisaAlis Injector] (x64)", 34);
    v0 = off_140033040;
    Point = 0;
    sub_14000B6F0(*((_QWORD*)off_140033040 + 751), &Point, 0);
    v1 = *((_QWORD*)v0 + 751);
    Point.x = 1141473280;
    Point.y = 1128792064;
    *(_DWORD*)(v1 + 176) &= 0xFFFFFFF1;
    *(_QWORD*)(v1 + 152) = 0;
    *(_DWORD*)(v1 + 44) = 1142456320;
    *(_DWORD*)(v1 + 48) = 1143111680;
    *(_BYTE*)(*((_QWORD*)v0 + 751) + 138LL) = 1;
    v2 = sub_1400022C0(
        "Process",
        0,
        *(unsigned int*)(*(_QWORD*)(*((_QWORD*)v0 + 751) + 504LL)
            + 4LL * (*(_DWORD*)(*((_QWORD*)v0 + 751) + 496LL) - 1)));
    if (*((_DWORD*)v0 + 1517) == v2)
        v0[6076] = 1;
    LOBYTE(v3) = 1;
    sub_1400070A0((unsigned int)"Process", v2, (unsigned int)&Point, v3, 0);
    Point.x = 1114636288;
    Point.y = 1106247680;
    sub_14000C370("Move", &Point, 0);
    v4 = off_140033040;
    v5 = *((_DWORD*)off_140033040 + 1517);
    if (v5 && v5 == *(_DWORD*)(*((_QWORD*)off_140033040 + 751) + 248LL))
    {
        if (GetCursorPos(&Point))
        {
            byte_140033048 = 0;
            SetWindowPos(hWnd, nullptr, Point.x, Point.y, 610, 650, 0x20u);
        }
        v4 = off_140033040;
    }
    if (*(_BYTE*)(*((_QWORD*)v4 + 751) + 268LL))
    {
        sub_140006A00("For Moving Window Click And Drag");
        v4 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v4 + 751) + 138LL) = 1;
    v6 = *((_QWORD*)v4 + 751);
    if (!*(_BYTE*)(v6 + 140))
    {
        v7 = *((float*)v4 + 1292) + *(float*)(v6 + 200);
        *(_DWORD*)(v6 + 196) = *(_DWORD*)(v6 + 204);
        *(_DWORD*)(v6 + 224) = *(_DWORD*)(v6 + 232);
        v8 = *(_DWORD*)(v6 + 236);
        *(float*)(v6 + 192) = v7;
        *(_DWORD*)(v6 + 228) = v8;
    }
    v47 = xmmword_14002DD00;
    sub_14000B980(&v47, "                  Process Name", 0);
    v9 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v9 = operator new(0x28u);
        Point = (struct tagPOINT)v9;
        qword_140050FA0 = (__int64)v9;
        v9[3] = 0;
        v9[4] = 0;
        *v9 = 0;
        v9[1] = 0;
        v9[2] = 0;
        *((_DWORD*)v9 + 6) = 0;
        *((_WORD*)v9 + 14) = 256;
        *((_DWORD*)v9 + 8) = 0;
        *((_BYTE*)v9 + 36) = 0;
    }
    sub_14000CD30("as", (char*)v9 + 29, 0);
    v10 = off_140033040;
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
    {
        sub_140006A00("Show Only x64 Bit Procces");
        v10 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v10 + 751) + 138LL) = 1;
    v11 = *((_QWORD*)v10 + 751);
    if (!*(_BYTE*)(v11 + 140))
    {
        v12 = *((float*)v10 + 1292) + *(float*)(v11 + 200);
        *(_DWORD*)(v11 + 196) = *(_DWORD*)(v11 + 204);
        *(_DWORD*)(v11 + 224) = *(_DWORD*)(v11 + 232);
        v13 = *(_DWORD*)(v11 + 236);
        *(float*)(v11 + 192) = v12;
        *(_DWORD*)(v11 + 228) = v13;
    }
    if (!qword_140050FA0)
    {
        v14 = operator new(0x28u);
        Point = (struct tagPOINT)v14;
        LODWORD(v11) = 0;
        qword_140050FA0 = (__int64)v14;
        v14[3] = 0;
        v14[4] = 0;
        *v14 = 0;
        v14[1] = 0;
        v14[2] = 0;
        *((_DWORD*)v14 + 6) = 0;
        *((_WORD*)v14 + 14) = 256;
        *((_DWORD*)v14 + 8) = 0;
        *((_BYTE*)v14 + 36) = 0;
    }
    Point = 0;
    sub_14000EEF0(v11, (unsigned int)&Destination, 128, (unsigned int)&Point, 0);
    v15 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v16 = *((_QWORD*)v15 + 751);
    if (!*(_BYTE*)(v16 + 140))
    {
        v17 = *((float*)v15 + 1292) + *(float*)(v16 + 200);
        *(_DWORD*)(v16 + 196) = *(_DWORD*)(v16 + 204);
        *(_DWORD*)(v16 + 224) = *(_DWORD*)(v16 + 232);
        v18 = *(_DWORD*)(v16 + 236);
        *(float*)(v16 + 192) = v17;
        *(_DWORD*)(v16 + 228) = v18;
    }
    if (!qword_140050FA0)
    {
        v19 = operator new(0x28u);
        Point = (struct tagPOINT)v19;
        qword_140050FA0 = (__int64)v19;
        v19[3] = 0;
        v19[4] = 0;
        *v19 = 0;
        v19[1] = 0;
        v19[2] = 0;
        *((_DWORD*)v19 + 6) = 0;
        *((_WORD*)v19 + 14) = 256;
        *((_DWORD*)v19 + 8) = 0;
        *((_BYTE*)v19 + 36) = 0;
    }
    sub_140022D70();
    if ((unsigned __int8)sub_140023F60())
    {
        v20 = xmmword_14002DD10;
        v21 = "                                 Procces Online";
    }
    else
    {
        v20 = xmmword_14002DD00;
        v21 = "                                 Process Offline";
    }
    v47 = v20;
    sub_14000B980(&v47, v21, 0);
    v23 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v23 = operator new(0x28u);
        Point = (struct tagPOINT)v23;
        qword_140050FA0 = (__int64)v23;
        v23[3] = 0;
        v23[4] = 0;
        *v23 = 0;
        v23[1] = 0;
        v23[2] = 0;
        *((_DWORD*)v23 + 6) = 0;
        *((_WORD*)v23 + 14) = 256;
        *((_DWORD*)v23 + 8) = 0;
        *((_BYTE*)v23 + 36) = 0;
    }
    LOBYTE(v22) = 1;
    sub_14000CD30("Auto Inject", (char*)v23 + 28, v22);
    v24 = off_140033040;
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
    {
        sub_140006A00("Inject When it detects Process Has Been Started");
        v24 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v24 + 751) + 138LL) = 1;
    v25 = *((_QWORD*)v24 + 751);
    if (!*(_BYTE*)(v25 + 140))
    {
        v26 = *((float*)v24 + 1292) + *(float*)(v25 + 200);
        *(_DWORD*)(v25 + 196) = *(_DWORD*)(v25 + 204);
        *(_DWORD*)(v25 + 224) = *(_DWORD*)(v25 + 232);
        v27 = *(_DWORD*)(v25 + 236);
        *(float*)(v25 + 192) = v26;
        *(_DWORD*)(v25 + 228) = v27;
    }
    LODWORD(v28) = qword_140050FA0;
    if (!qword_140050FA0)
    {
        v28 = operator new(0x28u);
        Point = (struct tagPOINT)v28;
        qword_140050FA0 = (__int64)v28;
        v28[3] = 0;
        v28[4] = 0;
        *v28 = 0;
        v28[1] = 0;
        v28[2] = 0;
        *((_DWORD*)v28 + 6) = 0;
        *((_WORD*)v28 + 14) = 256;
        *((_DWORD*)v28 + 8) = 0;
        *((_BYTE*)v28 + 36) = 0;
    }
    v48 = 0.0;
    Point.x = 1120403456;
    v29 = (_DWORD)v28 + 32;
    sub_1400021C0(Buffer);
    v31 = &v48;
    p_Point = &Point;
    if (v48 <= 0.0)
        v31 = nullptr;
    if (*(float*)&Point.x <= 0.0)
        LODWORD(p_Point) = 0;
    sub_140010F60((unsigned int)Buffer, v30, v29, (_DWORD)p_Point, (__int64)v31, (__int64)Buffer);
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
        sub_140006A00("(MiliSeconds) Delay The Injection \nThis Amount Of time (Only When Auto inject Selected)");
    v33 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v33 = operator new(0x28u);
        *(_QWORD*)&v47 = v33;
        qword_140050FA0 = (__int64)v33;
        v33[3] = 0;
        v33[4] = 0;
        *v33 = 0;
        v33[1] = 0;
        v33[2] = 0;
        *((_DWORD*)v33 + 6) = 0;
        *((_WORD*)v33 + 14) = 256;
        *((_DWORD*)v33 + 8) = 0;
        *((_BYTE*)v33 + 36) = 0;
    }
    if (*((_BYTE*)v33 + 36))
    {
        v34 = "                                 Auto Inject Complete...";
    }
    else
    {
        if (!*((_BYTE*)v33 + 28))
            goto LABEL_48;
        v34 = "                                 Waiting For Process...";
    }
    *(_OWORD*)Buffer = xmmword_14002DD10;
    sub_14000B980(Buffer, v34, 0);
LABEL_48:
    sub_1400072A0();
    v35 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v36 = *((_QWORD*)v35 + 751);
    if (!*(_BYTE*)(v36 + 140))
    {
        v37 = *((float*)v35 + 1292) + *(float*)(v36 + 200);
        *(_DWORD*)(v36 + 196) = *(_DWORD*)(v36 + 204);
        *(_DWORD*)(v36 + 224) = *(_DWORD*)(v36 + 232);
        v38 = *(_DWORD*)(v36 + 236);
        *(float*)(v36 + 192) = v37;
        *(_DWORD*)(v36 + 228) = v38;
    }
    Point = 0;
    if ((unsigned __int8)sub_14000C370("X", &Point, 0))
        ExitProcess(1u);
    v39 = off_140033040;
    Point.x = 1141473280;
    Point.y = 1128792064;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v40 = sub_1400022C0(
        "DllSelector",
        0,
        *(unsigned int*)(*(_QWORD*)(*((_QWORD*)v39 + 751) + 504LL)
            + 4LL * (*(_DWORD*)(*((_QWORD*)v39 + 751) + 496LL) - 1)));
    if (*((_DWORD*)v39 + 1517) == v40)
        v39[6076] = 1;
    LOBYTE(v41) = 1;
    sub_1400070A0((unsigned int)"DllSelector", v40, (unsigned int)&Point, v41, 0);
    sub_140023750();
    sub_1400072A0();
    sub_14000B830("                ");
    v42 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v43 = *((_QWORD*)v42 + 751);
    if (!*(_BYTE*)(v43 + 140))
    {
        v44 = *((float*)v42 + 1292) + *(float*)(v43 + 200);
        *(_DWORD*)(v43 + 196) = *(_DWORD*)(v43 + 204);
        *(_DWORD*)(v43 + 224) = *(_DWORD*)(v43 + 232);
        v45 = *(_DWORD*)(v43 + 236);
        *(float*)(v43 + 192) = v44;
        *(_DWORD*)(v43 + 228) = v45;
    }
    Point.x = 1135869952;
    Point.y = 1120403456;
    if ((unsigned __int8)sub_14000C370("MANUAL MAP INJECT", &Point, 0))
        sub_1400240F0();
    return sub_14000A7F0();
}
char __fastcall sub_14000C370(__int64 a1, _QWORD* a2, int a3)
{
    char* v3; // rbx
    __int64 v7; // rdi
    char result; // al
    int v9; // r8d
    int v10; // r9d
    int v11; // r12d
    _BYTE* v12; // rcx
    float* v13; // r14
    float v14; // xmm7_4
    float v15; // xmm1_4
    float v16; // xmm1_4
    float v17; // xmm2_4
    float v18; // xmm0_4
    float v19; // xmm8_4
    int v20; // eax
    char v21; // di
    __int64 v22; // rcx
    int v23; // eax
    int v24; // r9d
    float v25; // xmm1_4
    unsigned int v26; // xmm0_4
    int v27; // r9d
    char v28; // [rsp+40h] [rbp-29h] BYREF
    char v29; // [rsp+41h] [rbp-28h] BYREF
    unsigned __int64 v30; // [rsp+48h] [rbp-21h] BYREF
    float v31; // [rsp+50h] [rbp-19h] BYREF
    float v32; // [rsp+54h] [rbp-15h]
    _DWORD v33[2]; // [rsp+58h] [rbp-11h] BYREF
    int v34; // [rsp+60h] [rbp-9h] BYREF
    float v35; // [rsp+68h] [rbp-1h] BYREF
    float v36; // [rsp+6Ch] [rbp+3h]
    float v37; // [rsp+70h] [rbp+7h]
    float v38; // [rsp+74h] [rbp+Bh]

    v3 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v7 = *((_QWORD*)v3 + 751);
    if (*(_BYTE*)(v7 + 140))
        return 0;
    v11 = sub_1400022C0(a1, 0, *(unsigned int*)(*(_QWORD*)(v7 + 504) + 4LL * (*(_DWORD*)(v7 + 496) - 1)));
    if (*((_DWORD*)v3 + 1517) == v11)
        v3[6076] = 1;
    v34 = v11;
    v12 = (_BYTE*)a1;
    if (a1 != -1)
    {
        do
        {
            if (!*v12 || *v12 == 35 && v12[1] == 35)
                break;
            ++v12;
        } while (v12 != (_BYTE*)-1LL);
    }
    v13 = *((float**)v3 + 742);
    v14 = *((float*)v3 + 1486);
    if ((_BYTE*)a1 == v12)
    {
        v15 = 0.0;
    }
    else
    {
        sub_14001FC30((_DWORD)v13, (unsigned int)&v30, v9, v10, -1082130432, a1, (__int64)v12);
        v16 = *(float*)&v30;
        if (*(float*)&v30 > 0.0)
            v16 = *(float*)&v30 - (float)(v14 / *v13);
        v14 = *((float*)&v30 + 1);
        v15 = (float)(int)(float)(v16 + 0.94999999);
    }
    v30 = *(_QWORD*)(v7 + 192);
    *(float*)&v33[1] = v14;
    *(float*)v33 = v15;
    if ((a3 & 0x100) != 0 && (v17 = *((float*)v3 + 1290), v18 = *(float*)(v7 + 228), v18 > v17))
        v19 = *((float*)&v30 + 1) + (float)(v18 - v17);
    else
        v19 = *((float*)&v30 + 1);
    sub_140003590(&v31, *a2);
    v35 = *(float*)&v30;
    v36 = v19;
    v37 = *(float*)&v30 + v31;
    v38 = v32 + v19;
    v31 = (float)(*(float*)&v30 + v31) - *(float*)&v30;
    v32 = (float)(v32 + v19) - v19;
    sub_1400031E0(&v31);
    result = sub_1400032E0(&v35, &v34);
    if (result)
    {
        v20 = a3 | 1;
        if (!*(_BYTE*)(v7 + 317))
            v20 = a3;
        v21 = sub_14000C080((unsigned int)&v35, v11, (unsigned int)&v28, (unsigned int)&v29, v20);
        if (v28 && v29)
            v22 = 24;
        else
            v22 = (unsigned int)(v28 != 0) + 22;
        v23 = sub_140002880(v22);
        LOBYTE(v24) = 1;
        sub_140006260(LODWORD(v35), LODWORD(v37), v23, v24, *((_DWORD*)v3 + 1291));
        v25 = v38 - *((float*)v3 + 1290);
        v31 = v37 - *((float*)v3 + 1289);
        *(float*)&v26 = v35 + *((float*)v3 + 1289);
        v32 = v25;
        v30 = __PAIR64__(v36 + *((float*)v3 + 1290), v26);
        sub_140005F00((unsigned int)&v30, (unsigned int)&v31, a1, v27, (__int64)v33, (__int64)(v3 + 5216), (__int64)&v35);
        return v21;
    }
    return result;
}
__int64 sub_1400216C0()
{
    char* v0; // rbx
    __int64 v1; // rcx
    int v2; // eax
    int v3; // r9d
    char* v4; // rcx
    int v5; // edx
    __int64 v6; // rdx
    float v7; // xmm0_4
    int v8; // eax
    _QWORD* v9; // rax
    char* v10; // rdx
    __int64 v11; // rcx
    float v12; // xmm0_4
    int v13; // eax
    _QWORD* v14; // rax
    char* v15; // rdx
    __int64 v16; // rcx
    float v17; // xmm0_4
    int v18; // eax
    _QWORD* v19; // rax
    __int128 v20; // xmm0
    const char* v21; // rdx
    __int64 v22; // r8
    _QWORD* v23; // rax
    char* v24; // rdx
    __int64 v25; // rcx
    float v26; // xmm0_4
    int v27; // eax
    _QWORD* v28; // rax
    int v29; // ebx
    int v30; // edx
    float* v31; // rax
    struct tagPOINT* p_Point; // r9
    _QWORD* v33; // rax
    const char* v34; // rdx
    char* v35; // rdx
    __int64 v36; // rcx
    float v37; // xmm0_4
    int v38; // eax
    char* v39; // rbx
    int v40; // eax
    int v41; // r9d
    char* v42; // rdx
    __int64 v43; // rcx
    float v44; // xmm0_4
    int v45; // eax
    __int128 v47; // [rsp+48h] [rbp+7h] BYREF
    float v48; // [rsp+58h] [rbp+17h] BYREF
    struct tagPOINT Point; // [rsp+60h] [rbp+1Fh] BYREF
    char Buffer[16]; // [rsp+68h] [rbp+27h] BYREF

    byte_140033048 = 1;
    Point = 0;
    sub_140007CD0("[AlisaAlis Injector] (x64)", 34);
    v0 = off_140033040;
    Point = 0;
    sub_14000B6F0(*((_QWORD*)off_140033040 + 751), &Point, 0);
    v1 = *((_QWORD*)v0 + 751);
    Point.x = 1141473280;
    Point.y = 1128792064;
    *(_DWORD*)(v1 + 176) &= 0xFFFFFFF1;
    *(_QWORD*)(v1 + 152) = 0;
    *(_DWORD*)(v1 + 44) = 1142456320;
    *(_DWORD*)(v1 + 48) = 1143111680;
    *(_BYTE*)(*((_QWORD*)v0 + 751) + 138LL) = 1;
    v2 = sub_1400022C0(
        "Process",
        0,
        *(unsigned int*)(*(_QWORD*)(*((_QWORD*)v0 + 751) + 504LL)
            + 4LL * (*(_DWORD*)(*((_QWORD*)v0 + 751) + 496LL) - 1)));
    if (*((_DWORD*)v0 + 1517) == v2)
        v0[6076] = 1;
    LOBYTE(v3) = 1;
    sub_1400070A0((unsigned int)"Process", v2, (unsigned int)&Point, v3, 0);
    Point.x = 1114636288;
    Point.y = 1106247680;
    sub_14000C370("Move", &Point, 0);
    v4 = off_140033040;
    v5 = *((_DWORD*)off_140033040 + 1517);
    if (v5 && v5 == *(_DWORD*)(*((_QWORD*)off_140033040 + 751) + 248LL))
    {
        if (GetCursorPos(&Point))
        {
            byte_140033048 = 0;
            SetWindowPos(hWnd, nullptr, Point.x, Point.y, 610, 650, 0x20u);
        }
        v4 = off_140033040;
    }
    if (*(_BYTE*)(*((_QWORD*)v4 + 751) + 268LL))
    {
        sub_140006A00("For Moving Window Click And Drag");
        v4 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v4 + 751) + 138LL) = 1;
    v6 = *((_QWORD*)v4 + 751);
    if (!*(_BYTE*)(v6 + 140))
    {
        v7 = *((float*)v4 + 1292) + *(float*)(v6 + 200);
        *(_DWORD*)(v6 + 196) = *(_DWORD*)(v6 + 204);
        *(_DWORD*)(v6 + 224) = *(_DWORD*)(v6 + 232);
        v8 = *(_DWORD*)(v6 + 236);
        *(float*)(v6 + 192) = v7;
        *(_DWORD*)(v6 + 228) = v8;
    }
    v47 = xmmword_14002DD00;
    sub_14000B980(&v47, "                  Process Name", 0);
    v9 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v9 = operator new(0x28u);
        Point = (struct tagPOINT)v9;
        qword_140050FA0 = (__int64)v9;
        v9[3] = 0;
        v9[4] = 0;
        *v9 = 0;
        v9[1] = 0;
        v9[2] = 0;
        *((_DWORD*)v9 + 6) = 0;
        *((_WORD*)v9 + 14) = 256;
        *((_DWORD*)v9 + 8) = 0;
        *((_BYTE*)v9 + 36) = 0;
    }
    sub_14000CD30("as", (char*)v9 + 29, 0);
    v10 = off_140033040;
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
    {
        sub_140006A00("Show Only x64 Bit Procces");
        v10 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v10 + 751) + 138LL) = 1;
    v11 = *((_QWORD*)v10 + 751);
    if (!*(_BYTE*)(v11 + 140))
    {
        v12 = *((float*)v10 + 1292) + *(float*)(v11 + 200);
        *(_DWORD*)(v11 + 196) = *(_DWORD*)(v11 + 204);
        *(_DWORD*)(v11 + 224) = *(_DWORD*)(v11 + 232);
        v13 = *(_DWORD*)(v11 + 236);
        *(float*)(v11 + 192) = v12;
        *(_DWORD*)(v11 + 228) = v13;
    }
    if (!qword_140050FA0)
    {
        v14 = operator new(0x28u);
        Point = (struct tagPOINT)v14;
        LODWORD(v11) = 0;
        qword_140050FA0 = (__int64)v14;
        v14[3] = 0;
        v14[4] = 0;
        *v14 = 0;
        v14[1] = 0;
        v14[2] = 0;
        *((_DWORD*)v14 + 6) = 0;
        *((_WORD*)v14 + 14) = 256;
        *((_DWORD*)v14 + 8) = 0;
        *((_BYTE*)v14 + 36) = 0;
    }
    Point = 0;
    sub_14000EEF0(v11, (unsigned int)&Destination, 128, (unsigned int)&Point, 0);
    v15 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v16 = *((_QWORD*)v15 + 751);
    if (!*(_BYTE*)(v16 + 140))
    {
        v17 = *((float*)v15 + 1292) + *(float*)(v16 + 200);
        *(_DWORD*)(v16 + 196) = *(_DWORD*)(v16 + 204);
        *(_DWORD*)(v16 + 224) = *(_DWORD*)(v16 + 232);
        v18 = *(_DWORD*)(v16 + 236);
        *(float*)(v16 + 192) = v17;
        *(_DWORD*)(v16 + 228) = v18;
    }
    if (!qword_140050FA0)
    {
        v19 = operator new(0x28u);
        Point = (struct tagPOINT)v19;
        qword_140050FA0 = (__int64)v19;
        v19[3] = 0;
        v19[4] = 0;
        *v19 = 0;
        v19[1] = 0;
        v19[2] = 0;
        *((_DWORD*)v19 + 6) = 0;
        *((_WORD*)v19 + 14) = 256;
        *((_DWORD*)v19 + 8) = 0;
        *((_BYTE*)v19 + 36) = 0;
    }
    sub_140022D70();
    if ((unsigned __int8)sub_140023F60())
    {
        v20 = xmmword_14002DD10;
        v21 = "                                 Procces Online";
    }
    else
    {
        v20 = xmmword_14002DD00;
        v21 = "                                 Process Offline";
    }
    v47 = v20;
    sub_14000B980(&v47, v21, 0);
    v23 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v23 = operator new(0x28u);
        Point = (struct tagPOINT)v23;
        qword_140050FA0 = (__int64)v23;
        v23[3] = 0;
        v23[4] = 0;
        *v23 = 0;
        v23[1] = 0;
        v23[2] = 0;
        *((_DWORD*)v23 + 6) = 0;
        *((_WORD*)v23 + 14) = 256;
        *((_DWORD*)v23 + 8) = 0;
        *((_BYTE*)v23 + 36) = 0;
    }
    LOBYTE(v22) = 1;
    sub_14000CD30("Auto Inject", (char*)v23 + 28, v22);
    v24 = off_140033040;
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
    {
        sub_140006A00("Inject When it detects Process Has Been Started");
        v24 = off_140033040;
    }
    *(_BYTE*)(*((_QWORD*)v24 + 751) + 138LL) = 1;
    v25 = *((_QWORD*)v24 + 751);
    if (!*(_BYTE*)(v25 + 140))
    {
        v26 = *((float*)v24 + 1292) + *(float*)(v25 + 200);
        *(_DWORD*)(v25 + 196) = *(_DWORD*)(v25 + 204);
        *(_DWORD*)(v25 + 224) = *(_DWORD*)(v25 + 232);
        v27 = *(_DWORD*)(v25 + 236);
        *(float*)(v25 + 192) = v26;
        *(_DWORD*)(v25 + 228) = v27;
    }
    LODWORD(v28) = qword_140050FA0;
    if (!qword_140050FA0)
    {
        v28 = operator new(0x28u);
        Point = (struct tagPOINT)v28;
        qword_140050FA0 = (__int64)v28;
        v28[3] = 0;
        v28[4] = 0;
        *v28 = 0;
        v28[1] = 0;
        v28[2] = 0;
        *((_DWORD*)v28 + 6) = 0;
        *((_WORD*)v28 + 14) = 256;
        *((_DWORD*)v28 + 8) = 0;
        *((_BYTE*)v28 + 36) = 0;
    }
    v48 = 0.0;
    Point.x = 1120403456;
    v29 = (_DWORD)v28 + 32;
    sub_1400021C0(Buffer);
    v31 = &v48;
    p_Point = &Point;
    if (v48 <= 0.0)
        v31 = nullptr;
    if (*(float*)&Point.x <= 0.0)
        LODWORD(p_Point) = 0;
    sub_140010F60((unsigned int)Buffer, v30, v29, (_DWORD)p_Point, (__int64)v31, (__int64)Buffer);
    if (*(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 268LL))
        sub_140006A00("(MiliSeconds) Delay The Injection \nThis Amount Of time (Only When Auto inject Selected)");
    v33 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v33 = operator new(0x28u);
        *(_QWORD*)&v47 = v33;
        qword_140050FA0 = (__int64)v33;
        v33[3] = 0;
        v33[4] = 0;
        *v33 = 0;
        v33[1] = 0;
        v33[2] = 0;
        *((_DWORD*)v33 + 6) = 0;
        *((_WORD*)v33 + 14) = 256;
        *((_DWORD*)v33 + 8) = 0;
        *((_BYTE*)v33 + 36) = 0;
    }
    if (*((_BYTE*)v33 + 36))
    {
        v34 = "                                 Auto Inject Complete...";
    }
    else
    {
        if (!*((_BYTE*)v33 + 28))
            goto LABEL_48;
        v34 = "                                 Waiting For Process...";
    }
    *(_OWORD*)Buffer = xmmword_14002DD10;
    sub_14000B980(Buffer, v34, 0);
LABEL_48:
    sub_1400072A0();
    v35 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v36 = *((_QWORD*)v35 + 751);
    if (!*(_BYTE*)(v36 + 140))
    {
        v37 = *((float*)v35 + 1292) + *(float*)(v36 + 200);
        *(_DWORD*)(v36 + 196) = *(_DWORD*)(v36 + 204);
        *(_DWORD*)(v36 + 224) = *(_DWORD*)(v36 + 232);
        v38 = *(_DWORD*)(v36 + 236);
        *(float*)(v36 + 192) = v37;
        *(_DWORD*)(v36 + 228) = v38;
    }
    Point = 0;
    if ((unsigned __int8)sub_14000C370("X", &Point, 0))
        ExitProcess(1u);
    v39 = off_140033040;
    Point.x = 1141473280;
    Point.y = 1128792064;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v40 = sub_1400022C0(
        "DllSelector",
        0,
        *(unsigned int*)(*(_QWORD*)(*((_QWORD*)v39 + 751) + 504LL)
            + 4LL * (*(_DWORD*)(*((_QWORD*)v39 + 751) + 496LL) - 1)));
    if (*((_DWORD*)v39 + 1517) == v40)
        v39[6076] = 1;
    LOBYTE(v41) = 1;
    sub_1400070A0((unsigned int)"DllSelector", v40, (unsigned int)&Point, v41, 0);
    sub_140023750();
    sub_1400072A0();
    sub_14000B830("                ");
    v42 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v43 = *((_QWORD*)v42 + 751);
    if (!*(_BYTE*)(v43 + 140))
    {
        v44 = *((float*)v42 + 1292) + *(float*)(v43 + 200);
        *(_DWORD*)(v43 + 196) = *(_DWORD*)(v43 + 204);
        *(_DWORD*)(v43 + 224) = *(_DWORD*)(v43 + 232);
        v45 = *(_DWORD*)(v43 + 236);
        *(float*)(v43 + 192) = v44;
        *(_DWORD*)(v43 + 228) = v45;
    }
    Point.x = 1135869952;
    Point.y = 1120403456;
    if ((unsigned __int8)sub_14000C370("MANUAL MAP INJECT", &Point, 0))
        sub_1400240F0();
    return sub_14000A7F0();
}
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    LONG WindowLongA; // eax
    IDirect3D9* v6; // rbx
    _QWORD* v7; // rax
    WNDCLASSEXA v9; // [rsp+60h] [rbp-49h] BYREF
    struct tagMSG Msg; // [rsp+B0h] [rbp+7h] BYREF

    v9.cbSize = 80;
    *(_QWORD*)&v9.cbClsExtra = 0;
    v9.hbrBackground = CreateSolidBrush(0);
    v9.hCursor = LoadCursorA(nullptr, (LPCSTR)0x7F00);
    v9.hIcon = LoadIconA(nullptr, "devoicon_256px.ico");
    v9.hInstance = hInstance;
    v9.hIconSm = LoadIconA(nullptr, "devoicon_256px.ico");
    v9.lpszClassName = "AlisaAlis Injector (x64)";
    v9.lpfnWndProc = (WNDPROC)sub_140025760;
    v9.lpszMenuName = "AlisaAlis Injector (x64)";
    v9.style = 3;
    if (!RegisterClassExA(&v9))
        exit(154);
    hWnd = CreateWindowExA(
        0,
        "AlisaAlis Injector (x64)",
        "AlisaAlis Injector (x64)",
        0x80000000,
        500,
        100,
        610,
        600,
        nullptr,
        nullptr,
        nullptr,
        nullptr);
    SetLayeredWindowAttributes(hWnd, 0, 1u, 2u);
    SetLayeredWindowAttributes(hWnd, 0, 0, 1u);
    ShowWindow(hWnd, 5);
    WindowLongA = GetWindowLongA(hWnd, -20);
    SetWindowLongA(hWnd, -20, WindowLongA & 0xFFF7FFFF);
    SetForegroundWindow(hWnd);
    ShowWindow(hWnd, 5);
    v6 = Direct3DCreate9(0x20u);
    if (v6)
    {
        if (!qword_140050FA0)
        {
            v7 = operator new(0x28u);
            qword_140050FA0 = (__int64)v7;
            v7[3] = 0;
            v7[4] = 0;
            *v7 = 0;
            v7[1] = 0;
            v7[2] = 0;
            *((_DWORD*)v7 + 6) = 0;
            *((_WORD*)v7 + 14) = 256;
            *((_DWORD*)v7 + 8) = 0;
            *((_BYTE*)v7 + 36) = 0;
        }
        CreateThread(nullptr, 0, StartAddress, nullptr, 0, nullptr);
        qword_140054B78 = 0;
        qword_140054B88 = 1;
        qword_140054BA0 = 80;
        qword_140054BA8 = 0x8000000000000000uLL;
        qword_140054B98 = 0x100000001LL;
        qword_140054B70 = 0;
        qword_140054B80 = 0;
        qword_140054B90 = 0;
        if (((int(__fastcall*)(IDirect3D9*, _QWORD, __int64, HWND, int, __int64*, __int64*))v6->lpVtbl->CreateDevice)(
            v6,
            0,
            1,
            hWnd,
            64,
            &qword_140054B70,
            &qword_140050FA8) >= 0)
        {
            sub_140022280();
            *((_QWORD*)off_140033040 + 3) = &byte_1400296E6;
            memset(&Msg, 0, sizeof(Msg));
            ShowWindow(hWnd, 10);
            UpdateWindow(hWnd);
            while (Msg.message != 18)
            {
                if (PeekMessageA(&Msg, nullptr, 0, 0, 1u))
                {
                    TranslateMessage(&Msg);
                    DispatchMessageA(&Msg);
                }
                else
                {
                    sub_1400225F0();
                    sub_1400216C0();
                    (*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)qword_140050FA8 + 456LL))(qword_140050FA8, 7);
                    (*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)qword_140050FA8 + 456LL))(qword_140050FA8, 27);
                    (*(void(__fastcall**)(__int64, __int64, _QWORD))(*(_QWORD*)qword_140050FA8 + 456LL))(
                        qword_140050FA8,
                        174,
                        0);
                    (*(void(__fastcall**)(__int64, _QWORD, _QWORD, __int64, _DWORD, int, _DWORD))(*(_QWORD*)qword_140050FA8
                        + 344LL))(
                            qword_140050FA8,
                            0,
                            0,
                            1,
                            0,
                            1065353216,
                            0);
                    if ((*(int(__fastcall**)(__int64))(*(_QWORD*)qword_140050FA8 + 328LL))(qword_140050FA8) >= 0)
                    {
                        sub_140021F10();
                        sub_1400051B0();
                        (*(void(__fastcall**)(__int64))(*(_QWORD*)qword_140050FA8 + 336LL))(qword_140050FA8);
                    }
                    (*(void(__fastcall**)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD*)qword_140050FA8 + 136LL))(
                        qword_140050FA8,
                        0,
                        0,
                        0,
                        0);
                }
            }
            if (qword_140050FA8)
                (*(void(__fastcall**)(__int64))(*(_QWORD*)qword_140050FA8 + 16LL))(qword_140050FA8);
        }
        ((void(__fastcall*)(IDirect3D9*))v6->lpVtbl->Release)(v6);
    }
    UnregisterClassA("ImGui Example", v9.hInstance);
    return 0;
}
char sub_1400233B0()
{
    char* v0; // rdx
    __int64 v1; // rcx
    float v2; // xmm0_4
    int v3; // eax
    char result; // al
    char* v5; // rbx
    __int64 v6; // rcx
    _QWORD* v7; // rax
    __int64 v8; // rax
    __int64 v9; // rcx
    bool v10; // zf
    _QWORD* v11; // rax
    __int64 v12; // rax
    void* v13; // rcx
    unsigned __int64 v14; // rax
    __int64 Machine; // rcx
    __int64 v16; // rax
    _QWORD* v17; // [rsp+20h] [rbp-1F8h]
    char* v18; // [rsp+28h] [rbp-1F0h] BYREF
    unsigned __int64 v19; // [rsp+40h] [rbp-1D8h]
    char* v20; // [rsp+48h] [rbp-1D0h] BYREF
    struct tagOFNA v21; // [rsp+50h] [rbp-1C8h] BYREF
    char Source[272]; // [rsp+F0h] [rbp-128h] BYREF

    sub_14000B830("                                 ");
    v0 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v1 = *((_QWORD*)v0 + 751);
    if (!*(_BYTE*)(v1 + 140))
    {
        v2 = *((float*)v0 + 1292) + *(float*)(v1 + 200);
        *(_DWORD*)(v1 + 196) = *(_DWORD*)(v1 + 204);
        *(_DWORD*)(v1 + 224) = *(_DWORD*)(v1 + 232);
        v3 = *(_DWORD*)(v1 + 236);
        *(float*)(v1 + 192) = v2;
        *(_DWORD*)(v1 + 228) = v3;
    }
    v20 = nullptr;
    result = sub_14000C370((__int64)"ADD DLL..", &v20, 0);
    if (result)
    {
        memset(Source, 0, 0x104u);
        memset(&v21, 0, sizeof(v21));
        v21.hwndOwner = hWnd;
        v21.lpstrFilter = "DLL Files";
        v21.lpstrFile = Source;
        v21.lpstrTitle = "Please Select DLL File";
        v21.lStructSize = 152;
        v21.nMaxFile = 260;
        v21.Flags = 33558528;
        if (GetOpenFileNameA(&v21))
        {
            v5 = (char*)operator new(0x210u);
            memset(v5, 0, 0x210u);
            v20 = v5;
            if (!qword_140050FA0)
            {
                v7 = operator new(0x28u);
                v6 = 0;
                qword_140050FA0 = (__int64)v7;
                v7[3] = 0;
                v7[4] = 0;
                *v7 = 0;
                v7[1] = 0;
                v7[2] = 0;
                *((_DWORD*)v7 + 6) = 0;
                *((_WORD*)v7 + 14) = 256;
                *((_DWORD*)v7 + 8) = 0;
                *((_BYTE*)v7 + 36) = 0;
            }
            v8 = sub_1400229B0(v6, Source);
            v10 = qword_140050FA0 == 0;
            *(_QWORD*)v5 = v8;
            if (v10)
            {
                v11 = operator new(0x28u);
                v9 = 0;
                qword_140050FA0 = (__int64)v11;
                v11[3] = 0;
                v11[4] = 0;
                *v11 = 0;
                v11[1] = 0;
                v11[2] = 0;
                *((_DWORD*)v11 + 6) = 0;
                *((_WORD*)v11 + 14) = 256;
                *((_DWORD*)v11 + 8) = 0;
                *((_BYTE*)v11 + 36) = 0;
            }
            v12 = sub_140022AB0(v9, &v18, Source);
            if (*(_QWORD*)(v12 + 24) >= 0x10u)
                v12 = *(_QWORD*)v12;
            strcpy_s(v5 + 264, 0x100u, (const char*)v12);
            if (v19 >= 0x10)
            {
                v13 = v18;
                if (v19 + 1 >= 0x1000)
                {
                    if (((unsigned __int8)v18 & 0x1F) != 0)
                        invalid_parameter_noinfo_noreturn();
                    v14 = *((_QWORD*)v18 - 1);
                    if (v14 >= (unsigned __int64)v18)
                        invalid_parameter_noinfo_noreturn();
                    if ((unsigned __int64)&v18[-v14] < 8)
                        invalid_parameter_noinfo_noreturn();
                    if ((unsigned __int64)&v18[-v14] > 0x27)
                        invalid_parameter_noinfo_noreturn();
                    v13 = *((void**)v18 - 1);
                }
                j_free(v13);
            }
            strcpy_s(v5 + 8, 0x100u, Source);
            v10 = qword_140050FA0 == 0;
            v5[520] = 0;
            if (v10)
            {
                v17 = operator new(0x28u);
                qword_140050FA0 = (__int64)v17;
                v17[3] = 0;
                v17[4] = 0;
                *v17 = 0;
                v17[1] = 0;
                v17[2] = 0;
                *((_DWORD*)v17 + 6) = 0;
                *((_WORD*)v17 + 14) = 256;
                *((_DWORD*)v17 + 8) = 0;
                *((_BYTE*)v17 + 36) = 0;
            }
            Machine = ImageNtHeader(*(PVOID*)v5)->FileHeader.Machine;
            if ((_WORD)Machine == 332 || (_WORD)Machine != 0x8664 && (_DWORD)v20)
            {
                return MessageBoxA(nullptr, "This DLL is x86 You are running x64 program", "Dll Bit Error", 0);
            }
            else
            {
                v16 = sub_140024300(Machine);
                return sub_140024350(v16, &v20);
            }
        }
        else
        {
            return strcpy_s(byte_140050EA0, 0x100u, "No File");
        }
    }
    return result;
}
char sub_1400233B0()
{
    char* v0; // rdx
    __int64 v1; // rcx
    float v2; // xmm0_4
    int v3; // eax
    char result; // al
    char* v5; // rbx
    __int64 v6; // rcx
    _QWORD* v7; // rax
    __int64 v8; // rax
    __int64 v9; // rcx
    bool v10; // zf
    _QWORD* v11; // rax
    __int64 v12; // rax
    void* v13; // rcx
    unsigned __int64 v14; // rax
    __int64 Machine; // rcx
    __int64 v16; // rax
    _QWORD* v17; // [rsp+20h] [rbp-1F8h]
    char* v18; // [rsp+28h] [rbp-1F0h] BYREF
    unsigned __int64 v19; // [rsp+40h] [rbp-1D8h]
    char* v20; // [rsp+48h] [rbp-1D0h] BYREF
    struct tagOFNA v21; // [rsp+50h] [rbp-1C8h] BYREF
    char Source[272]; // [rsp+F0h] [rbp-128h] BYREF

    sub_14000B830("                                 ");
    v0 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    v1 = *((_QWORD*)v0 + 751);
    if (!*(_BYTE*)(v1 + 140))
    {
        v2 = *((float*)v0 + 1292) + *(float*)(v1 + 200);
        *(_DWORD*)(v1 + 196) = *(_DWORD*)(v1 + 204);
        *(_DWORD*)(v1 + 224) = *(_DWORD*)(v1 + 232);
        v3 = *(_DWORD*)(v1 + 236);
        *(float*)(v1 + 192) = v2;
        *(_DWORD*)(v1 + 228) = v3;
    }
    v20 = nullptr;
    result = sub_14000C370((__int64)"ADD DLL..", &v20, 0);
    if (result)
    {
        memset(Source, 0, 0x104u);
        memset(&v21, 0, sizeof(v21));
        v21.hwndOwner = hWnd;
        v21.lpstrFilter = "DLL Files";
        v21.lpstrFile = Source;
        v21.lpstrTitle = "Please Select DLL File";
        v21.lStructSize = 152;
        v21.nMaxFile = 260;
        v21.Flags = 33558528;
        if (GetOpenFileNameA(&v21))
        {
            v5 = (char*)operator new(0x210u);
            memset(v5, 0, 0x210u);
            v20 = v5;
            if (!qword_140050FA0)
            {
                v7 = operator new(0x28u);
                v6 = 0;
                qword_140050FA0 = (__int64)v7;
                v7[3] = 0;
                v7[4] = 0;
                *v7 = 0;
                v7[1] = 0;
                v7[2] = 0;
                *((_DWORD*)v7 + 6) = 0;
                *((_WORD*)v7 + 14) = 256;
                *((_DWORD*)v7 + 8) = 0;
                *((_BYTE*)v7 + 36) = 0;
            }
            v8 = sub_1400229B0(v6, Source);
            v10 = qword_140050FA0 == 0;
            *(_QWORD*)v5 = v8;
            if (v10)
            {
                v11 = operator new(0x28u);
                v9 = 0;
                qword_140050FA0 = (__int64)v11;
                v11[3] = 0;
                v11[4] = 0;
                *v11 = 0;
                v11[1] = 0;
                v11[2] = 0;
                *((_DWORD*)v11 + 6) = 0;
                *((_WORD*)v11 + 14) = 256;
                *((_DWORD*)v11 + 8) = 0;
                *((_BYTE*)v11 + 36) = 0;
            }
            v12 = sub_140022AB0(v9, &v18, Source);
            if (*(_QWORD*)(v12 + 24) >= 0x10u)
                v12 = *(_QWORD*)v12;
            strcpy_s(v5 + 264, 0x100u, (const char*)v12);
            if (v19 >= 0x10)
            {
                v13 = v18;
                if (v19 + 1 >= 0x1000)
                {
                    if (((unsigned __int8)v18 & 0x1F) != 0)
                        invalid_parameter_noinfo_noreturn();
                    v14 = *((_QWORD*)v18 - 1);
                    if (v14 >= (unsigned __int64)v18)
                        invalid_parameter_noinfo_noreturn();
                    if ((unsigned __int64)&v18[-v14] < 8)
                        invalid_parameter_noinfo_noreturn();
                    if ((unsigned __int64)&v18[-v14] > 0x27)
                        invalid_parameter_noinfo_noreturn();
                    v13 = *((void**)v18 - 1);
                }
                j_free(v13);
            }
            strcpy_s(v5 + 8, 0x100u, Source);
            v10 = qword_140050FA0 == 0;
            v5[520] = 0;
            if (v10)
            {
                v17 = operator new(0x28u);
                qword_140050FA0 = (__int64)v17;
                v17[3] = 0;
                v17[4] = 0;
                *v17 = 0;
                v17[1] = 0;
                v17[2] = 0;
                *((_DWORD*)v17 + 6) = 0;
                *((_WORD*)v17 + 14) = 256;
                *((_DWORD*)v17 + 8) = 0;
                *((_BYTE*)v17 + 36) = 0;
            }
            Machine = ImageNtHeader(*(PVOID*)v5)->FileHeader.Machine;
            if ((_WORD)Machine == 332 || (_WORD)Machine != 0x8664 && (_DWORD)v20)
            {
                return MessageBoxA(nullptr, "This DLL is x86 You are running x64 program", "Dll Bit Error", 0);
            }
            else
            {
                v16 = sub_140024300(Machine);
                return sub_140024350(v16, &v20);
            }
        }
        else
        {
            return strcpy_s(byte_140050EA0, 0x100u, "No File");
        }
    }
    return result;
}
char __fastcall sub_140025390(char* lpBuffer)
{
    DWORD v2; // eax
    HANDLE v3; // rbp
    char* v4; // rax
    char* v5; // rdi
    char* v6; // r15
    unsigned __int64 v7; // rsi
    unsigned int* v8; // rbx
    ULONG(__stdcall * v9)(PVOID); // rax
    ULONG(__stdcall * v10)(PVOID); // rsi
    char* v11; // rax
    HMODULE ModuleHandleA; // rax
    HMODULE v13; // rax
    HMODULE v14; // rax
    void* v15; // rax
    void* v16; // rdi
    HANDLE RemoteThread; // rax
    _QWORD Buffer[7]; // [rsp+40h] [rbp-68h] BYREF

    v2 = sub_1400256B0();
    v3 = OpenProcess(0x1FFFFFu, 0, v2);
    if (*(_WORD*)lpBuffer == 23117)
    {
        v5 = &lpBuffer[*((int*)lpBuffer + 15)];
        if (*(_DWORD*)v5 == 17744 && (*((_WORD*)v5 + 11) & 0x2000) != 0)
        {
            v4 = (char*)VirtualAllocEx(v3, nullptr, *((unsigned int*)v5 + 20), 0x3000u, 0x40u);
            v6 = v4;
            if (v4)
            {
                LODWORD(v4) = WriteProcessMemory(v3, v4, lpBuffer, *((unsigned int*)v5 + 21), nullptr);
                if ((_DWORD)v4)
                {
                    v7 = 0;
                    if (*((_WORD*)v5 + 3))
                    {
                        v8 = (unsigned int*)(v5 + 284);
                        do
                        {
                            WriteProcessMemory(v3, &v6[*(v8 - 2)], &lpBuffer[*v8], *(v8 - 1), nullptr);
                            v8 += 10;
                            ++v7;
                        } while (v7 < *((unsigned __int16*)v5 + 3));
                    }
                    v9 = (ULONG(__stdcall*)(PVOID))VirtualAllocEx(
                        v3,
                        nullptr,
                        (char*)UserMathErrorFunction - (char*)sub_140025210,
                        0x3000u,
                        0x40u);
                    v10 = v9;
                    if (!v9)
                        goto LABEL_15;
                    if (!WriteProcessMemory(
                        v3,
                        v9,
                        sub_140025210,
                        (char*)UserMathErrorFunction - (char*)sub_140025210,
                        nullptr))
                        goto LABEL_15;
                    v11 = &v6[*((int*)lpBuffer + 15)];
                    Buffer[0] = v6;
                    Buffer[1] = v11;
                    Buffer[2] = &v6[*((unsigned int*)v5 + 44)];
                    Buffer[3] = &v6[*((unsigned int*)v5 + 36)];
                    ModuleHandleA = GetModuleHandleA("kernel32.dll");
                    Buffer[4] = GetProcAddress(ModuleHandleA, "LoadLibraryA");
                    v13 = GetModuleHandleA("kernel32.dll");
                    Buffer[5] = GetProcAddress(v13, "GetProcAddress");
                    v14 = GetModuleHandleA("user32.dll");
                    Buffer[6] = GetProcAddress(v14, "MessageBoxA");
                    v15 = VirtualAllocEx(v3, nullptr, 0x38u, 0x3000u, 0x40u);
                    v16 = v15;
                    if (!v15)
                        goto LABEL_15;
                    if (WriteProcessMemory(v3, v15, Buffer, 0x38u, nullptr))
                    {
                        RemoteThread = CreateRemoteThread(v3, nullptr, 0, v10, v16, 0, nullptr);
                        WaitForSingleObject(RemoteThread, 0xFFFFFFFF);
                        VirtualFreeEx(v3, v6, 0x1000u, 0x10000u);
                        VirtualFreeEx(v3, v10, (char*)UserMathErrorFunction - (char*)sub_140025210, 0x10000u);
                        VirtualFreeEx(v3, v16, 0x38u, 0x10000u);
                        LOBYTE(v4) = 1;
                    }
                    else
                    {
                    LABEL_15:
                        LOBYTE(v4) = 0;
                    }
                }
            }
        }
        else
        {
            LOBYTE(v4) = 0;
        }
    }
    else
    {
        LOBYTE(v4) = 0;
    }
    return (char)v4;
}
int sub_1400240F0()
{
    _QWORD* v0; // rcx
    int result; // eax
    _QWORD* v2; // rdx
    unsigned __int64 v3; // rbx
    int i; // edi
    char v5; // al

    v0 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v0 = operator new(0x28u);
        qword_140050FA0 = (__int64)v0;
        v0[3] = 0;
        v0[4] = 0;
        *v0 = 0;
        v0[1] = 0;
        v0[2] = 0;
        *((_DWORD*)v0 + 6) = 0;
        *((_WORD*)v0 + 14) = 256;
        *((_DWORD*)v0 + 8) = 0;
        *((_BYTE*)v0 + 36) = 0;
    }
    if (*v0 == v0[1])
        return MessageBoxA(nullptr, "No DLL Selected", "No DLL Selected", 0);
    if (!(unsigned __int8)sub_140023F60())
        return MessageBoxA(nullptr, "Target Process Not Running", "Target Process Not Running", 0);
    v2 = (_QWORD*)qword_140050FA0;
    v3 = 0;
    for (i = 0; ; ++i)
    {
        if (!v2)
        {
            v2 = operator new(0x28u);
            qword_140050FA0 = (__int64)v2;
            v2[3] = 0;
            v2[4] = 0;
            *v2 = 0;
            v2[1] = 0;
            v2[2] = 0;
            *((_DWORD*)v2 + 6) = 0;
            *((_WORD*)v2 + 14) = 256;
            *((_DWORD*)v2 + 8) = 0;
            *((_BYTE*)v2 + 36) = 0;
        }
        result = i;
        if (i >= (unsigned __int64)((__int64)(v2[1] - *v2) >> 3))
            break;
        if (!v2)
        {
            v2 = operator new(0x28u);
            qword_140050FA0 = (__int64)v2;
            v2[3] = 0;
            v2[4] = 0;
            *v2 = 0;
            v2[1] = 0;
            v2[2] = 0;
            *((_DWORD*)v2 + 6) = 0;
            *((_WORD*)v2 + 14) = 256;
            *((_DWORD*)v2 + 8) = 0;
            *((_BYTE*)v2 + 36) = 0;
        }
        if ((__int64)(v2[1] - *v2) >> 3 <= v3)
        {
            std::_Xout_of_range("invalid vector<T> subscript");
            __debugbreak();
        }
        v5 = sub_140025390(**(char***)(*v2 + 8 * v3));
        v2 = (_QWORD*)qword_140050FA0;
        if (v5 == 1)
        {
            if (!qword_140050FA0)
            {
                v2 = operator new(0x28u);
                qword_140050FA0 = (__int64)v2;
                v2[3] = 0;
                v2[4] = 0;
                *v2 = 0;
                v2[1] = 0;
                v2[2] = 0;
                *((_DWORD*)v2 + 6) = 0;
                *((_WORD*)v2 + 14) = 256;
                *((_DWORD*)v2 + 8) = 0;
                *((_BYTE*)v2 + 36) = 0;
            }
            if ((__int64)(v2[1] - *v2) >> 3 <= v3)
            {
                std::_Xout_of_range("invalid vector<T> subscript");
                __debugbreak();
            }
            *(_BYTE*)(*(_QWORD*)(*v2 + 8 * v3) + 520LL) = 1;
        }
        ++v3;
    }
    return result;
}
__int64 __fastcall sub_14000B8B0(__int64 a1)
{
    char* v1; // rdi
    __int64 v2; // rax
    __int128 v3; // xmm0
    __int64 result; // rax

    sub_14000B4B0(0, a1);
    v1 = off_140033040;
    *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
    if (!*(_BYTE*)(*((_QWORD*)v1 + 751) + 140LL))
    {
        sub_140002230(v1 + 11960);
        sub_14000B9A0(v1 + 11960);
        v1 = off_140033040;
    }
    v2 = *((_QWORD*)v1 + 768);
    v3 = *(_OWORD*)(v2 + 20LL * (*((_DWORD*)v1 + 1534) - 1) + 4);
    result = 2 * (*(int*)(v2 + 20LL * (*((_DWORD*)v1 + 1534) - 1)) + 328LL);
    *(_OWORD*)&v1[8 * result] = v3;
    --*((_DWORD*)v1 + 1534);
    return result;
}
bool sub_140023F60()
{
    _QWORD* v0; // rcx
    _QWORD* v2; // rax

    v0 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v0 = operator new(0x28u);
        qword_140050FA0 = (__int64)v0;
        v0[3] = 0;
        v0[4] = 0;
        *v0 = 0;
        v0[1] = 0;
        v0[2] = 0;
        *((_DWORD*)v0 + 6) = 0;
        *((_WORD*)v0 + 14) = 256;
        *((_DWORD*)v0 + 8) = 0;
        *((_BYTE*)v0 + 36) = 0;
    }
    if (!Destination)
        return 0;
    if (!v0)
    {
        v2 = operator new(0x28u);
        qword_140050FA0 = (__int64)v2;
        v2[3] = 0;
        v2[4] = 0;
        *v2 = 0;
        v2[1] = 0;
        v2[2] = 0;
        *((_DWORD*)v2 + 6) = 0;
        *((_WORD*)v2 + 14) = 256;
        *((_DWORD*)v2 + 8) = 0;
        *((_BYTE*)v2 + 36) = 0;
    }
    return (unsigned int)sub_140024020() != 0;
}
__int64 sub_140024020()
{
    HANDLE Toolhelp32Snapshot; // rax
    void* v1; // rbx
    BOOL v3; // eax
    PROCESSENTRY32 pe; // [rsp+20h] [rbp-148h] BYREF

    Toolhelp32Snapshot = CreateToolhelp32Snapshot(2u, 0);
    v1 = Toolhelp32Snapshot;
    if (Toolhelp32Snapshot == (HANDLE)-1LL)
        return 0;
    pe.dwSize = 304;
    if (!Process32First(Toolhelp32Snapshot, &pe))
        return 0;
    while (strcmp(pe.szExeFile, &Destination))
    {
        v3 = Process32Next(v1, &pe);
        pe.dwSize = 304;
        if (!v3)
            return 0;
    }
    return pe.th32ProcessID;
}
void __fastcall sub_140024350(__int64* a1, _QWORD* a2)
{
    unsigned __int64 v4; // rdx
    __int64 v5; // r9
    __int64 v6; // rcx
    __int64 v7; // rdi
    __int64 v8; // rdx
    unsigned __int64 v9; // rdx
    unsigned __int64 v10; // rcx
    unsigned __int64 v11; // r9
    _QWORD* v12; // rdx
    __int64 v13; // rcx
    __int64 v14; // rdx
    unsigned __int64 v15; // rdx
    unsigned __int64 v16; // rcx
    unsigned __int64 v17; // r9
    _QWORD* v18; // rcx

    v4 = a1[1];
    if ((unsigned __int64)a2 >= v4 || (v5 = *a1, *a1 > (unsigned __int64)a2))
    {
        v13 = a1[2];
        if (v4 == v13 && !((__int64)(v13 - v4) >> 3))
        {
            v14 = (__int64)(v4 - *a1) >> 3;
            if (v14 == 0x1FFFFFFFFFFFFFFFLL)
                std::_Xlength_error("vector<T> too long");
            v15 = v14 + 1;
            v16 = (v13 - *a1) >> 3;
            v17 = 0;
            if (0x1FFFFFFFFFFFFFFFLL - (v16 >> 1) >= v16)
                v17 = v16 + (v16 >> 1);
            if (v17 >= v15)
                v15 = v17;
            sub_140024C50(a1, v15);
        }
        v18 = (_QWORD*)a1[1];
        if (v18)
            *v18 = *a2;
    }
    else
    {
        v6 = a1[2];
        v7 = ((__int64)a2 - v5) >> 3;
        if (v4 == v6 && !((__int64)(v6 - v4) >> 3))
        {
            v8 = (__int64)(v4 - v5) >> 3;
            if (v8 == 0x1FFFFFFFFFFFFFFFLL)
                std::_Xlength_error("vector<T> too long");
            v9 = v8 + 1;
            v10 = (v6 - v5) >> 3;
            v11 = 0;
            if (0x1FFFFFFFFFFFFFFFLL - (v10 >> 1) >= v10)
                v11 = v10 + (v10 >> 1);
            if (v11 >= v9)
                v9 = v11;
            sub_140024C50(a1, v9);
        }
        v12 = (_QWORD*)a1[1];
        if (v12)
        {
            *v12 = *(_QWORD*)(*a1 + 8 * v7);
            a1[1] += 8;
            return;
        }
    }
    a1[1] += 8;
}
rdata:0000000140031F88 word_140031F88  dw 32Ch; DATA XREF : .rdata : 0000000140031C08↑o
.rdata : 0000000140031F8A                 db 'GlobalAlloc', 0
.rdata : 0000000140031F96 word_140031F96  dw 337h; DATA XREF : .rdata : 0000000140031C00↑o
.rdata : 0000000140031F98                 db 'GlobalLock', 0
.rdata : 0000000140031FA3                 align 4
.rdata : 0000000140031FA4 word_140031FA4  dw 33Eh; DATA XREF : .rdata : 0000000140031BF8↑o
.rdata : 0000000140031FA6                 db 'GlobalUnlock', 0
.rdata : 0000000140031FB3                 align 4
.rdata : 0000000140031FB4 word_140031FB4  dw 442h; DATA XREF : .rdata : 0000000140031BE8↑o
.rdata : 0000000140031FB6                 db 'QueryPerformanceFrequency', 0
.rdata : 0000000140031FD0 word_140031FD0  dw 15Fh; DATA XREF : .rdata : 0000000140031BF0↑o
.rdata : 0000000140031FD2                 db 'ExitProcess', 0
.rdata : 0000000140031FDE word_140031FDE  dw 441h; DATA XREF : .rdata : 0000000140031BE0↑o
.rdata : 0000000140031FE0                 db 'QueryPerformanceCounter', 0
.rdata : 0000000140031FF8 word_140031FF8  dw 467h; DATA XREF : .rdata : 0000000140031B48↑o
.rdata : 0000000140031FFA                 db 'ReadFile', 0
.rdata : 0000000140032003                 align 4
.rdata : 0000000140032004 word_140032004  dw 41Fh; DATA XREF : .rdata : off_140031AC0↑o
.rdata : 0000000140032006                 db 'Process32First', 0
.rdata : 0000000140032015                 align 2
.rdata : 0000000140032016 word_140032016  dw 5C5h; DATA XREF : .rdata : 0000000140031AC8↑o
.rdata : 0000000140032018                 db 'VirtualFree', 0
.rdata:0000000140032024 word_140032024  dw 5C2h; DATA XREF : .rdata : 0000000140031AD0↑o
.rdata : 0000000140032026                 db 'VirtualAlloc', 0
.rdata : 0000000140032033                 align 4
.rdata : 0000000140032034 word_140032034  dw 273h; DATA XREF : .rdata : 0000000140031AD8↑o
.rdata : 0000000140032036                 db 'GetModuleHandleA', 0
.rdata : 0000000140032047                 align 8
.rdata : 0000000140032048 word_140032048  dw 401h; DATA XREF : .rdata : 0000000140031AE0↑o
.rdata : 000000014003204A                 db 'OpenProcess', 0
.rdata : 0000000140032056 word_140032056  dw 0F7h; DATA XREF : .rdata : 0000000140031AE8↑o
.rdata : 0000000140032058                 db 'CreateToolhelp32Snapshot', 0
.rdata:0000000140032071                 align 2
.rdata : 0000000140032072 word_140032072  dw 0C0h; DATA XREF : .rdata : 0000000140031AF0↑o
.rdata : 0000000140032074                 db 'CreateFileA', 0
.rdata : 0000000140032080 word_140032080  dw 421h; DATA XREF : .rdata : 0000000140031AF8↑o
.rdata : 0000000140032082                 db 'Process32Next', 0
.rdata:0000000140032090 word_140032090  dw 84h; DATA XREF : .rdata : 0000000140031B00↑o
.rdata : 0000000140032092                 db 'CloseHandle', 0
.rdata:000000014003209E word_14003209E  dw 0EEh; DATA XREF : .rdata : 0000000140031B08↑o
.rdata : 00000001400320A0                 db 'CreateThread', 0
.rdata : 00000001400320AD                 align 2
.rdata : 00000001400320AE word_1400320AE  dw 2ADh; DATA XREF : .rdata : 0000000140031B10↑o
.rdata : 00000001400320B0                 db 'GetProcAddress', 0
.rdata : 00000001400320BF                 align 20h
.rdata : 00000001400320C0 word_1400320C0  dw 24Bh; DATA XREF : .rdata : 0000000140031B18↑o
.rdata : 00000001400320C2                 db 'GetFileSize', 0
.rdata : 00000001400320CE word_1400320CE  dw 614h; DATA XREF : .rdata : 0000000140031B20↑o
.rdata : 00000001400320D0                 db 'WriteProcessMemory', 0
.rdata : 00000001400320E3                 align 4
.rdata : 00000001400320E4 word_1400320E4  dw 5D3h; DATA XREF : .rdata : 0000000140031B28↑o
.rdata : 00000001400320E6                 db 'WaitForSingleObject', 0
.rdata : 00000001400320FA word_1400320FA  dw 5C3h; DATA XREF : .rdata : 0000000140031B30↑o
.rdata : 00000001400320FC                 db 'VirtualAllocEx', 0
.rdata : 000000014003210B                 align 4
.rdata : 000000014003210C word_14003210C  dw 0E3h; DATA XREF : .rdata : 0000000140031B38↑o
.rdata : 000000014003210E                 db 'CreateRemoteThread', 0
.rdata : 0000000140032121                 align 2
.rdata : 0000000140032122 word_140032122  dw 5C6h; DATA XREF : .rdata : 0000000140031B40↑o
.rdata : 0000000140032124                 db 'VirtualFreeEx', 0
.rdata : 0000000140032132 aKernel32Dll    db 'KERNEL32.dll', 0; DATA XREF : .rdata : 0000000140031928↑o
.rdata:000000014003213F                 align 20h
.rdata : 0000000140032140 word_140032140  dw 2F8h; DATA XREF : .rdata : 0000000140031C68↑o
.rdata : 0000000140032142                 db 'SetClipboardData', 0
.rdata : 0000000140032153                 align 4
.rdata : 0000000140032154 word_140032154  dw 12Fh; DATA XREF : .rdata : 0000000140031C70↑o
.rdata : 0000000140032156                 db 'GetClipboardData', 0
.rdata : 0000000140032167                 align 8
.rdata : 0000000140032168 word_140032168  dw 0E2h; DATA XREF : .rdata : 0000000140031CD0↑o
.rdata : 000000014003216A                 db 'EmptyClipboard', 0
.rdata : 0000000140032179                 align 2
.rdata:000000014003217A word_14003217A  dw 4Dh; DATA XREF : .rdata : 0000000140031CE0↑o
.rdata : 000000014003217C                 db 'CloseClipboard', 0
.rdata : 000000014003218B                 align 4
.rdata:000000014003218C word_14003218C  dw 277h; DATA XREF : .rdata : 0000000140031CE8↑o
.rdata : 000000014003218E                 db 'OpenClipboard', 0
.rdata : 000000014003219C word_14003219C  dw 13Ah; DATA XREF : .rdata : 0000000140031CF0↑o
.rdata : 000000014003219E                 db 'GetCursorPos', 0
.rdata : 00000001400321AB                 align 4
.rdata : 00000001400321AC word_1400321AC  dw 12Ch; DATA XREF : .rdata : 0000000140031CF8↑o
.rdata : 00000001400321AE                 db 'GetClientRect', 0
.rdata : 00000001400321BC word_1400321BC  dw 2FBh; DATA XREF : .rdata : 0000000140031D00↑o
.rdata : 00000001400321BE                 db 'SetCursor', 0
.rdata : 00000001400321C8 word_1400321C8  dw 346h; DATA XREF : .rdata : 0000000140031D08↑o
.rdata : 00000001400321CA                 db 'SetWindowPos', 0
.rdata : 00000001400321D7                 align 8
.rdata : 00000001400321D8 word_1400321D8  dw 15Ch; DATA XREF : .rdata : 0000000140031D10↑o
.rdata : 00000001400321DA                 db 'GetKeyState', 0
.rdata : 00000001400321E6 word_1400321E6  dw 25Fh; DATA XREF : .rdata : 0000000140031D18↑o
.rdata : 00000001400321E8                 db 'MessageBoxA', 0
.rdata : 00000001400321F4 word_1400321F4  dw 308h; DATA XREF : .rdata : 0000000140031D20↑o
.rdata : 00000001400321F6                 db 'SetForegroundWindow', 0
.rdata : 000000014003220A word_14003220A  dw 390h; DATA XREF : .rdata : 0000000140031CC8↑o
.rdata : 000000014003220C                 db 'UpdateWindow', 0
.rdata : 0000000140032219                 align 2
.rdata:000000014003221A word_14003221A  dw 2B3h; DATA XREF : .rdata : 0000000140031CC0↑o
.rdata : 000000014003221C                 db 'RegisterClassExA', 0
.rdata : 000000014003222D                 align 2
.rdata : 000000014003222E word_14003222E  dw 28Ah; DATA XREF : .rdata : 0000000140031CB8↑o
.rdata : 0000000140032230                 db 'PostQuitMessage', 0
.rdata : 0000000140032240 word_140032240  dw 380h; DATA XREF : .rdata : 0000000140031CB0↑o
.rdata : 0000000140032242                 db 'UnregisterClassA', 0
.rdata : 0000000140032253                 align 4
.rdata : 0000000140032254 word_140032254  dw 284h; DATA XREF : .rdata : 0000000140031CA8↑o
.rdata : 0000000140032256                 db 'PeekMessageA', 0
.rdata : 0000000140032263                 align 4
.rdata : 0000000140032264 word_140032264  dw 23Bh; DATA XREF : .rdata : 0000000140031CA0↑o
.rdata : 0000000140032266                 db 'LoadIconA', 0
.rdata : 0000000140032270 word_140032270  dw 377h; DATA XREF : .rdata : 0000000140031C90↑o
.rdata : 0000000140032272                 db 'TranslateMessage', 0
.rdata : 0000000140032283                 align 4
.rdata:0000000140032284 word_140032284  dw 30Dh; DATA XREF : .rdata : 0000000140031C58↑o
.rdata : 0000000140032286                 db 'SetLayeredWindowAttributes', 0
.rdata:00000001400322A1                 align 2
.rdata : 00000001400322A2 word_1400322A2  dw 72h; DATA XREF : .rdata : off_140031C50↑o
.rdata : 00000001400322A4                 db 'CreateWindowExA', 0
.rdata : 00000001400322B4 word_1400322B4  dw 0A3h; DATA XREF : .rdata : 0000000140031C60↑o
.rdata : 00000001400322B6                 db 'DefWindowProcA', 0
.rdata : 00000001400322C5                 align 2
.rdata : 00000001400322C6 word_1400322C6  dw 1D1h; DATA XREF : .rdata : 0000000140031C78↑o
.rdata : 00000001400322C8                 db 'GetWindowLongA', 0
.rdata : 00000001400322D7                 align 8
.rdata : 00000001400322D8 word_1400322D8  dw 341h; DATA XREF : .rdata : 0000000140031C80↑o
.rdata : 00000001400322DA                 db 'SetWindowLongA', 0
.rdata : 00000001400322E9                 align 2
.rdata : 00000001400322EA word_1400322EA  dw 357h; DATA XREF : .rdata : 0000000140031C88↑o
.rdata : 00000001400322EC                 db 'ShowWindow', 0
.rdata : 00000001400322F7                 align 8
.rdata : 00000001400322F8 word_1400322F8  dw 237h; DATA XREF : .rdata : 0000000140031CD8↑o
.rdata : 00000001400322FA                 db 'LoadCursorA', 0
.rdata : 0000000140032306 word_140032306  dw 0B7h; DATA XREF : .rdata : 0000000140031C98↑o
.rdata : 0000000140032308                 db 'DispatchMessageA', 0
.rdata:0000000140032319                 align 2
.rdata:000000014003231A aUser32Dll      db 'USER32.dll', 0; DATA XREF : .rdata : 000000014003193C↑o
.rdata:0000000140032325                 align 2
.rdata : 0000000140032326 word_140032326  dw 68h; DATA XREF : .rdata : off_140031A98↑o
.rdata : 0000000140032328                 db 'CreateSolidBrush', 0
.rdata:0000000140032339                 align 2
.rdata:000000014003233A aGdi32Dll       db 'GDI32.dll', 0; DATA XREF : .rdata : 0000000140031950↑o
.rdata:0000000140032344 word_140032344  dw 0Bh; DATA XREF : .rdata : off_140031A88↑o
.rdata : 0000000140032346                 db 'GetOpenFileNameA', 0
.rdata : 0000000140032357                 align 8
.rdata : 0000000140032358 aComdlg32Dll    db 'COMDLG32.dll', 0; DATA XREF : .rdata : 0000000140031964↑o
.rdata:0000000140032365                 align 2
.rdata : 0000000140032366 word_140032366  dw 77h; DATA XREF : .rdata : off_140031AA8↑o
.rdata : 0000000140032368                 db 'ImmSetCompositionWindow', 0
.rdata:0000000140032380 word_140032380  dw 3Bh; DATA XREF : .rdata : 0000000140031AB0↑o
.rdata : 0000000140032382                 db 'ImmGetContext', 0
.rdata:0000000140032390 aImm32Dll       db 'IMM32.dll', 0; DATA XREF : .rdata : 0000000140031978↑o
.rdata:000000014003239A word_14003239A  dw 9; DATA XREF : .rdata : off_140031F48↑o
.rdata : 000000014003239C                 db 'Direct3DCreate9', 0
.rdata:00000001400323AC aD3d9Dll        db 'd3d9.dll', 0; DATA XREF : .rdata : 000000014003198C↑o
.rdata:00000001400323B5                 align 2
.rdata : 00000001400323B6 word_1400323B6  dw 28Bh; DATA XREF : .rdata : 0000000140031C38↑o
.rdata : 00000001400323B8                 db '?_Xbad_alloc@std@@YAXXZ', 0
.rdata : 00000001400323D0 word_1400323D0  dw 28Fh; DATA XREF : .rdata : 0000000140031C30↑o
.rdata : 00000001400323D2                 db '?_Xout_of_range@std@@YAXPEBD@Z', 0
.rdata : 00000001400323F1                 align 2
.rdata : 00000001400323F2 word_1400323F2  dw 28Eh; DATA XREF : .rdata : 0000000140031C28↑o
.rdata : 00000001400323F4                 db '?_Xlength_error@std@@YAXPEBD@Z', 0
.rdata : 0000000140032413                 align 4
.rdata : 0000000140032414 word_140032414  dw 5B6h; DATA XREF : .rdata : off_140031C20↑o
.rdata : 0000000140032416                 db '_Thrd_sleep', 0
.rdata : 0000000140032422 word_140032422  dw 5CCh; DATA XREF : .rdata : 0000000140031C40↑o
.rdata : 0000000140032424                 db '_Xtime_get_ticks', 0
.rdata : 0000000140032435                 align 2
.rdata : 0000000140032436 aMsvcp140Dll    db 'MSVCP140.dll', 0; DATA XREF : .rdata : 00000001400319A0↑o
.rdata:0000000140032443                 align 4
.rdata : 0000000140032444 word_140032444  dw 1Bh; DATA XREF : .rdata : off_140031F58↑o
.rdata : 0000000140032446                 db 'ImageNtHeader', 0
.rdata : 0000000140032454 aImagehlpDll    db 'imagehlp.dll', 0; DATA XREF : .rdata : 00000001400319B4↑o
.rdata:0000000140032461                 align 2
.rdata : 0000000140032462 word_140032462  dw 2D0h; DATA XREF : .rdata : off_140031F68↑o
.rdata : 0000000140032464                 db 'RtlCaptureContext', 0
.rdata : 0000000140032476 word_140032476  dw 48Dh; DATA XREF : .rdata : 0000000140031F70↑o
.rdata : 0000000140032478                 db 'RtlLookupFunctionEntry', 0
.rdata:000000014003248F                 align 10h
.rdata:0000000140032490 word_140032490  dw 5B7h; DATA XREF : .rdata : 0000000140031F78↑o
.rdata : 0000000140032492                 db 'RtlVirtualUnwind', 0
.rdata:00000001400324A3                 align 4
.rdata : 00000001400324A4 aNtdllDll       db 'ntdll.dll', 0; DATA XREF : .rdata : 00000001400319C8↑o
.rdata:00000001400324AE word_1400324AE  dw 3Dh; DATA XREF : .rdata : 0000000140031D78↑o
.rdata : 00000001400324B0                 db 'memmove', 0
.rdata : 00000001400324B8 word_1400324B8  dw 23h; DATA XREF : .rdata : 0000000140031D90↑o
.rdata : 00000001400324BA                 db '__std_terminate', 0
.rdata : 00000001400324CA word_1400324CA  dw 42h; DATA XREF : .rdata : 0000000140031D70↑o
.rdata : 00000001400324CC                 db 'strstr', 0
.rdata : 00000001400324D3                 align 4
.rdata : 00000001400324D4 word_1400324D4  dw 40h; DATA XREF : .rdata : 0000000140031D68↑o
.rdata : 00000001400324D6                 db 'strchr', 0
.rdata : 00000001400324DD                 align 2
.rdata : 00000001400324DE word_1400324DE  dw 3Ah; DATA XREF : .rdata : 0000000140031D60↑o
.rdata : 00000001400324E0                 db 'memchr', 0
.rdata : 00000001400324E7                 align 8
.rdata : 00000001400324E8 word_1400324E8  dw 30h; DATA XREF : .rdata : 0000000140031D58↑o
.rdata : 00000001400324EA                 db '__vcrt_InitializeCriticalSectionEx', 0
.rdata : 000000014003250D                 align 2
.rdata : 000000014003250E word_14003250E  dw 8; DATA XREF : .rdata : 0000000140031D50↑o
.rdata : 0000000140032510                 db '__C_specific_handler', 0
.rdata : 0000000140032525                 align 2
.rdata : 0000000140032526 word_140032526  dw 3Eh; DATA XREF : .rdata : 0000000140031D48↑o
.rdata : 0000000140032528                 db 'memset', 0
.rdata:000000014003252F                 align 10h
.rdata : 0000000140032530 word_140032530  dw 21h; DATA XREF : .rdata : 0000000140031D40↑o
.rdata : 0000000140032532                 db '__std_exception_copy', 0
.rdata : 0000000140032547                 align 8
.rdata : 0000000140032548 word_140032548  dw 22h; DATA XREF : .rdata : 0000000140031D38↑o
.rdata : 000000014003254A                 db '__std_exception_destroy', 0
.rdata : 0000000140032562 word_140032562  dw 1; DATA XREF : .rdata : off_140031D30↑o
.rdata : 0000000140032564                 db '_CxxThrowException', 0
.rdata : 0000000140032577                 align 8
.rdata : 0000000140032578 aVcruntime140Dl db 'VCRUNTIME140.dll', 0; DATA XREF : .rdata : 00000001400319DC↑o
.rdata:0000000140032589                 align 2
.rdata:000000014003258A word_14003258A  dw 89h; DATA XREF : .rdata : 0000000140031F08↑o
.rdata : 000000014003258C                 db 'ftell', 0
.rdata:0000000140032592 word_140032592  dw 6Ch; DATA XREF : .rdata : off_140031F18↑o
.rdata : 0000000140032594                 db 'isprint', 0
.rdata:000000014003259C word_14003259C  dw 0; DATA XREF : .rdata : 0000000140031F00↑o
.rdata : 000000014003259E                 db '__acrt_iob_func', 0
.rdata : 00000001400325AE word_1400325AE  dw 77h; DATA XREF : .rdata : 0000000140031EF8↑o
.rdata : 00000001400325B0                 db 'fflush', 0
.rdata : 00000001400325B7                 align 8
.rdata : 00000001400325B8 word_1400325B8  dw 74h; DATA XREF : .rdata : 0000000140031EF0↑o
.rdata : 00000001400325BA                 db 'fclose', 0
.rdata : 00000001400325C1                 align 2
.rdata : 00000001400325C2 word_1400325C2  dw 87h; DATA XREF : .rdata : 0000000140031EE8↑o
.rdata : 00000001400325C4                 db 'fseek', 0
.rdata : 00000001400325CA word_1400325CA  dw 3; DATA XREF : .rdata : 0000000140031EE0↑o
.rdata : 00000001400325CC                 db '__stdio_common_vfprintf', 0
.rdata : 00000001400325E4 word_1400325E4  dw 19h; DATA XREF : .rdata : off_140031F38↑o
.rdata : 00000001400325E6                 db 'qsort', 0
.rdata : 00000001400325EC word_1400325EC  dw 8Fh; DATA XREF : .rdata : 0000000140031F20↑o
.rdata : 00000001400325EE                 db 'strncpy', 0
.rdata : 00000001400325F6 word_1400325F6  dw 62h; DATA XREF : .rdata : 0000000140031EC0↑o
.rdata : 00000001400325F8                 db '_wfopen', 0
.rdata : 0000000140032600 word_140032600  dw 0Dh; DATA XREF : .rdata : 0000000140031EB8↑o
.rdata : 0000000140032602                 db '__stdio_common_vsprintf', 0
.rdata : 000000014003261A word_14003261A  dw 18h; DATA XREF : .rdata : 0000000140031DB8↑o
.rdata : 000000014003261C                 db 'free', 0
.rdata : 0000000140032621                 align 2
.rdata : 0000000140032622 word_140032622  dw 83h; DATA XREF : .rdata : 0000000140031ED8↑o
.rdata : 0000000140032624                 db 'fread', 0
.rdata : 000000014003262A word_14003262A  dw 10h; DATA XREF : .rdata : 0000000140031EC8↑o
.rdata : 000000014003262C                 db '__stdio_common_vsscanf', 0
.rdata : 0000000140032643                 align 4
.rdata : 0000000140032644 word_140032644  dw 19h; DATA XREF : .rdata : off_140031DA0↑o
.rdata : 0000000140032646                 db 'malloc', 0
.rdata : 000000014003264D                 align 2
.rdata : 000000014003264E word_14003264E  dw 89h; DATA XREF : .rdata : 0000000140031F28↑o
.rdata : 0000000140032650                 db 'strcpy_s', 0
.rdata : 0000000140032659                 align 2
.rdata:000000014003265A word_14003265A  dw 39h; DATA XREF : .rdata : 0000000140031E80↑o
.rdata : 000000014003265C                 db '_invalid_parameter_noinfo_noreturn', 0
.rdata : 000000014003267F                 align 20h
.rdata : 0000000140032680 word_140032680  dw 55h; DATA XREF : .rdata : 0000000140031E60↑o
.rdata : 0000000140032682                 db 'exit', 0
.rdata:0000000140032687                 align 8
.rdata:0000000140032688 word_140032688  dw 67h; DATA XREF : .rdata : 0000000140031E88↑o
.rdata : 000000014003268A                 db 'terminate', 0
.rdata:0000000140032694 word_140032694  dw 18h; DATA XREF : .rdata : 0000000140031EA0↑o
.rdata : 0000000140032696                 db '_configure_narrow_argv', 0
.rdata:00000001400326AD                 align 2
.rdata : 00000001400326AE word_1400326AE  dw 33h; DATA XREF : .rdata : 0000000140031E98↑o
.rdata : 00000001400326B0                 db '_initialize_narrow_environment', 0
.rdata : 00000001400326CF                 align 10h
.rdata : 00000001400326D0 word_1400326D0  dw 34h; DATA XREF : .rdata : 0000000140031E90↑o
.rdata : 00000001400326D2                 db '_initialize_onexit_table', 0
.rdata : 00000001400326EB                 align 4
.rdata : 00000001400326EC word_1400326EC  dw 3Ch; DATA XREF : .rdata : 0000000140031E78↑o
.rdata : 00000001400326EE                 db '_register_onexit_function', 0
.rdata : 0000000140032708 word_140032708  dw 1Eh; DATA XREF : .rdata : 0000000140031E38↑o
.rdata : 000000014003270A                 db '_crt_atexit', 0
.rdata : 0000000140032716 word_140032716  dw 16h; DATA XREF : .rdata : off_140031E20↑o
.rdata : 0000000140032718                 db '_cexit', 0
.rdata:000000014003271F                 align 20h
.rdata : 0000000140032720 word_140032720  dw 8; DATA XREF : .rdata : 0000000140031DB0↑o
.rdata : 0000000140032722                 db '_callnewh', 0
.rdata : 000000014003272C word_14003272C  dw 40h; DATA XREF : .rdata : 0000000140031E28↑o
.rdata : 000000014003272E                 db '_seh_filter_exe', 0
.rdata : 000000014003273E word_14003273E  dw 42h; DATA XREF : .rdata : 0000000140031E30↑o
.rdata : 0000000140032740                 db '_set_app_type', 0
.rdata : 000000014003274E word_14003274E  dw 9; DATA XREF : .rdata : 0000000140031E08↑o
.rdata : 0000000140032750                 db '__setusermatherr', 0
.rdata : 0000000140032761                 align 2
.rdata : 0000000140032762 word_140032762  dw 2Bh; DATA XREF : .rdata : 0000000140031E40↑o
.rdata : 0000000140032764                 db '_get_narrow_winmain_command_line', 0
.rdata : 0000000140032785                 align 2
.rdata:0000000140032786 word_140032786  dw 36h; DATA XREF : .rdata : 0000000140031E48↑o
.rdata : 0000000140032788                 db '_initterm', 0
.rdata:0000000140032792 word_140032792  dw 37h; DATA XREF : .rdata : 0000000140031E50↑o
.rdata : 0000000140032794                 db '_initterm_e', 0
.rdata:00000001400327A0 word_1400327A0  dw 23h; DATA XREF : .rdata : 0000000140031E58↑o
.rdata : 00000001400327A2                 db '_exit', 0
.rdata : 00000001400327A8 word_1400327A8  dw 54h; DATA XREF : .rdata : off_140031EB0↑o
.rdata : 00000001400327AA                 db '_set_fmode', 0
.rdata : 00000001400327B5                 align 2
.rdata : 00000001400327B6 word_1400327B6  dw 15h; DATA XREF : .rdata : 0000000140031E68↑o
.rdata : 00000001400327B8                 db '_c_exit', 0
.rdata : 00000001400327C0 word_1400327C0  dw 3Dh; DATA XREF : .rdata : 0000000140031E70↑o
.rdata : 00000001400327C2                 db '_register_thread_local_exe_atexit_callback', 0
.rdata : 00000001400327ED                 align 2
.rdata : 00000001400327EE word_1400327EE  dw 8; DATA XREF : .rdata : off_140031DC8↑o
.rdata : 00000001400327F0                 db '_configthreadlocale', 0
.rdata : 0000000140032804 word_140032804  dw 16h; DATA XREF : .rdata : 0000000140031DA8↑o
.rdata : 0000000140032806                 db '_set_new_mode', 0
.rdata:0000000140032814 word_140032814  dw 1; DATA XREF : .rdata : 0000000140031ED0↑o
.rdata : 0000000140032816                 db '__p__commode', 0
.rdata:0000000140032823                 align 4
.rdata:0000000140032824 aApiMsWinCrtStd db 'api-ms-win-crt-stdio-l1-1-0.dll', 0
.rdata:0000000140032824; DATA XREF : .rdata : 00000001400319F0↑o
.rdata:0000000140032844 aApiMsWinCrtStr db 'api-ms-win-crt-string-l1-1-0.dll', 0
.rdata:0000000140032844; DATA XREF : .rdata : 0000000140031A04↑o
.rdata : 0000000140032865                 align 2
.rdata:0000000140032866 aApiMsWinCrtUti db 'api-ms-win-crt-utility-l1-1-0.dll', 0
.rdata:0000000140032866; DATA XREF : .rdata : 0000000140031A18↑o
.rdata : 0000000140032888 aApiMsWinCrtHea db 'api-ms-win-crt-heap-l1-1-0.dll', 0
.rdata:0000000140032888; DATA XREF : .rdata : 0000000140031A2C↑o
.rdata : 00000001400328A7                 align 8
.rdata:00000001400328A8 aApiMsWinCrtRun db 'api-ms-win-crt-runtime-l1-1-0.dll', 0
.rdata:00000001400328A8; DATA XREF : .rdata : 0000000140031A40↑o
.rdata : 00000001400328CA aApiMsWinCrtMat db 'api-ms-win-crt-math-l1-1-0.dll', 0
.rdata:00000001400328CA; DATA XREF : .rdata : 0000000140031A54↑o
.rdata : 00000001400328E9                 align 2
.rdata : 00000001400328EA aApiMsWinCrtLoc db 'api-ms-win-crt-locale-l1-1-0.dll', 0
.rdata : 00000001400328EA; DATA XREF : .rdata : 0000000140031A68↑o
.rdata : 000000014003290B                 align 4
.rdata:000000014003290C word_14003290C  dw 131h; DATA XREF : .rdata : 0000000140031C10↑o
.rdata : 000000014003290E                 db 'EnterCriticalSection', 0
.rdata : 0000000140032923                 align 4
.rdata:0000000140032924 word_140032924  dw 3B3h; DATA XREF : .rdata : 0000000140031B50↑o
.rdata : 0000000140032926                 db 'LeaveCriticalSection', 0
.rdata:000000014003293B                 align 4
.rdata:000000014003293C word_14003293C  dw 10Dh; DATA XREF : .rdata : 0000000140031B58↑o
.rdata : 000000014003293E                 db 'DeleteCriticalSection', 0
.rdata : 0000000140032954 word_140032954  dw 513h; DATA XREF : .rdata : 0000000140031B60↑o
.rdata : 0000000140032956                 db 'SetEvent', 0
.rdata:000000014003295F                 align 20h
.rdata:0000000140032960 word_140032960  dw 4BAh; DATA XREF : .rdata : 0000000140031B68↑o
.rdata : 0000000140032962                 db 'ResetEvent', 0
.rdata:000000014003296D                 align 2
.rdata:000000014003296E word_14003296E  dw 5D4h; DATA XREF : .rdata : 0000000140031B70↑o
.rdata : 0000000140032970                 db 'WaitForSingleObjectEx', 0
.rdata:0000000140032986 word_140032986  dw 0BCh; DATA XREF : .rdata : 0000000140031B78↑o
.rdata : 0000000140032988                 db 'CreateEventW', 0
.rdata:0000000140032995                 align 2
.rdata:0000000140032996 word_140032996  dw 276h; DATA XREF : .rdata : 0000000140031B80↑o
.rdata : 0000000140032998                 db 'GetModuleHandleW', 0
.rdata:00000001400329A9                 align 2
.rdata:00000001400329AA word_1400329AA  dw 5A9h; DATA XREF : .rdata : 0000000140031B88↑o
.rdata : 00000001400329AC                 db 'UnhandledExceptionFilter', 0
.rdata:00000001400329C5                 align 2
.rdata:00000001400329C6 word_1400329C6  dw 569h; DATA XREF : .rdata : 0000000140031B90↑o
.rdata : 00000001400329C8                 db 'SetUnhandledExceptionFilter', 0
.rdata:00000001400329E4 word_1400329E4  dw 218h; DATA XREF : .rdata : 0000000140031B98↑o
.rdata : 00000001400329E6                 db 'GetCurrentProcess', 0
.rdata : 00000001400329F8 word_1400329F8  dw 587h; DATA XREF : .rdata : 0000000140031BA0↑o
.rdata : 00000001400329FA                 db 'TerminateProcess', 0
.rdata:0000000140032A0B                 align 4
.rdata : 0000000140032A0C word_140032A0C  dw 37Eh; DATA XREF : .rdata : 0000000140031BA8↑o
.rdata : 0000000140032A0E                 db 'IsProcessorFeaturePresent', 0
.rdata : 0000000140032A28 word_140032A28  dw 377h; DATA XREF : .rdata : 0000000140031BB0↑o
.rdata : 0000000140032A2A                 db 'IsDebuggerPresent', 0
.rdata : 0000000140032A3C word_140032A3C  dw 2CFh; DATA XREF : .rdata : 0000000140031BB8↑o
.rdata : 0000000140032A3E                 db 'GetStartupInfoW', 0
.rdata : 0000000140032A4E word_140032A4E  dw 219h; DATA XREF : .rdata : 0000000140031BC0↑o
.rdata : 0000000140032A50                 db 'GetCurrentProcessId', 0
.rdata : 0000000140032A64 word_140032A64  dw 21Dh; DATA XREF : .rdata : 0000000140031BC8↑o
.rdata : 0000000140032A66                 db 'GetCurrentThreadId', 0
.rdata : 0000000140032A79                 align 2
.rdata : 0000000140032A7A word_140032A7A  dw 2E8h; DATA XREF : .rdata : 0000000140031BD0↑o
.rdata : 0000000140032A7C                 db 'GetSystemTimeAsFileTime', 0
.rdata : 0000000140032A94 word_140032A94  dw 361h; DATA XREF : .rdata : 0000000140031BD8↑o
.rdata : 0000000140032A96                 db 'InitializeSListHead', 0
.rdata : 0000000140032AAA word_140032AAA  dw 0Eh; DATA XREF : .rdata : 0000000140031D80↑o
.rdata : 0000000140032AAC                 db '__CxxFrameHandler3', 0
.rdata : 0000000140032ABF                 align 20h
.rdata : 0000000140032AC0 word_140032AC0  dw 3Ch; DATA XREF : .rdata : 0000000140031D88↑o
.rdata : 0000000140032AC2                 db 'memcpy', 0
.rdata : 0000000140032AC9                 align 2
.rdata : 0000000140032ACA word_140032ACA  dw 7Ch; DATA XREF : .rdata : 0000000140031E10↑o
.rdata : 0000000140032ACC                 db 'ceil', 0
.rdata : 0000000140032AD1                 align 2
.rdata : 0000000140032AD2 word_140032AD2  dw 91h; DATA XREF : .rdata : off_140031DD8↑o
.rdata : 0000000140032AD4                 db 'cosf', 0
.rdata : 0000000140032AD9                 align 2
.rdata : 0000000140032ADA word_140032ADA  dw 0BEh; DATA XREF : .rdata : 0000000140031E00↑o
.rdata : 0000000140032ADC                 db 'floor', 0
.rdata : 0000000140032AE2 word_140032AE2  dw 0CAh; DATA XREF : .rdata : 0000000140031DF8↑o
.rdata : 0000000140032AE4                 db 'fmodf', 0
.rdata : 0000000140032AEA word_140032AEA  dw 113h; DATA XREF : .rdata : 0000000140031DE0↑o
.rdata : 0000000140032AEC                 db 'sinf', 0
.rdata : 0000000140032AF1                 align 2
.rdata : 0000000140032AF2 word_140032AF2  dw 116h; DATA XREF : .rdata : 0000000140031DF0↑o
.rdata : 0000000140032AF4                 db 'sqrt', 0
.rdata : 0000000140032AF9                 align 2
.rdata : 0000000140032AFA word_140032AFA  dw 117h; DATA XREF : .rdata : 0000000140031DE8↑o
.rdata : 0000000140032AFC                 db 'sqrtf', 0
.rdata : 0000000140032B02                 align 800h
.rdata : 0000000140032B02 _rdata          ends

void sub_140023750()
{
    _QWORD* v0; // rax
    __int64 v1; // rax
    void* v2; // rcx
    unsigned __int64 v3; // rax
    _QWORD* v4; // rdx
    unsigned int v5; // r14d
    unsigned __int64 i; // rdi
    _QWORD* v7; // rcx
    _QWORD* v8; // rax
    _BYTE* v9; // rdx
    size_t v10; // r8
    char* v11; // rdx
    __int64 v12; // rcx
    _QWORD* v13; // rdx
    char* v14; // rdx
    __int64 v15; // rcx
    _QWORD* v16; // rax
    __int128 v17; // xmm0
    const char* v18; // rdx
    char* v19; // rdx
    __int64 v20; // rcx
    __int64 v21; // rax
    void* v22; // rcx
    unsigned __int64 v23; // rax
    _QWORD* v24; // rcx
    char* v25; // rbx
    int v26; // xmm6_4
    char v27; // al
    _QWORD* v28; // rbx
    void* v29; // rcx
    unsigned __int64 v30; // rax
    void* v31; // rcx
    unsigned __int64 v32; // rax
    _QWORD* v33; // rax
    void* v34; // rcx
    unsigned __int64 v35; // rax
    __int128 v36; // [rsp+28h] [rbp-69h] BYREF
    __int64 v37; // [rsp+38h] [rbp-59h]
    unsigned __int64 v38; // [rsp+40h] [rbp-51h]
    _QWORD v39[2]; // [rsp+48h] [rbp-49h] BYREF
    _QWORD v40[2]; // [rsp+58h] [rbp-39h] BYREF
    __int64 v41; // [rsp+68h] [rbp-29h]
    unsigned __int64 v42; // [rsp+70h] [rbp-21h]
    _QWORD v43[2]; // [rsp+78h] [rbp-19h] BYREF
    __int64 v44; // [rsp+88h] [rbp-9h]
    unsigned __int64 v45; // [rsp+90h] [rbp-1h]
    _QWORD Src[3]; // [rsp+98h] [rbp+7h] BYREF
    unsigned __int64 v47; // [rsp+B0h] [rbp+1Fh]

    v39[1] = -2;
    v47 = 15;
    Src[2] = 0;
    LOBYTE(Src[0]) = 0;
    sub_1400246A0(Src, &byte_1400296E6, 0);
    sub_140024960(Src, "\t\t\t\t\t\t\t\t   ", 0xBu);
    sub_140024960(Src, " DLL List [", 0xBu);
    v0 = (_QWORD*)qword_140050FA0;
    if (!qword_140050FA0)
    {
        v0 = operator new(0x28u);
        v39[0] = v0;
        v0[3] = 0;
        v0[4] = 0;
        *v0 = 0;
        v0[1] = 0;
        v0[2] = 0;
        *((_DWORD*)v0 + 6) = 0;
        *((_WORD*)v0 + 14) = 256;
        *((_DWORD*)v0 + 8) = 0;
        *((_BYTE*)v0 + 36) = 0;
        qword_140050FA0 = (__int64)v0;
    }
    v1 = sub_140022750(v40, (__int64)(v0[1] - *v0) >> 3);
    sub_140024AB0(Src, v1, 0, -1);
    if (v42 >= 0x10)
    {
        v2 = (void*)v40[0];
        if (v42 + 1 >= 0x1000)
        {
            if ((v40[0] & 0x1F) != 0)
                invalid_parameter_noinfo_noreturn();
            v3 = *(_QWORD*)(v40[0] - 8LL);
            if (v3 >= v40[0])
                invalid_parameter_noinfo_noreturn();
            if (v40[0] - v3 < 8)
                invalid_parameter_noinfo_noreturn();
            if (v40[0] - v3 > 0x27)
                invalid_parameter_noinfo_noreturn();
            v2 = *(void**)(v40[0] - 8LL);
        }
        j_free(v2);
    }
    sub_140024960(Src, "]", 1u);
    v4 = Src;
    if (v47 >= 0x10)
        v4 = (_QWORD*)Src[0];
    v36 = xmmword_14002DD00;
    sub_14000B980((__int64)&v36, (__int64)v4);
    sub_140011800();
    v5 = 0;
    for (i = 0; ; ++i)
    {
        v7 = (_QWORD*)qword_140050FA0;
        if (!qword_140050FA0)
        {
            v7 = operator new(0x28u);
            *(_QWORD*)&v36 = v7;
            v7[3] = 0;
            v7[4] = 0;
            *v7 = 0;
            v7[1] = 0;
            v7[2] = 0;
            *((_DWORD*)v7 + 6) = 0;
            *((_WORD*)v7 + 14) = 256;
            *((_DWORD*)v7 + 8) = 0;
            *((_BYTE*)v7 + 36) = 0;
            qword_140050FA0 = (__int64)v7;
        }
        if ((int)v5 >= (unsigned __int64)((__int64)(v7[1] - *v7) >> 3))
            break;
        v42 = 15;
        v41 = 0;
        LOBYTE(v40[0]) = 0;
        sub_1400246A0(v40, &byte_1400296E6, 0);
        v8 = (_QWORD*)qword_140050FA0;
        if (!qword_140050FA0)
        {
            v8 = operator new(0x28u);
            *(_QWORD*)&v36 = v8;
            v8[3] = 0;
            v8[4] = 0;
            *v8 = 0;
            v8[1] = 0;
            v8[2] = 0;
            *((_DWORD*)v8 + 6) = 0;
            *((_WORD*)v8 + 14) = 256;
            *((_DWORD*)v8 + 8) = 0;
            *((_BYTE*)v8 + 36) = 0;
            qword_140050FA0 = (__int64)v8;
        }
        if ((__int64)(v8[1] - *v8) >> 3 <= i)
        {
            std::_Xout_of_range("invalid vector<T> subscript");
            break;
        }
        v9 = (_BYTE*)(*(_QWORD*)(*v8 + 8 * i) + 264LL);
        if (*v9)
        {
            v10 = -1;
            do
                ++v10;
            while (v9[v10]);
        }
        else
        {
            v10 = 0;
        }
        sub_140024960(v40, v9, v10);
        sub_14000C910();
        v11 = off_140033040;
        *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
        v12 = *((_QWORD*)v11 + 751);
        if (!*(_BYTE*)(v12 + 140))
        {
            *(float*)(v12 + 192) = *((float*)v11 + 1292) + *(float*)(v12 + 200);
            *(_DWORD*)(v12 + 196) = *(_DWORD*)(v12 + 204);
            *(_DWORD*)(v12 + 224) = *(_DWORD*)(v12 + 232);
            *(_DWORD*)(v12 + 228) = *(_DWORD*)(v12 + 236);
        }
        v13 = v40;
        if (v42 >= 0x10)
            v13 = (_QWORD*)v40[0];
        v36 = xmmword_14002DD10;
        sub_14000B980((__int64)&v36, (__int64)v13);
        v14 = off_140033040;
        *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
        v15 = *((_QWORD*)v14 + 751);
        if (!*(_BYTE*)(v15 + 140))
        {
            *(float*)(v15 + 192) = *((float*)v14 + 1292) + *(float*)(v15 + 200);
            *(_DWORD*)(v15 + 196) = *(_DWORD*)(v15 + 204);
            *(_DWORD*)(v15 + 224) = *(_DWORD*)(v15 + 232);
            *(_DWORD*)(v15 + 228) = *(_DWORD*)(v15 + 236);
        }
        v16 = (_QWORD*)qword_140050FA0;
        if (!qword_140050FA0)
        {
            v16 = operator new(0x28u);
            *(_QWORD*)&v36 = v16;
            v16[3] = 0;
            v16[4] = 0;
            *v16 = 0;
            v16[1] = 0;
            v16[2] = 0;
            *((_DWORD*)v16 + 6) = 0;
            *((_WORD*)v16 + 14) = 256;
            *((_DWORD*)v16 + 8) = 0;
            *((_BYTE*)v16 + 36) = 0;
            qword_140050FA0 = (__int64)v16;
        }
        if ((__int64)(v16[1] - *v16) >> 3 <= i)
        {
            std::_Xout_of_range("invalid vector<T> subscript");
            __debugbreak();
        }
        if (*(_BYTE*)(*(_QWORD*)(*v16 + 8 * i) + 520LL))
        {
            v17 = xmmword_14002DD10;
            v18 = "Injected";
        }
        else
        {
            v17 = xmmword_14002DD00;
            v18 = "Not Injected";
        }
        v36 = v17;
        sub_14000B980((__int64)&v36, (__int64)v18);
        v19 = off_140033040;
        *(_BYTE*)(*((_QWORD*)off_140033040 + 751) + 138LL) = 1;
        v20 = *((_QWORD*)v19 + 751);
        if (!*(_BYTE*)(v20 + 140))
        {
            *(float*)(v20 + 192) = *((float*)v19 + 1292) + *(float*)(v20 + 200);
            *(_DWORD*)(v20 + 196) = *(_DWORD*)(v20 + 204);
            *(_DWORD*)(v20 + 224) = *(_DWORD*)(v20 + 232);
            *(_DWORD*)(v20 + 228) = *(_DWORD*)(v20 + 236);
        }
        v45 = 15;
        v44 = 0;
        LOBYTE(v43[0]) = 0;
        sub_1400246A0(v43, &byte_1400296E6, 0);
        sub_140024960(v43, "Remove", 6u);
        v21 = sub_140022710(&v36, v5);
        sub_140024AB0(v43, v21, 0, -1);
        if (v38 >= 0x10)
        {
            v22 = (void*)v36;
            if (v38 + 1 >= 0x1000)
            {
                if ((v36 & 0x1F) != 0)
                    invalid_parameter_noinfo_noreturn();
                v23 = *(_QWORD*)(v36 - 8);
                if (v23 >= (unsigned __int64)v36)
                    invalid_parameter_noinfo_noreturn();
                if ((unsigned __int64)v36 - v23 < 8)
                    invalid_parameter_noinfo_noreturn();
                if ((unsigned __int64)v36 - v23 > 0x27)
                    invalid_parameter_noinfo_noreturn();
                v22 = *(void**)(v36 - 8);
            }
            j_free(v22);
        }
        v38 = 15;
        v37 = 0;
        LOBYTE(v36) = 0;
        v24 = v43;
        if (v45 >= 0x10)
            v24 = (_QWORD*)v43[0];
        v25 = off_140033040;
        v26 = *((_DWORD*)off_140033040 + 1290);
        *((_DWORD*)off_140033040 + 1290) = 0;
        v39[0] = 0;
        v27 = sub_14000C370((__int64)v24, v39, 256);
        *((_DWORD*)v25 + 1290) = v26;
        if (v27)
        {
            v28 = (_QWORD*)qword_140050FA0;
            if (!qword_140050FA0)
            {
                v28 = operator new(0x28u);
                *(_QWORD*)&v36 = v28;
                v28[3] = 0;
                v28[4] = 0;
                *v28 = 0;
                v28[1] = 0;
                v28[2] = 0;
                *((_DWORD*)v28 + 6) = 0;
                *((_WORD*)v28 + 14) = 256;
                *((_DWORD*)v28 + 8) = 0;
                *((_BYTE*)v28 + 36) = 0;
                qword_140050FA0 = (__int64)v28;
            }
            memmove(
                (void*)(*v28 + 8LL * (int)v5),
                (const void*)(*v28 + 8LL * (int)v5 + 8),
                v28[1] - (*v28 + 8LL * (int)v5 + 8));
            v28[1] -= 8LL;
        }
        if (v45 >= 0x10)
        {
            v29 = (void*)v43[0];
            if (v45 + 1 >= 0x1000)
            {
                if ((v43[0] & 0x1F) != 0)
                    invalid_parameter_noinfo_noreturn();
                v30 = *(_QWORD*)(v43[0] - 8LL);
                if (v30 >= v43[0])
                    invalid_parameter_noinfo_noreturn();
                if (v43[0] - v30 < 8)
                    invalid_parameter_noinfo_noreturn();
                if (v43[0] - v30 > 0x27)
                    invalid_parameter_noinfo_noreturn();
                v29 = *(void**)(v43[0] - 8LL);
            }
            j_free(v29);
        }
        v45 = 15;
        v44 = 0;
        LOBYTE(v43[0]) = 0;
        if (v42 >= 0x10)
        {
            v31 = (void*)v40[0];
            if (v42 + 1 >= 0x1000)
            {
                if ((v40[0] & 0x1F) != 0)
                    invalid_parameter_noinfo_noreturn();
                v32 = *(_QWORD*)(v40[0] - 8LL);
                if (v32 >= v40[0])
                    invalid_parameter_noinfo_noreturn();
                if (v40[0] - v32 < 8)
                    invalid_parameter_noinfo_noreturn();
                if (v40[0] - v32 > 0x27)
                    invalid_parameter_noinfo_noreturn();
                v31 = *(void**)(v40[0] - 8LL);
            }
            j_free(v31);
        }
        v42 = 15;
        v41 = 0;
        LOBYTE(v40[0]) = 0;
        ++v5;
    }
    sub_140011800();
    if (!qword_140050FA0)
    {
        v33 = operator new(0x28u);
        *(_QWORD*)&v36 = v33;
        v33[3] = 0;
        v33[4] = 0;
        *v33 = 0;
        v33[1] = 0;
        v33[2] = 0;
        *((_DWORD*)v33 + 6) = 0;
        *((_WORD*)v33 + 14) = 256;
        *((_DWORD*)v33 + 8) = 0;
        *((_BYTE*)v33 + 36) = 0;
        qword_140050FA0 = (__int64)v33;
    }
    sub_1400233B0();
    if (v47 >= 0x10)
    {
        v34 = (void*)Src[0];
        if (v47 + 1 >= 0x1000)
        {
            if ((Src[0] & 0x1F) != 0)
                invalid_parameter_noinfo_noreturn();
            v35 = *(_QWORD*)(Src[0] - 8LL);
            if (v35 >= Src[0])
                invalid_parameter_noinfo_noreturn();
            if (Src[0] - v35 < 8)
                invalid_parameter_noinfo_noreturn();
            if (Src[0] - v35 > 0x27)
                invalid_parameter_noinfo_noreturn();
            v34 = *(void**)(Src[0] - 8LL);
        }
        j_free(v34);
    }
}
_QWORD* __fastcall sub_1400246A0(_QWORD* Src, char* a2, size_t Size)
{
    size_t v3; // rdi
    unsigned __int64 v6; // rcx
    char* v7; // rax
    _QWORD* v8; // rax
    unsigned __int64 v9; // rdx
    char* v10; // rax
    char* v11; // rsi
    char* v12; // rcx
    _QWORD* v13; // rax
    void* v15; // rcx
    bool v16; // cf
    _QWORD* v17; // rax

    v3 = Size;
    if (!a2
        || ((v6 = Src[3], v6 < 0x10) ? (v7 = (char*)Src) : (v7 = (char*)*Src),
            a2 < v7 || (v6 < 0x10 ? (v8 = Src) : (v8 = (_QWORD*)*Src), v9 = Src[2], (char*)v8 + v9 <= a2)))
    {
        if (Size == -1)
            std::_Xlength_error("string too long");
        if (Src[3] >= Size)
        {
            if (!Size)
            {
                v16 = Src[3] < 0x10u;
                Src[2] = 0;
                if (v16)
                    *(_BYTE*)Src = 0;
                else
                    *(_BYTE*)*Src = 0;
                return Src;
            }
        }
        else
        {
            sub_140024DF0(Src);
            if (!v3)
                return Src;
        }
        if (Src[3] < 0x10u)
            v15 = Src;
        else
            v15 = (void*)*Src;
        if (v3)
            memcpy(v15, a2, v3);
        v16 = Src[3] < 0x10u;
        Src[2] = v3;
        if (v16)
            v17 = Src;
        else
            v17 = (_QWORD*)*Src;
        *((_BYTE*)v17 + v3) = 0;
        return Src;
    }
    if (v6 < 0x10)
        v10 = (char*)Src;
    else
        v10 = (char*)*Src;
    v11 = (char*)(a2 - v10);
    if (v9 < (unsigned __int64)v11)
    {
        std::_Xout_of_range("invalid string position");
        __debugbreak();
    }
    if (Size > v9 - (unsigned __int64)v11)
        v3 = v9 - (_QWORD)v11;
    v12 = &v11[v3];
    if (v9 < (unsigned __int64)&v11[v3])
    {
        std::_Xout_of_range("invalid string position");
        __debugbreak();
    }
    Src[2] = v12;
    if (Src[3] < 0x10u)
        v13 = Src;
    else
        v13 = (_QWORD*)*Src;
    v12[(_QWORD)v13] = 0;
    sub_140024D20(Src, 0, v11);
    return Src;
}
_QWORD* __fastcall sub_140024960(_QWORD* Src, char* a2, size_t Size)
{
    _QWORD* v5; // rbx
    unsigned __int64 v6; // r9
    char* v7; // rax
    char* v8; // rax
    size_t v10; // rdi
    _QWORD* v11; // rcx
    bool v12; // cf
    _QWORD* v13; // rax

    v5 = Src;
    if (!a2)
        goto LABEL_13;
    v6 = Src[3];
    v7 = v6 < 0x10 ? (char*)Src : (char*)*Src;
    if (a2 < v7)
        goto LABEL_13;
    if (v6 >= 0x10)
        Src = (_QWORD*)*Src;
    if ((char*)Src + v5[2] <= a2)
    {
    LABEL_13:
        if (~v5[2] <= Size)
            std::_Xlength_error("string too long");
        v10 = v5[2] + Size;
        if (!Size)
            return v5;
        if (v10 == -1)
            std::_Xlength_error("string too long");
        if (v5[3] >= v10)
        {
            if (v10)
                goto LABEL_20;
            v5[2] = 0;
            if (v5[3] < 0x10u)
                *(_BYTE*)v5 = 0;
            else
                *(_BYTE*)*v5 = 0;
        }
        else
        {
            sub_140024DF0(v5);
            if (v10)
            {
            LABEL_20:
                if (v5[3] < 0x10u)
                    v11 = v5;
                else
                    v11 = (_QWORD*)*v5;
                memcpy((char*)v11 + v5[2], a2, Size);
                v12 = v5[3] < 0x10u;
                v5[2] = v10;
                if (v12)
                    v13 = v5;
                else
                    v13 = (_QWORD*)*v5;
                *((_BYTE*)v13 + v10) = 0;
            }
        }
        return v5;
    }
    if (v6 < 0x10)
        v8 = (char*)v5;
    else
        v8 = (char*)*v5;
    return (_QWORD*)sub_140024AB0(v5, v5, a2 - v8, Size);
}
_QWORD* __fastcall sub_140024AB0(_QWORD* a1, _QWORD* a2, unsigned __int64 a3, size_t a4)
{
    unsigned __int64 v4; // rax
    size_t v5; // rsi
    _QWORD* v7; // r14
    __int64 v9; // r8
    size_t v10; // rax
    size_t v11; // rdi
    _QWORD* v12; // rcx
    bool v13; // cf
    _QWORD* v14; // rax

    v4 = a2[2];
    v5 = a4;
    v7 = a2;
    if (v4 < a3)
    {
        std::_Xout_of_range("invalid string position");
        __debugbreak();
    }
    v9 = a1[2];
    v10 = v4 - a3;
    if (a4 > v10)
        v5 = v10;
    if (~v9 <= v5)
        std::_Xlength_error("string too long");
    v11 = v9 + v5;
    if (v5)
    {
        if (v11 == -1)
            std::_Xlength_error("string too long");
        if (a1[3] >= v11)
        {
            if (!v11)
            {
                a1[2] = 0;
                if (a1[3] < 0x10u)
                    *(_BYTE*)a1 = 0;
                else
                    *(_BYTE*)*a1 = 0;
                return a1;
            }
        }
        else
        {
            sub_140024DF0(a1);
            if (!v11)
                return a1;
        }
        if (v7[3] >= 0x10u)
            v7 = (_QWORD*)*v7;
        if (a1[3] < 0x10u)
            v12 = a1;
        else
            v12 = (_QWORD*)*a1;
        memcpy((char*)v12 + a1[2], (char*)v7 + a3, v5);
        v13 = a1[3] < 0x10u;
        a1[2] = v11;
        if (v13)
            v14 = a1;
        else
            v14 = (_QWORD*)*a1;
        *((_BYTE*)v14 + v11) = 0;
    }
    return a1;
}