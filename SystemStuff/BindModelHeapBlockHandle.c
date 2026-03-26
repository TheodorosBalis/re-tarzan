// Address: 0x004397C0

void BindModelHeapBlockHandle(int param_1,int *param_2)

{
  if (*(undefined4 **)(param_1 + -0x14) != (undefined4 *)0xffffffff) {
    **(undefined4 **)(param_1 + -0x14) = 0;
  }
  *(undefined2 *)(param_1 + -0x18) = 0;
  *(int **)(param_1 + -0x14) = param_2;
  *param_2 = param_1;
  return;
}


