// Address: 0x00453B40

void ResetEntitySoundSlotLists(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  StopAllSoundChannelsAndResetAudioLine();
  iVar3 = 0xf;
  puVar1 = &DAT_00533cd0;
  do {
    puVar2 = puVar1;
    iVar3 = iVar3 + -1;
    *(undefined **)(puVar2 + 0x18) = puVar2 + 0x30;
    puVar1 = puVar2 + 0x30;
  } while (iVar3 != 0);
  *(undefined4 *)(puVar2 + 0x48) = 0;
  g_ActiveEntitySoundSlotList = 0;
  g_FreeEntitySoundSlotList = &DAT_00533cd0;
  return;
}


