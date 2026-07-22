#include "tarzan_ghidra_types.hpp"

// Address: 0x00457680
// Label: Stampede::InitTreeFragmentImpactObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitTreeFragmentImpactObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x8c,0x10000000);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0xc) = 0;
    *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2003;
    value3 = CreateEntityEntitySceneObject((uint *)entry,4);
    if (value3 != 0) {
      *(int *)(value2 + 0x70) = value3;
      *(undefined2 *)(value3 + 0xa6) = 0;
      value = g_WorldEntitySceneObjectArrayBase;
      *(undefined2 *)(value3 + 0xc) = 0x2027;
      *(int *)(value3 + 0x10) = value + 0x30c0;
      *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) & 0x7fff;
      *(undefined4 *)(value2 + 0x1c) = 3;
      *(undefined4 *)(value2 + 0x60) = 0x78;
      *(undefined4 *)(value2 + 0x20) = 0;
      *(undefined4 *)(value2 + 0x34) = 0x7fff;
      *(undefined4 *)(value2 + 0x74) = *(undefined4 *)(entity->sceneObjects + 0x14);
      *(int *)(value2 + 0x78) = *(int *)(entity->sceneObjects + 0x18) + -0x200;
      *(undefined4 *)(value2 + 0x7c) = *(undefined4 *)(entity->sceneObjects + 0x1c);
    }
  }
  return;
}

