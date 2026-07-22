#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C9B0
// Label: CEntities::InitDustPuff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitDustPuff(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_DustPuffScriptDesc);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) | 0x1421;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

