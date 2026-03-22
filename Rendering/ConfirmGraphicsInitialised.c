/* Address: 0x0049CC20 */

void ConfirmGraphicsInitialised(void)

{
  undefined4 uVar1;
  
  uVar1 = CurrentGraphicsMode();
  switch(uVar1) {
  case 1:
    FUN_0049d070();
    return;
  case 2:
    CheckIfVfTableExistsAndProcess2();
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

