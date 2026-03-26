// Address: 0x00453B70

void AcquireEntitySoundSlot(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = g_FreeEntitySoundSlotList;
  if (g_FreeEntitySoundSlotList == (undefined4 *)0x0) {
    return;
  }
  piVar1 = g_FreeEntitySoundSlotList + 6;
  g_FreeEntitySoundSlotList = (undefined4 *)g_FreeEntitySoundSlotList[6];
  *piVar1 = g_ActiveEntitySoundSlotList;
  puVar2[5] = 0;
  if (g_ActiveEntitySoundSlotList != 0) {
    *(undefined4 **)(g_ActiveEntitySoundSlotList + 0x14) = puVar2;
  }
  *puVar2 = 0;
  return;
}


