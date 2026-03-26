// Address: 0x0049C820

void RunLegacyHandlersOrUpdateFrame(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_18 [6];
  
  piVar3 = (int *)&stack0xffffffe4;
  uVar1 = CurrentGraphicsMode();
  if ((bLastTimeCrashed == 0) || (DAT_00515de0 == 5)) {
    if (DAT_00515de0 == 7) {
      do {
        piVar3 = piVar3 + 1;
        iVar2 = *piVar3;
        if (iVar2 == 0) {
          InternalError(s_GFX_HandleDisplayRequest_1__00515e04);
        }
        SetActiveBitmapSlot(iVar2);
        iVar2 = CheckForLegacyRequirementsOrUpdateFrame();
      } while (iVar2 < 0);
      ConsumeGraphicsModeFailure(0);
      return;
    }
    iVar2 = CheckForLegacyRequirementsOrUpdateFrame();
    if (iVar2 < 0) {
      SetActiveBitmapSlot(uVar1);
      iVar2 = CheckForLegacyRequirementsOrUpdateFrame();
      if (iVar2 < 0) {
        SetActiveBitmapSlot(5);
        iVar2 = CheckForLegacyRequirementsOrUpdateFrame();
        if (iVar2 < 0) {
          InternalError(s_GFX_HandleDisplayRequest_2__00515de8);
        }
      }
    }
  }
  return;
}


