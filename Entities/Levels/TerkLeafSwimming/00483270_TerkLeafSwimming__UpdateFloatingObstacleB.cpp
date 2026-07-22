#include "tarzan_ghidra_types.hpp"

// Address: 0x00483270
// Label: TerkLeafSwimming::UpdateFloatingObstacleB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::UpdateFloatingObstacleB(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short shortValue;
  short shortValue2;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  char resultFlag;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value2 = *(int *)(value + 0x38);
    *(int *)(value + 0x38) = value2 + -1;
    if (value2 == 0) {
      value2 = *(int *)(value + 0xc);
      *(undefined4 *)(value + 0x10) = *(undefined4 *)(value2 + 0x14);
      *(undefined4 *)(value + 0x14) = *(undefined4 *)(value2 + 0x18);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x1c);
      *(int *)(value + 0x34) = (int)*(short *)(value2 + 0xa2);
      *(undefined4 *)(value + 0x38) = *(undefined4 *)(value + 0x48);
    }
    value2 = *(int *)(value + 0x28);
    value3 = entity->sceneObjects;
    shortValue = (&g_SinCosTable12Bit)[*(uint *)(value + 0x2c) & 0xfff];
    shortValue2 = (&g_SinCosTable12Bit)[*(uint *)(value + 0x2c) - 0x400 & 0xfff];
    value4 = ((EntitySceneObject *)value3)->z;
    value5 = ((EntitySceneObject *)value3)->x;
    value6 = *(int *)(value + 0x18);
    value7 = *(int *)(value + 0x10);
    value = GetWrappedSignedAngleDelta12Bit
                       ((int)((EntitySceneObject *)value3)->yaw,*(undefined4 *)(value + 0x34));
    ((EntitySceneObject *)value3)->yaw = ((EntitySceneObject *)value3)->yaw + (short)(value >> 3);
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) - ((value5 - (shortValue2 * value2 >> 0xc)) - value7 >> 3)
    ;
    intCursor = (int *)(entity->sceneObjects + 0x1c);
    *intCursor = *intCursor - ((value4 - (shortValue * value2 >> 0xc)) - value6 >> 3);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

