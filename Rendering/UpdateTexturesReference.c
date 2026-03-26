// Address: 0x004A4C00

void UpdateTexturesReference(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar8 = DAT_005175f0;
  (&g_DirtyTexturePageFlags)[param_1 & 0xf] = 1;
  iVar1 = (param_1 & 0xf) * 0x10000;
  if (iVar8 == 0) {
    if (0 < param_5) {
      puVar4 = (undefined4 *)&g_MenuTextureAtlasPixels;
      iVar8 = (param_3 * 0x100 + iVar1 + param_2) * 2;
      do {
        puVar9 = (undefined4 *)(g_GraphicsPageBufferBase + iVar8);
        iVar8 = iVar8 + 0x200;
        puVar7 = puVar4;
        for (uVar3 = (uint)(param_4 * 2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        puVar4 = puVar4 + 0x80;
        param_5 = param_5 + -1;
        for (uVar3 = param_4 * 2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      } while (param_5 != 0);
    }
  }
  else if (0 < param_5) {
    puVar5 = &g_MenuTextureAtlasPixels;
    iVar8 = (param_3 * 0x100 + iVar1 + param_2) * 2;
    do {
      puVar2 = puVar5;
      iVar1 = iVar8;
      iVar6 = param_4;
      if (0 < param_4) {
        do {
          iVar6 = iVar6 + -1;
          *(ushort *)(iVar1 + g_GraphicsPageBufferBase) = (*puVar2 & 0xffe0) << 1 | *puVar2 & 0x3f;
          puVar2 = puVar2 + 1;
          iVar1 = iVar1 + 2;
        } while (iVar6 != 0);
      }
      iVar8 = iVar8 + 0x200;
      puVar5 = puVar5 + 0x100;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}


