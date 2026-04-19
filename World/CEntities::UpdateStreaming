// 0x00444580

void CEntities::UpdateStreaming(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  _g_RuntimeProcessingPhase = 1;
  *g_Phase2RuntimeEntryList = 0;
  *DAT_005314a8 = 0;
  ActivateRuntimeDescriptorsInBounds();
  if (*(code **)(DAT_00534004 + 0x14) != (code *)0x0) {
    (**(code **)(DAT_00534004 + 0x14))();
  }
  uVar4 = (uint)DAT_005314e4;
  if (uVar4 < DAT_00531b04) {
    iVar3 = uVar4 * 0x54;
    do {
      iVar1 = DAT_00531488 + iVar3;
      if ((*(byte *)(DAT_00531488 + iVar3) & 1) != 0) {
        uVar2 = *(uint *)(iVar1 + 0x28);
        if ((uVar2 & 1) != 0) {
          (**(code **)(iVar1 + 0x30))(iVar1);
        }
        if ((uVar2 & 2) != 0) {
          *g_Phase2RuntimeEntryList = *g_Phase2RuntimeEntryList + 1;
          g_Phase2RuntimeEntryList[*g_Phase2RuntimeEntryList] = iVar1;
        }
        if ((uVar2 & 0x1000) != 0) {
          *DAT_005314a8 = *DAT_005314a8 + 1;
          DAT_005314a8[*DAT_005314a8] = iVar1;
        }
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x54;
    } while ((int)uVar4 < (int)(uint)DAT_00531b04);
    _g_RuntimeProcessingPhase = 0;
    return;
  }
  _g_RuntimeProcessingPhase = 0;
  return;