// Address: 0x00496B50

void CheckIfVfTableExistsAndProcess3(byte param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (param_1 < 0x10) {
    uVar2 = (uint)param_1;
    piVar1 = (int *)(&DAT_0053ac44)[uVar2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)(&DAT_005530fc)[uVar2];
    (&DAT_0053ac44)[uVar2] = 0;
    if (piVar1 != (int *)0x0) {
      DAT_005535bc = (**(code **)(*piVar1 + 8))(piVar1);
    }
    (&DAT_005530fc)[uVar2] = 0;
    (&DAT_0055353c)[uVar2] = 0;
  }
  return;
}


