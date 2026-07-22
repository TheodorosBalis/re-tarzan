#include "tarzan_ghidra_types.hpp"

// Address: 0x00468D20
// Label: CPlayerHero::EnterAdultTarzanMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanMode(void)

{
  _g_PlayerHeroMode = 1;
  *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0xd0;
  *g_PlayerEntitySceneObjectData = 0;
  g_ActiveSwingMotionTable = &g_AdultTarzanSwingMotionTable;
  *(byte *)((int)g_PlayerEntitySceneObjectData + 3) =
       *(byte *)((int)g_PlayerEntitySceneObjectData + 3) | 2;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerSurfaceMotionSpeed = 0x80;
  if (((*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x06') && (g_CurrentCheckpointId == 0)) &&
     (g_SaborDefeatedEncounterFlags == 0)) {
    g_PlayerActionState = 0x32;
    (*(code *)g_AdultTarzanEnterLevelIntroPoseHandlerPtr)();
  }
  else {
    g_PlayerActionState = 0;
    (*(code *)g_AdultTarzanActionStateEnterColumn)();
  }
  (*(code *)(&g_AdultTarzanActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  g_PlayerBounceChainCount = 0;
  return;
}

