#include "tarzan_ghidra_types.hpp"

// Address: 0x00427FB0
// Label: ElephantHairDare::SpawnTokenOnWaterCollectionEffects
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::SpawnTokenOnWaterCollectionEffects
               (undefined4 entry,undefined4 sceneObject,undefined4 attachment,int flags)

{
  int value;
  
  value = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x7d,0x11);
  if (value != 0) {
    *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2000;
  }
  value = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x7e,0x11);
  if (value != 0) {
    *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2000;
  }
  if (0 < flags) {
    do {
      value = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,0x7f,0x11);
      if (value != 0) {
        *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2001;
        value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
        if ((value != 0) && (*(int *)(value + 0xc) != 0)) {
          *(undefined2 *)(*(int *)(*(int *)(value + 0xc) + 0x38) + 0xc) = 0x2000;
        }
      }
      flags = flags + -1;
    } while (flags != 0);
  }
  return;
}

