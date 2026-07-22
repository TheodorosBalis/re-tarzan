#include "tarzan_ghidra_types.hpp"

// Address: 0x004286A0
// Label: ElephantHairDare::InitCrocodile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitCrocodile(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  undefined4 value3;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x34,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0x28) = 0;
    if (entity->descriptor != 0) {
      *(undefined4 *)(value + 0x28) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
      ;
    }
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x13e8;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_ElephantHairDareCrocodileScriptDesc);
    *(int *)(value + 0x14) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    value2 = entity->sceneObjects;
    intCursor = (int *)(value + 0x1c);
    *intCursor = ((EntitySceneObject *)value2)->x;
    *(undefined4 *)(value + 0x20) = ((EntitySceneObject *)value2)->y;
    value3 = ((EntitySceneObject *)value2)->z;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x24) = value3;
    if (*(int *)(value + 0x28) == 0) {
      *(undefined4 *)(value + 0x18) = 0x400;
      *(undefined4 *)(value + 0x2c) = 0x300;
      *(int *)(entity->sceneObjects + 0x14) = (g_SinCosTable12Bit * 0x300 >> 0xc) + *intCursor;
      *(int *)(entity->sceneObjects + 0x1c) =
           ((int)(&g_SinCosTable12Bit)[*(uint *)(value + 0x18) & 0xfff] * *(int *)(value + 0x2c) >>
           0xc) + *(int *)(value + 0x24);
    }
    if (*(int *)(value + 0x28) == 1) {
      *(undefined4 *)(value + 0x18) = 0x928;
      *(undefined4 *)(value + 0x2c) = 0x400;
      *(int *)(entity->sceneObjects + 0x14) =
           (((int)g_LevelEntityInitScratch_Field05D8 << 10) >> 0xc) + *intCursor;
      *(int *)(entity->sceneObjects + 0x1c) =
           ((int)(&g_SinCosTable12Bit)[*(uint *)(value + 0x18) & 0xfff] * *(int *)(value + 0x2c) >>
           0xc) + *(int *)(value + 0x24);
    }
    if (*(int *)(value + 0x28) == 2) {
      *(undefined4 *)(value + 0x18) = 0x158;
      *(undefined4 *)(value + 0x2c) = 0x300;
      *(int *)(entity->sceneObjects + 0x14) =
           (g_LevelEntityInitScratch_Field1638 * 0x300 >> 0xc) + *intCursor;
      *(int *)(entity->sceneObjects + 0x1c) =
           ((int)(&g_SinCosTable12Bit)[*(uint *)(value + 0x18) & 0xfff] * *(int *)(value + 0x2c) >>
           0xc) + *(int *)(value + 0x24);
    }
  }
  return;
}

