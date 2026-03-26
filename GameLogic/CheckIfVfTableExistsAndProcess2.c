// Address: 0x00494E50

void CheckIfVfTableExistsAndProcess2(void)

{
  int *piVar1;
  
  if ((DAT_005535c0 != 0) && (DAT_005535cc != 0)) {
    piVar1 = UnkownFunctionPTR_4;
    if (DAT_005535d0 == 0) {
      piVar1 = DAT_00553594;
    }
    if (piVar1 != (int *)0x0) {
      piVar1 = DAT_00553594;
      if (DAT_005535d0 != 0) {
        piVar1 = UnkownFunctionPTR_4;
      }
      DAT_005535bc = (**(code **)(*piVar1 + 0x80))(piVar1,0);
    }
    DAT_005535cc = 0;
  }
  return;
}


