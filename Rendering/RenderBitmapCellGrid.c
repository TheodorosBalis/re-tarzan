// Address: 0x004A9B40

void RenderBitmapCellGrid(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar10;
  int iVar11;
  uint *puVar12;
  uint *local_28;
  uint local_24;
  int local_14;
  int local_10;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_2 == (uint *)0x0) {
    return;
  }
  uVar4 = 0x1000 - g_FadeBrightnessInverse;
  if (g_FadeBrightnessInverse == 0) {
    uVar1 = 0xffffff;
  }
  else {
    uVar1 = ((uVar4 & 0xfffffff0) << 8 | uVar4 & 0xfffffff0) << 4 | (int)uVar4 >> 4;
  }
  local_28 = (uint *)*param_1;
  if (local_28 == (uint *)0x0) {
    return;
  }
  local_24 = param_2[1];
  uVar7 = *(int *)((int)param_1 + 0x4e) << 1 | 1;
  bVar3 = (char)*(undefined4 *)((int)param_1 + 0x3e) + 1;
  if ((int)local_24 < 0) {
    iVar11 = (int)-local_24 >> (bVar3 & 0x1f);
    if (*(int *)((int)param_1 + 0x2e) <= iVar11) {
      return;
    }
    uVar6 = -local_24 & uVar7;
    local_24 = -uVar6;
    local_10 = (int)(uVar7 + uVar6 + 0x1e0) >> (bVar3 & 0x1f);
    iVar2 = *(int *)((int)param_1 + 0x2e) - iVar11;
    if (iVar2 < local_10) {
      local_10 = iVar2;
    }
    local_28 = (uint *)((int)local_28 + *(int *)((int)param_1 + 0x2a) * iVar11 * 0xe);
  }
  else {
    local_10 = (int)((uVar7 - local_24) + 0x1e0) >> (bVar3 & 0x1f);
    if (local_10 < 1) {
      return;
    }
    if (*(int *)((int)param_1 + 0x2e) <= local_10) {
      local_10 = *(int *)((int)param_1 + 0x2e);
    }
  }
  if (*(int *)((int)param_1 + 0x6a) == 0) {
    uVar7 = *param_2;
    if ((int)uVar7 < 0) {
      bVar3 = (byte)*(undefined4 *)((int)param_1 + 0x3a);
      iVar11 = (int)-uVar7 >> (bVar3 & 0x1f);
      local_28 = (uint *)((int)local_28 + iVar11 * 0xe);
      if (*(int *)((int)param_1 + 0x2a) <= iVar11) {
        return;
      }
      uVar6 = -uVar7 & *(uint *)((int)param_1 + 0x4a);
      uVar7 = -uVar6;
      param_2 = (uint *)((int)(*(uint *)((int)param_1 + 0x4a) + uVar6 + 0x280) >> (bVar3 & 0x1f));
      if ((int)param_2 < 1) {
        return;
      }
      iVar11 = *(int *)((int)param_1 + 0x2a) - iVar11;
      if ((int)param_2 <= iVar11) goto LAB_004a9d03;
    }
    else {
      if (0x27f < (int)uVar7) {
        return;
      }
      param_2 = (uint *)((int)((*(int *)((int)param_1 + 0x4a) - uVar7) + 0x280) >>
                        ((byte)*(undefined4 *)((int)param_1 + 0x3a) & 0x1f));
      if ((int)param_2 < 1) {
        return;
      }
      iVar11 = *(int *)((int)param_1 + 0x2a);
      if ((int)param_2 <= iVar11) goto LAB_004a9d03;
    }
    param_2 = (uint *)iVar11;
  }
  else {
    bVar3 = (byte)*(undefined4 *)((int)param_1 + 0x3a);
    local_28 = (uint *)((int)local_28 + ((int)*param_2 >> (bVar3 & 0x1f)) * 0xe);
    uVar6 = *(uint *)((int)param_1 + 0x4a) & *param_2;
    uVar7 = -uVar6;
    param_2 = (uint *)((int)(*(uint *)((int)param_1 + 0x4a) + uVar6 + 0x280) >> (bVar3 & 0x1f));
    if ((int)param_2 < 1) {
      return;
    }
  }
LAB_004a9d03:
  if (0 < local_10) {
    do {
      iVar11 = (int)(short)uVar7;
      puVar12 = local_28;
      local_14 = (int)param_2;
      if (0 < (int)param_2) {
        do {
          uVar6 = *puVar12;
          uVar8 = uVar6 & 0xc00000;
          if (uVar8 != 0) {
            uVar5 = uVar1 | 0xff000000;
            if (uVar8 == 0x400000) {
LAB_004a9dac:
              uVar9 = uVar6 >> 9 & 0xff;
            }
            else {
              if (uVar4 == 0x1000) {
                uVar5 = puVar12[1] | 0xff000000;
              }
              else {
                uVar5 = puVar12[1];
                uVar5 = ((uVar5 >> 0x10 & 0xff) * uVar4 & 0xfffff000 | 0xfff00000) << 4 |
                        ((uVar5 >> 8 & 0xff) * uVar4 >> 0xc) << 8 | (uVar5 & 0xff) * uVar4 >> 0xc;
              }
              if (uVar8 == 0x400000) goto LAB_004a9dac;
              uVar9 = 0;
            }
            if (uVar8 == 0x400000) {
              uVar10 = (undefined1)*puVar12;
            }
            else {
              uVar10 = 0;
            }
            DrawTexturedQuad(*(short *)((int)puVar12 + 10) + iVar11,local_24 + (short)puVar12[3] * 2
                             ,uVar6 & 0x1ff,(uVar6 >> 9 & 0x1ff) << 1,(ushort)puVar12[2] & 0xff,
                             (char)((ushort)puVar12[2] >> 8),uVar10,uVar9,uVar6 >> 0x12 & 0xffffff0f
                             ,uVar5,0,CONCAT22((short)((uint)iVar11 >> 0x10),
                                               (undefined2)g_DrawWindowXOffset),0,1);
          }
          local_14 = local_14 + -1;
          iVar11 = iVar11 + *(int *)((int)param_1 + 0x42);
          puVar12 = (uint *)((int)puVar12 + 0xe);
        } while (local_14 != 0);
      }
      local_28 = (uint *)((int)local_28 + *(int *)((int)param_1 + 0x2a) * 0xe);
      local_24 = local_24 + *(int *)((int)param_1 + 0x46) * 2;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return;
}


