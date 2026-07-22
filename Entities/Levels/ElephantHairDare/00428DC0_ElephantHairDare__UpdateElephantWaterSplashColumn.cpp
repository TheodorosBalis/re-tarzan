#include "tarzan_ghidra_types.hpp"

// Address: 0x00428DC0
// Label: ElephantHairDare::UpdateElephantWaterSplashColumn
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateElephantWaterSplashColumn(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  uint value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(value + 0xc) == 0) {
      value2 = ((int)(short)(&g_SinCosTable12Bit)[*(int *)(value + 0x10) - 0x400U & 0xfff] << 0xc) >>
              0x1f;
      *(uint *)(entity->sceneObjects + 0xac) =
           (((int)(short)(&g_SinCosTable12Bit)[*(int *)(value + 0x10) - 0x400U & 0xfff] << 0xc) >>
            0xc ^ value2) - value2;
      if (*(int *)(entity->sceneObjects + 0xac) == 0x1000) {
        *(undefined4 *)(value + 0xc) = 1;
      }
      *(uint *)(value + 0x10) = *(int *)(value + 0x10) + 0x80U & 0xfff;
    }
    else if (*(int *)(value + 0xc) == 1) {
      *(int *)(entity->sceneObjects + 0xac) = *(int *)(entity->sceneObjects + 0xac) + -0x80;
      *(int *)(entity->sceneObjects + 0xa8) = *(int *)(entity->sceneObjects + 0xa8) + 0x80;
      *(int *)(entity->sceneObjects + 0xb0) = *(int *)(entity->sceneObjects + 0xb0) + 0x80;
      *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + -0x100
      ;
      if (*(int *)(entity->sceneObjects + 0xac) < 0) {
        *(undefined4 *)(entity->sceneObjects + 0xac) = 0;
      }
      if (0x2000 < *(int *)(entity->sceneObjects + 0xa8)) {
        *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x2000;
      }
      if (0x2000 < *(int *)(entity->sceneObjects + 0xb0)) {
        *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x2000;
      }
      if (*(int *)(entity->sceneObjects + 0x30) < 0) {
        *(undefined4 *)(entity->sceneObjects + 0x30) = 0;
        return;
      }
    }
  }
  return;
}

