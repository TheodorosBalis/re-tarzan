#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E260
// Label: JourneyToTheTreeHouse::InitRewardFlowerPetal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitRewardFlowerPetal(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  ((EntitySceneObject *)value2)->worldObject = g_CurrentWorldSceneContext;
  *(undefined2 *)(value2 + 0xc) = 0x2012;
  ((EntitySceneObject *)value2)->roll = 0;
  *(undefined4 *)(value2 + 0xb4) = 1;
  value = RandomModulo(0x1000);
  value = value + 0x1000;
  *(int *)(value2 + 0xb0) = value;
  *(int *)(value2 + 0xac) = value;
  *(int *)(value2 + 0xa8) = value;
  value2 = RandomModulo(0xb4);
  *(int *)(entry + 0x50) = value2 + -0x5a;
  value2 = RandomModulo(0xb4);
  *(int *)(entry + 0x4c) = value2 + -0x5a;
  return;
}

