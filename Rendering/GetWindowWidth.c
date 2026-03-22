/* Address: 0x0049C720 */

undefined4 GetWindowWidth(void)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    uVar1 = FUN_0049cea0();
    return uVar1;
  case 2:
    uVar1 = FUN_00494d30();
    return uVar1;
  case 3:
  case 4:
    uVar1 = FUN_00497450();
    return uVar1;
  case 5:
    uVar1 = SetWindowWidth();
    return uVar1;
  default:
    return 0;
  }
}

