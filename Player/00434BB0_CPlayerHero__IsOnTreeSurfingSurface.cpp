#include "tarzan_ghidra_types.hpp"

// Address: 0x00434BB0
// Label: CPlayerHero::IsOnTreeSurfingSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CPlayerHero::IsOnTreeSurfingSurface(void)

{
  uint value;
  
  value = g_PlayerEntitySceneObject;
  if ((*(int *)(g_PlayerEntitySceneObject + 0x108) == 2) &&
     (value = *(uint *)(g_PlayerEntitySceneObject + 0x10c), *(int *)(value + 0x18) == 3)) {
    return CONCAT31((int3)(value >> 8),1);
  }
  return value & 0xffffff00;
}

