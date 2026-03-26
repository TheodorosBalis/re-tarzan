// Address: 0x004ACCE0

void BuildMenuTextBlockRuntime(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  int *piVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  int local_10;
  int local_c;
  
  if (param_1 != (int *)0x0) {
    puVar6 = (undefined2 *)param_1[1];
    iVar2 = 0;
    if (0 < *param_1) {
      do {
        *puVar6 = 0;
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 0x13;
      } while (iVar2 < *param_1);
    }
    if (param_1[4] != 0) {
      local_10 = 0;
      if (0 < param_1[4]) {
        piVar7 = (int *)(param_1[5] + 0x52);
        do {
          iVar2 = *piVar7 + param_1[2];
          iVar10 = 0;
          puVar9 = (ushort *)(iVar2 + 0x34);
          if (0 < *(int *)(iVar2 + 8)) {
            do {
              iVar8 = 0;
              if (0 < *(int *)(iVar2 + 4)) {
                do {
                  if ((*puVar9 & 0x8000) == 0) {
                    *(undefined2 *)(param_1[1] + (uint)*puVar9 * 0x26) = 1;
                  }
                  iVar8 = iVar8 + 1;
                  puVar9 = puVar9 + 1;
                } while (iVar8 < *(int *)(iVar2 + 4));
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < *(int *)(iVar2 + 8));
          }
          local_10 = local_10 + 1;
          piVar7 = (int *)((int)piVar7 + 0x72);
        } while (local_10 < param_1[4]);
      }
    }
    piVar7 = (int *)param_1[3];
    if (piVar7 != (int *)0x0) {
      local_10 = 0;
      piVar7 = (int *)(*piVar7 + (int)piVar7);
      piVar3 = piVar7 + 1;
      if (0 < *piVar7) {
        do {
          iVar2 = *piVar3;
          local_c = 0;
          puVar6 = (undefined2 *)(param_1[1] + piVar3[1] * 0x26);
          if (0 < piVar3[2]) {
            do {
              iVar10 = *(int *)((int)piVar3 + local_c * 4 + iVar2);
              uVar4 = FUN_004ade70(puVar6[1],puVar6[2],0);
              *(uint *)((int)piVar3 + local_c * 4 + iVar2) = uVar4;
              if (uVar4 != 0) {
                UploadPalettedTextureRect
                          (uVar4 >> 1 & 0xf,(uVar4 >> 5 & 0x1f) << 3,(uVar4 >> 10 & 0x1f) << 3,
                           puVar6[1],puVar6[2],(int)piVar3 + local_c * 4 + iVar10 + iVar2,
                           **(undefined2 **)(puVar6 + 0x11),*(undefined2 **)(puVar6 + 0x11) + 2);
              }
              local_c = local_c + 1;
            } while (local_c < piVar3[2]);
          }
          puVar6[3] = 0;
          *puVar6 = 0;
          local_10 = local_10 + 1;
          piVar3 = piVar3 + 5;
        } while (local_10 < *piVar7);
      }
    }
    puVar6 = (undefined2 *)param_1[1];
    iVar2 = 0;
    if (0 < *param_1) {
      do {
        if (*(int *)(puVar6 + 0xb) == 0) {
          uVar1 = puVar6[2];
          uVar5 = *puVar6;
          if (uVar1 < 0x28) {
            uVar5 = 1;
          }
          if (*(char *)(puVar6 + 10) == '\0') {
            uVar4 = (uint)uVar1;
          }
          else {
            uVar4 = (uint)uVar1 << 1;
          }
          uVar4 = FUN_004ade70(puVar6[1],uVar4,uVar5);
          puVar6[3] = (ushort)(uVar4 >> 1) & 0xf;
          *(uint *)(puVar6 + 8) = uVar4;
          *puVar6 = (short)((uVar4 >> 10 & 0x1f | (uVar4 >> 5 & 0xff) << 8) << 3);
          if ((uVar4 != 0) &&
             (UploadPalettedTextureRect
                        (uVar4 >> 1 & 0xf,(uVar4 >> 5 & 0x1f) << 3,(uVar4 >> 10 & 0x1f) << 3,
                         puVar6[1],puVar6[2],*(int *)(puVar6 + 6) + param_1[2],
                         **(undefined2 **)(puVar6 + 0x11),*(undefined2 **)(puVar6 + 0x11) + 2),
             *(char *)(puVar6 + 10) != '\0')) {
            uVar4 = *(uint *)(puVar6 + 8);
            UploadPalettedTextureRect
                      (uVar4 >> 1 & 0xf,(uVar4 >> 5 & 0x1f) << 3,
                       (uint)(ushort)puVar6[2] + (uVar4 >> 10 & 0x1f) * 8,puVar6[1],
                       (uint)(ushort)puVar6[2],*(int *)(puVar6 + 6) + param_1[2],
                       **(undefined2 **)(puVar6 + 0x11),*(undefined2 **)(puVar6 + 0x11) + 2);
          }
        }
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 0x13;
      } while (iVar2 < *param_1);
    }
    if (param_1[4] != 0) {
      iVar2 = param_1[5];
      iVar10 = 0;
      if (0 < param_1[4]) {
        do {
          FUN_004ad210(*(int *)(iVar2 + 0x52) + param_1[2],iVar2,param_1);
          iVar2 = iVar2 + 0x72;
          LegacyTransitionCallback_Stub(0,0,0);
          iVar10 = iVar10 + 1;
        } while (iVar10 < param_1[4]);
      }
    }
  }
  return;
}


