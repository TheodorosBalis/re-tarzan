#include "tarzan_ghidra_types.hpp"

// Address: 0x00437E70
// Label: CPlayerHero::UpdateJaneScriptedEntityFollow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneScriptedEntityFollow(void)

{
  int entry;
  int entry2;
  
  if ((_g_PlayerSequenceFlags & 0x2000) != 0) {
    for (entry = *(int *)(g_PlayerEntity + 0x18); entry != 0; entry = *(int *)(entry + 0x18)) {
      if (((*(short *)(entry + 0x46) == 0xcf) && (*(int *)(entry + 0x38) != 0)) &&
         (entry2 = *(int *)(*(int *)(entry + 0x38) + 0x34), entry2 != 0)) {
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 8) = *(undefined4 *)(entry2 + 0x14);
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc) = *(undefined4 *)(entry2 + 0x18);
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10) = *(undefined4 *)(entry2 + 0x1c);
        *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = *(undefined2 *)(entry2 + 0xa2);
      }
    }
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

