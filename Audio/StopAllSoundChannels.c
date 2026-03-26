// Address: 0x004A8CF0

void StopAllSoundChannels(void)

{
  char cVar1;
  
  cVar1 = '\0';
  do {
    StopSoundChannelByIndex(0xffffffff,cVar1);
    cVar1 = cVar1 + '\x01';
  } while (cVar1 < '\x10');
  return;
}


