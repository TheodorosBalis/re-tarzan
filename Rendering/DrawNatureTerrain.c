// Address: 0x00439F10

void DrawNatureTerrain(int *param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 5) & 2) != 0) {
    FUN_00439db0(param_1,param_2);
  }
  FUN_004acb80(*param_1 + 0x10);
  return;
}


