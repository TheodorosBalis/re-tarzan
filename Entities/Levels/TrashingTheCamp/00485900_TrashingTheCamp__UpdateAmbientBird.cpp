#include "tarzan_ghidra_types.hpp"

// Address: 0x00485900
// Label: TrashingTheCamp::UpdateAmbientBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateAmbientBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  undefined4 value3;
  uint value4;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_00485b13;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) goto LAB_00485b13;
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
    g_TrashingTheCampAmbientBirdVariantCounter = g_TrashingTheCampAmbientBirdVariantCounter + 1;
    if ((*(byte *)(entry + 0x4a) & 1) == 0) {
      value4 = g_TrashingTheCampAmbientBirdVariantCounter & 0x80000003;
      if ((int)value4 < 0) {
        value4 = (value4 - 1 | 0xfffffffc) + 1;
      }
      if (value4 == 0) {
        dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_B;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
        goto LAB_00485af2;
      }
      if (value4 == 1) {
        dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_B;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
      }
      else {
        if (value4 == 2) {
          dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_A;
          ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
          goto LAB_00485af2;
        }
        dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_A;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
      }
LAB_00485a4d:
      value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
      *(undefined4 *)(value + 0x70) = 2;
    }
    else if ((int)g_TrashingTheCampAmbientBirdVariantCounter % 3 == 0) {
      dataCursor = &DAT_0050ed88;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
LAB_00485af2:
      value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0xfdff;
    }
    else {
      if ((int)g_TrashingTheCampAmbientBirdVariantCounter % 3 == 1) {
        dataCursor = &DAT_0050ed88;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
        goto LAB_00485a4d;
      }
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
      value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050ed88);
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
      *(undefined4 *)(value + 0x70) = 3;
    }
  }
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
LAB_00485b13:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

