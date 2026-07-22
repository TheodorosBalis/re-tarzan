#include "tarzan_ghidra_types.hpp"

// Address: 0x00402DA0
// Label: TheBaboonChase::UpdateRunningAnimals
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateRunningAnimals(int entry)

{
  int value;
  char resultFlag;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined4 localState2;
  undefined4 localState3;
  int localState;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) goto switchD_00402e0f_caseD_2;
  value5 = *(int *)(value + 0x38);
  value3 = *(int *)(value5 + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value4 = *(int *)(value5 + 0x18) - *(int *)(g_PlayerEntitySceneObject + 0x18);
  value5 = *(int *)(value5 + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value5 = SqrtToInt(value5 * value5 + value4 * value4 + value3 * value3);
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 0:
    value5 = *(int *)(value + 0x38);
    localState2 = *(undefined4 *)(value5 + 0x14);
    localState3 = *(undefined4 *)(value5 + 0x18);
    localState = *(int *)(value5 + 0x1c) + -0x100;
    value5 = CEntities::IsPointMostlyPositiveXFromReference
                      (&localState2,g_PlayerEntitySceneObject + 0x14);
    if (value5 != 0) {
      *(undefined4 *)(value2 + 0xc) = 1;
    }
    break;
  case 1:
    if (*(int *)(value2 + 0x14) == 0) {
      if (value5 >> 6 < 0x7d1) {
        value5 = *(int *)(value2 + 0x10);
      }
      else {
        value5 = *(int *)(value2 + 0x10) + 0x14;
      }
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value,value5);
      value5 = *(int *)(value + 0x38);
      localState2 = *(undefined4 *)(value5 + 0x14);
      localState3 = *(undefined4 *)(value5 + 0x18);
      localState = *(int *)(value5 + 0x1c) + -200;
      value5 = CEntities::IsPointMostlyPositiveXFromReference
                        (&localState2,g_PlayerEntitySceneObject + 0x14);
      if (value5 == 0) {
        *(byte *)(g_PlayerEntitySceneObject + 0xf) = *(byte *)(g_PlayerEntitySceneObject + 0xf) | 2;
        *(undefined4 *)(value2 + 0x10) = 0;
        g_PlayerFacingCurrentCollisionSurface = 1;
        g_JaneDamageReactionType = 4;
      }
    }
    if ((*(int *)(value2 + 0x14) == 1) || (*(int *)(value2 + 0x14) == 2)) {
      value5 = *(int *)(*(int *)(value + 0x38) + 0x10c);
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value,*(undefined4 *)(value2 + 0x10));
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,&localState2);
      if (resultFlag != '\0') {
        g_PlayerFacingCurrentCollisionSurface = 1;
        g_JaneDamageReactionType = 3;
        QueuePlayerDamageEvent(value,4);
        if (*(int *)(value2 + 0x14) == 1) {
          PlayAudioById(0x111,*(int *)(value + 0x38) + 0x104,*(int *)(value + 0x38) + 0x14);
          CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x18),5);
          *(undefined4 *)(value2 + 0xc) = 5;
          *(int *)(value2 + 0x10) = *(int *)(value2 + 0x10) + 10;
        }
      }
      value2 = *(int *)(*(int *)(value + 0x38) + 0x110);
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                  g_CollisionSurfaceTable) + -0x200 <= value5) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
        return;
      }
    }
    value2 = *(int *)(value + 0x38);
    value5 = value2;
    goto LAB_0040305e;
  case 4:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value5 = *(int *)(value + 0x38);
    localState2 = *(undefined4 *)(value5 + 0x14);
    localState3 = *(undefined4 *)(value5 + 0x18);
    localState = *(int *)(value5 + 0x1c) + 0x300;
    value5 = CEntities::IsPointMostlyPositiveXFromReference
                      (&localState2,g_PlayerEntitySceneObject + 0x14);
    if (value5 != 0) {
      *(undefined4 *)(value2 + 0xc) = 1;
    }
    break;
  case 5:
    value5 = *(int *)(*(int *)(value + 0x38) + 0x10c);
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value,*(undefined4 *)(value2 + 0x10));
    value2 = *(int *)(*(int *)(value + 0x38) + 0x110);
    if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                g_CollisionSurfaceTable) + -0x200 <= value5) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
      return;
    }
    value2 = *(int *)(value + 0x38);
    value5 = *(int *)(value + 0x38);
LAB_0040305e:
    value5 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value5);
    *(int *)(value2 + 0x18) = *(int *)(value2 + 0x18) + value5;
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
  }
switchD_00402e0f_caseD_2:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

