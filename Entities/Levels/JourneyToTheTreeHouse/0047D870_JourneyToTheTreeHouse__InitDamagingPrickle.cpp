#include "tarzan_ghidra_types.hpp"

// Address: 0x0047D870
// Label: JourneyToTheTreeHouse::InitDamagingPrickle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitDamagingPrickle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2005;
    ((EntitySceneObject *)value)->worldObject = value2;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

