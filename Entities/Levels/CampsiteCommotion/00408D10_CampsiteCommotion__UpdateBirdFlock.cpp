#include "tarzan_ghidra_types.hpp"

// Address: 0x00408D10
// Label: CampsiteCommotion::UpdateBirdFlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBirdFlock(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  short shortValue2;
  int value;
  char resultFlag;
  int value2;
  int value3;
  uint value4;
  short shortValue3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x20000);
    if (value2 != 0) {
      value3 = *(int *)(value2 + 0x10) + *(int *)(value2 + 0xc);
      *(int *)(value2 + 0xc) = value3;
      shortValue = (&g_SinCosTable12Bit)[value3 - 0x400U & 0xfff];
      shortValue2 = (&g_SinCosTable12Bit)[value3 >> 1 & 0xfff];
      *(int *)(value + 0x40) = *(int *)(value2 + 0x20) - ((int)shortValue + (int)shortValue2 >> 5);
      if (*(char *)(value + 0x75) == '\0') {
        value4 = *(int *)(value2 + 0x14) - *(int *)(value2 + 0x18);
        shortValue3 = (short)value4 + 0x400;
      }
      else {
        value4 = *(int *)(value2 + 0x14) + *(int *)(value2 + 0x18);
        shortValue3 = (short)value4 + -0x400;
      }
      value4 = value4 & 0xfff;
      ((EntitySceneObject *)value)->yaw = shortValue3;
      value3 = (int)shortValue + (int)shortValue2 >> 6;
      *(uint *)(value2 + 0x14) = value4;
      *(int *)(value + 0x3c) =
           (int)(short)(&g_SinCosTable12Bit)[value4 - 0x400 & 0xfff] *
           (value3 + *(int *)(value2 + 0x1c)) >> 0xc;
      *(int *)(value + 0x44) =
           (int)(short)(&g_SinCosTable12Bit)[value4] * (value3 + *(int *)(value2 + 0x1c)) >> 0xc;
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      resultFlag = CEntities::CheckPlayerDamageContact(value);
      if (resultFlag != '\0') {
        *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      }
    }
  }
  return;
}

