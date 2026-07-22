#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E4E0
// Label: CEntities::IsEntityVectorMostlyPositiveZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::IsEntityVectorMostlyPositiveZ(int entry,int sceneObject)

{
  Entity *entity2 = (Entity *)sceneObject;
  Entity *entity = (Entity *)entry;
  uint value;
  
  value = GetAngleFromXZVector12Bit
                    (*(int *)(entity->sceneObjects + 0x14) -
                     *(int *)(entity2->sceneObjects + 0x14),
                     *(int *)(entity->sceneObjects + 0x1c) -
                     *(int *)(entity2->sceneObjects + 0x1c));
  if ((value & 0xfff) < 0x400) {
    return true;
  }
  return 0xc00 < (value & 0xfff);
}

