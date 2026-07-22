#include "tarzan_ghidra_types.hpp"

// Address: 0x004428C0
// Label: CEntities::DoWorldSpheresOverlap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::DoWorldSpheresOverlap(int *entry,int sceneObject,int *attachment,int flags)

{
  int value;
  
  value = *entry - *attachment;
  return CONCAT31((int3)((uint)value >> 8),
                  (entry[2] - attachment[2]) * (entry[2] - attachment[2]) +
                  (entry[1] - attachment[1]) * (entry[1] - attachment[1]) + value * value <=
                  (flags + sceneObject) * (flags + sceneObject));
}

