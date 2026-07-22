#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C9A0
// Label: StorkRide::UpdateScriptedBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateScriptedBird(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value7;
  char resultFlag;
  int value;
  int value2;
  int value3;
  int value4;
  uint value6;
  int value5;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0x100;
  localState2[0] = 0x100;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    *(undefined4 *)(entity->sceneObjects + 0x110) = g_StorkLeftBoundarySurfaceIndex;
    *(undefined4 *)(value2 + 0x10) = *(undefined4 *)(entity->sceneObjects + 0x54);
    *(undefined4 *)(entity->sceneObjects + 0x110) = g_StorkRightBoundarySurfaceIndex;
    *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(entity->sceneObjects + 0x54);
    resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                      (entity->sceneObjects,localState,g_PlayerEntitySceneObject,
                       localState2);
    if ((resultFlag != '\0') && (*(int *)(value2 + 0x20) == 0)) {
      CPlayerHero::EnterStorkTerrainImpactReaction();
      *(undefined4 *)(value2 + 0x20) = 1;
    }
    switch(*(undefined4 *)(value2 + 0xc)) {
    case 1:
      *(undefined4 *)(value2 + 0x18) = 0;
      if (*(int *)(value2 + 0x1c) == 0) {
        *(undefined **)(value + 0xc) = &DAT_005040a0;
        *(undefined2 *)(value + 0x16) = 0;
        *(undefined4 *)(value2 + 0x1c) = 1;
      }
      *(int *)(entity->sceneObjects + 0x14) = *(int *)(entity->sceneObjects + 0x14) + -8;
      *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x400;
      if (*(int *)(value2 + 0x10) < 0) {
        *(undefined4 *)(value2 + 0xc) = 3;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      return;
    case 2:
      *(undefined4 *)(value2 + 0x18) = 0;
      if (*(int *)(value2 + 0x1c) == 0) {
        *(undefined **)(value + 0xc) = &DAT_005040a0;
        *(undefined2 *)(value + 0x16) = 0;
        *(undefined4 *)(value2 + 0x1c) = 1;
      }
      *(int *)(entity->sceneObjects + 0x14) = *(int *)(entity->sceneObjects + 0x14) + 8;
      *(undefined2 *)(entity->sceneObjects + 0xa2) = 0xc00;
      if (0 < *(int *)(value2 + 0x14)) {
        *(undefined4 *)(value2 + 0xc) = 4;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      return;
    case 3:
      if (*(int *)(value2 + 0x18) == 0) {
        *(undefined **)(value + 0xc) = &DAT_005040a8;
        *(undefined2 *)(value + 0x16) = 0;
        *(undefined4 *)(value2 + 0x18) = 1;
        *(undefined4 *)(value2 + 0x1c) = 0;
      }
      value = entity->sceneObjects;
      value4 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value)->yaw,0xc00);
      value7 = (short *)(&((EntitySceneObject *)value)->yaw);
      *value7 = *value7 + (short)(value4 >> 3);
      value6 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      if ((value6 & 1) != 0) {
        *(undefined4 *)(value2 + 0xc) = 2;
        return;
      }
      break;
    case 4:
      if (*(int *)(value2 + 0x18) == 0) {
        *(undefined **)(value + 0xc) = &DAT_005040a8;
        *(undefined2 *)(value + 0x16) = 0xffff;
        *(undefined4 *)(value2 + 0x18) = 1;
        *(undefined4 *)(value2 + 0x1c) = 0;
      }
      value = entity->sceneObjects;
      value4 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value)->yaw,0x400);
      value7 = (short *)(&((EntitySceneObject *)value)->yaw);
      *value7 = *value7 + (short)(value4 >> 3);
      value6 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      if ((value6 & 1) != 0) {
        *(undefined4 *)(value2 + 0xc) = 1;
      }
      break;
    case 7:
      value = entity->sceneObjects;
      value4 = *(int *)(g_PlayerEntity + 0x38);
      value3 = ((EntitySceneObject *)value)->x - *(int *)(value4 + 0x14);
      value5 = ((EntitySceneObject *)value)->y - *(int *)(value4 + 0x18);
      value = ((EntitySceneObject *)value)->z - *(int *)(value4 + 0x1c);
      if (value * value + value5 * value5 + value3 * value3 < 0x2400000) {
        *(undefined4 *)(value2 + 0xc) = 1;
      }
      *(undefined4 *)(entity->sceneObjects + 0x14) = *(undefined4 *)(value2 + 0x14);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      return;
    }
  }
  return;
}

