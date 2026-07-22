#include "tarzan_ghidra_types.hpp"

// Address: 0x00430E80
// Label: CEntities::UpdateSmashableDustEmitter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSmashableDustEmitter(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 value2;
  int value;
  
  value = *(int *)(entry + 0x50) + -1;
  *(int *)(entry + 0x50) = value;
  if (value < 1) {
    value = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value;
    if (value < 1) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value = RandomModulo(0x100,0x13,0x11);
    value = RandomModulo(0x100,value + -0x80 + *(int *)(entity->sceneObjects + 0x1c));
    value = RandomModulo(0x100,value + -0x80 + *(int *)(entity->sceneObjects + 0x18));
    value = CEntities::SpawnEntityByTypeAtPosition
                      (value + -0x80 + *(int *)(entity->sceneObjects + 0x14));
    if (value == 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value2 = RandomModulo(5);
    *(undefined4 *)(entry + 0x50) = value2;
  }
  return;
}

