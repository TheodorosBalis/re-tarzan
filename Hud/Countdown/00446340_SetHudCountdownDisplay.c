
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetHudCountdownDisplay(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  short sVar7;
  
  if (g_HudCountdownScene != 0) {
    if ((short)param_1 == -1) {
      param_1 = g_HudCountdownBcdTime >> 8;
    }
    if ((short)param_2 == -1) {
      param_2 = g_HudCountdownFlags;
    }
    g_HudCountdownFlags = CONCAT22(g_HudCountdownFlags._2_2_,(short)param_2);
    g_HudCountdownBcdTime = (param_1 & 0xffff) << 8;
    *(int *)(g_HudCountdownScene + 0x10) = g_WorldSceneEntryArrayBase + 0x68;
    *(undefined2 *)(g_HudCountdownScene + 0xc) = 0x2019;
    *(undefined **)(g_HudCountdownScene + 0x38) = &DAT_005328e8;
    *(undefined2 *)(g_HudCountdownScene + 0xe) = 0x100;
    *(ushort *)(g_HudCountdownScene + 0xe) =
         *(ushort *)(g_HudCountdownScene + 0xe) | (ushort)((~param_2 & 0xfffe) << 0xe);
    iVar6 = g_HudCountdownScene;
    *(undefined4 *)(g_HudCountdownScene + 0x14) = DAT_00532180;
    *(undefined4 *)(iVar6 + 0x18) = DAT_00532184;
    *(undefined4 *)(iVar6 + 0x1c) = DAT_00532188;
    iVar6 = g_HudCountdownScene;
    _DAT_005328f4 = 4;
    puVar1 = (undefined4 *)(g_HudCountdownScene + 0x20);
    psVar2 = &DAT_005328f8;
    puVar4 = &DAT_004f0258;
    do {
      sVar7 = (short)(param_1 & 0xf);
      if (9 < (param_1 & 0xf)) {
        sVar7 = 0;
      }
      *(undefined4 *)(psVar2 + 2) = *(undefined4 *)(iVar6 + 0x10);
      *psVar2 = sVar7 + 0x200f;
      puVar5 = puVar4 + 1;
      psVar2[1] = *(ushort *)(iVar6 + 0xe) & 0x7fff;
      *(undefined4 *)(psVar2 + 4) = *puVar4;
      psVar2[6] = 0;
      psVar2[7] = 0;
      psVar2[8] = 0;
      psVar2[9] = 0;
      param_1 = param_1 >> 4 & 0xfff;
      *(undefined4 *)(psVar2 + 10) = *puVar1;
      *(undefined4 *)(psVar2 + 0xc) = *(undefined4 *)(iVar6 + 0x24);
      *(undefined4 *)(psVar2 + 0xe) = *(undefined4 *)(iVar6 + 0x28);
      *(undefined4 *)(psVar2 + 0x10) = *(undefined4 *)(iVar6 + 0x2c);
      psVar2 = psVar2 + 0x14;
      puVar4 = puVar5;
    } while ((int)puVar5 < 0x4f0268);
    iVar6 = (-(uint)((g_HudCountdownFlags & 4) != 0) & 0xfffffffe) + 4;
    if (0 < iVar6) {
      puVar3 = &DAT_005328fa;
      do {
        *(byte *)((int)puVar3 + 1) = *(byte *)((int)puVar3 + 1) | 0x80;
        puVar3 = puVar3 + 0x14;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}

