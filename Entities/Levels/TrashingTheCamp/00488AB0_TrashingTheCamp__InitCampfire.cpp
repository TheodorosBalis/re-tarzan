#include "tarzan_ghidra_types.hpp"

// Address: 0x00488AB0
// Label: TrashingTheCamp::InitCampfire
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitCampfire(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined4 *)(value + 0xb4) = 1;
    *(undefined4 *)(value + 0xa8) = 0x2000;
    *(undefined4 *)(value + 0xac) = 0x2000;
    *(undefined4 *)(value + 0xb0) = 0x2000;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

