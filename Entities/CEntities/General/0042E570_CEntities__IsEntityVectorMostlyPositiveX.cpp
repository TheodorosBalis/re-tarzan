#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E570
// Label: CEntities::IsEntityVectorMostlyPositiveX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::IsEntityVectorMostlyPositiveX(int entry,int sceneObject)

{
  Entity *entity2 = (Entity *)sceneObject;
  Entity *entity = (Entity *)entry;
  int entry2;
  uint value;
  
  entry2 = GetAngleFromXZVector12Bit
                    (*(int *)(entity->sceneObjects + 0x14) -
                     *(int *)(entity2->sceneObjects + 0x14),
                     *(int *)(entity->sceneObjects + 0x1c) -
                     *(int *)(entity2->sceneObjects + 0x1c));
  value = entry2 + 0x400U & 0xfff;
  if (value < 0x400) {
    return true;
  }
  return 0xc00 < value;
}

