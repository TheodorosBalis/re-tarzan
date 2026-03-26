// Address: 0x00453C60

undefined4 * LoadSoundFileAndInitAudio(uint param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 & 0x8000) != 0) {
    PlayStreamingSoundByIndex();
    return (undefined4 *)0x0;
  }
  iVar2 = Return1(param_1);
  if (iVar2 == 0) {
    return (undefined4 *)0x0;
  }
  if ((param_2 == (int *)0x0) && (param_3 == (undefined4 *)0x0)) {
    InitEntitySoundSlotPlayback(param_1,0,0);
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)AcquireEntitySoundSlot();
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[5] = 0;
    puVar3[6] = g_ActiveEntitySoundSlotList;
    g_ActiveEntitySoundSlotList = puVar3;
    *(short *)(puVar3 + 8) = (short)param_1;
    if (param_2 == (int *)0x0) {
      if (param_3 != (undefined4 *)0x0) {
        puVar3[1] = *param_3;
        puVar3[2] = param_3[1];
        uVar1 = param_3[2];
        puVar3[4] = puVar3 + 1;
        puVar3[3] = uVar1;
      }
    }
    else {
      if (*param_2 != 0) {
        DetachEntitySoundHandle(param_2);
      }
      *param_2 = (int)puVar3;
      *puVar3 = param_2;
      puVar3[4] = param_3;
    }
    InitEntitySoundSlotPlayback(param_1,(int)puVar3 + 0x22,param_3);
  }
  return puVar3;
}


