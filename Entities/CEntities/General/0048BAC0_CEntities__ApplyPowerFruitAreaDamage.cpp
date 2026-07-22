#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BAC0
// Label: CEntities::ApplyPowerFruitAreaDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ApplyPowerFruitAreaDamage(int entry)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int *intCursor;
  int value6;
  
  *(int *)(entry + 0x18) = *(int *)(entry + 0x18) + -0x60;
  PlayAudioById(0xc2,0,(int *)(entry + 0x14));
  value3 = 0;
  intCursor = g_LateEntityList;
  if (0 < *g_LateEntityList) {
    do {
      value = intCursor[value3 + 1];
      value3 = value3 + 1;
      for (value2 = *(int *)(value + 0x38); value2 != 0; value2 = *(int *)(value2 + 0x34)) {
        value4 = *(int *)(entry + 0x14) - *(int *)(value2 + 0x14);
        value5 = *(int *)(entry + 0x18) - *(int *)(value2 + 0x18);
        value6 = *(int *)(entry + 0x1c) - *(int *)(value2 + 0x1c);
        if (value6 * value6 + value5 * value5 + value4 * value4 < 0x1000000) {
          *(undefined2 *)(value + 0x3e) = 0xffff;
        }
        intCursor = g_LateEntityList;
      }
    } while (value3 < *intCursor);
  }
  return;
}

