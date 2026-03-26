// Address: 0x0049E0F0

void CaptureKInputsInBuffer(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_00723ce8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  iVar2 = 0;
  puVar3 = &InputBuffer;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  do {
    GetUserInputAndConvert(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  return;
}


