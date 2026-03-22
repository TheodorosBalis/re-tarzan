/* Address: 0x004A8010 */

uint QueryForSoundID(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  short *psVar4;
  
  bVar2 = 0;
  uVar1 = 0;
  psVar4 = &DAT_009e49e0;
  do {
    if (*psVar4 == -1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1 << (bVar2 & 0x1f);
    }
    uVar1 = uVar1 | uVar3;
    psVar4 = psVar4 + 2;
    bVar2 = bVar2 + 1;
  } while ((int)psVar4 < 0x9e4a20);
  return uVar1;
}

