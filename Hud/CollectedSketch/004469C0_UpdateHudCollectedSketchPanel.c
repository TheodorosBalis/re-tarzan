
void UpdateHudCollectedSketchPanel(void)

{
  int iVar1;
  
  if (g_HudCollectedSketchScene != 0) {
    if (((byte)g_GameplayStateFlags & 1) != 0) {
      if (*(int *)(g_HudCollectedSketchScene + 0x18) < 0x110) {
        *(int *)(g_HudCollectedSketchScene + 0x18) =
             *(int *)(g_HudCollectedSketchScene + 0x18) + 0x30;
        return;
      }
      *(undefined4 *)(g_HudCollectedSketchScene + 0x18) = 0x110;
      return;
    }
    iVar1 = *(int *)(g_HudCollectedSketchScene + 0x18);
    if (g_HudCollectedSketchSlideTicks < 0) {
      if (-0x80 < iVar1) {
        *(int *)(g_HudCollectedSketchScene + 0x18) = iVar1 + -0x30;
        return;
      }
    }
    else {
      if (iVar1 < 0x110) {
        *(int *)(g_HudCollectedSketchScene + 0x18) = iVar1 + 0x30;
        g_HudCollectedSketchSlideTicks = g_HudCollectedSketchSlideTicks + -1;
        return;
      }
      *(undefined4 *)(g_HudCollectedSketchScene + 0x18) = 0x110;
      g_HudCollectedSketchSlideTicks = g_HudCollectedSketchSlideTicks + -1;
    }
  }
  return;
}

