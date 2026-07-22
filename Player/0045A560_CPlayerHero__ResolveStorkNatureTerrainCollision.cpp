#include "tarzan_ghidra_types.hpp"

// Address: 0x0045A560
// Label: CPlayerHero::ResolveStorkNatureTerrainCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CPlayerHero::ResolveStorkNatureTerrainCollision(void)

{
  uint value2;
  int value;
  
  value2 = ResolvePositionAgainstNatureTerrainCollisionTriangles
                    (&g_CurrentWorldSceneContext,g_PlayerEntitySceneObject + 0x14,
                     g_PlayerEntitySceneObject + 0x14);
  value = (int)value2 >> 0x10;
  value2 = value2 & 0xffff;
  if (value == -1) {
    return 0x40;
  }
  g_StorkTerrainVerticalOffset = value;
  if (value < 300) {
    value2 = value2 | 2;
  }
  if (500 < value) {
    value2 = value2 | 0x40;
  }
  return value2;
}

