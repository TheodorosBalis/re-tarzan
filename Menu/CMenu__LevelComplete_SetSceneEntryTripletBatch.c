// Address: 0x0045E450

void CMenu__LevelComplete_SetSceneEntryTripletBatch(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if (param_2 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0xa8);
    do {
      puVar1[3] = 1;
      *puVar1 = param_3;
      puVar1[1] = param_3;
      puVar1[2] = param_3;
      puVar1 = puVar1 + 0x51;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


