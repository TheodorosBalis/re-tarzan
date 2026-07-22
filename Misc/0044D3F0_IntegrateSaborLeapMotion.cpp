#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D3F0
// Label: IntegrateSaborLeapMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void IntegrateSaborLeapMotion(int arg1,int arg2)

{
  Entity *entity2 = (Entity *)arg2;
  *(int *)(arg2 + 0x20) = *(int *)(arg2 + 0x20) + 6;
  *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + entity2->next;
  *(int *)(arg1 + 0x18) = *(int *)(arg1 + 0x18) + *(int *)(arg2 + 0x20);
  *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + *(int *)(arg2 + 0x30);
  return;
}

