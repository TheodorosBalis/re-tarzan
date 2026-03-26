// Address: 0x00498190

void StreamedThreadEntry(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_ESI;
  undefined4 *puVar5;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 *puStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  bVar1 = false;
  do {
    DAT_00719da8 = 1;
    for (; (DAT_00719da4 == 0 && (DAT_00515848 - DAT_0051584c < 3)); DAT_00515848 = DAT_00515848 + 1
        ) {
      if (DAT_00515848 < (int)(DAT_00718f64 / 0xf)) {
        if (((uint)(&DAT_00718f6c)[DAT_00515848] < 0x5ab5d) &&
           (iVar4 = LoadGameFileInBuffer(&DAT_006be3f8,(&DAT_00718f6c)[DAT_00515848],1,DAT_00719d7c)
           , iVar4 == 1)) {
          uVar3 = DAT_00515848 + 1U & 0x80000003;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
          }
          *(undefined4 *)(uVar3 * 0x5ab5c + 0x553688) = DAT_006be3f8;
          uVar3 = DAT_00515848 + 1U & 0x80000003;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
          }
          iVar4 = FUN_0049a270(&DAT_006c0f10,&DAT_005561a0 + uVar3 * 0x5ab5c);
          if (iVar4 != 0x58044) {
            DAT_00719da4 = -2;
          }
        }
        else {
          DAT_00719da4 = -1;
        }
      }
      else {
        bVar1 = true;
      }
      if ((DAT_00719da4 == 0) && (DAT_00719d8c != (int *)0x0)) {
        puStack_c = (undefined4 *)0x0;
        uStack_10 = 0;
        uStack_14 = 0;
        uStack_8 = 0;
        uVar3 = DAT_00515848 + 1U & 0x80000003;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
        }
        uVar3 = uVar3 * 0xac44;
        iVar4 = (**(code **)(*DAT_00719d8c + 0x10))(DAT_00719d8c,&uStack_14,&uStack_8);
        uVar2 = 0xffffffff;
        while ((((iVar4 == 0 && (uVar2 != unaff_ESI)) && (uVar3 <= unaff_ESI)) &&
               (unaff_ESI <= uVar3 + 0xac44))) {
          Sleep(5);
          iVar4 = (**(code **)(*DAT_00719d8c + 0x10))(DAT_00719d8c,&stack0xffffffe0,&uStack_14);
          uVar2 = unaff_ESI;
        }
        iVar4 = (**(code **)(*DAT_00719d8c + 0x2c))
                          (DAT_00719d8c,uVar3,0xac44,&stack0xffffffe8,&stack0xffffffe4,0,0,0);
        if (iVar4 == -0x7787ff6a) {
          (**(code **)(*DAT_00719d8c + 0x50))(DAT_00719d8c);
          (**(code **)(*DAT_00719d8c + 0x48))(DAT_00719d8c);
          (**(code **)(*DAT_00719d8c + 0x2c))
                    (DAT_00719d8c,0,0xac44,&uStack_14,&stack0xffffffe8,0,0,0);
          bVar1 = true;
        }
        if ((puStack_c != (undefined4 *)0x0) && (uStack_10 != 0)) {
          if (bVar1) {
            puVar5 = puStack_c;
            for (uVar3 = uStack_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            for (uVar3 = uStack_10 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined1 *)puVar5 = 0;
              puVar5 = (undefined4 *)((int)puVar5 + 1);
            }
          }
          else {
            FUN_00493be0(&DAT_006be3fc,puStack_c,0xac44,&uStack_4);
          }
          (**(code **)(*DAT_00719d8c + 0x4c))(DAT_00719d8c,puStack_c,uStack_10,0,0);
        }
        bVar1 = false;
      }
    }
    DAT_00719da8 = 0;
    if (DAT_00719d9c != (HANDLE)0x0) {
      SuspendThread(DAT_00719d9c);
    }
  } while( true );
}


