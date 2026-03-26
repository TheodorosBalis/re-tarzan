// Address: 0x0049F0D0

uint GetUserInputInMenuAndProcessSound(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = IsControlBindingPressed(0x26);
  uVar3 = (uint)(iVar1 != 0);
  iVar1 = IsControlBindingPressed(0x28);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 2;
  }
  iVar1 = IsControlBindingPressed(0xd);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 0x10;
  }
  iVar1 = IsControlBindingPressed(0x20);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 0x10;
  }
  iVar1 = IsControlBindingPressed(0x25);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 4;
  }
  iVar1 = IsControlBindingPressed(0x27);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 8;
  }
  iVar1 = IsControlBindingPressed(0x1b);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 0x60;
  }
  iVar1 = IsControlBindingPressed(8);
  if (iVar1 != 0) {
    uVar3 = uVar3 | 0x20;
  }
  uVar2 = CheckForJoystickInputs(0);
  if ((uVar2 & 0x40000000) != 0) {
    uVar3 = uVar3 | 1;
  }
  if ((uVar2 & 0x80000000) != 0) {
    uVar3 = uVar3 | 2;
  }
  if ((uVar2 & 0x10000000) != 0) {
    uVar3 = uVar3 | 4;
  }
  if ((uVar2 & 0x20000000) != 0) {
    uVar3 = uVar3 | 8;
  }
  if ((param_1 != 0) && ((uVar2 & 0xfffffff) != 0)) {
    uVar3 = uVar3 | 0x10;
  }
  uVar2 = uVar3;
  if ((DAT_007241e4 != 0) && (uVar3 != 0)) {
    uVar3 = uVar3 | 0x8000;
    uVar2 = DAT_007241e4;
  }
  DAT_007241e4 = uVar2;
  if (((uVar3 & 0x8000) == 0) && (uVar3 != 0)) {
    InitSoundAndNewGameStateFile(0xaa);
    PlaySoundID(0xaa,100,0,0,0x3fb33333);
  }
  return uVar3;
}


