#include "tarzan_ghidra_types.hpp"

// Address: 0x00436B60
// Label: CPlayerHero::IsFacingCurrentCollisionSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool CPlayerHero::IsFacingCurrentCollisionSurface(void)

{
  short shortValue;
  int value;
  
  if (g_PlayerDamageContactEntitySceneObject != 0) {
    shortValue = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObjectData + 8) -
                       *(int *)(g_PlayerDamageContactEntitySceneObject + 0x14),
                       *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
                       *(int *)(g_PlayerDamageContactEntitySceneObject + 0x1c));
    GetAngleFromXZVector12Bit
              (*(int *)(g_PlayerEntitySceneObjectData + 8) - *g_PlayerCurrentCollisionSurface,
               *(int *)(g_PlayerEntitySceneObjectData + 0x10) - g_PlayerCurrentCollisionSurface[2]);
    value = GetWrappedAngleDistance12Bit((int)shortValue,_g_PlayerMoveHeadingAngle & 0xffff);
    return value < 0x400;
  }
  return (bool)g_PlayerFacingCurrentCollisionSurface;
}

