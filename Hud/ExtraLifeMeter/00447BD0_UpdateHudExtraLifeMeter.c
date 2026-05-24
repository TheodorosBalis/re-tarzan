
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateHudExtraLifeMeter(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  short *psVar5;
  int iVar6;
  uint uVar7;
  
  if (g_HudExtraLifeMeterEnabled != '\0') {
    iVar2 = (g_ExtraLifeMeterProgress * 0x60) / g_ExtraLifeMeterThreshold;
    if ((int)g_HudExtraLifeMeterDisplayedProgress < iVar2) {
      g_HudExtraLifeMeterDisplayedProgress = g_HudExtraLifeMeterDisplayedProgress + 1;
    }
    if ((g_HudExtraLifeAwardTriggered == 0) && (0x5e < iVar2)) {
      g_HudExtraLifeAwardTriggered = 1;
      g_HudExtraLifeMeterEnabled = '\0';
      TriggerHudExtraLifeAward();
    }
    uVar7 = g_HudExtraLifeMeterDisplayedProgress;
    sVar1 = (short)((short)(&g_SinCosTable12Bit)[g_HudExtraLifeMeterPulsePhase - 0x400 & 0xfff] *
                    g_HudExtraLifeMeterPulseAmplitude >> 0xc) + (short)g_HudExtraLifeMeterBaseX;
    g_HudExtraLifeMeterPulsePhase = g_HudExtraLifeMeterPulsePhase + 0x200 & 0xfff;
    if (g_HudExtraLifeMeterPulsePhase == 0) {
      g_HudExtraLifeMeterPulseAmplitude = g_HudExtraLifeMeterPulseAmplitude >> 1;
    }
    if (g_HudExtraLifeMeterPulseAmplitude < 4) {
      g_HudExtraLifeMeterPulseAmplitude = 0;
    }
    _g_HudExtraLifeMeterIconX = sVar1 + -0x18;
    g_HudExtraLifeMeterIconQuad = 0x8022;
    psVar5 = &g_HudExtraLifeMeterSegment0X;
    do {
      *psVar5 = sVar1;
      psVar5 = psVar5 + 0x1c;
    } while ((int)psVar5 < 0x53266c);
    iVar3 = (int)uVar7 >> 4;
    iVar2 = iVar3 + 1;
    iVar6 = 1;
    if (1 < iVar2) {
      puVar4 = &g_HudExtraLifeMeterSegment1Width;
      do {
        *(undefined4 *)(puVar4 + -9) = 0x8002;
        *puVar4 = 0x10;
        puVar4 = puVar4 + 0x1c;
        iVar3 = iVar3 + -1;
        iVar6 = iVar2;
      } while (iVar3 != 0);
    }
    uVar7 = uVar7 & 0xf;
    if (uVar7 != 0) {
      _g_HudExtraLifeMeterPartialSegmentWidth = (short)uVar7;
      _g_HudExtraLifeMeterPartialSegmentX =
           (0xd2 - (short)(iVar6 << 4)) - _g_HudExtraLifeMeterPartialSegmentWidth;
      g_HudExtraLifeMeterPartialSegmentV = '\x0f' - (char)uVar7;
      g_HudExtraLifeMeterPartialSegmentQuad = 0x8022;
      g_HudExtraLifeMeterPartialSegmentU = 0;
    }
    if (iVar6 < 7) {
      puVar4 = (undefined2 *)(&g_HudExtraLifeMeterPartialSegmentWidth + iVar6 * 0x38);
      do {
        *(undefined4 *)(puVar4 + -9) = 0x802b;
        *puVar4 = 0x10;
        puVar4 = puVar4 + 0x1c;
      } while ((int)puVar4 < 0x532672);
    }
  }
  return;
}

