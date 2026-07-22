#include "tarzan_ghidra_types.hpp"

// Address: 0x00408850
// Label: CampsiteCommotion::UpdatePatrollingCampAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdatePatrollingCampAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  undefined4 value3;
  uint value4;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_00408a63;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) goto LAB_00408a63;
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x28);
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
  if (*(char *)(value + 0x74) == '\0') {
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      if ((*(byte *)(entry + 0x4a) & 1) != 0) {
        QueuePlayerDamageEvent(entry,6);
      }
      *(undefined1 *)(value + 0x74) = 0x10;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    }
  }
  else {
    *(char *)(value + 0x74) = *(char *)(value + 0x74) + -1;
  }
  if (*(byte *)(value + 0x75) == 0) {
    if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                 ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - ((EntitySceneObject *)value)->surfaceIndex <
        100) {
      *(undefined1 *)(value + 0x75) = 0xff;
    }
  }
  else if (((EntitySceneObject *)value)->surfaceIndex < 100) {
    *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
  }
  if ((*(byte *)(((EntitySceneObject *)value)->surface + 0x14) & 1) == 0) {
    *(undefined4 *)(entry + 0x50) = 0;
  }
  else if (*(int *)(entry + 0x50) == 0) {
    *(undefined4 *)(entry + 0x50) = 1;
    g_CampsiteCommotionAnimalVariantCounter = g_CampsiteCommotionAnimalVariantCounter + 1;
    if ((*(byte *)(entry + 0x4a) & 1) == 0) {
      value4 = g_CampsiteCommotionAnimalVariantCounter & 0x80000003;
      if ((int)value4 < 0) {
        value4 = (value4 - 1 | 0xfffffffc) + 1;
      }
      if (value4 == 0) {
        dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescB;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
        goto LAB_00408a42;
      }
      if (value4 == 1) {
        dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescB;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
      }
      else {
        if (value4 == 2) {
          dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescA;
          ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
          goto LAB_00408a42;
        }
        dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescA;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
      }
LAB_0040899d:
      value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
      *(undefined4 *)(value + 0x70) = 2;
    }
    else if ((int)g_CampsiteCommotionAnimalVariantCounter % 3 == 0) {
      dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescC;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
LAB_00408a42:
      value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0xfdff;
    }
    else {
      if ((int)g_CampsiteCommotionAnimalVariantCounter % 3 == 1) {
        dataCursor = &g_CampsiteCommotionPatrollingAnimalScriptDescC;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
        goto LAB_0040899d;
      }
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
      value3 = CEntities::SetEntitySceneObjectScriptAttachment
                        (entry,&g_CampsiteCommotionPatrollingAnimalScriptDescC);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
      *(undefined4 *)(value + 0x70) = 3;
    }
  }
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
LAB_00408a63:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

