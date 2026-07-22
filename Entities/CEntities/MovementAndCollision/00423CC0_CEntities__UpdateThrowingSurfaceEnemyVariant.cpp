#include "tarzan_ghidra_types.hpp"

// Address: 0x00423CC0
// Label: CEntities::UpdateThrowingSurfaceEnemyVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateThrowingSurfaceEnemyVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value6;
  short shortValue;
  int value;
  int value2;
  char resultFlag;
  short shortValue2;
  int value3;
  int value4;
  int value5;
  
  value5 = entity->sceneObjects;
  if ((value5 != 0) &&
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value3 + 0x18);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value5,0x28,0xffffffe2);
    value4 = CEntities::HandleAnimalScriptEvent(entry,value5,(int)shortValue2);
    value = ((EntitySceneObject *)value5)->surfaceIndex;
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value5)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value5)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    resultFlag = CEntities::CheckPlayerDamageContact(value5);
    if ((resultFlag != '\0') &&
       (QueuePlayerDamageEvent(entry,5), g_PlayerDamageContactEntitySceneObject = value5,
       *(short *)(entry + 0x48) != 7)) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
      *(undefined2 *)(entry + 0x48) = 0;
    }
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    if (*(short *)(entry + 0x3e) < 1) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      *(undefined2 *)(entry + 0x48) = 1;
      CEntities::SelectScriptAttachmentSequence(value3,0);
      value5 = RandomModulo(3);
      *(int *)(entry + 0x4c) = value5 + 1;
      break;
    case 1:
      if (value4 != 0) {
        value5 = CEntities::ComputeEntitySceneObjectDataDistance3D
                          (value5 + 0xc,g_PlayerEntitySceneObjectData);
        if ((value5 < 0x4b0) &&
           (value5 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value5 != 0)) {
          *(undefined2 *)(entry + 0x48) = 6;
        }
        else {
          value5 = *(int *)(entry + 0x4c) + -1;
          *(int *)(entry + 0x4c) = value5;
          if (value5 < 0) {
            *(ushort *)(entry + 0x48) = ((value < 600) - 1 & 4) + 4;
          }
        }
      }
      break;
    case 2:
      CEntities::SelectScriptAttachmentSequence(value3,6);
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
      *(undefined2 *)(entry + 0x48) = 10;
      break;
    case 4:
      CEntities::SelectScriptAttachmentSequence(value3,1);
      *(undefined2 *)(entry + 0x48) = 5;
      break;
    case 5:
      if ((value4 != 0) && (value2 - value < 600)) {
        CEntities::SelectScriptAttachmentSequence(value3,3);
        *(undefined2 *)(entry + 0x48) = 0xb;
      }
      break;
    case 6:
      *(undefined2 *)(entry + 0x48) = 7;
      CEntities::SelectScriptAttachmentSequence(value3,0xe);
      *(undefined4 *)(entry + 0x50) = 0xc;
      break;
    case 7:
      value3 = *(int *)(entry + 0x50) + -1;
      *(int *)(entry + 0x50) = value3;
      if (value3 < 0) {
        value5 = CEntities::ComputeEntitySceneObjectDataDistance3D
                          (value5 + 0xc,g_PlayerEntitySceneObjectData);
        if ((value5 < 0x5dc) &&
           (value5 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value5 != 0)) {
          value5 = CEntities::SpawnEntityByTypeAtPosition
                            (*(undefined4 *)(g_PlayerEntitySceneObject + 0x14),
                             *(int *)(g_PlayerEntitySceneObject + 0x18) + -0x80,
                             *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c),0x13,0x11);
          if (value5 != 0) {
            *(undefined4 *)(*(int *)(value5 + 0x38) + 0x30) = 0;
            value6 = (byte *)(*(int *)(value5 + 0x38) + 0xf);
            *value6 = *value6 | 4;
            *(undefined4 *)(*(int *)(value5 + 0x38) + 0x20) = 0;
            *(undefined4 *)(*(int *)(value5 + 0x38) + 0x28) = 0;
            *(undefined4 *)(*(int *)(value5 + 0x38) + 0x24) = 0x1000;
          }
          QueuePlayerDamageEvent(entry,7);
        }
        *(undefined2 *)(entry + 0x48) = 1;
      }
      break;
    case 8:
      CEntities::SelectScriptAttachmentSequence(value3,9);
      *(undefined2 *)(entry + 0x48) = 9;
      break;
    case 9:
      if ((value4 != 0) && (value < 600)) {
        CEntities::SelectScriptAttachmentSequence(value3,0xb);
        *(undefined2 *)(entry + 0x48) = 10;
      }
      break;
    case 10:
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
      break;
    case 0xb:
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 6;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

