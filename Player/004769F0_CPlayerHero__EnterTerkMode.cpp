#include "tarzan_ghidra_types.hpp"

// Address: 0x004769F0
// Label: CPlayerHero::EnterTerkMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkMode(void)

{
  _g_PlayerHeroMode = 6;
  *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0xe38;
  *g_PlayerEntitySceneObjectData = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0;
  (*(code *)g_TerkActionStateHandlerTable)();
  (*(code *)(&g_TerkActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x140) = 0xb0;
  return;
}

