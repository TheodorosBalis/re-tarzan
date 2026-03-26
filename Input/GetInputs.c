// Address: 0x004383E0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetInputs(void)

{
  uint uVar1;
  uint uVar2;
  
  scan_input();
  uVar1 = (&MenuKeyJustReleased)[DAT_0051cf6c * 3];
  uVar2 = (&MenuKeyPressed)[DAT_0051cf6c * 3];
  DAT_0051cf68 = uVar2 & uVar1;
  DAT_0051cf60 = (uVar1 == 0 | uVar2) & DAT_0051cf60 | uVar2 & uVar1;
  DAT_0051cf38 = (&MenuKeyPressed)[DAT_004eca78 * 3];
  _DAT_0051cf40 = (&MenuKeyJustReleased)[DAT_004eca78 * 3] & (&MenuKeyPressed)[DAT_004eca78 * 3];
  return;
}


