#include "tarzan_ghidra_types.hpp"

// Address: 0x00431830
// Label: JourneyToTheTreeHouse::UpdateBlueButterflies
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateBlueButterflies(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 4;
  value2 = RandomModulo(0x20);
  ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + value2 + -0xf;
  value2 = RandomModulo(0x20);
  value2 = ((EntitySceneObject *)value)->y + value2 + -0xf;
  ((EntitySceneObject *)value)->y = value2;
  value3 = ((EntitySceneObject *)value)->x +
          ((short)(&g_SinCosTable12Bit)[TotalGameLoopTicks * 4 - 0x400U & 0xfff] * 3 >> 0xc);
  ((EntitySceneObject *)value)->x = value3;
  ((EntitySceneObject *)value)->x =
       ((short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 0x40U & 0xff) * 0x10] * 9 >> 0xc) + value3
  ;
  ((EntitySceneObject *)value)->y =
       (((int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 8U & 0x1f) * 0x80] << 1) >> 0xc) +
       value2;
  CEntities::ClampEffectSceneObjectNearSourcePosition(entry,400);
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

