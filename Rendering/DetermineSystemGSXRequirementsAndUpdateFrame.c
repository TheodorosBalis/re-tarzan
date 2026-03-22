/* Address: 0x0049CDC0 */

undefined4 DetermineSystemGSXRequirementsAndUpdateFrame(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_00722968 != 0) {
    return 1;
  }
  if (param_1 == 0) {
    return 0;
  }
  puVar2 = &DAT_0072297c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_00722964 = param_1;
  DAT_00722978 = 0;
  DAT_0072296c = 0;
  iVar1 = InitBackBufferDIBSection(param_1);
  if (iVar1 == 0) {
    LegacyRoutinesForGraphicsIfNeeded();
    InternalError(s_Gfx_Init::_00515e20);
    DAT_00722968 = 0;
    return 0;
  }
  GraphicsMode = 0;
  DAT_00722994 = 1;
  SetActiveBitmapSlot(5);
  RunLegacyHandlersOrUpdateFrame();
  WriteToGraphicsBufferIfGraphicsInitialized_stub(0,0,0);
  ConfirmGraphicsInitialized();
  ShowFrameOnScreen();
  DAT_00722968 = 1;
  return 1;
}

