/* Address: 0x004A8C70 */

void OnlyonLegacyAudio(void)

{
  int *piVar1;
  short *psVar2;
  
  if (DAT_009e4a50 == 0) {
    DAT_009e4a50 = 1;
    FUN_004a8dc0();
    FUN_004a8af0();
    psVar2 = &DAT_009e49e0;
    do {
      if ((*psVar2 != -1) &&
         (piVar1 = (int *)(&DAT_009cf220)[*psVar2 * 0xb + (int)psVar2[1]], piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0x48))(piVar1);
      }
      psVar2 = psVar2 + 2;
    } while ((int)psVar2 < 0x9e4a20);
  }
  return;
}

