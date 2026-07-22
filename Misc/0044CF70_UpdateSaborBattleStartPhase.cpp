#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CF70
// Label: UpdateSaborBattleStartPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateSaborBattleStartPhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  ushort value4;
  int value;
  int value2;
  undefined4 value5;
  int value3;
  
  value3 = entity->sceneObjects;
  value = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  LoadEncodedResourceId(0x1017);
  if (*(int *)(g_WorldEntitySceneObjectArrayBase + 0x11ec) == 0) {
    g_SaborBattleStartWaitFrames = g_SaborBattleStartWaitFrames + 1;
    if (g_SaborBattleStartWaitFrames < 300) {
      return;
    }
    g_SaborBattleHudMeterValue = 0;
    value4 = (ushort)(1 << (g_CurrentSaborEncounterIndex & 0x1f));
    g_SaborDefeatedEncounterFlags = g_SaborDefeatedEncounterFlags | value4;
    g_SaborEncounterCleanupFlags = g_SaborEncounterCleanupFlags | value4;
    RestoreCameraAfterSaborBattle();
    *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) & 0x7fff;
    SetSaborBattlePhase(5);
    UnloadSaborBattleActiveResource();
    RestoreDefaultGameplayResourceAfterSaborBattle();
    CPlayerHero::SetAdultTarzanActionState(0x3f);
    return;
  }
  PlayAudioById(500,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
  value5 = 0xfffff830;
  if (*(short *)(&g_SaborEncounterInitialFacingTable + _g_CurrentSaborEncounterIndex * 2) != 0) {
    value5 = 2000;
  }
  PlaceSaborOnPlayerSurfaceAndMove(value3,value5);
  *(byte *)(value3 + 0xf) = *(byte *)(value3 + 0xf) | 0x80;
  *(undefined4 *)(value2 + 0x20) = 0;
  *(undefined4 *)(value2 + 0x30) = 0;
  *(undefined4 *)(value + 0xc) = 0x1f;
  *(undefined4 *)(value2 + 0x10) = 0x12;
  SetSaborAnimationState(arg1,0xd);
  SetSaborBattlePhase(2);
  value3 = (int)_g_CurrentSaborEncounterIndex;
  g_SaborBattleHudMeterValue =
       (int)*(short *)(&g_SaborHealthByEncounterAndDifficulty +
                      (value3 * 3 + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) * 2);
  if (value3 == 1) {
    value3 = CEntities::SpawnEntityByTypeAtPosition
                      (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -400,
                       *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0xc9,0x11);
    if (value3 == 0) {
      return;
    }
    value5 = 0x7d3;
  }
  else {
    if (value3 != 2) {
      return;
    }
    value3 = CEntities::SpawnEntityByTypeAtPosition
                      (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -400,
                       *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0xc9,0x11);
    if (value3 == 0) {
      return;
    }
    value5 = 0x7d1;
  }
  value5 = ResolveCollisionSurfaceIndexByCoordRef(value5);
  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x110) = value5;
  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10c) = 10;
  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x108) = 1;
  UpdateEntityEntitySceneObjectTransformFromPlacement(*(undefined4 *)(value3 + 0x38));
  value3 = *(int *)(value3 + 0x38);
  ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y + *(int *)(value3 + 0x58);
  return;
}

