#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BA90
// Label: CEntities::UpdateThrowableImpactEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateThrowableImpactEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  
  if (entity->sceneObjects != 0) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

