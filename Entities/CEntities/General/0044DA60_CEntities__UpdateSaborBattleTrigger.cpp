#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DA60
// Label: CEntities::UpdateSaborBattleTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateSaborBattleTrigger(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  uint value2;
  uint value3;
  
  SelectSaborEncounterIndexFromPlayerX();
  value = entity->sceneObjects;
  value2 = ((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObjectData + 4);
  if (_g_PlayerHeroMode == 3) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  if (g_PlayerActionState == 0x3e) {
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x80;
    ((EntitySceneObject *)value)->x = *(undefined4 *)(g_PlayerEntitySceneObjectData + 4);
    ((EntitySceneObject *)value)->y = *(undefined4 *)(g_PlayerEntitySceneObjectData + 6);
    ((EntitySceneObject *)value)->z = *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
    ((EntitySceneObject *)value)->yaw = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
    *(short *)(value + 0xc) = *g_PlayerEntitySceneObjectData + -0x362;
    return;
  }
  if ((g_PlayerActionState == 0x33) ||
     (((((-1 < _g_CurrentSaborEncounterIndex &&
         (((int)g_SaborDefeatedEncounterFlags & 1 << ((byte)_g_CurrentSaborEncounterIndex & 0x1f))
          == 0)) && (value3 = (int)value2 >> 0x1f, (int)((value2 ^ value3) - value3) < 900)) &&
       ((g_PlayerActionState != 4 && (g_PlayerActionState != 5)))) &&
      ((g_PlayerActionState != 6 && ((g_PlayerActionState != 7 && (g_PlayerActionState != 8))))))))
  {
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x3e;
    (*(code *)g_AdultTarzanEnterSaborBattleIntroHandlerPtr)();
    g_SaborBattleHudMeterValue =
         (int)*(short *)(&g_SaborHealthByEncounterAndDifficulty +
                        (_g_CurrentSaborEncounterIndex * 3 + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) *
                        2);
  }
  else {
    resultFlag = IsWorldPositionOutsideOuterActivationBounds((undefined4 *)(&((EntitySceneObject *)value)->x));
    if (resultFlag != '\0') {
      SaborBattleTriggerReleaseHookStub();
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
  }
  return;
}

