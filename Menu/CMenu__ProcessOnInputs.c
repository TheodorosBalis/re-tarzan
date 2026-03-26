// Address: 0x00452BA0

void CMenu__ProcessOnInputs(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0x1c) != (code *)0x0)) {
    (**(code **)(iVar1 + 0x1c))(iVar1);
  }
  return;
}


