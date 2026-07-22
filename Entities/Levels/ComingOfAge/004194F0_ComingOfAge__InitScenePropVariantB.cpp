#include "tarzan_ghidra_types.hpp"

// Address: 0x004194F0
// Label: ComingOfAge::InitScenePropVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitScenePropVariantB(int entry3)

{
  Entity *entity = (Entity *)entry3;
  short shortValue;
  int entry;
  int entry2;
  
  entry = entity->sceneObjects;
  entry2 = *(int *)(entity->descriptor + 0x10);
  if (entry != 0) {
    ((EntitySceneObject *)entry)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xb60;
    CEntities::AcquireEntitySceneObjectResourceSet(entry);
    *(ushort *)(entry + 0xe) = *(ushort *)(entry + 0xe) & 0x7fff;
    *(undefined4 *)(entry3 + 0x4c) = 0;
    shortValue = *(short *)(entry2 + 0xc);
    *(short *)(entry3 + 0x4a) = shortValue;
    if (shortValue == 0) {
      *(undefined2 *)(entry3 + 0x4a) = 0x3c;
    }
    entry = *(int *)(entry2 + 0x10);
    *(int *)(entry3 + 0x50) = entry;
    if (entry == 0) {
      *(undefined4 *)(entry3 + 0x50) = 0x3c;
    }
  }
  return;
}

