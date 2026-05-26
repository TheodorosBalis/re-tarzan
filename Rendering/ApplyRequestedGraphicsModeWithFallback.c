// Address: 0x0049C820

void ApplyRequestedGraphicsModeWithFallback(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_18 [6];
  
  piVar3 = (int *)&stack0xffffffe4;
  uVar1 = CurrentGraphicsMode();
  if ((bLastTimeCrashed == 0) || (g_RequestedGraphicsMode == 5)) {
    if (g_RequestedGraphicsMode == 7) {
      do {
        piVar3 = piVar3 + 1;
        iVar2 = *piVar3;
        if (iVar2 == 0) {
          InternalError(s_GFX_HandleDisplayRequest(1)_00515e04);
        }
        RequestGraphicsModeChange(iVar2);
        iVar2 = TryApplyRequestedGraphicsMode();
      } while (iVar2 < 0);
      ConsumeGraphicsModeFailure(0);
      return;
    }
    iVar2 = TryApplyRequestedGraphicsMode();
    if (iVar2 < 0) {
      RequestGraphicsModeChange(uVar1);
      iVar2 = TryApplyRequestedGraphicsMode();
      if (iVar2 < 0) {
        RequestGraphicsModeChange(5);
        iVar2 = TryApplyRequestedGraphicsMode();
        if (iVar2 < 0) {
          InternalError(s_GFX_HandleDisplayRequest(2)_00515de8);
        }
      }
    }
  }
  return;
}


