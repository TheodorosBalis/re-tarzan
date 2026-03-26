// Address: 0x00453D30

void DetachEntitySoundHandle(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    StopEntitySoundSlotPlayback(iVar1 + 0x22);
    ReleaseEntitySoundSlot(iVar1);
    *param_1 = 0;
  }
  return;
}


