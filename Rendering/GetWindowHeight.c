/* Address: 0x0049C760 */

undefined4 GetWindowHeight(void)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    uVar1 = FUN_0049ceb0();
    return uVar1;
  case 2:
    uVar1 = FUN_00494d40();
    return uVar1;
  case 3:
  case 4:
    uVar1 = FUN_00497470();
    return uVar1;
  case 5:
    uVar1 = SetWindowHeight();
    return uVar1;
  default:
    return 0;
  }
}

