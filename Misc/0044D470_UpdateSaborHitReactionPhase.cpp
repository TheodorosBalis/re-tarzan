#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D470
// Label: UpdateSaborHitReactionPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateSaborHitReactionPhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  byte flagByte;
  int value;
  short shortValue;
  int value2;
  undefined4 value3;
  
  value = entity->sceneObjects;
  value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  if (shortValue == 2) {
    if (g_SaborAnimationState == 0x13) {
      flagByte = *(byte *)(value + 0x75);
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
      *(byte *)(value + 0x75) = ~flagByte;
      if ((byte)~flagByte == 0) {
        value3 = 0x200;
      }
      else {
        value3 = 0xfffffe00;
      }
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(value,value3);
    }
    SetSaborAnimationStateAndAdvance(arg1,9);
    SetSaborBattlePhase(9);
    *(undefined4 *)(value2 + 0xc) = 0x2c;
    return;
  }
  if (shortValue != 0x12) {
    return;
  }
  g_SaborTurnDirective = 0;
  if (g_SaborBattleHudMeterValue < 1) {
    g_SaborDefeatedEncounterFlags =
         g_SaborDefeatedEncounterFlags | (ushort)(1 << ((byte)_g_CurrentSaborEncounterIndex & 0x1f))
    ;
    g_SaborTurnDirective = (ushort)(*(char *)(value + 0x75) != -1);
    g_SaborBattleCameraState = 4;
    if (_g_CurrentSaborEncounterIndex == 2) {
      SetSaborAnimationStateAndAdvance(g_SaborBattleEntity,0x14);
      SetSaborBattlePhase(10);
      return;
    }
    SetSaborAnimationStateAndAdvance(g_SaborBattleEntity,0x13);
    SetSaborBattlePhase(9);
    return;
  }
  value2 = *(int *)(g_SaborEntitySceneObject + 0x10c);
  if (*(char *)(value + 0x75) == -1) {
    if (*(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) + -0xcfa <
        value2) {
      g_SaborTurnDirective = 0;
      return;
    }
    if ((0xcfa < value2) && (value2 < *(int *)(g_PlayerEntitySceneObject + 0x10c))) {
      g_SaborTurnDirective = 0;
      return;
    }
  }
  else {
    if (value2 < 0xcfa) {
      g_SaborTurnDirective = 0;
      return;
    }
    if ((value2 < *(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) +
                 -0xcfa) && (*(int *)(g_PlayerEntitySceneObject + 0x10c) < value2)) {
      g_SaborTurnDirective = 0;
      return;
    }
  }
  SetSaborAnimationStateAndAdvance(g_SaborBattleEntity,0x13);
  g_SaborTurnDirective = 0;
  return;
}

