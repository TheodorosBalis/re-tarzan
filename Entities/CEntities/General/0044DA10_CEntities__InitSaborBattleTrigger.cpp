#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DA10
// Label: CEntities::InitSaborBattleTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSaborBattleTrigger(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  SaborBattleResourceHookStubA();
  SaborBattleResourceHookStubB();
  g_SaborBattleGroundY = ((EntitySceneObject *)value)->y;
  value2 = g_WorldEntitySceneObjectArrayBase + 0x11e0;
  *(undefined2 *)(value + 0xc) = 0x19e;
  ((EntitySceneObject *)value)->worldObject = value2;
  ((EntitySceneObject *)value)->roll = 0;
  *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
  return;
}

