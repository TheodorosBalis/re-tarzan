#include "tarzan_ghidra_types.hpp"

// Address: 0x004539A0
// Label: UpdateIntroScriptedPropA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateIntroScriptedPropA(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  short shortValue;
  int value2;
  uint value3;
  
  if (g_IntroScriptedPropsDisabled == '\0') {
    value = entity->sceneObjects;
    if (value != 0) {
      value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x20000);
      if (value2 != 0) {
        shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
        if (shortValue != 0) {
          if (shortValue == 4) {
            *(undefined4 *)(value2 + 0xc) = 0;
          }
          else if (shortValue == 5) {
            *(undefined4 *)(value2 + 0xc) = 1;
          }
        }
        if (*(int *)(value2 + 0xc) != 0) {
          ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x10;
        }
        value3 = ((EntitySceneObject *)value)->yaw - 0x400 & 0xfff;
        shortValue = (&g_SinCosTable12Bit)[value3];
        ((EntitySceneObject *)value)->x = -((short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * 0x14 >> 8);
        ((EntitySceneObject *)value)->z = -(shortValue * 0x14 >> 8);
        return;
      }
    }
    CEntities::ReleaseEntityToFreeList((byte *)arg1);
  }
  return;
}

