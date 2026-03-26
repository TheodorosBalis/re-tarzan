// Address: 0x004AC6C0

void StopEntitySoundSlotPlayback(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    StopSoundChannelByIndex(0xffffffff,*(undefined1 *)(param_1 + 1));
    param_1[1] = 0xffffffff;
    *param_1 = 0xffffffff;
    param_1[2] = 0;
  }
  return;
}


