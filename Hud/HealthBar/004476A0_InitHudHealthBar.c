
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudHealthBar(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  g_HudHealthBarEnabled = 1;
  g_HudDisplayedHealth = 0;
  g_HudDisplayedHealthMax = 0x100;
  iVar2 = 0;
  puVar1 = &DAT_00532208;
  do {
    puVar1[-2] = 0;
    *puVar1 = 0x3017;
    *(undefined2 *)(puVar1 + 2) = 0x40;
    *(undefined2 *)((int)puVar1 + 10) = 0x10;
    *(short *)(puVar1 + 1) =
         ((short)((ulonglong)((longlong)iVar2 * 0x66666667) >> 0x28) + 0x40) -
         ((short)(char)((char)(iVar2 / 0x2800000) + (char)(iVar2 >> 0x1f)) >> 0xf);
    *(undefined2 *)((int)puVar1 + 6) = 0xd7;
    puVar1[7] = 0x80303030;
    *(short *)((int)puVar1 + 10) = *(short *)((int)puVar1 + 10) + -1;
    if (0x13f < *(short *)(puVar1 + 1)) {
      *(short *)(puVar1 + 1) = *(short *)(puVar1 + 1) + -1;
    }
    puVar1 = puVar1 + 0xe;
    iVar2 = iVar2 + 0x8000;
  } while ((int)puVar1 < 0x5324a8);
  g_HudPartialHealthFillWidth._0_2_ = 0x40;
  g_HudPartialHealthFillX = 0x40;
  g_HudPartialHealthFillQuad = 0;
  DAT_005321e4._0_1_ = 0;
  DAT_005321e4._1_1_ = 0;
  g_HudPartialHealthFillUWidth._1_1_ = 0;
  DAT_005321e8._0_1_ = 0;
  DAT_005321d0 = 0x3017;
  g_HudPartialHealthFillWidth._2_2_ = 0xf;
  _DAT_005321d6 = 0xd7;
  g_HudPartialHealthFillUWidth._0_1_ = 0x3f;
  DAT_005321e8._1_1_ = 0xf;
  g_HudPartialHealthFillClippedUWidth._0_1_ = 0x3f;
  g_HudPartialHealthFillClippedUWidth._1_1_ = 0xf;
  return;
}

