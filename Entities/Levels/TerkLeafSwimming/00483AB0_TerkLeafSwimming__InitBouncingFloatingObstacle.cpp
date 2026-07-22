#include "tarzan_ghidra_types.hpp"

// Address: 0x00483AB0
// Label: TerkLeafSwimming::InitBouncingFloatingObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::InitBouncingFloatingObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value4;
  undefined4 value3;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x12b0;
    value4 = (byte *)(entity->sceneObjects + 0xf);
    *value4 = *value4 | 4;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0x1000;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 2;
    value3 = *(undefined4 *)(entity->sceneObjects + 0x18);
    *(undefined4 *)(value + 0x14) = 0;
    *(undefined4 *)(value + 0x10) = value3;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0xff1d;
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050e690);
    *(int *)(value + 0x18) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
    if (value != 0) {
      *(undefined4 *)(value + 0xc) = 2;
      *(undefined4 *)(value + 0x18) = 0x1e;
      *(undefined4 *)(value + 0x2c) = 1;
      *(undefined4 *)(value + 0x10) = 0;
      *(int *)(value + 0x40) =
           -((short)(&g_SinCosTable12Bit)
                    [*(ushort *)(entity->sceneObjects + 0xa2) - 0x400 & 0xfff] * 10 >> 0xc);
      *(int *)(value + 0x44) =
           -((short)(&g_SinCosTable12Bit)[*(ushort *)(entity->sceneObjects + 0xa2) & 0xfff] * 10
            >> 0xc);
      *(int *)(value + 0x24) = *(int *)(entity->sceneObjects + 0x18) + 200;
    }
  }
  return;
}

