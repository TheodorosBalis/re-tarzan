#include "tarzan_ghidra_types.hpp"

// Address: 0x00441BF0
// Label: CEntities::SelectScriptAttachmentSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SelectScriptAttachmentSequence(uint *entry,short sceneObject)

{
  if ((*entry & 0xff) == 1) {
    if (entry[4] != 0) {
      *(short *)(entry + 6) = sceneObject;
      entry[3] = *(uint *)(entry[4] + sceneObject * 4);
    }
    *(undefined2 *)((int)entry + 0x16) = 0;
    *(undefined2 *)(entry + 5) = 0xffff;
  }
  else if ((*entry & 0xff) == 2) {
    if (entry[4] != 0) {
      *(short *)(entry + 6) = sceneObject;
      entry[3] = *(uint *)(entry[4] + sceneObject * 4);
    }
    *(undefined2 *)((int)entry + 0x16) = 0xffff;
    *(undefined2 *)(entry + 5) = 0xffff;
    return;
  }
  return;
}

