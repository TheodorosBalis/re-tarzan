#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BA30
// Label: CEntities::InitThrowableImpactEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitThrowableImpactEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ThrowableImpactEffectScriptDesc);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    *(undefined2 *)(entry + 0x48) = 4;
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) | 0x1421;
    ((EntitySceneObject *)value)->roll = 3;
    *(undefined4 *)(value + 0x6c) = 0xffffff80;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

