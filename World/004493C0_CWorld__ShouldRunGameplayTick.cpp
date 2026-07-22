#include "tarzan_ghidra_types.hpp"

// Address: 0x004493C0
// Label: CWorld::ShouldRunGameplayTick
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CWorld::ShouldRunGameplayTick(void)

{
  if (((short)g_GameplayStateFlags != 0) && (g_PlayerDamageFlashTicks != 0)) {
    *(byte *)(g_PlayerEntitySceneObjectData + 3) =
         *(byte *)(g_PlayerEntitySceneObjectData + 3) | 0x80;
  }
  return ~g_GameplayStateFlags >> 0xb & 1;
}

