#include "tarzan_ghidra_types.hpp"

// Address: 0x00485780
// Label: TrashingTheCamp::InitAmbientBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitAmbientBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined2 value3;
  int value2;
  uint value4;
  undefined *dataCursor;
  
  if (entity->descriptor != 0) {
    if ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 1) == 0) {
      *(undefined2 *)(entry + 0x4a) = 0;
    }
    else {
      *(undefined2 *)(entry + 0x4a) = 1;
    }
  }
  value = entity->sceneObjects;
  *(undefined4 *)(entry + 0x50) = 0;
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (value == 0) {
    return;
  }
  ((EntitySceneObject *)value)->roll = 1;
  *(undefined2 *)(value + 0x140) = 0;
  ((EntitySceneObject *)value)->worldObject = value2 + 0x6e8;
  g_TrashingTheCampAmbientBirdVariantCounter = g_TrashingTheCampAmbientBirdVariantCounter + 1;
  if ((*(byte *)(entry + 0x4a) & 1) == 0) {
    value4 = g_TrashingTheCampAmbientBirdVariantCounter & 0x80000003;
    if ((int)value4 < 0) {
      value4 = (value4 - 1 | 0xfffffffc) + 1;
    }
    if (value4 != 0) {
      if (value4 == 1) {
        dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_B;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
      }
      else {
        if (value4 == 2) {
          dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_A;
          ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
          goto LAB_004858d7;
        }
        dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_A;
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
      }
LAB_0048583a:
      value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
      *(undefined4 *)(value + 0x70) = 2;
      goto LAB_004858e8;
    }
    dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_B;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
  }
  else {
    if ((int)g_TrashingTheCampAmbientBirdVariantCounter % 3 != 0) {
      if ((int)g_TrashingTheCampAmbientBirdVariantCounter % 3 != 1) {
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
        value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050ed88);
        *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
        *(undefined4 *)(value + 0x70) = 3;
        goto LAB_004858e8;
      }
      dataCursor = &DAT_0050ed88;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
      goto LAB_0048583a;
    }
    dataCursor = &DAT_0050ed88;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
  }
LAB_004858d7:
  value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
  *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0xfdff;
LAB_004858e8:
  if (value2 != 0) {
    value3 = RandomModulo(9);
    *(undefined2 *)(value2 + 0x16) = value3;
  }
  return;
}

