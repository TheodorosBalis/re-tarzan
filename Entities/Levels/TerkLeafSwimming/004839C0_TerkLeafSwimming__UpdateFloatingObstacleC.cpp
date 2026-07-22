#include "tarzan_ghidra_types.hpp"

// Address: 0x004839C0
// Label: TerkLeafSwimming::UpdateFloatingObstacleC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::UpdateFloatingObstacleC(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value3;
  short shortValue;
  int value;
  int value2;
  
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value != 0) {
    AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if (value2 != 0) {
      value = ((EntitySceneObject *)value)->z;
      shortValue = (&g_SinCosTable12Bit)[*(int *)(value2 + 0x30) - 0x400U & 0xfff];
      *(uint *)(value2 + 0x30) = (*(int *)(value2 + 0x44) >> 2) + *(int *)(value2 + 0x30) & 0xfff;
      value2 = entity->sceneObjects;
      value = GetWrappedSignedAngleDelta12Bit
                        ((int)((EntitySceneObject *)value2)->yaw,(((int)shortValue << 8) >> 0xc) - value);
      value3 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value3 = *value3 + (short)(value >> 3);
      value = entity->sceneObjects;
      shortValue = (&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value)->yaw - 0x800U & 0xfff];
      ((EntitySceneObject *)value)->x =
           ((EntitySceneObject *)value)->x +
           (((int)(short)(&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value)->yaw + 0x400U & 0xfff] << 3)
           >> 0xc);
      *(int *)(entity->sceneObjects + 0x1c) =
           *(int *)(entity->sceneObjects + 0x1c) + (((int)shortValue << 3) >> 0xc);
    }
  }
  return;
}

