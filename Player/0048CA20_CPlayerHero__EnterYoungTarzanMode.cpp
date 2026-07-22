#include "tarzan_ghidra_types.hpp"

// Address: 0x0048CA20
// Label: CPlayerHero::EnterYoungTarzanMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTarzanMode(void)

{
  _g_PlayerHeroMode = 2;
  *(int *)(g_PlayerEntitySceneObject + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1a0;
  *g_PlayerEntitySceneObjectData = 0x9d;
  g_ActiveSwingMotionTable = &g_YoungTarzanSwingMotionTable;
  *(byte *)((int)g_PlayerEntitySceneObjectData + 3) =
       *(byte *)((int)g_PlayerEntitySceneObjectData + 3) | 2;
  g_PlayerSurfaceMotionSpeed = 0x60;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1000;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) = 0x1000;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) = 0x1000;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x80;
  g_PlayerPickupTriggerRadius = 0x80;
  g_TutorialPickupSequencePhase = 0;
  g_PlayerPickupInteractionFlags = 0;
  g_ActiveTutorialPickupEntity = 0;
  g_TutorialPickupSkipApproachFlag = 0;
  g_PlayerBounceChainCount = 0;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0;
  (*(code *)g_YoungTarzanActionStateTable)();
                    /* WARNING: Could not recover jumptable at 0x0048caf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&g_YoungTarzanActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  return;
}

