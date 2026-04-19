// 0x00444560

void CWorld::UpdateHudPhase(void)

{
  _g_RuntimeProcessingPhase = 4;
  CWorld::UpdateHud();
  _g_RuntimeProcessingPhase = 0;
  return;
}