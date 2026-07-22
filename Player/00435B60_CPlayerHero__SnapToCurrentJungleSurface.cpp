#include "tarzan_ghidra_types.hpp"

// Address: 0x00435B60
// Label: CPlayerHero::SnapToCurrentJungleSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::SnapToCurrentJungleSurface(void)

{
  int *intCursor;
  int value;
  int value2;
  
  g_PlayerTiltControlEnabled = 0;
  value = g_CurrentSwingEntity;
  if ((_g_PlayerCurrentCollisionMode & 0xffff) == 2) {
    if (g_PlayerCurrentCollisionSurface == 0) {
      value = 0;
    }
    else {
      value = *(int *)(g_PlayerCurrentCollisionSurface + 0xc) -
              *(int *)(g_PlayerEntitySceneObject + 0x10c);
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value,0,g_PlayerEntitySceneObject);
    value = *(int *)(g_PlayerEntitySceneObject + 0x114);
    *(int *)(g_PlayerEntitySceneObjectData + 8) =
         *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) + *(int *)(g_PlayerEntitySceneObject + 0x5c)
    ;
    if ((*(byte *)(value + 0x14) & 0x10) != 0) {
      *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 300);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x58) = 0;
    }
    value = g_CurrentSwingEntity;
    if ((g_CurrentSwingEntity != 0) &&
       (value2 = g_ActiveSwingEntityList, g_ActiveSwingEntityList != 0)) {
      while ((*(int *)(value2 + 0x38) == 0 ||
             (value = value2,
             *(int *)(*(int *)(value2 + 0x38) + 0x10c) != *(int *)(g_PlayerEntitySceneObject + 0x10c)
             ))) {
        intCursor = (int *)(value2 + 0x20);
        value2 = *intCursor;
        if (*intCursor == 0) {
          return;
        }
      }
    }
  }
  g_CurrentSwingEntity = value;
  return;
}

