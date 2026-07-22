#include "tarzan_ghidra_types.hpp"

// Address: 0x00432740
// Label: GoingApe::UpdateMonkeyTreeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateMonkeyTreeSurfing(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  uint value7;
  int value3;
  int value4;
  int value5;
  int value;
  bool flagByte;
  undefined4 value6;
  
  value4 = entity->sceneObjects;
  if (value4 == 0) goto switchD_00432923_caseD_4;
  value5 = *(int *)(entry + 0x4c) + (uint)(*(int *)(entry + 0x50) == 0);
  *(int *)(entry + 0x4c) = value5;
  if (0x11 < value5) {
    *(undefined4 *)(entry + 0x50) = 1;
  }
  if (*(int *)(entry + 0x4c) < -0x11) {
    *(undefined4 *)(entry + 0x50) = 0;
  }
  value5 = *(int *)(entry + 0x4c);
  if (value5 < 0x10) {
    if (value5 < -0xf) {
      value5 = -0xf;
    }
  }
  else {
    value5 = 0xf;
  }
  value5 = (value5 * 0x8c) / 0xf;
  value7 = ((EntitySceneObject *)value4)->yaw + 0x400 & 0xfff;
  *(int *)(value4 + 0x3c) = -((short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * value5) >> 0xc;
  *(int *)(value4 + 0x44) = -((short)(&g_SinCosTable12Bit)[value7] * value5) >> 0xc;
  value5 = value5 + value5 / 2;
  value7 = -value5 & 0xfff;
  *(int *)(value4 + 0x40) = -((short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * value5) >> 0xc;
  ((EntitySceneObject *)value4)->pitch = (short)value7;
  value5 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value5 == 0) goto switchD_00432923_caseD_4;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value5 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value4,0x24,0x14);
  resultFlag = CEntities::HandleAnimalScriptEvent(entry,value4,(int)shortValue2);
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value4)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value4)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  value = ((EntitySceneObject *)value4)->surfaceIndex;
  resultFlag2 = CEntities::CheckPlayerDamageContact(value4);
  if ((resultFlag2 != '\0') &&
     (QueuePlayerDamageEvent(entry,0x1006), g_PlayerDamageInvulnerabilityTicks == 0)) {
    value3 = RandomModulo(2);
    if (value3 == 0) {
      value3 = entity->sceneObjects;
      value6 = 0x112;
LAB_004328f6:
      PlayAudioById(value6,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
    }
    else if (value3 == 1) {
      value3 = entity->sceneObjects;
      value6 = 0x110;
      goto LAB_004328f6;
    }
    PlayAudioById(0x19,(int *)0,(undefined4 *)0);
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
  case 2:
    CEntities::SelectScriptAttachmentSequence(value5,1);
    *(undefined2 *)(entry + 0x48) = 3;
    break;
  case 1:
    value4 = CEntities::ComputeEntitySceneObjectDataDistance3D
                      (value4 + 0xc,g_PlayerEntitySceneObjectData);
    if (value4 < 0x41a) {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    break;
  case 3:
    if (resultFlag != '\0') {
      if (*(char *)(value4 + 0x75) == '\0') {
        value = value2 - value;
        value2 = value + -0x400;
        flagByte = value2 == 0;
      }
      else {
        value2 = value + -0x400;
        flagByte = value == 0x400;
      }
      if (flagByte || SBORROW4(value,0x400) != value2 < 0) {
        CEntities::SelectScriptAttachmentSequence(value5,6);
        *(undefined2 *)(entry + 0x48) = 0xc;
      }
      else {
        value4 = CEntities::ComputeEntitySceneObjectDataDistance3D
                          (value4 + 0xc,g_PlayerEntitySceneObjectData);
        if ((value4 < 800) &&
           (value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value4 != 0)) {
          CEntities::SelectScriptAttachmentSequence(value5,10);
          *(undefined2 *)(entry + 0x48) = 0xf;
        }
      }
    }
    break;
  case 0xc:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 0xf:
    if (*(char *)(value4 + 0x75) == '\0') {
      value = value2 - value;
      value4 = value + -0x600;
      flagByte = value4 == 0;
    }
    else {
      value4 = value + -0x600;
      flagByte = value == 0x600;
    }
    if (flagByte || SBORROW4(value,0x600) != value4 < 0) {
      CEntities::AdvanceScriptAttachmentSequence(value5);
      *(undefined2 *)(entry + 0x48) = 3;
    }
  }
switchD_00432923_caseD_4:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

