#include "tarzan_ghidra_types.hpp"

// Address: 0x00462FB0
// Label: TarzanToTheRescue::UpdateBoxInWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateBoxInWater(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short *value5;
  char resultFlag;
  int value;
  int value2;
  int value3;
  int value4;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(entity->sceneObjects + 0x60) == 0) {
      *(undefined4 *)(value + 0x40) = 0;
    }
    else if (*(int *)(value + 0x40) == 0) {
      PlayAudioById(0x38b,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value + 0x40) = 1;
      *(undefined4 *)(value + 0x38) = 0x20;
    }
    if (*(int *)(value + 0x38) != 0) {
      value2 = RandomModulo(0x1000);
      *(int *)(value + 0x38) = *(int *)(value + 0x38) + -1;
      value3 = entity->sceneObjects;
      value3 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x20,
                         ((EntitySceneObject *)value3)->z,0x166,0x11);
      if (value3 != 0) {
        value4 = CEntities::FindEntityAttachmentByFlags(value3,0x10000000);
        if (value4 != 0) {
          *(int *)(value4 + 0x18) = value2;
          intCursor = (int *)(*(int *)(value3 + 0x38) + 0x14);
          *intCursor = *intCursor + ((short)(&g_SinCosTable12Bit)[value2 - 0x400U & 0xfff] * 0x168 >> 0xc);
          *(int *)(*(int *)(value3 + 0x38) + 0x1c) =
               *(int *)(*(int *)(value3 + 0x38) + 0x1c) +
               ((short)(&g_SinCosTable12Bit)[*(uint *)(value4 + 0x18) & 0xfff] * 0x168 >> 0xc);
        }
      }
      value3 = entity->sceneObjects;
      value3 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x20,
                         ((EntitySceneObject *)value3)->z,0x166,0x11);
      if (value3 != 0) {
        value4 = CEntities::FindEntityAttachmentByFlags(value3,0x10000000);
        if (value4 != 0) {
          *(int *)(value4 + 0x18) = value2 + 0x800;
          *(int *)(*(int *)(value3 + 0x38) + 0x14) =
               *(int *)(*(int *)(value3 + 0x38) + 0x14) +
               ((short)(&g_SinCosTable12Bit)[value2 + 0x400U & 0xfff] * 400 >> 0xc);
          *(int *)(*(int *)(value3 + 0x38) + 0x1c) =
               *(int *)(*(int *)(value3 + 0x38) + 0x1c) +
               ((short)(&g_SinCosTable12Bit)[*(uint *)(value4 + 0x18) & 0xfff] * 400 >> 0xc);
        }
      }
    }
    value5 = (short *)(entity->sceneObjects + 0xa2);
    *value5 = *value5 + *(short *)(value + 0x3c);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

