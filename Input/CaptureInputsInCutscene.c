/* Address: 0x004AC360 */

bool CaptureInputsInCutscene(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return false;
  }
  iVar1 = FUN_0049e060(0xd);
  if (iVar1 != 0) {
    return true;
  }
  iVar1 = FUN_0049e060(0x20);
  if (iVar1 != 0) {
    return true;
  }
  iVar1 = FUN_0049e060(0x1b);
  if (iVar1 != 0) {
    return true;
  }
  uVar2 = CheckForJoystickInputs(0);
  return (uVar2 & 0xfffffff) != 0;
}

