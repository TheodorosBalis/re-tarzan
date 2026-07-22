#include "tarzan_ghidra_types.hpp"

// Address: 0x00467260
// Label: TarzanToTheRescue::UpdateSinkingScriptedProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateSinkingScriptedProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  
  intCursor = (int *)(entity->sceneObjects + 0x30);
  *intCursor = *intCursor - *(int *)(entry + 0x4c);
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (*(int *)(entity->sceneObjects + 0x30) < 0) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  return;
}

