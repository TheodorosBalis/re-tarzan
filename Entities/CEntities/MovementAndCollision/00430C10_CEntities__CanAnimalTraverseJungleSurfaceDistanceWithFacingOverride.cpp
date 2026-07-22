#include "tarzan_ghidra_types.hpp"

// Address: 0x00430C10
// Label: CEntities::CanAnimalTraverseJungleSurfaceDistanceWithFacingOverride
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CanAnimalTraverseJungleSurfaceDistanceWithFacingOverride(undefined4 entry,int sceneObject,undefined4 attachment,undefined1 flags)

{
  undefined1 value;
  
  value = *(undefined1 *)(sceneObject + 0x75);
  *(undefined1 *)(sceneObject + 0x75) = flags;
  CEntities::CanAnimalTraverseJungleSurfaceDistance(entry,sceneObject,attachment);
  *(undefined1 *)(sceneObject + 0x75) = value;
  return 0;
}

