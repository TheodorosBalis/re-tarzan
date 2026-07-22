#include "tarzan_ghidra_types.hpp"

// Address: 0x00434E20
// Label: CPlayerHero::RefreshIdleCollisionContact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::RefreshIdleCollisionContact(void)

{
  uint value3;
  int value;
  int value2;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  value2 = g_PlayerEntitySceneObject;
  dataCursor = (undefined4 *)(g_PlayerEntitySceneObject + 0x108);
  dataCursor2 = &DAT_0051cd38;
  for (value = 0xf; value != 0; value = value + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  g_PlayerIdleCollisionContactX = *(undefined4 *)(value2 + 0x54);
  g_PlayerIdleCollisionContactY = *(undefined4 *)(value2 + 0x58);
  g_PlayerIdleCollisionContactZ = *(undefined4 *)(value2 + 0x5c);
  ComputeEntitySceneObjectCollisionMoveDelta
            ((-(uint)(*(char *)(value2 + 0x75) != '\0') & 0xffffffec) + 10,
             _g_PlayerMoveHeadingAngle & 0xffff,value2);
  value2 = g_PlayerEntitySceneObject;
  value3 = *(uint *)(g_PlayerEntitySceneObject + 0x13c);
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x54) = g_PlayerIdleCollisionContactX;
  *(undefined4 *)(value2 + 0x58) = g_PlayerIdleCollisionContactY;
  *(undefined4 *)(value2 + 0x5c) = g_PlayerIdleCollisionContactZ;
  dataCursor = &DAT_0051cd38;
  dataCursor2 = (undefined4 *)(g_PlayerEntitySceneObject + 0x108);
  for (value2 = 0xf; value2 != 0; value2 = value2 + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  *(uint *)(g_PlayerEntitySceneObject + 0x13c) =
       *(uint *)(g_PlayerEntitySceneObject + 0x13c) & 0xfffffffd;
  *(uint *)(g_PlayerEntitySceneObject + 0x13c) =
       *(uint *)(g_PlayerEntitySceneObject + 0x13c) | value3 & 2;
  return;
}

