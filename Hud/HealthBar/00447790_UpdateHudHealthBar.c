
void UpdateHudHealthBar(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined2 local_4;
  
  if (g_HudHealthBarEnabled == '\0') {
    return;
  }
  uVar2 = (uint)g_PlayerMaxHealth;
  bVar6 = (int)(g_HudDisplayedHealthMax - uVar2) < 0;
  if ((int)g_HudDisplayedHealthMax < (int)uVar2) {
    g_HudDisplayedHealthMax = g_HudDisplayedHealthMax + 2;
    if ((int)uVar2 < (int)g_HudDisplayedHealthMax) {
      bVar6 = false;
      g_HudDisplayedHealthMax = uVar2;
      goto LAB_004477c7;
    }
  }
  else {
LAB_004477c7:
    if ((g_HudDisplayedHealthMax != uVar2 && SBORROW4(g_HudDisplayedHealthMax,uVar2) == bVar6) &&
       (g_HudDisplayedHealthMax = g_HudDisplayedHealthMax - 2,
       (int)g_HudDisplayedHealthMax < (int)uVar2)) {
      g_HudDisplayedHealthMax = uVar2;
    }
  }
  uVar2 = g_HudDisplayedHealthMax;
  uVar3 = (uint)g_PlayerHealth;
  bVar6 = (int)(g_HudDisplayedHealth - uVar3) < 0;
  if ((int)g_HudDisplayedHealth < (int)uVar3) {
    g_HudDisplayedHealth = g_HudDisplayedHealth + 2;
    if ((int)g_HudDisplayedHealth <= (int)uVar3) goto LAB_0044781c;
    bVar6 = false;
    g_HudDisplayedHealth = uVar3;
  }
  if ((g_HudDisplayedHealth != uVar3 && SBORROW4(g_HudDisplayedHealth,uVar3) == bVar6) &&
     (g_HudDisplayedHealth = g_HudDisplayedHealth - 2, (int)g_HudDisplayedHealth < (int)uVar3)) {
    g_HudDisplayedHealth = uVar3;
  }
LAB_0044781c:
  uVar3 = g_HudDisplayedHealth;
  if ((int)g_HudDisplayedHealthMax < (int)g_HudDisplayedHealth) {
    uVar3 = g_HudDisplayedHealthMax;
  }
  iVar4 = 0;
  iVar5 = (int)g_HudDisplayedHealthMax >> 6;
  if (0 < iVar5) {
    puVar1 = &g_HudHealthSegment0Color;
    do {
      if (iVar4 < (int)uVar3 >> 6) {
        puVar1[-9] = 0x800c;
        *puVar1 = 0x80005000;
      }
      else {
        puVar1[-9] = 0x800a;
        *puVar1 = 0x80000050;
      }
      *(undefined2 *)(puVar1 + -5) = 0x40;
      iVar4 = iVar4 + 1;
      puVar1 = puVar1 + 0xe;
    } while (iVar4 < iVar5);
  }
  uVar2 = uVar2 & 0x3f;
  iVar5 = iVar4;
  if (uVar2 != 0) {
    local_4 = (undefined2)uVar2;
    iVar5 = iVar4 + 1;
    (&g_HudHealthSegmentQuads)[iVar4 * 0xe] = 0x802c;
    (&g_HudHealthSegment0Color)[iVar4 * 0xe] = 0x80000050;
    (&g_HudHealthSegment0Width)[iVar4 * 0x1c] = local_4;
    (&g_HudHealthSegment0UWidth)[iVar4 * 0x38] = (char)uVar2;
    (&g_HudHealthSegment0ClippedUWidth)[iVar4 * 0x38] = (char)uVar2;
  }
  if (iVar5 < 0xc) {
    puVar1 = &g_HudHealthSegmentQuads + iVar5 * 0xe;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0xe;
    } while ((int)puVar1 < 0x5324a0);
  }
  uVar2 = uVar3 & 0x3f;
  if (uVar2 != 0) {
    iVar4 = ((int)uVar3 >> 6) << 0xf;
    g_HudPartialHealthFillQuad = 0x802c;
    g_HudPartialHealthFillColor = 0x80005000;
    g_HudPartialHealthFillWidth._0_2_ = (undefined2)uVar2;
    g_HudPartialHealthFillUWidth._0_1_ = (undefined1)uVar2;
    g_HudPartialHealthFillX =
         ((short)((ulonglong)((longlong)iVar4 * 0x66666667) >> 0x28) + 0x40) -
         ((short)(char)((char)(iVar4 / 0x2800000) + (char)(iVar4 >> 0x1f)) >> 0xf);
    g_HudPartialHealthFillClippedUWidth._0_1_ = (undefined1)g_HudPartialHealthFillUWidth;
    if (0x13f < g_HudPartialHealthFillX) {
      g_HudPartialHealthFillX = g_HudPartialHealthFillX + -1;
    }
  }
  return;
}

