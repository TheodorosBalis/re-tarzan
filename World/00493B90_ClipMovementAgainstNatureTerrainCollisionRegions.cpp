#include "tarzan_ghidra_types.hpp"

// Address: 0x00493B90
// Label: ClipMovementAgainstNatureTerrainCollisionRegions
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ClipMovementAgainstNatureTerrainCollisionRegions
               (int arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4,
               undefined4 arg5)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  arg1 = arg1 + 0x3c;
  while( true ) {
    if (value2 == 0) {
      return;
    }
    value2 = value2 + -1;
    value = ClipMovementAgainstNatureTerrainRegionPlane(arg1,arg2,arg3,arg4,arg5);
    if (value != 0) break;
    arg1 = arg1 + 0x38;
  }
  return;
}

