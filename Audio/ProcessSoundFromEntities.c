/* Address: 0x00453C00 */

void ProcessSoundFromEntities(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  FUN_004ac730();
  piVar1 = DAT_00533fd4;
  while (piVar2 = piVar1, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[6];
    iVar3 = FUN_004ac760((int)piVar2 + 0x22,piVar2[4]);
    if (iVar3 != 1) {
      if (*piVar2 == 0) {
        FUN_004ac6c0((int)piVar2 + 0x22);
        FUN_00453bb0(piVar2);
      }
      else {
        FUN_00453d30(*piVar2);
      }
    }
  }
  return;
}

