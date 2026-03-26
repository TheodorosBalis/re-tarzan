// Address: 0x004A8490

void StopSoundChannelByIndex(ushort param_1,byte param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 < 2000) {
    iVar3 = 0;
    piVar4 = &DAT_009cf220 + (short)param_1 * 0xb;
    do {
      piVar2 = (int *)*piVar4;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x48))(piVar2);
      }
      piVar2 = (int *)*piVar4;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x34))(piVar2,0);
      }
      (&DAT_009cf247)[(short)param_1 * 0x2c + iVar3] = 0;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < 4);
  }
  else if (param_2 < 0x10) {
    iVar3 = (int)(char)param_2;
    if ((&DAT_009e49e0)[iVar3 * 2] != -1) {
      piVar4 = (int *)(&DAT_009cf220)
                      [(short)(&DAT_009e49e0)[iVar3 * 2] * 0xb +
                       (int)(short)(&DAT_009e49e2)[iVar3 * 2]];
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x48))(piVar4);
      }
      piVar4 = (int *)(&DAT_009cf220)
                      [(short)(&DAT_009e49e0)[iVar3 * 2] * 0xb +
                       (int)(short)(&DAT_009e49e2)[iVar3 * 2]];
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x34))(piVar4,0);
      }
      sVar1 = (&DAT_009e49e0)[iVar3 * 2];
      (&DAT_009e49e0)[iVar3 * 2] = 0xffff;
      (&DAT_009cf247)[sVar1 * 0x2c + (int)(short)(&DAT_009e49e2)[iVar3 * 2]] = 0;
      return;
    }
  }
  return;
}


