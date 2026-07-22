#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D620
// Label: UpdateSaborDefeatPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateSaborDefeatPhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  byte flagByte;
  int value;
  int value2;
  short shortValue;
  int value3;
  undefined4 value4;
  int localState [3];
  
  value = entity->sceneObjects;
  value3 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  value4 = CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  if ((g_SaborBattleHudMeterValue == 0) &&
     ((int)(&g_SaborFightAnchor0RightX)[_g_CurrentSaborEncounterIndex] <
      *(int *)(*(int *)(g_SaborBattleEntity + 0x38) + 0x14))) {
    g_SaborEncounterCleanupFlags =
         g_SaborEncounterCleanupFlags | (ushort)(1 << ((byte)_g_CurrentSaborEncounterIndex & 0x1f));
  }
  TryApplySaborAttackDamageToPlayer(value);
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  if (shortValue != 0) {
    value2 = *(int *)(value3 + 0xc);
    if (value2 == 0x14) {
      if (g_SaborBattleHudMeterValue == 0) {
        value3 = *(int *)(g_SaborBattleEntity + 0x38);
        ProjectSaborWorldPositionToScreen
                  (*(undefined4 *)(value3 + 0x14),*(undefined4 *)(value3 + 0x18),
                   *(undefined4 *)(value3 + 0x1c),localState);
        if (((0x22000 < localState[0]) && (g_SaborBattleHudMeterValue == 0)) &&
           (g_SaborBattleCameraState == 5)) {
          g_SaborEncounterCleanupFlags =
               g_SaborEncounterCleanupFlags | (ushort)(1 << (g_CurrentSaborEncounterIndex & 0x1f));
          RestoreCameraAfterSaborBattle();
          *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
          SetSaborBattlePhase(5);
          UnloadSaborBattleActiveResource();
          RestoreDefaultGameplayResourceAfterSaborBattle();
        }
      }
      else {
        SetSaborAnimationState(arg1,10);
        *(undefined4 *)(value3 + 0xc) = 0x2d;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
    }
    else {
      if (value2 != 0x2c) {
        if (value2 == 0x2d) {
          SelectSaborNextAttack(arg1,value,value3,value4);
          ApplySaborAnimationMotion(arg1);
          return;
        }
        if (g_SaborTurnDirective != 1) {
          if (g_SaborTurnDirective != 2) {
            flagByte = *(byte *)(value + 0x75);
            ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
            *(byte *)(value + 0x75) = ~flagByte;
            if ((byte)~flagByte == 0) {
              value4 = 0x200;
            }
            else {
              value4 = 0xfffffe00;
            }
            CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(value,value4);
            *(undefined4 *)(value3 + 0xc) = 0x14;
            SetSaborAnimationStateAndAdvance(arg1,1);
            ApplySaborAnimationMotion(arg1);
            return;
          }
          g_SaborTurnDirective = 0;
          ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
          *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
          *(undefined4 *)(value3 + 0xc) = 0x14;
          SetSaborAnimationStateAndAdvance(arg1,1);
          ApplySaborAnimationMotion(arg1);
          return;
        }
        g_SaborTurnDirective = 2;
        flagByte = *(byte *)(value + 0x75);
        ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
        *(byte *)(value + 0x75) = ~flagByte;
        if ((byte)~flagByte == 0) {
          value4 = 0x200;
        }
        else {
          value4 = 0xfffffe00;
        }
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(value,value4);
        SetSaborAnimationStateAndAdvance(arg1,0x17);
        ApplySaborAnimationMotion(arg1);
        return;
      }
      *(undefined4 *)(value3 + 0xc) = 0x14;
      SetSaborAnimationStateAndAdvance(arg1,1);
      if (g_SaborBattleHudMeterValue == 0) {
        PlayAudioById(0x204,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        ApplySaborAnimationMotion(arg1);
        return;
      }
    }
  }
  ApplySaborAnimationMotion(arg1);
  return;
}

