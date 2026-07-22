#include "tarzan_ghidra_types.hpp"

// Address: 0x00412040
// Label: ComingOfAge::UpdateEagle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateEagle(int entry)

{
  Entity *entity = (Entity *)entry;
  byte flagByte;
  ushort value8;
  int value2;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  int value5;
  int value6;
  int value;
  uint value7;
  
  value2 = entity->sceneObjects;
  if (value2 == 0) goto LAB_004122b7;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value3 == 0) goto LAB_004122b7;
  value4 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value4 == 0) goto LAB_004122b7;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  resultFlag = CEntities::CheckPlayerDamageContact(value2);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x2008);
  }
  value6 = ((EntitySceneObject *)value2)->surface;
  if (value6 != 0) {
    value8 = *(ushort *)(entry + 0x4a);
    if ((value8 & 0x80) == 0) {
      if ((*(byte *)(value6 + 0x14) & 1) != 0) {
        *(ushort *)(entry + 0x4a) = value8 ^ 0x100 | 0x80;
        if ((((byte)(value8 >> 8) ^ 1) & 1) == 0) {
          *(undefined4 *)(value4 + 0x1c) = 3;
        }
        else {
          *(undefined4 *)(value4 + 0x1c) = 1;
        }
      }
    }
    else if ((*(byte *)(value6 + 0x14) & 1) == 0) {
      *(ushort *)(entry + 0x4a) = value8 & 0xff7f;
    }
  }
  if (*(short *)(entry + 0x48) != 10) {
    if (*(short *)(entry + 0x48) == 0xb) {
      value3 = (*(int *)(value4 + 0x14) - (int)((EntitySceneObject *)value2)->yaw) * 0x100000;
      ((EntitySceneObject *)value2)->yaw =
           (short)((int)((value3 >> 0x14) + (value3 >> 0x1f & 7U)) >> 3) + ((EntitySceneObject *)value2)->yaw;
      value3 = (*(int *)(value4 + 0x18) - (int)*(short *)(value2 + 0xa0)) * 0x100000;
      *(short *)(value2 + 0xa0) =
           (short)((int)((value3 >> 0x14) + (value3 >> 0x1f & 7U)) >> 3) + *(short *)(value2 + 0xa0);
      value3 = ((int)((EntitySceneObject *)value2)->yaw - *(int *)(value4 + 0x14)) * 0x100000;
      value7 = value3 >> 0x1f;
      if ((int)((value3 >> 0x14 ^ value7) - value7) < 0x100) {
        *(undefined2 *)(entry + 0x48) = 10;
        *(byte *)(value2 + 0x75) = ~*(byte *)(value2 + 0x75);
        PlayAudioById(0x14d,(int *)&((EntitySceneObject *)value2)->soundPosition,(undefined4 *)&((EntitySceneObject *)value2)->x);
      }
    }
    goto LAB_004122b7;
  }
  CEntities::MoveEntityForwardOnSurface(entry,*(undefined4 *)(value4 + 0xc));
  CEntities::EaseEntitySceneObjectToCurrentJungleSurfaceAngles(entry,value2);
  value5 = CEntities::HandleAnimalScriptEvent(entry,value2,(int)shortValue);
  value6 = *(int *)(value4 + 0x10) - *(int *)(value4 + 0xc);
  *(int *)(value4 + 0xc) = ((int)(value6 + (value6 >> 0x1f & 7U)) >> 3) + *(int *)(value4 + 0xc);
  value6 = ((EntitySceneObject *)value2)->surfaceIndex;
  value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value2)->surfacePathIndex * 4) + 8 +
                    ((EntitySceneObject *)value2)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - value6;
  if (value6 < 1000) {
    *(int *)(value4 + 0x10) = ((int)(value6 + (value6 >> 0x1f & 0x1fU)) >> 5) + 10;
  }
  else if (value < 1000) {
    *(int *)(value4 + 0x10) = ((int)(value + (value >> 0x1f & 0x1fU)) >> 5) + 10;
  }
  else {
    *(undefined4 *)(value4 + 0x10) = 0x46;
  }
  flagByte = *(byte *)(value2 + 0x75);
  if (flagByte == 0) {
LAB_00412245:
    if (value < 0x32) {
LAB_0041224a:
      if ((*(byte *)(entry + 0x4b) & 2) == 0) {
        *(byte *)(value2 + 0x75) = ~flagByte;
        PlayAudioById(0x14d,(int *)&((EntitySceneObject *)value2)->soundPosition,(undefined4 *)&((EntitySceneObject *)value2)->x);
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0xb;
        shortValue = ((EntitySceneObject *)value2)->yaw;
        *(undefined4 *)(value4 + 0x18) = 0;
        *(int *)(value4 + 0x14) = (shortValue + -0x800) * 0x100000 >> 0x14;
      }
    }
  }
  else {
    if (value6 < 0x32) goto LAB_0041224a;
    if (flagByte == 0) goto LAB_00412245;
  }
  if ((value5 != 0) && (*(int *)(value4 + 0x1c) != -1)) {
    CEntities::SelectScriptAttachmentSequence(value3,*(int *)(value4 + 0x1c));
    *(undefined4 *)(value4 + 0x1c) = 0xffffffff;
  }
LAB_004122b7:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

