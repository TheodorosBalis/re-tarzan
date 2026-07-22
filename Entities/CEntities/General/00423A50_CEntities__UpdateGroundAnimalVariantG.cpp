#include "tarzan_ghidra_types.hpp"

// Address: 0x00423A50
// Label: CEntities::UpdateGroundAnimalVariantG
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateGroundAnimalVariantG(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value5;
  byte flagByte;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  
  value3 = entity->sceneObjects;
  if (value3 == 0) goto LAB_00423c2e;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) goto LAB_00423c2e;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value3,0x50,0x50);
  CEntities::HandleAnimalScriptEvent(entry,value3,(int)shortValue);
  value4 = ((EntitySceneObject *)value3)->surfaceIndex;
  value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value3)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value3)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  resultFlag = CEntities::CheckPlayerDamageContact(value3);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,2);
  }
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (*(short *)(entry + 0x3e) < 1) {
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                       ((EntitySceneObject *)value3)->z,0x13,0x11);
    if (value2 != 0) {
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x30) = 0;
      value5 = (byte *)(*(int *)(value2 + 0x38) + 0xf);
      *value5 = *value5 | 4;
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x20) = 0;
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x28) = 0;
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x24) = 0x800;
    }
    PlayAudioById(0x157,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  shortValue = *(short *)(entry + 0x48);
  if (shortValue == 0) {
    value3 = RandomModulo(0xc);
    *(int *)(entry + 0x4c) = value3 + 2;
    *(undefined2 *)(entry + 0x48) = 1;
    CEntities::SelectScriptAttachmentSequence(value2,0);
    goto LAB_00423c2e;
  }
  if (shortValue != 1) {
    if (shortValue == 2) {
      if ((*(byte *)(entry + 0x4a) & 2) == 0) {
        *(undefined4 *)(value3 + 0x40) = 0;
      }
      else {
        *(int *)(value3 + 0x40) =
             *(int *)(&g_GroundAnimalVariantGHopVelocityTable + *(int *)(entry + 0x50) * 4) * -8;
        *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + 1;
      }
      if (*(short *)(value2 + 0x18) == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    goto LAB_00423c2e;
  }
  flagByte = *(byte *)(value3 + 0x75);
  if (flagByte == 0) {
LAB_00423bad:
    if (value - value4 < 0x201) {
      if ((*(byte *)(entry + 0x4b) & 2) != 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      *(undefined1 *)(value3 + 0x75) = 0xff;
      goto LAB_00423c2e;
    }
  }
  else {
    if (value4 < 0x201) {
      *(byte *)(value3 + 0x75) = ~flagByte;
      goto LAB_00423c2e;
    }
    if (flagByte == 0) goto LAB_00423bad;
  }
  value4 = *(int *)(entry + 0x4c) + -1;
  *(int *)(entry + 0x4c) = value4;
  if (value4 < 1) {
    CEntities::SelectScriptAttachmentSequence(value2,1);
    *(undefined2 *)(entry + 0x48) = 2;
    *(undefined4 *)(entry + 0x50) = 0;
    PlayAudioById(0x109,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
  }
LAB_00423c2e:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

