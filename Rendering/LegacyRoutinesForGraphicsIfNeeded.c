/* Address: 0x0049CE70 */

void LegacyRoutinesForGraphicsIfNeeded(void)

{
  SetActiveBitmapSlot(5);
  RunLegacyHandlersOrUpdateFrame();
  DoReconfigurationStuffOnWindow();
  UnavailableFunctionsDoNothing();
  CheckForUnsupportedFunctions_DoNothing();
  GraphicsMode = 0;
  return;
}

