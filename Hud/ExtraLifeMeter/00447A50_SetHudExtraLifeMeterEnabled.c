
void SetHudExtraLifeMeterEnabled(char param_1)

{
  undefined4 *puVar1;
  
  g_HudExtraLifeMeterEnabled = param_1;
  if (param_1 == '\0') {
    puVar1 = &g_HudExtraLifeMeterPartialSegmentQuad;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0xe;
    } while ((int)puVar1 < 0x532660);
    g_HudExtraLifeMeterIconQuad = 0;
  }
  return;
}

