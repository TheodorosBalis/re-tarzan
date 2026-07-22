#include "tarzan_ghidra_types.hpp"

// Address: 0x00430710
// Label: CEntities::ComputeEntitySceneObjectDataDistance3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ComputeEntitySceneObjectDataDistance3D(int entry,int sceneObject)

{
  ComputeDistance3D(*(undefined4 *)(entry + 8),*(undefined4 *)(entry + 0xc),
                    *(undefined4 *)(entry + 0x10),*(undefined4 *)(sceneObject + 8),
                    *(undefined4 *)(sceneObject + 0xc),*(undefined4 *)(sceneObject + 0x10));
  return 0;
}

