#include "tarzan_ghidra_types.hpp"

// Address: 0x00436170
// Label: CEntities::InitPlayerSceneCopyForFatalSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitPlayerSceneCopyForFatalSequence(int entry)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    entry3 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(ushort *)(entry2 + 0xe) = *(ushort *)(entry2 + 0xe) & 0x7fff;
    ((EntitySceneObject *)entry2)->worldObject = entry3;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

