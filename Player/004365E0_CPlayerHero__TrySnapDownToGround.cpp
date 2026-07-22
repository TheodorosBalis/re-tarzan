#include "tarzan_ghidra_types.hpp"

// Address: 0x004365E0
// Label: CPlayerHero::TrySnapDownToGround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero::TrySnapDownToGround(void)

{
  ushort value2;
  uint value3;
  uint value4;
  int value;
  
  value3 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(g_PlayerEntitySceneObject + 0x48);
  value4 = (int)value3 >> 0x1f;
  value = (value3 ^ value4) - value4;
  if (value < 0x10) {
    value = 4;
  }
  value4 = (uint)_g_PlayerCollisionSnapRange;
  value3 = CPlayerHero::FindGroundSnapOffset();
  if (((value3 != 0x7fffffff) && ((int)value3 < 0)) && ((int)(~(value + value4) + 1) <= (int)value3)) {
    *(uint *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + value3;
    value3 = *(int *)(g_PlayerEntitySceneObject + 0x108) - 1;
    if (((value3 == 0) && (value3 = 0, g_PlayerActiveSurfaceDefinition != 0)) &&
       (value3 = *(uint *)(g_PlayerActiveSurfaceDefinition + 0x14), value3 != 0)) {
      g_PlayerCurrentCollisionMode = (undefined2)value3;
    }
    if (g_PlayerTriggeredCollisionEntry != 0) {
      value2 = *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42);
      value3 = CONCAT22((short)(value3 >> 0x10),value2);
      if ((value2 & 0x40) != 0) {
        value3 = CONCAT31((int3)(value3 >> 8),(char)value2) | 0x80;
        *(short *)(g_PlayerTriggeredCollisionEntry + 0x42) = (short)value3;
      }
    }
    return CONCAT31((int3)(value3 >> 8),1);
  }
  return value3 & 0xffffff00;
}

