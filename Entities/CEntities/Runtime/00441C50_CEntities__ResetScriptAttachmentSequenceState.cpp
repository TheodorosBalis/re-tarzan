#include "tarzan_ghidra_types.hpp"

// Address: 0x00441C50
// Label: CEntities::ResetScriptAttachmentSequenceState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ResetScriptAttachmentSequenceState(int entry,short sceneObject)

{
  Entity *entity = (Entity *)entry;
  if (*(int *)(entry + 0x24) != 0) {
    *(short *)(entry + 0x2c) = sceneObject;
    *(undefined4 *)(entry + 0x20) = *(undefined4 *)(*(int *)(entry + 0x24) + sceneObject * 4);
  }
  *(undefined2 *)(entry + 0x2a) = 0;
  *(undefined2 *)(entry + 0x28) = 0xffff;
  return;
}

