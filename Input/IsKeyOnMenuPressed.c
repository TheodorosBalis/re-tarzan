/* Address: 0x00453260 */

void IsKeyOnMenuPressed(void)

{
  undefined **ppuVar1;
  int iVar2;
  
  ppuVar1 = &PTR_LAB_004f1fe0;
  iVar2 = 3;
  do {
    FUN_004531e0(ppuVar1);
    ppuVar1 = ppuVar1 + 0x24;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

