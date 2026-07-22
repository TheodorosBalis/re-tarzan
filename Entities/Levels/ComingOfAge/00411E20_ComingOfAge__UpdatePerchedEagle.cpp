#include "tarzan_ghidra_types.hpp"

// Address: 0x00411E20
// Label: ComingOfAge::UpdatePerchedEagle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdatePerchedEagle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 != 0)) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveSurfaceEntityFromMotionFlags(entry,value,0,*(undefined4 *)(entry + 0x4c));
    value2 = CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue);
    if ((*(short *)(entry + 0x48) == 8) && (shortValue == 0x10e)) {
      value3 = *(int *)(entry + 0x4c) + -0x19;
      *(int *)(entry + 0x4c) = value3;
      if (value3 < -0x1e) {
        *(undefined4 *)(entry + 0x4c) = 0xffffffe2;
      }
    }
    else if (*(int *)(entry + 0x4c) < 0x19) {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + 1;
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x2008);
    }
    value3 = GetAngleFromXZVector12Bit
                      (((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObjectData + 8),
                       ((EntitySceneObject *)value)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10));
    value3 = (value3 - ((EntitySceneObject *)value)->yaw) * 0x100000;
    ((EntitySceneObject *)value)->yaw =
         (short)((int)((value3 >> 0x14) + (value3 >> 0x1f & 0xfU)) >> 4) + ((EntitySceneObject *)value)->yaw;
    switch(*(undefined2 *)(entry + 0x48)) {
    case 4:
      if (value2 != 0) {
        *(undefined2 *)(entry + 0x48) = 5;
      }
      break;
    case 5:
      if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - ((EntitySceneObject *)value)->surfaceIndex
          < 0x101) {
        *(undefined2 *)(entry + 0x48) = 7;
      }
      break;
    case 7:
      if (value2 != 0) {
        *(undefined2 *)(entry + 0x48) = 8;
      }
      break;
    case 8:
      if (((EntitySceneObject *)value)->surfaceIndex < 0x100) {
        *(undefined2 *)(entry + 0x48) = 4;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

