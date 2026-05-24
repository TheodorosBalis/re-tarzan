
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CWorld__UpdateHudPhase(void)

{
  _g_RuntimeProcessingPhase = 4;
  CWorld__UpdateHud();
  _g_RuntimeProcessingPhase = 0;
  return;
}

