#include "tarzan_ghidra_types.hpp"

// Address: 0x0040BFD0
// Label: CampsiteCommotion::InitSackOnPlank
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitSackOnPlank(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_CurrentWorldSceneContext;
    *(undefined2 *)(value + 0xc) = 0x2002;
    ((EntitySceneObject *)value)->roll = 1;
    CEntities::CreateRuntimeMotionStateAttachment(entry);
    *(undefined2 *)(entry + 0x48) = 1;
    CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

