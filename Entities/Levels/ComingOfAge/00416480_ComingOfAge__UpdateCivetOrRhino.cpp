#include "tarzan_ghidra_types.hpp"

// Address: 0x00416480
// Label: ComingOfAge::UpdateCivetOrRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateCivetOrRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  byte flagByte;
  int value;
  char resultFlag;
  char resultFlag2;
  short shortValue;
  int value2;
  int value3;
  int value4;
  uint value6;
  bool flagByte2;
  undefined4 value5;
  
  value4 = entity->sceneObjects;
  if ((value4 == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 == 0))
  goto switchD_0041659b_caseD_1;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue < 0x106) {
    if (shortValue == 0x105) {
      *(undefined4 *)(entry + 0x50) = 0x14;
    }
    else if ((shortValue == 4) ||
            ((shortValue == 6 &&
             (value3 = *(int *)(entry + 0x50) + -4, *(int *)(entry + 0x50) = value3, value3 < 0))))
    {
      *(undefined4 *)(entry + 0x50) = 0;
    }
  }
  else if (shortValue == 0x106) {
    *(undefined4 *)(entry + 0x50) = 0x30;
  }
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x50));
  CEntities::CheckEntitySceneObjectCollisionDelta(value4);
  value3 = ((EntitySceneObject *)value4)->surface;
  value = ((EntitySceneObject *)value4)->surfaceIndex;
  value6 = *(int *)(g_PlayerEntitySceneObject + 0x10c) - value;
  if (*(char *)(value4 + 0x75) == '\0') {
    flagByte2 = 0 < (int)value6;
  }
  else {
    flagByte2 = (int)value6 < 0;
  }
  if (((EntitySceneObject *)value4)->surfacePathIndex != *(int *)(g_PlayerEntitySceneObject + 0x110)) {
    flagByte2 = false;
    value6 = 0x7fffffff;
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  resultFlag2 = CEntities::CheckPlayerDamageContact(value4);
  if (resultFlag2 != '\0') {
    QueuePlayerDamageEvent(entry,0xc);
    g_PlayerDamageContactEntitySceneObject = value4;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if (resultFlag == '\0') {
      if (g_PlayerActionState != 0x2c) {
        value3 = *(int *)(entry + 0x4c) + -1;
        *(int *)(entry + 0x4c) = value3;
        if (value3 != 0) {
          CEntities::SelectScriptAttachmentSequence(value2,1);
          break;
        }
        value3 = RandomModulo(0x14);
        *(int *)(entry + 0x4c) = value3 + 10;
        if (*(char *)(value4 + 0x75) == '\0') {
          value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value4)->surfacePathIndex * 4) + 8 +
                           ((EntitySceneObject *)value4)->surfacePathIndex * 4 + g_CollisionSurfaceTable) -
                  ((EntitySceneObject *)value4)->surfaceIndex;
        }
        else {
          value4 = ((EntitySceneObject *)value4)->surfaceIndex;
        }
        if (value4 < 200) {
          *(undefined2 *)(entry + 0x48) = 2;
          CEntities::SelectScriptAttachmentSequence(value2,4);
          break;
        }
        value4 = RandomModulo(2);
        if (value4 != 0) {
          *(undefined2 *)(entry + 0x48) = 4;
          CEntities::SelectScriptAttachmentSequence(value2,5);
          break;
        }
        goto LAB_00416734;
      }
      value4 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value4;
      if (value4 != 0) break;
      if (!flagByte2) goto LAB_00416601;
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value2,5);
      value5 = 10;
    }
    else if (flagByte2) {
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value2,5);
      value5 = 10;
    }
    else {
LAB_00416601:
      *(undefined2 *)(entry + 0x48) = 2;
      CEntities::SelectScriptAttachmentSequence(value2,4);
      value5 = 10;
    }
    goto LAB_00416959;
  case 2:
    if (shortValue == 0x107) {
      ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw ^ 0x800;
      *(byte *)(value4 + 0x75) = ~*(byte *)(value4 + 0x75);
      *(undefined2 *)(entry + 0x48) = 0;
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    break;
  case 3:
    if (((*(byte *)(value3 + 0x14) & 2) != 0) || ((*(byte *)(value4 + 0x13c) & 2) != 0)) {
      *(undefined4 *)(entry + 0x50) = 0;
      *(undefined2 *)(entry + 0x48) = 0;
      value4 = RandomModulo(0x14);
      *(int *)(entry + 0x4c) = value4 + 10;
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    break;
  case 4:
    if (shortValue != 8) break;
    goto LAB_00416734;
  case 5:
    if ((*(byte *)(value3 + 0x14) & 1) != 0) {
      g_EntityHitResponseScratch = 1;
    }
    if (*(char *)(value4 + 0x75) == '\0') {
      if ((*(byte *)(value4 + 0x13c) & 2) != 0) {
        *(undefined2 *)(entry + 0x48) = 8;
        value4 = RandomModulo(8);
        *(int *)(entry + 0x4c) = value4 + 10;
        CEntities::SelectScriptAttachmentSequence(value2,0x14);
        break;
      }
    }
    else if (value < 0x800) {
      *(undefined2 *)(entry + 0x48) = 7;
      CEntities::SelectScriptAttachmentSequence(value2,0xb);
      break;
    }
    if ((!flagByte2) && (0x400 < (int)((value6 ^ (int)value6 >> 0x1f) - ((int)value6 >> 0x1f)))) {
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value2,0x1b);
    }
    break;
  case 6:
    if (shortValue == 0x107) {
      ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw ^ 0x800;
      *(byte *)(value4 + 0x75) = ~*(byte *)(value4 + 0x75);
      *(undefined2 *)(entry + 0x48) = 5;
    }
    break;
  case 7:
    if ((*(byte *)(value3 + 0x14) & 1) != 0) {
      g_EntityHitResponseScratch = 1;
    }
    if (shortValue == 9) {
      *(undefined2 *)(entry + 0x48) = 9;
      *(undefined4 *)(entry + 0x4c) = 10;
      CEntities::SelectScriptAttachmentSequence(value2,0x1e);
    }
    break;
  case 8:
    if (shortValue != 8) break;
    if (*(int *)(entry + 0x4c) != 0) {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
    }
    if (*(int *)(entry + 0x4c) != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0x15);
      break;
    }
    *(undefined4 *)(entry + 0x50) = 0;
    *(undefined2 *)(entry + 0x48) = 0;
    value5 = 0x14;
LAB_00416959:
    value4 = RandomModulo(value5);
    *(int *)(entry + 0x4c) = value4 + 10;
    break;
  case 9:
    if (shortValue != 8) break;
    if (!flagByte2) {
      if (*(int *)(entry + 0x4c) != 0) {
        *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      }
      if (value6 == 0x7fffffff) {
        if (*(int *)(entry + 0x4c) == 0) {
          *(undefined2 *)(entry + 0x48) = 0;
          value4 = RandomModulo(0x14);
          *(int *)(entry + 0x4c) = value4 + 10;
          CEntities::SelectScriptAttachmentSequence(value2,0);
        }
      }
      else {
        *(undefined2 *)(entry + 0x48) = 10;
        CEntities::SelectScriptAttachmentSequence(value2,4);
      }
      break;
    }
    if ((*(char *)(value4 + 0x75) != '\0') && (value < 0x800)) break;
LAB_00416734:
    *(undefined2 *)(entry + 0x48) = 5;
    CEntities::SelectScriptAttachmentSequence(value2,8);
    break;
  case 10:
    if (shortValue != 0x107) break;
    flagByte = *(byte *)(value4 + 0x75);
    if (flagByte2) {
      if ((flagByte == 0) || (0x7ff < value)) goto LAB_00416734;
      ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw ^ 0x800;
      *(byte *)(value4 + 0x75) = ~flagByte;
    }
    else {
      ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw ^ 0x800;
      *(byte *)(value4 + 0x75) = ~flagByte;
    }
    *(undefined2 *)(entry + 0x48) = 9;
    CEntities::SelectScriptAttachmentSequence(value2,0x1e);
  }
switchD_0041659b_caseD_1:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

