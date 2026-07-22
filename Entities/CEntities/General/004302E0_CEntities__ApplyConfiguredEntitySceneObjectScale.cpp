#include "tarzan_ghidra_types.hpp"

// Address: 0x004302E0
// Label: CEntities::ApplyConfiguredEntitySceneObjectScale
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ApplyConfiguredEntitySceneObjectScale(int entry,int sceneObject)

{
  if (sceneObject != 0) {
    sceneObject = sceneObject << 4;
    *(undefined4 *)(entry + 0xb4) = 1;
    *(int *)(entry + 0xb0) = sceneObject;
    *(int *)(entry + 0xac) = sceneObject;
    *(int *)(entry + 0xa8) = sceneObject;
  }
  return;
}

