
void CEntities__ResetRandomAmbientSoundCountdown(void)

{
  uint uVar1;
  
  uVar1 = NextRandomValue();
  g_RandomAmbientSoundCountdownTicks = uVar1 & 0x7f;
  return;
}

