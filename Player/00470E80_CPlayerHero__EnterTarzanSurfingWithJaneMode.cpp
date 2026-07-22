#include "tarzan_ghidra_types.hpp"

// Address: 0x00470E80
// Label: CPlayerHero::EnterTarzanSurfingWithJaneMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneMode(void)

{
  int value;
  
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 1;
  *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) =
       *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) | 2;
  _g_PlayerHeroMode = 5;
  *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0x270;
  *g_PlayerEntitySceneObjectData = 10;
  *(byte *)((int)g_PlayerEntitySceneObjectData + 3) =
       *(byte *)((int)g_PlayerEntitySceneObjectData + 3) | 2;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  g_TarzanSurfingWithJaneActionEffectTimer = 0;
  g_TarzanSurfingWithJaneActionEffectLevel = 0;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 2;
  (*(code *)g_JaneSurfingEnterSurfingHandlerPtr)();
  (*(code *)(&g_TarzanSurfingWithJaneActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  g_CameraRelativeTurnInputMask = 0;
  g_TarzanSurfingWithJaneAttachmentProbeARadiusSquared = 0;
  g_TarzanSurfingWithJaneAttachmentProbeBRadiusSquared = 0;
  value = *(int *)(g_CurrentWorldSceneContext + 0x24);
  *(undefined4 *)(value + 0x5a) = 0x80;
  *(undefined4 *)(value + 0x66) = 0;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = 0xffffffc0;
  g_TarzanSurfingWithJaneActionSoundActive = 0;
  ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,2);
  UnloadEncodedResourceId(2);
  UnloadEncodedResourceId(5);
  LoadEncodedResourceId(0x4a);
  g_PlayerCollisionFacingFlags = 0;
  PlayAudioById(0x79,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  return;
}

