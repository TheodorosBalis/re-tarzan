/* Address: 0x0049CD80 */

void ConfirmGraphicsInitialized(void)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    ZeroGlobal723738();
    return;
  case 2:
    CheckIfVfTableExistsAndProcess();
    return;
  case 3:
  case 4:
    UnavailableFunctionsDoNothing_2();
    return;
  case 5:
    SetZeroFlagIfGraphicsAreInitialized();
    return;
  default:
    return;
  }
}

