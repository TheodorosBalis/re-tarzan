#include "tarzan_ghidra_types.hpp"

// Address: 0x00402BA0
// Label: TheBaboonChase::InitRunningAnimals
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitRunningAnimals(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  undefined2 value4;
  int value;
  undefined4 value5;
  int value2;
  int value3;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    value5 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc830);
    ((EntitySceneObject *)value)->y = value5;
    if (entity->descriptor != 0) {
      value3 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value3 + 0xc) == 1) {
        PlayAudioById(0x289,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      }
      value3 = *(int *)(value3 + 4);
      if (value3 != 0) {
        if (value3 == 1) {
          ((EntitySceneObject *)value)->x = 1;
          ((EntitySceneObject *)value)->worldObject = 0x3c;
          CEntities::SelectScriptAttachmentSequence(((EntitySceneObject *)value)->y,3);
          CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
          value4 = RandomModulo(0xc);
          *(undefined2 *)(((EntitySceneObject *)value)->y + 0x16) = value4;
          shortValue = *(short *)(((EntitySceneObject *)value)->y + 0x16);
          if (shortValue < 2) {
            *(short *)(((EntitySceneObject *)value)->y + 0x16) = shortValue + 2;
          }
          value3 = g_WorldEntitySceneObjectArrayBase + 0x9c0;
        }
        else {
          if (value3 != 2) {
            return;
          }
          ((EntitySceneObject *)value)->x = 2;
          ((EntitySceneObject *)value)->worldObject = 0x3c;
          CEntities::SelectScriptAttachmentSequence(((EntitySceneObject *)value)->y,4);
          CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
          value4 = RandomModulo(0xc);
          *(undefined2 *)(((EntitySceneObject *)value)->y + 0x16) = value4;
          shortValue = *(short *)(((EntitySceneObject *)value)->y + 0x16);
          if (shortValue < 2) {
            *(short *)(((EntitySceneObject *)value)->y + 0x16) = shortValue + 2;
          }
          value3 = g_WorldEntitySceneObjectArrayBase + 0x478;
        }
        *(int *)(entity->sceneObjects + 0x10) = value3;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
        *(undefined4 *)(value + 0xc) = 4;
        CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0);
        value = entity->sceneObjects;
        value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
        ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value3;
        *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
        *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
        return;
      }
      ((EntitySceneObject *)value)->x = 0;
      CEntities::SelectScriptAttachmentSequence(((EntitySceneObject *)value)->y,0);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value4 = RandomModulo(0xc);
      *(undefined2 *)(((EntitySceneObject *)value)->y + 0x16) = value4;
      shortValue = *(short *)(((EntitySceneObject *)value)->y + 0x16);
      if (shortValue < 2) {
        *(short *)(((EntitySceneObject *)value)->y + 0x16) = shortValue + 2;
      }
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1e10;
      *(undefined4 *)(value + 0xc) = 0;
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0);
      value3 = entity->sceneObjects;
      value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value3);
      ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y + value2;
      *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
      *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
      ((EntitySceneObject *)value)->worldObject = 0x2d;
    }
  }
  return;
}

