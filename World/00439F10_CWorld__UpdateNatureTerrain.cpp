#include "tarzan_ghidra_types.hpp"

// Address: 0x00439F10
// Label: CWorld::UpdateNatureTerrain
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::UpdateNatureTerrain(int *entry,undefined4 sceneObject)

{
  if ((*(byte *)(entry + 5) & 2) != 0) {
    CollectNatureTerrainEntitySceneObjects(entry,sceneObject);
  }
  UpdateEntitySceneObjectAnimations(*entry + 0x10);
  return;
}

