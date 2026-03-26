// Address: 0x00453BB0

void ReleaseEntitySoundSlot(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = *(undefined4 *)(param_1 + 0x14);
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x18) = *(undefined4 *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = g_FreeEntitySoundSlotList;
    g_FreeEntitySoundSlotList = param_1;
    return;
  }
  g_ActiveEntitySoundSlotList = *(undefined4 *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = g_FreeEntitySoundSlotList;
  g_FreeEntitySoundSlotList = param_1;
  return;
}


