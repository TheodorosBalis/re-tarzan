#include "tarzan_ghidra_types.hpp"

// Address: 0x00493430
// Label: WelcomeToTheJungle::InitTutorialCameraAnchor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::InitTutorialCameraAnchor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
    ((EntitySceneObject *)value)->worldObject = value2;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

