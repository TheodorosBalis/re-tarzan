/* Address: 0x004AB280 */

byte ScanForInputs(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = CheckForJoystickInputs(0);
  if ((uVar1 & 0xfffffff) != 0) {
    return 1;
  }
  iVar2 = FUN_0049e060(0x20);
  if (iVar2 != 0) {
    return 2;
  }
  iVar2 = FUN_0049e060(0xd);
  if (iVar2 != 0) {
    return 3;
  }
  iVar2 = FUN_0049e060(0x1b);
  return -(iVar2 != 0) & 4;
}

