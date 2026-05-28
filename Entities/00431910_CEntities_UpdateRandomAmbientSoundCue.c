
void CEntities__UpdateRandomAmbientSoundCue(void)

{
  int iVar1;
  int iVar2;
  
  g_RandomAmbientSoundCountdownTicks = g_RandomAmbientSoundCountdownTicks + -1;
  if (g_RandomAmbientSoundCountdownTicks < 1) {
    iVar1 = RandomModulo(0x58);
    g_RandomAmbientSoundCountdownTicks = iVar1 + 0x1e;
    NextRandomValue();
    iVar1 = RandomModulo(0x14);
    iVar2 = RandomModulo(0xb);
    iVar2 = RandomModulo(0xb,(float)(iVar2 - 5));
    iVar2 = RandomModulo(0xb,(float)(iVar2 - 5));
    PlaySoundID(CONCAT22((short)(iVar2 - 5U >> 0x10),
                         *(undefined2 *)(&g_RandomAmbientSoundCueIdTable + iVar1 * 4)),100,
                (float)(iVar2 - 5U));
  }
  return;
}

