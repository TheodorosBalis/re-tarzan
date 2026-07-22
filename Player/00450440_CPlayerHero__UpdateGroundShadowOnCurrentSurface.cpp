#include "tarzan_ghidra_types.hpp"

// Address: 0x00450440
// Label: CPlayerHero::UpdateGroundShadowOnCurrentSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateGroundShadowOnCurrentSurface(void)

{
  int value;
  
  if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
    *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x108) = 1;
    *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x110) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
    *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10c) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
    *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
    ComputeEntitySceneObjectCollisionMoveDelta
              ((-(uint)(*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') & 0x40) - 0x20,0,
               g_PlayerGroundShadowProbeEntitySceneObject);
    *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) +
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x54);
    *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) +
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x58);
    *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) +
         *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x5c);
    *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa0) =
         0x400U - *(short *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x130) & 0xfff;
    *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa2) =
         *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x132) ^ 0x800;
    value = (*(int *)(g_PlayerEntitySceneObjectData + 0xc) -
             *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) >> 1) + 0x400;
    if (value < 0) {
      value = 0;
    }
    *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = value;
  }
  return;
}

