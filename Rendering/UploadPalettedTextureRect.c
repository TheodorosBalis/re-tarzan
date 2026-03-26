// Address: 0x004AD010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UploadPalettedTextureRect
               (undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               int param_7,int param_8)

{
  byte *pbVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  int iVar8;
  short *psVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  int local_208;
  int local_204;
  short local_200;
  undefined4 local_1fe [127];
  
  if ((((param_2 < 0x100) && (param_3 < 0x100)) && (param_4 < 0x101)) &&
     (((param_5 < 0x101 && (param_2 + param_4 < 0x101)) && (param_3 + param_5 < 0x101)))) {
    local_200 = 0;
    puVar11 = local_1fe;
    for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    iVar8 = ((0x10 < param_7) - 1 & 0xfffffffc) + 8;
    *(undefined2 *)puVar11 = 0;
    iVar5 = 1 << ((byte)iVar8 & 0x1f);
    if (0 < iVar5) {
      psVar9 = &local_200;
      do {
        uVar3 = *(ushort *)((param_8 - (int)&local_200) + (int)psVar9);
        if ((uVar3 & 0x8000) != 0) {
          uVar6 = (uint)(short)uVar3;
          _DAT_00c46078 = uVar6 >> 10 & 0x1f | (uVar6 & 0x1f) << 10 | uVar6 & 0x3e0;
          *psVar9 = (short)_DAT_00c46078;
          if ((short)_DAT_00c46078 == 0) {
            *psVar9 = 1;
          }
        }
        psVar9 = psVar9 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (iVar8 == 8) {
      local_204 = param_4;
    }
    else {
      local_204 = param_4 / 2;
    }
    if (0 < param_5) {
      puVar10 = &DAT_0077e7b2;
      local_208 = param_5;
      do {
        if (iVar8 == 8) {
          iVar5 = 0;
          if (0 < param_4) {
            puVar7 = puVar10 + -1;
            do {
              pbVar1 = (byte *)(iVar5 + param_6);
              iVar5 = iVar5 + 1;
              *puVar7 = *(undefined2 *)((int)local_1fe + (uint)*pbVar1 * 2 + -2);
              puVar7 = puVar7 + 1;
            } while (iVar5 < param_4);
          }
        }
        else {
          iVar5 = 0;
          puVar7 = puVar10;
          if (0 < param_4 / 2) {
            do {
              uVar4 = *(undefined2 *)((int)local_1fe + (*(byte *)(iVar5 + param_6) & 0xf) * 2 + -2);
              puVar7[-1] = uVar4;
              puVar2 = (undefined1 *)(iVar5 + param_6);
              iVar5 = iVar5 + 1;
              *puVar7 = *(undefined2 *)
                         ((int)local_1fe +
                         ((int)(uint)CONCAT11((char)((ushort)uVar4 >> 8),*puVar2) >> 4 & 0xfU) * 2 +
                         -2);
              puVar7 = puVar7 + 2;
            } while (iVar5 < param_4 / 2);
          }
        }
        puVar10 = puVar10 + 0x100;
        param_6 = param_6 + local_204;
        local_208 = local_208 + -1;
      } while (local_208 != 0);
    }
    UpdateTexturesReference(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}


