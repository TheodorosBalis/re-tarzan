#include "tarzan_ghidra_types.hpp"

// Address: 0x00488720
// Label: TrashingTheCamp::InitFallingCampDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitFallingCampDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = g_CurrentWorldSceneContext;
    CEntities::CreateRuntimeMotionStateAttachment(entry);
    *(undefined1 *)(value + 0x74) = 1;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

