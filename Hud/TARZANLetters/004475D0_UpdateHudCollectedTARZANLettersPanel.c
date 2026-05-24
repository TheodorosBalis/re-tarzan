
void UpdateHudCollectedTARZANLettersPanel(void)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = g_HudCollectedTARZANslotScene;
  if (g_HudCollectedTARZANslotScene != 0) {
    puVar2 = &g_HudTARZANLetterQuad0Flags;
    uVar3 = (uint)g_CollectedTARZANLetterMask6;
    do {
      if ((uVar3 & 1) == 0) {
        *puVar2 = *puVar2 | 0x421;
      }
      else {
        *puVar2 = *puVar2 & 0xfbde;
      }
      puVar2 = puVar2 + 0x14;
      uVar3 = (int)uVar3 >> 1;
    } while ((int)puVar2 < 0x532812);
    if (((byte)g_GameplayStateFlags & 1) == 0) {
      iVar1 = *(int *)(iVar4 + 0x1c);
      if (g_HudCollectedTARZANslotSlideTicks < 0) {
        if (-0x800 < iVar1) {
          *(int *)(iVar4 + 0x1c) = iVar1 + -0x100;
          iVar4 = g_HudCollectedTARZANslotScene;
        }
      }
      else {
        if (iVar1 < 0) {
          *(int *)(iVar4 + 0x1c) = iVar1 + 0x100;
        }
        else {
          *(undefined4 *)(iVar4 + 0x1c) = 0;
        }
        g_HudCollectedTARZANslotSlideTicks = g_HudCollectedTARZANslotSlideTicks + -1;
        iVar4 = g_HudCollectedTARZANslotScene;
      }
    }
    else if (*(int *)(iVar4 + 0x1c) < 0) {
      *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 0x100;
      iVar4 = g_HudCollectedTARZANslotScene;
    }
    else {
      *(undefined4 *)(iVar4 + 0x1c) = 0;
      iVar4 = g_HudCollectedTARZANslotScene;
    }
    if (*(int *)(iVar4 + 0x1c) < -0x7ff) {
      *(undefined4 *)(iVar4 + 0x38) = 0;
    }
    else {
      *(undefined **)(iVar4 + 0x38) = &g_HudTARZANLetterQuads;
    }
    *(ushort *)(g_HudCollectedTARZANslotScene + 0xa4) =
         (ushort)(*(int *)(g_HudCollectedTARZANslotScene + 0x1c) >> 1) & 0xfff;
  }
  return;
}

