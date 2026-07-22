#include "tarzan_ghidra_types.hpp"

// Address: 0x00434C10
// Label: CPlayerHero::RefreshClimbableEdgeCollisionContext
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::RefreshClimbableEdgeCollisionContext(void)

{
  byte flagByte;
  int value;
  undefined4 value2;
  
  _g_PlayerLinkedCollisionSurface = 0;
  _g_PlayerLinkedCollisionSurfaceIndex = 0xffffffff;
  g_PlayerInteractionCollisionSurface = 0;
  g_PlayerInteractionCollisionSurfaceIndex = 0xffffffff;
  g_PlayerPreviousCollisionMode = *(int *)(g_PlayerEntitySceneObject + 0x108);
  if (_g_PlayerHeroMode == 2) {
    g_PlayerCollisionStepHeight = 0x70;
    value = (*(short *)(g_PlayerEntitySceneObject + 0x142) * 3) / 2;
  }
  else if (_g_PlayerHeroMode == 6) {
    g_PlayerCollisionStepHeight = 0xa0;
    value = 0;
  }
  else {
    g_PlayerCollisionStepHeight = 0xb0;
    value = *(short *)(g_PlayerEntitySceneObject + 0x142) + 0x20;
  }
  if (g_PlayerPreviousCollisionMode == 1) {
    g_PlayerCollisionLateralLimit =
         GetJungleSurfaceLateralLimit
                   (*(undefined4 *)(g_PlayerEntitySceneObject + 0x10c),
                    *(undefined4 *)(g_PlayerEntitySceneObject + 0x114));
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      value2 = 1;
    }
    else {
      value2 = 0xffffffff;
    }
    UpdateEntitySceneObjectCollisionSurfaceRef(value2,0,g_PlayerEntitySceneObject);
    g_PlayerCurrentCollisionSurface = *(int *)(g_PlayerEntitySceneObject + 0x114);
    if (g_PlayerCurrentCollisionSurface != 0) {
      flagByte = CPlayerHero::IsFacingCurrentCollisionSurface();
      g_PlayerCollisionFacingFlags = g_PlayerCollisionFacingFlags | flagByte;
      if ((*(uint *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x8000) != 0) {
        _g_PlayerLinkedCollisionSurfaceIndex =
             (uint)*(ushort *)(g_PlayerCurrentCollisionSurface + 0x18);
        _g_PlayerLinkedCollisionSurface =
             *(int *)(g_CollisionSurfaceTable + 4 + _g_PlayerLinkedCollisionSurfaceIndex * 4) + 0x34
             + ((uint)*(ushort *)(g_PlayerCurrentCollisionSurface + 0x1a) * 7 +
               _g_PlayerLinkedCollisionSurfaceIndex) * 4 + g_CollisionSurfaceTable;
        if ((*(uint *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x8000) == 0) {
          g_PlayerInteractionCollisionSurfaceIndex = *(uint *)(g_PlayerEntitySceneObject + 0x110);
          g_PlayerInteractionCollisionSurface = g_PlayerCurrentCollisionSurface;
        }
        else {
          g_PlayerInteractionCollisionSurfaceIndex =
               (uint)*(ushort *)(_g_PlayerLinkedCollisionSurface + 0x18);
          g_PlayerInteractionCollisionSurface =
               *(int *)(g_CollisionSurfaceTable + 4 + g_PlayerInteractionCollisionSurfaceIndex * 4)
               + 0x34 + ((uint)*(ushort *)(_g_PlayerLinkedCollisionSurface + 0x1a) * 7 +
                        g_PlayerInteractionCollisionSurfaceIndex) * 4 + g_CollisionSurfaceTable;
        }
        if ((*(byte *)(g_PlayerInteractionCollisionSurface + 0x14) & 0x80) != 0) {
          g_PlayerInteractionCollisionBaseY = *(int *)(g_PlayerCurrentCollisionSurface + 4);
          g_PlayerInteractionCollisionHeightRange =
               ((((*(int *)(_g_PlayerLinkedCollisionSurface + 4) + g_PlayerCollisionStepHeight * -2)
                 - *(int *)(g_PlayerCurrentCollisionSurface + 4)) - value) /
               g_PlayerCollisionStepHeight) * g_PlayerCollisionStepHeight;
          return;
        }
        if ((*(byte *)(_g_PlayerLinkedCollisionSurface + 0x14) & 0x80) != 0) {
          g_PlayerInteractionCollisionSurface = _g_PlayerLinkedCollisionSurface;
          g_PlayerInteractionCollisionSurfaceIndex = _g_PlayerLinkedCollisionSurfaceIndex;
          g_PlayerInteractionCollisionBaseY = *(int *)(_g_PlayerLinkedCollisionSurface + 4);
          g_PlayerInteractionCollisionHeightRange =
               ((((*(int *)(g_PlayerCurrentCollisionSurface + 4) + g_PlayerCollisionStepHeight * -2)
                 - *(int *)(_g_PlayerLinkedCollisionSurface + 4)) - value) /
               g_PlayerCollisionStepHeight) * g_PlayerCollisionStepHeight;
          return;
        }
        g_PlayerInteractionCollisionSurface = 0;
        g_PlayerInteractionCollisionSurfaceIndex = 0xffffffff;
      }
    }
  }
  return;
}

