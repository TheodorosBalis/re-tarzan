#include "tarzan_ghidra_types.hpp"

// Address: 0x00430E30
// Label: CEntities::SpawnSmashableDustEmitter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::SpawnSmashableDustEmitter(undefined4 entry,undefined4 sceneObject,undefined4 attachment)

{
  int value;
  int value2;
  undefined4 value3;
  
  value = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x1d,0x11);
  if (value == 0) {
    return 1;
  }
  value2 = RandomModulo(6);
  *(int *)(value + 0x4c) = value2 + 6;
  value3 = RandomModulo(5);
  *(undefined4 *)(value + 0x50) = value3;
  return 0;
}

