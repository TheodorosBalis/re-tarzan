#include "tarzan_ghidra_types.hpp"

// Address: 0x00458E00
// Label: Stampede::UpdateGorillas
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateGorillas(int entry)

{
  int value;
  char resultFlag;
  int value2;
  int value3;
  int value4;
  undefined4 localState4;
  undefined4 localState3;
  int localState;
  int localState5 [2];
  int localState2;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) goto LAB_004590ee;
  value4 = *(int *)(value2 + 0xc);
  entry = 0;
  if (value4 == 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value4 = *(int *)(value + 0x38);
    localState4 = *(undefined4 *)(value4 + 0x14);
    localState3 = *(undefined4 *)(value4 + 0x18);
    localState = *(int *)(value4 + 0x1c) + 0x300;
    value4 = CEntities::IsPointMostlyPositiveXFromReference
                      (&localState4,g_PlayerEntitySceneObject + 0x14);
    if (value4 != 0) {
      *(undefined4 *)(value2 + 0xc) = 1;
      if (*(int *)(value2 + 0x28) == 3) {
        PlayAudioById(0x1da,(int *)0,(undefined4 *)0);
        PlayAudioById(0x815a,(int *)0,(undefined4 *)0);
      }
      if (*(int *)(value2 + 0x28) == 0) {
        PlayAudioById(0x1d8,(int *)0,(undefined4 *)0);
        PlayAudioById(0x815b,(int *)0,(undefined4 *)0);
      }
      if (*(int *)(value2 + 0x28) == 2) {
        PlayAudioById(0x815c,(int *)0,(undefined4 *)0);
        PlayAudioById(0x1d9,(int *)0,(undefined4 *)0);
      }
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x2c) + 1);
    }
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry,
                       localState5);
    if (resultFlag == '\0') goto LAB_004590ee;
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) + localState5[0];
    localState2 = *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState2;
  }
  else {
    if (value4 == 1) {
      value4 = *(int *)(*(int *)(value + 0x38) + 0x10c);
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp(*(int *)(value + 0x38),value2 + 0x18,1);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value,*(undefined4 *)(value2 + 0x24));
      value2 = *(int *)(value + 0x38);
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value2);
      *(int *)(value2 + 0x18) = *(int *)(value2 + 0x18) + value3;
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState5);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState5[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState2;
        CPlayerHero::ApplyStampedeDamageReaction(value,2);
      }
      value2 = *(int *)(*(int *)(value + 0x38) + 0x110);
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                  g_CollisionSurfaceTable) + -0x200 <= value4) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
        return;
      }
      goto LAB_004590ee;
    }
    if (value4 != 2) goto LAB_004590ee;
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value4 = *(int *)(value + 0x38);
    localState4 = *(undefined4 *)(value4 + 0x14);
    localState3 = *(undefined4 *)(value4 + 0x18);
    localState = *(int *)(value4 + 0x1c) + 0x300;
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value,10);
    value4 = *(int *)(value + 0x38);
    value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value4);
    *(int *)(value4 + 0x18) = *(int *)(value4 + 0x18) + value3;
    value4 = CEntities::IsPointMostlyPositiveXFromReference
                      (&localState4,g_PlayerEntitySceneObject + 0x14);
    if (value4 != 0) {
      *(undefined4 *)(value2 + 0xc) = 1;
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x2c) + 1);
    }
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry,
                       localState5);
    if (resultFlag == '\0') goto LAB_004590ee;
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) + localState5[0];
    localState2 = *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState2;
  }
  *(int *)(g_PlayerEntitySceneObject + 0x1c) = localState2;
  CPlayerHero::ApplyStampedeDamageReaction(value,2);
LAB_004590ee:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

