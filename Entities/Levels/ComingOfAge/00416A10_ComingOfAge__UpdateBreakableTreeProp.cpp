#include "tarzan_ghidra_types.hpp"

// Address: 0x00416A10
// Label: ComingOfAge::UpdateBreakableTreeProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBreakableTreeProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if ((value != 0) && (g_EntityHitResponseScratch != '\0')) {
    ComingOfAge::SpawnBreakableTreeDebris(value);
    PlayAudioById(0xce,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  return;
}

