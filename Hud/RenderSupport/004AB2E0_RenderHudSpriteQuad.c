
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderHudSpriteQuad(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint3 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  puVar3 = param_1;
  uVar1 = *(uint *)(*(int *)(param_1[1] + 0x14) + 0x10 + (param_1[2] & 0xfff) * 0x26);
  uVar7 = *param_1;
  param_1 = (uint *)0xffffff;
  if ((uVar7 & 0x18) != 0) {
    uVar7 = puVar3[9];
    _DAT_00a348a8 = uVar7 & 0xff00 | uVar7 >> 0x10 & 0xff | (uVar7 & 0xff) << 0x10;
    param_1 = (uint *)_DAT_00a348a8;
  }
  if (g_FadeBrightnessInverse != 0) {
    iVar9 = 0x1000 - g_FadeBrightnessInverse;
    param_1 = (uint *)((((uint)param_1 >> 0x10) * iVar9 & 0xfffff000) << 4 |
                      (((uint)param_1 >> 8 & 0xff) * iVar9 & 0xfffff00f |
                      ((uint)param_1 & 0xff) * iVar9 >> 8) >> 4);
  }
  if (((uint)param_1 & 0xff0000) < 0x7f8000) {
    uVar7 = (uint)param_1 >> 0xf & 0x1fe;
  }
  else {
    uVar7 = 0xff;
  }
  if (((uint)param_1 & 0xff00) < 0x7f80) {
    uVar8 = (uint)param_1 >> 7 & 0x1fe;
  }
  else {
    uVar8 = 0xff;
  }
  uVar4 = ((uint)param_1 & 0xff) * 2;
  if (0xfe < uVar4) {
    uVar4 = 0xff;
  }
  if ((*puVar3 & 4) == 0) {
    iVar9 = (uVar1 >> 0x17 & 0xff) + 1;
    iVar10 = (uVar1 >> 0xf & 0xff) + 1;
  }
  else {
    iVar9 = (int)*(short *)((int)puVar3 + 0x12);
    iVar10 = (int)(short)puVar3[4];
  }
  uVar2 = (uint3)(uVar1 >> 8);
  iVar5 = (CONCAT31((int3)(((uint)(uVar2 >> 9) << 0x10) >> 8),(char)(uVar1 >> 10)) & 0xffffff1f) <<
          3;
  iVar6 = (short)puVar3[3] * 0x280;
  DrawTexturedQuad((int)(iVar6 + (iVar6 >> 0x1f & 0x1ffU)) >> 9,
                   (*(short *)((int)puVar3 + 0xe) * 0x1e0) / 0xf0,(int)(short)puVar3[4],
                   (int)*(short *)((int)puVar3 + 0x12) << 1,
                   (CONCAT31((int3)((uint)iVar5 >> 8),(char)(uVar1 >> 5)) & 0xffff001f) << 3,iVar5,
                   iVar10,iVar9,CONCAT31(uVar2 >> 1,(char)(uVar1 >> 1)) & 0xffffff0f,
                   uVar4 | uVar7 << 0x10 | uVar8 << 8 | 0xff000000,
                   CONCAT31((int3)((uint)param_2 >> 8),(byte)*puVar3) & 0xffffff01,param_2,0,1);
  return;
}

