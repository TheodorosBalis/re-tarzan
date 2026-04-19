// 0x004493c0

uint CWorld::ShouldRunGameplayTick(void)

{
  if (((short)g_GameplayStateFlags != 0) && (g_PlayerDamageFlashTicks != 0)) {
    *(byte *)(g_PlayerSceneEntryData + 3) = *(byte *)(g_PlayerSceneEntryData + 3) | 0x80;
  }
  return ~g_GameplayStateFlags >> 0xb & 1;
}