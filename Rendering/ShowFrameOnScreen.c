/* Address: 0x0049C7A0 */

void ShowFrameOnScreen(void)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    FUN_0049d140();
    return;
  case 2:
    FUN_004963d0();
    return;
  case 3:
  case 4:
    FUN_00497490();
    return;
  case 5:
    FUN_0049b440();
    return;
  default:
    return;
  }
}

