#include "tarzan_ghidra_types.hpp"

// Address: 0x00492D40
// Label: CEntities::InitTutorialPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::InitTutorialPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  uint value3;
  
  value3 = 0;
  if ('\x01' < *( undefined1 *)((int)&g_LevelTransitionContext + 1)) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  _g_TutorialPickupInitResetFlag = 0;
  if (entity->descriptor != 0) {
    value3 = (uint)*(ushort *)(entity->descriptor + 0x14);
  }
  *(uint *)(entry + 0x4c) = value3;
  value = entity->sceneObjects;
  *(undefined4 *)(entry + 0x50) = 0;
  *(undefined2 *)(entry + 0x48) = 1;
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (value != 0) {
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined4 *)(value + 0x40) = 0xc0;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x340;
    *(undefined2 *)(value + 0xc) = 0x2011;
    *(undefined4 *)(value + 0xb4) = 1;
    *(undefined4 *)(value + 0xa8) = 0xc00;
    *(undefined4 *)(value + 0xac) = 0xc00;
    *(undefined4 *)(value + 0xb0) = 0xc00;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

