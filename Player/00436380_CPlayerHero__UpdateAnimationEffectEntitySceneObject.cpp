#include "tarzan_ghidra_types.hpp"

// Address: 0x00436380
// Label: CPlayerHero::UpdateAnimationEffectEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAnimationEffectEntitySceneObject(undefined2 arg1)

{
  int entry;
  int entry2;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  if (g_PlayerAnimationEffectEntitySceneObject != 0) {
    *(undefined2 *)(g_PlayerAnimationEffectEntitySceneObject + 0xc) = arg1;
    *(byte *)(g_PlayerAnimationEffectEntitySceneObject + 0xf) =
         *(byte *)(g_PlayerAnimationEffectEntitySceneObject + 0xf) | 0x80;
    entry = g_PlayerAnimationEffectEntitySceneObject;
    entry2 = g_PlayerEntitySceneObject;
    *(undefined4 *)(g_PlayerAnimationEffectEntitySceneObject + 0x14) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(undefined4 *)(entry + 0x18) = *(undefined4 *)(entry2 + 0x18);
    *(undefined4 *)(entry + 0x1c) = *(undefined4 *)(entry2 + 0x1c);
    dataCursor = (undefined4 *)(g_PlayerEntitySceneObject + 0xa0);
    dataCursor2 = (undefined4 *)(g_PlayerAnimationEffectEntitySceneObject + 0xa0);
    for (entry2 = 0x18; entry2 != 0; entry2 = entry2 + -1) {
      *dataCursor2 = *dataCursor;
      dataCursor = dataCursor + 1;
      dataCursor2 = dataCursor2 + 1;
    }
  }
  return;
}

