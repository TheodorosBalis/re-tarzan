#include "tarzan_ghidra_types.hpp"

// Address: 0x004592F0
// Label: Stampede::UpdateCivetRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateCivetRhino(int entry)

{
  int value;
  char resultFlag;
  int value2;
  uint value6;
  int value3;
  int value4;
  int value5;
  uint value7;
  undefined4 value8;
  undefined4 localState5;
  undefined4 localState4;
  int localState2;
  int localState [2];
  int localState3;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    entry = 0;
    switch(*(undefined4 *)(value2 + 0xc)) {
    case 0:
      value4 = *(int *)(value + 0x38);
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - *(int *)(value4 + 0x14);
      value5 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) - *(int *)(value4 + 0x1c);
      value3 = value5 * value5 + value3 * value3;
      if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') {
        resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                          (g_PlayerEntitySceneObject,0x200,value4,0x200,&entry,localState);
        if (resultFlag != '\0') {
          *(int *)(g_PlayerEntitySceneObject + 0x14) =
               *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
          *(int *)(g_PlayerEntitySceneObject + 0x1c) =
               *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        }
        if (0x109968f < value3) break;
        value8 = *(undefined4 *)(value2 + 0x18);
        *(undefined4 *)(value2 + 0xc) = 1;
      }
      else {
        if (0x245430f < value3) break;
        value8 = *(undefined4 *)(value2 + 0x18);
        *(undefined4 *)(value2 + 0xc) = 1;
      }
      CEntities::SelectScriptAttachmentSequence(value8,1);
      break;
    case 1:
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(value,0x14);
      value4 = *(int *)(value + 0x38);
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value4);
      *(int *)(value4 + 0x18) = *(int *)(value4 + 0x18) + value3;
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') {
        resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                          (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                           &entry,localState);
        if (resultFlag != '\0') {
          *(int *)(g_PlayerEntitySceneObject + 0x14) =
               *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
          *(int *)(g_PlayerEntitySceneObject + 0x1c) =
               *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
          CPlayerHero::ApplyStampedeDamageReaction(value,6);
        }
        if ((g_StampedeElephantsEntity != 0) &&
           (value4 = CEntities::IsEntityVectorMostlyPositiveZ(value,g_PlayerEntity), value4 != 0)) {
          if (*(int *)(value2 + 0x30) == 0) {
            *(undefined4 *)(value2 + 0x28) = 0x3c;
          }
          if (*(int *)(value2 + 0x30) == 1) {
            *(undefined4 *)(value2 + 0x28) = 200;
          }
          CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x18),1);
          *(undefined4 *)(value2 + 0xc) = 2;
        }
      }
      break;
    case 2:
      value4 = *(int *)(*(int *)(value + 0x38) + 0x10c);
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(int *)(value + 0x38),0x200,&entry,
                         localState);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        CPlayerHero::ApplyStampedeDamageReaction(value,6);
      }
      value6 = *(int *)(*(int *)(value + 0x38) + 0x1c) -
              *(int *)(*(int *)(g_StampedeElephantsEntity + 0x38) + 0x1c);
      value7 = (int)value6 >> 0x1f;
      if ((int)((value6 ^ value7) - value7) < 0x864) {
        value3 = *(int *)(value2 + 0x28) + 1;
      }
      else {
        value3 = *(int *)(value2 + 0x28) + -1;
      }
      *(int *)(value2 + 0x28) = value3;
      if ((*(int *)(value2 + 0x30) == 0) && (0x3c < *(int *)(value2 + 0x28))) {
        *(undefined4 *)(value2 + 0x28) = 0x3c;
      }
      if ((*(int *)(value2 + 0x30) == 1) && (200 < *(int *)(value2 + 0x28))) {
        *(undefined4 *)(value2 + 0x28) = 200;
      }
      if (*(int *)(value2 + 0x28) < 0) {
        *(undefined4 *)(value2 + 0x28) = 0;
      }
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(value,*(undefined4 *)(value2 + 0x28));
      value2 = *(int *)(value + 0x38);
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value2);
      *(int *)(value2 + 0x18) = *(int *)(value2 + 0x18) + value3;
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      value2 = *(int *)(*(int *)(value + 0x38) + 0x110);
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                  g_CollisionSurfaceTable) + -0x200 <= value4) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
        return;
      }
      break;
    case 3:
      value2 = *(int *)(*(int *)(value + 0x38) + 0x10c);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(value,0x3c);
      value4 = *(int *)(*(int *)(value + 0x38) + 0x110);
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value4 * 4) + 8 + value4 * 4 +
                  g_CollisionSurfaceTable) + -0x200 <= value2) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
        return;
      }
      break;
    case 4:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      value4 = *(int *)(value + 0x38);
      localState5 = *(undefined4 *)(value4 + 0x14);
      localState4 = *(undefined4 *)(value4 + 0x18);
      localState2 = *(int *)(value4 + 0x1c) + 2000;
      value4 = CEntities::IsPointMostlyPositiveXFromReference
                        (&localState5,g_PlayerEntitySceneObject + 0x14);
      if (value4 != 0) {
        *(undefined4 *)(value2 + 0xc) = 3;
        PlayAudioById(0x1dc,(int *)0,(undefined4 *)0);
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

