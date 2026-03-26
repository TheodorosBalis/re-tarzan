// Address: 0x0049C700

undefined4 IsHardware3DGraphicsMode(void)

{
  int iVar1;
  
  iVar1 = CurrentGraphicsMode();
  if (iVar1 != 1) {
    iVar1 = CurrentGraphicsMode();
    if (iVar1 != 2) {
      return 0;
    }
  }
  return 1;
}


