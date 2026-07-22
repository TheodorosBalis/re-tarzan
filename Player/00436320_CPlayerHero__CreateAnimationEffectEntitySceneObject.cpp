#include "tarzan_ghidra_types.hpp"

// Address: 0x00436320
// Label: CPlayerHero::CreateAnimationEffectEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::CreateAnimationEffectEntitySceneObject(void)

{
  g_PlayerAnimationEffectEntitySceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,9);
  if (g_PlayerAnimationEffectEntitySceneObject != 0) {
    *(undefined4 *)(g_PlayerAnimationEffectEntitySceneObject + 0x10) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x10);
    *(undefined2 *)(g_PlayerAnimationEffectEntitySceneObject + 0xe) = 0;
    *(undefined4 *)(g_PlayerAnimationEffectEntitySceneObject + 0x6c) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c);
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = 1;
  }
  return;
}

