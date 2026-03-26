// Address: 0x00453C00

void UpdateEntity3DSounds(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  RefreshAudioListenerAndChannelMask();
  piVar1 = g_ActiveEntitySoundSlotList;
  while (piVar2 = piVar1, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[6];
    iVar3 = UpdateEntitySoundSlotPlayback((int)piVar2 + 0x22,piVar2[4]);
    if (iVar3 != 1) {
      if (*piVar2 == 0) {
        StopEntitySoundSlotPlayback((int)piVar2 + 0x22);
        ReleaseEntitySoundSlot(piVar2);
      }
      else {
        DetachEntitySoundHandle(*piVar2);
      }
    }
  }
  return;
}


