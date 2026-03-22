/* Address: 0x0049C900 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CheckForLegacyRequirementsOrUpdateFrame(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00515de0;
  iVar2 = 0;
  if (DAT_00515de0 == GraphicsMode) {
    return GraphicsMode;
  }
  if (DAT_00515de0 == 7) {
    return GraphicsMode;
  }
  if (DAT_00515de0 < 0) {
    DAT_00515de0 = GraphicsMode;
    DAT_00722978 = -iVar1;
    return iVar1;
  }
  DAT_00722994 = DAT_00722994 + 1;
  DoReconfigurationStuffOnWindow();
  UnavailableFunctionsDoNothing();
  CheckForUnsupportedFunctions_DoNothing();
  switch(DAT_00515de0) {
  case 1:
    iVar1 = FUN_0049d160(DAT_00722964,0,DAT_0072296c == 1);
    if (iVar1 == 0) {
      DAT_0072296c = -1;
    }
    else {
      if (DAT_00722980 == 0) {
        DAT_00722980 = iVar1;
      }
      iVar2 = 1;
    }
    break;
  case 2:
    iVar1 = FUN_00494ec0(DAT_00722964,0,DAT_0072296c == -1);
    if (iVar1 == 0) {
      iVar1 = FUN_00494eb0();
      if (iVar1 != 0) {
        DAT_0072296c = 1;
      }
    }
    else {
      if (DAT_00722984 == 0) {
        DAT_00722984 = iVar1;
      }
      iVar2 = 2;
    }
    break;
  case 3:
    iVar1 = FUN_00497710(DAT_00722964,0,&DAT_00722974,&DAT_00722970);
    if (iVar1 == 0) goto LAB_0049c9af;
    if (DAT_00722988 == 0) {
      DAT_00722988 = iVar1;
    }
    iVar2 = 3;
    goto LAB_0049ca70;
  case 4:
    iVar1 = FUN_00497710(DAT_00722964,1,&DAT_00722974,&DAT_00722970);
    if (iVar1 != 0) {
      if (DAT_0072298c == 0) {
        DAT_0072298c = iVar1;
      }
      GraphicsMode = 0;
      DAT_00722978 = 4;
      return -4;
    }
    goto LAB_0049c9af;
  case 5:
    DAT_00722970 = 0;
    _DAT_00722974 = 0;
    DAT_00515de0 = 5;
    goto LAB_0049c9af;
  default:
    GraphicsMode = 0;
    DAT_00722978 = 1;
    return -1;
  }
  DAT_00722970 = 0;
  _DAT_00722974 = 0;
  if (iVar2 != 0) {
LAB_0049ca70:
    DAT_00722978 = iVar2;
    GraphicsMode = 0;
    return -iVar2;
  }
LAB_0049c9af:
  GraphicsMode = DAT_00515de0;
  ConfirmGraphicsInitialized();
  WriteToGraphicsBufferIfGraphicsInitialized_stub(0,0,0);
  ConfirmGraphicsInitialized();
  ShowFrameOnScreen();
  return 0;
}

