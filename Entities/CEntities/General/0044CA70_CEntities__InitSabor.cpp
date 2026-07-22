#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CA70
// Label: CEntities::InitSabor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::InitSabor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  if ((*(byte *)(entry + 0x44) & 1) == 0) {
    value2 = CEntities::CreateEntityAttachment(entry,0x14,0x10000001);
    value3 = CEntities::CreateRuntimeMotionStateAttachment(entry);
    value = entity->sceneObjects;
    if (((value != 0) && (value2 != 0)) && (value3 != 0)) {
      g_SaborBattleEntity = entry;
      g_SaborEntitySceneObject = entity->sceneObjects;
      *(undefined4 *)(value + 0x6c) = 0xffffffa0;
      *(undefined4 *)(value2 + 0xc) = 0x16;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x11e0;
      *(undefined2 *)(value + 0xc) = 0x91;
      ((EntitySceneObject *)value)->roll = 0;
      *(undefined1 *)(value + 0x75) = 0;
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SaborScriptAttachmentConfig);
      SetSaborAnimationState(entry,6);
      PlaceSaborOnPlayerSurfaceAndMove(entity->sceneObjects,0xfffffe70);
      ((EntitySceneObject *)value)->yaw = 0xc00;
      SelectSaborEncounterIndexFromPlayerX();
      if (_g_CurrentSaborEncounterIndex < 0) {
        *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
        SetSaborBattlePhase(5);
        g_OptionalHudMeterScene = 0;
        g_SaborBattleHudMeterValue =
             (int)*(short *)(&g_SaborHealthByEncounterAndDifficulty +
                            *( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2);
        return;
      }
      CEntities::SpawnEntityByTypeAtPosition
                (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x21,0x11);
      *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
      SetSaborBattlePhase(5);
      g_OptionalHudMeterScene = 0;
      g_SaborBattleHudMeterValue =
           (int)*(short *)(&g_SaborHealthByEncounterAndDifficulty +
                          (_g_CurrentSaborEncounterIndex * 3 + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1))
                          * 2);
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

