#include "tarzan_ghidra_types.hpp"

// Address: 0x004831B0
// Label: TerkLeafSwimming::InitFloatingObstacleB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::InitFloatingObstacleB(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort value2;
  int value;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x60,0x10000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0;
    *(int *)(entity->sceneObjects + 0x18) = *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x80
    ;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2490;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x2000;
    *(undefined4 *)(entity->sceneObjects + 0xac) = 0x2000;
    *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x2000;
    *(undefined4 *)(value + 0x38) = 0;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050e450);
    if (value != 0) {
      value2 = RandomModulo(0x80);
      *(ushort *)(value + 0x16) = value2 & 7;
    }
  }
  return;
}

