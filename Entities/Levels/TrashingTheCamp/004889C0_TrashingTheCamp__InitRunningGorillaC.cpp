#include "tarzan_ghidra_types.hpp"

// Address: 0x004889C0
// Label: TrashingTheCamp::InitRunningGorillaC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitRunningGorillaC(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3398;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    value = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TrashingTheCampRunningGorillaCScriptDesc);
    if (value != 0) {
      CEntities::SelectScriptAttachmentSequence(value,1);
    }
    *(undefined2 *)(entry + 0x48) = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

