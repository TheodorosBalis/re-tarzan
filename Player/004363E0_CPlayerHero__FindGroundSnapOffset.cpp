#include "tarzan_ghidra_types.hpp"

// Address: 0x004363E0
// Label: CPlayerHero::FindGroundSnapOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CPlayerHero::FindGroundSnapOffset(void)

{
  int foundIndex;
  
  foundIndex = CPlayerHero::FindNearestGroundCollisionOffset
                    (*(undefined4 *)(g_PlayerEntitySceneObject + 0x58));
  if (*(int *)(g_PlayerEntitySceneObject + 0x108) != 1) {
    _g_PlayerGroundSnapProbeY =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerEntitySceneObject + 0x58);
    return foundIndex;
  }
  if ((*(int *)(g_PlayerEntitySceneObject + 0x114) != 0) &&
     ((*(uint *)(*(int *)(g_PlayerEntitySceneObject + 0x114) + 0x14) & 0x800) != 0)) {
    if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = 0;
    }
    if (foundIndex < 1) {
      if ((g_GameplayRuntimeFlags & 0x80000040) == 0x80000040) {
        return 0;
      }
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        QueuePlayerDamageEvent(0,0x600);
        g_PlayerSequenceDelayTicks = 0;
      }
      foundIndex = 0x7ff;
    }
  }
  return foundIndex;
}

