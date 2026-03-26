// Address: 0x004ABD00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CanOpenPauseMenu(void)

{
  if ((((g_PendingTransitionPayload == 0) && (DAT_00c4604c != 0)) && ((ram0x00534026 & 0x8000) == 0)
      ) && (FadeBrightness != 0)) {
    return 1;
  }
  return 0;
}


