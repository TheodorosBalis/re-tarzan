#include "tarzan_ghidra_types.hpp"

// Address: 0x00442870
// Label: CEntities::IsPointInsideLocalAttachmentBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CEntities::IsPointInsideLocalAttachmentBounds(int *entry,short *sceneObject)

{
  short *value;
  
  if (((((int)*sceneObject <= *entry) && (*entry <= (int)sceneObject[3])) &&
      ((int)sceneObject[4] <= entry[1])) &&
     ((entry[1] <= (int)sceneObject[1] && ((int)sceneObject[2] <= entry[2])))) {
    value = sceneObject + 5;
    sceneObject = (short *)(int)*value;
    if (entry[2] <= (int)sceneObject) {
      return CONCAT31((int3)(char)((ushort)*value >> 8),1);
    }
  }
  return (uint)sceneObject & 0xffffff00;
}

