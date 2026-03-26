// Address: 0x004A8BE0

void CheckIfSoundIsAvailableAndRunOrSomething(void)

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  
  if (DAT_009e4a4c != 0) {
    DAT_009e4a4c = 0;
    if (DAT_009e4a50 == 0) {
      psVar3 = &DAT_009e49e0;
      do {
        sVar1 = *psVar3;
        if (sVar1 != -1) {
          piVar2 = (int *)(&DAT_009cf220)[(int)psVar3[1] + sVar1 * 0xb];
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0x30))(piVar2,0,0,(&DAT_009cf246)[sVar1 * 0x2c] & 1);
          }
        }
        psVar3 = psVar3 + 2;
      } while ((int)psVar3 < 0x9e4a20);
    }
    return;
  }
  return;
}


