// 00444660

void CEntities::Process(void)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  
  _g_RuntimeProcessingPhase = 2;
  iVar3 = 0;
  piVar2 = g_Phase2RuntimeEntryList;
  if (0 < *g_Phase2RuntimeEntryList) {
    do {
      pbVar1 = (byte *)piVar2[iVar3 + 1];
      iVar3 = iVar3 + 1;
      if ((*pbVar1 & 1) != 0) {
        (**(code **)(pbVar1 + 0x30))(pbVar1);
        piVar2 = g_Phase2RuntimeEntryList;
      }
    } while (iVar3 < *piVar2);
  }
  _g_RuntimeProcessingPhase = 0;
  CWorld::UpdateBonusLevelTimer();
  CWorld::UpdateHud();
  return;
}