/* Address: 0x0049C6C0 */

undefined4 VerifyGraphicsMode(void)

{
  int iVar1;
  
  iVar1 = CurrentGraphicsMode();
  if (iVar1 != 1) {
    iVar1 = CurrentGraphicsMode();
    if (iVar1 != 2) {
      iVar1 = CurrentGraphicsMode();
      if (iVar1 != 3) {
        iVar1 = CurrentGraphicsMode();
        if (iVar1 != 4) {
          return 0;
        }
      }
    }
  }
  return 1;
}

