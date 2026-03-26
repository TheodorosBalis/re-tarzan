// Address: 0x004A8200

void UpdateSoundChannel3DPosition
               (ushort param_1,byte param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
               )

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 < 2000) {
    _param_2 = 4;
    piVar3 = (int *)(&DAT_009cf230 + (short)param_1 * 0x2c);
    do {
      piVar2 = (int *)*piVar3;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x4c))(piVar2,param_3,param_4,param_5,1);
      }
      piVar3 = piVar3 + 1;
      _param_2 = _param_2 + -1;
    } while (_param_2 != 0);
  }
  else if (param_2 < 0x10) {
    sVar1 = (&DAT_009e49e0)[(char)param_2 * 2];
    if (((sVar1 != -1) && ((&DAT_009cf220)[sVar1 * 0xb] != 0)) &&
       (piVar3 = *(int **)(&DAT_009cf230 +
                          ((int)(short)(&DAT_009e49e2)[(char)param_2 * 2] + sVar1 * 0xb) * 4),
       piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 0x4c))(piVar3,param_3,param_4,param_5,1);
      return;
    }
  }
  return;
}


