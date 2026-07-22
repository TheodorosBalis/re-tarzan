#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FFC0
// Label: CEntities::MoveEntityForwardOnSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntityForwardOnSurface(int entry,uint sceneObject)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    if (*(char *)(entry2 + 0x75) != '\0') {
      sceneObject = ~sceneObject + 1;
    }
    CEntities::MoveEntitySceneObjectAlongJungleSurface(entry2,sceneObject);
  }
  return;
}

