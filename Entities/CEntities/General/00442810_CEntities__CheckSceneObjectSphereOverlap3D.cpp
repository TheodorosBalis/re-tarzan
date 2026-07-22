#include "tarzan_ghidra_types.hpp"

// Address: 0x00442810
// Label: CEntities::CheckSceneObjectSphereOverlap3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::CheckSceneObjectSphereOverlap3D(int entry5,int *sceneObject,int attachment,int *flags)

{
  int entry;
  int entry2;
  int entry3;
  int entry4;
  
  entry = *(int *)(entry5 + 0x14) - *(int *)(attachment + 0x14);
  entry4 = *(int *)(entry5 + 0x1c) - *(int *)(attachment + 0x1c);
  entry3 = *(int *)(entry5 + 0x18) - *(int *)(attachment + 0x18);
  entry2 = *flags * *flags;
  return CONCAT31((int3)((uint)entry2 >> 8),
                  entry4 * entry4 + entry3 * entry3 + entry * entry < *sceneObject * *sceneObject + entry2);
}

