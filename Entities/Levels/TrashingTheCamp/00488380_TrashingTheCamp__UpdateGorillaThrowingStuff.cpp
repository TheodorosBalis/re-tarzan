#include "tarzan_ghidra_types.hpp"

// Address: 0x00488380
// Label: TrashingTheCamp::UpdateGorillaThrowingStuff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateGorillaThrowingStuff(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value3 = GetSceneAttachmentWorldPositionByMask(value,1,&localState3);
    value4 = GetSceneAttachmentWorldPositionByMask(value,2,&localState6);
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue == 8) {
      if (g_TrashingTheCampImpactThrownPropEntity != 0) {
        TrashingTheCamp::SpawnCampThrownPropDebris(g_TrashingTheCampImpactThrownPropEntity);
        CEntities::ReleaseEntityToFreeList((byte *)g_TrashingTheCampImpactThrownPropEntity);
        g_TrashingTheCampImpactThrownPropEntity = 0;
      }
      if (value3 != 0) {
        g_TrashingTheCampHeldThrownPropEntity =
             CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0xf9,0x11);
      }
    }
    else if (shortValue == 9) {
      if (g_TrashingTheCampHeldThrownPropEntity != 0) {
        TrashingTheCamp::SpawnCampThrownPropDebris(g_TrashingTheCampHeldThrownPropEntity);
        CEntities::ReleaseEntityToFreeList((byte *)g_TrashingTheCampHeldThrownPropEntity);
        g_TrashingTheCampHeldThrownPropEntity = 0;
      }
      if (value4 != 0) {
        g_TrashingTheCampImpactThrownPropEntity =
             CEntities::SpawnEntityByTypeAtPosition(localState6,localState5,localState4,0xf9,0x11);
      }
    }
    if ((g_TrashingTheCampHeldThrownPropEntity != 0) &&
       (value2 = *(int *)(g_TrashingTheCampHeldThrownPropEntity + 0x38), value2 != 0)) {
      if (value3 != 0) {
        *(undefined4 *)(value2 + 0x14) = localState3;
        *(undefined4 *)(value2 + 0x18) = localState2;
        *(undefined4 *)(value2 + 0x1c) = localState;
      }
      *(undefined2 *)(value2 + 0xa2) = ((EntitySceneObject *)value)->yaw;
      *(undefined4 *)(value2 + 0x110) = ((EntitySceneObject *)value)->surfacePathIndex;
      *(undefined4 *)(value2 + 0x10c) = ((EntitySceneObject *)value)->surfaceIndex;
    }
    if ((g_TrashingTheCampImpactThrownPropEntity != 0) &&
       (value3 = *(int *)(g_TrashingTheCampImpactThrownPropEntity + 0x38), value3 != 0)) {
      if (value4 != 0) {
        *(undefined4 *)(value3 + 0x14) = localState6;
        *(undefined4 *)(value3 + 0x18) = localState5;
        *(undefined4 *)(value3 + 0x1c) = localState4;
      }
      *(undefined2 *)(value3 + 0xa2) = ((EntitySceneObject *)value)->yaw;
      *(undefined4 *)(value3 + 0x110) = ((EntitySceneObject *)value)->surfacePathIndex;
      *(undefined4 *)(value3 + 0x10c) = ((EntitySceneObject *)value)->surfaceIndex;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    if (g_TrashingTheCampHeldThrownPropEntity != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)g_TrashingTheCampHeldThrownPropEntity);
    }
    if (g_TrashingTheCampImpactThrownPropEntity != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)g_TrashingTheCampImpactThrownPropEntity);
    }
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

