#include "tarzan_ghidra_types.hpp"

// Address: 0x00466BD0
// Label: TarzanToTheRescue::UpdateClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateClayton(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short *value4;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  undefined1 localState2 [12];
  int localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value2 = *(int *)(entity->sceneObjects + 0x110) * 4 + 4;
    localState = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    SnapCameraAnchorAttachmentToNearestPathSegment(localState2,g_PlayerEntitySceneObject + 0x14);
    value3 = *(int *)(entity->sceneObjects + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value2 = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14);
    if (value3 * value3 + value2 * value2 < 0x100000) {
      g_TarzanToTheRescueElephantRescueSequenceActive = 1;
    }
    if ((g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 == 0) &&
       (g_TarzanToTheRescueElephantRideMountState == 0)) {
      if ((g_TarzanToTheRescueTrackedKnifeEnemyGroupB2 != 0) &&
         (g_TarzanToTheRescueKnifeEnemyVariantCReleased == 0)) {
        CEntities::SpawnEntityByTypeAtPosition(0xfffff768,0x100,0x19a00,0x16e,0x11);
      }
      g_TarzanToTheRescueElephantRideMountState = 1;
    }
    switch(*(undefined4 *)(value + 0xc)) {
    case 0:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      RefreshEntitySceneObjectNatureTerrainVerticalDelta(entity->sceneObjects);
      value2 = *(int *)(entity->sceneObjects + 0x58);
      if ((-0x100 < value2) && (value2 < 0x100)) {
        intCursor = (int *)(entity->sceneObjects + 0x18);
        *intCursor = *intCursor + value2;
      }
      if (g_TarzanToTheRescueElephantRescueSequenceActive != 0) {
        *(undefined4 *)(value + 0xc) = 2;
        value4 = (short *)(entity->sceneObjects + 0xa2);
        *value4 = *value4 + 0x800;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
        return;
      }
      value2 = *(int *)(value + 0x18);
      *(int *)(value + 0x18) = value2 + -1;
      if (value2 < 0) {
        *(undefined4 *)(value + 0xc) = 3;
        PlayAudioById(*(undefined4 *)(&DAT_005071dc + *(int *)(value + 0x20) * 4),(int *)0,(undefined4 *)0);
        *(uint *)(value + 0x20) = *(int *)(value + 0x20) + 1U & 7;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),2);
        *(undefined4 *)(value + 0x18) = 0xf0;
      }
      break;
    case 1:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
              *(int *)(entity->sceneObjects + 0x1c);
      value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
              *(int *)(entity->sceneObjects + 0x14);
      if (value3 * value3 + value2 * value2 < 0x900000) {
        *(undefined4 *)(value + 0x14) = 1;
        *(undefined4 *)(value + 0xc) = 0;
      }
      break;
    case 2:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      *(int *)(entity->sceneObjects + 0x1c) = *(int *)(entity->sceneObjects + 0x1c) + 0x30;
      RefreshEntitySceneObjectNatureTerrainVerticalDelta(entity->sceneObjects);
      value = *(int *)(entity->sceneObjects + 0x58);
      if ((-0x100 < value) && (value < 0x100)) {
        intCursor = (int *)(entity->sceneObjects + 0x18);
        *intCursor = *intCursor + value;
      }
      if (0x1aa00 < *(int *)(entity->sceneObjects + 0x1c)) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      break;
    case 3:
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      if (shortValue == 1) {
        *(undefined4 *)(value + 0xc) = 0;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),1);
        return;
      }
      if (g_TarzanToTheRescueElephantRescueSequenceActive != 0) {
        *(undefined4 *)(value + 0xc) = 2;
        value4 = (short *)(entity->sceneObjects + 0xa2);
        *value4 = *value4 + 0x800;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
        return;
      }
    }
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

