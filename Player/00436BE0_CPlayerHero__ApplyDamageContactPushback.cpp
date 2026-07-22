#include "tarzan_ghidra_types.hpp"

// Address: 0x00436BE0
// Label: CPlayerHero::ApplyDamageContactPushback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero::ApplyDamageContactPushback(void)

{
  short shortValue;
  int value;
  uint value2;
  
  if ((((*(int *)(g_PlayerEntitySceneObject + 0x60) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
      (g_PlayerDamageContactEntitySceneObject != 0)) &&
     (g_PlayerDamageContactPushDistance != 0x7fffffff)) {
    if (0x300 < g_PlayerDamageContactPushDistance) {
      g_PlayerDamageContactPushDistance = 0x300;
    }
    shortValue = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObjectData + 8) -
                       *(int *)(g_PlayerDamageContactEntitySceneObject + 0x14),
                       *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
                       *(int *)(g_PlayerDamageContactEntitySceneObject + 0x1c));
    value2 = g_PlayerDamageContactPushDistance + 2;
    value = GetWrappedAngleDistance12Bit((int)shortValue,_g_PlayerMoveHeadingAngle & 0xffff);
    if (value < 0x400) {
      value2 = ~value2 + 1;
    }
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') {
      value2 = ~value2 + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value2,0,g_PlayerEntitySceneObject);
    return value2;
  }
  return 0;
}

