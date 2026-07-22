#include "tarzan_ghidra_types.hpp"

// Address: 0x00440330
// Label: CEntities::CreateEntityAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CreateEntityAttachment(undefined4 entry,undefined4 sceneObject,undefined4 attachment)

{
  CEntities::AllocEntityAttachment(entry,sceneObject,attachment,0);
  return 0;
}

