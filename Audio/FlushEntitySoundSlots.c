// Address: 0x00453D60

void FlushEntitySoundSlots(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = g_ActiveEntitySoundSlotList;
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[6];
    if (*piVar2 == 0) {
      StopEntitySoundSlotPlayback((int)piVar2 + 0x22);
      ReleaseEntitySoundSlot(piVar2);
      piVar2 = piVar1;
    }
    else {
      DetachEntitySoundHandle(*piVar2);
      piVar2 = piVar1;
    }
  }
  StopAllSoundChannelsAndResetAudioLine();
  return;
}


