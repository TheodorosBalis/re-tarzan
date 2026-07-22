#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E470
// Label: SaborAttacks::InitPrickle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitPrickle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    CreateEntityEntitySceneObjectFromSourceRef(value);
    *(undefined2 *)(entry + 0x48) = 0;
    if (entity->descriptor != 0) {
      *(undefined4 *)(entry + 0x4c) =
           *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
    }
  }
  return;
}

