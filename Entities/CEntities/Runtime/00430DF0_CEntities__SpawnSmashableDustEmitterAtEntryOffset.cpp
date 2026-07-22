#include "tarzan_ghidra_types.hpp"

// Address: 0x00430DF0
// Label: CEntities::SpawnSmashableDustEmitterAtEntryOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::SpawnSmashableDustEmitterAtEntryOffset(int entry,int sceneObject,int attachment,int flags)

{
  Entity *entity = (Entity *)entry;
  int offset;
  undefined4 value;
  
  offset = entity->sceneObjects;
  if (offset != 0) {
    value = CEntities::SpawnSmashableDustEmitter
                      (((EntitySceneObject *)offset)->x + sceneObject,((EntitySceneObject *)offset)->y + attachment,
                       ((EntitySceneObject *)offset)->z + flags);
    return value;
  }
  return 1;
}

