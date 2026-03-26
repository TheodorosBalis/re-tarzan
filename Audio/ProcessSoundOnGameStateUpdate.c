// Address: 0x004A82D0

void ProcessSoundOnGameStateUpdate(ushort param_1,byte param_2,byte param_3)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (100 < param_3) {
    param_3 = 100;
  }
  if (param_1 < 2000) {
    iVar4 = 4;
    piVar3 = &DAT_009cf220 + (short)param_1 * 0xb;
    do {
      piVar2 = (int *)*piVar3;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x3c))(piVar2,(int)(short)(&g_DSoundVolumeCurve)[(char)param_3]);
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else if (param_2 < 0x10) {
    sVar1 = (&DAT_009e49e0)[(char)param_2 * 2];
    if (((sVar1 != -1) && ((&DAT_009cf220)[sVar1 * 0xb] != 0)) &&
       (piVar3 = (int *)(&DAT_009cf220)
                        [(int)(short)(&DAT_009e49e2)[(char)param_2 * 2] + sVar1 * 0xb],
       piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 0x3c))(piVar3,(int)(short)(&g_DSoundVolumeCurve)[(char)param_3]);
      return;
    }
  }
  return;
}


