// Address: 0x004394F0

void UnlinkModelHeapFreeBlock(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = *(undefined4 *)(param_1 + 0x14);
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10) = *(undefined4 *)(param_1 + 0x10);
  }
  return;
}


