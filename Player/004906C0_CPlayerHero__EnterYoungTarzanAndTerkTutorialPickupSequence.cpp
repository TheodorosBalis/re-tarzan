#include "tarzan_ghidra_types.hpp"

// Address: 0x004906C0
// Label: CPlayerHero::EnterYoungTarzanAndTerkTutorialPickupSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTarzanAndTerkTutorialPickupSequence(void)

{
  CPlayerHero::PlayAnimation(0x9d);
  *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0xe38;
  *g_PlayerEntitySceneObjectData = 0x2a;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0xa00;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) = 0xa00;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) = 0xa00;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x140) = 0;
  *(undefined2 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x140) = 0;
  g_PlayerCurrentCollisionMode =
       CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject
                 (g_PlayerEntitySceneObject,
                  (&g_TutorialPickupApproachPlacementTable)[g_ActiveTutorialPickupId * 0xc]);
  g_TutorialPickupSequencePhase = 3;
  g_PlayerActionState = 0x38;
  return;
}

