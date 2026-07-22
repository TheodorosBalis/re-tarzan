#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C4E0
// Label: CampsiteCommotion::InitCampDamageHazard
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitCampDamageHazard(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0xc) = 0x5039;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

