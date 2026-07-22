#include "tarzan_ghidra_types.hpp"

// Address: 0x004681C0
// Label: TarzanToTheRescue::InitGorillaInTheBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::InitGorillaInTheBox(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value3;
  int value;
  int value2;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x84,0x10000000);
  if (value2 != 0) {
    value = *(int *)(entity->descriptor + 0x10);
    if (*(int *)(value + 4) == 0) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2023;
      *(undefined4 *)(value2 + 0x7c) = 0;
      *(undefined4 *)(value2 + 0x78) = 1;
    }
    if (*(int *)(value + 4) == 1) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2026;
      *(undefined4 *)(value2 + 0x7c) = 0x200;
      *(undefined4 *)(value2 + 0x78) = 0;
    }
    g_TarzanToTheRescueActiveElephantBarrier = entry;
    value3 = (byte *)(entity->sceneObjects + 0xf);
    *value3 = *value3 | 8;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined4 *)(value2 + 0x10) = 1;
    *(undefined4 *)(value2 + 0x40) = 1;
    *(undefined4 *)(value2 + 0xc) = 100;
    *(undefined4 *)(value2 + 0x20) = 10;
    *(undefined4 *)(value2 + 0x2c) = 0xffffffd8;
    *(undefined4 *)(value2 + 0x24) = 0;
    *(undefined4 *)(value2 + 0x54) = 0;
    *(undefined4 *)(value2 + 0x58) = 0;
    *(int *)(value2 + 0x38) = *(int *)(value2 + 0x7c) + -0x5ad;
    CEntities::AdvanceBounceMotionAndReturnImpact(entity->sceneObjects,value2 + 0x14);
    *(undefined4 *)(value2 + 0x80) = 0;
    _g_TarzanToTheRescueElephantBarrierPlayerDeltaXQuarter =
         *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14) >> 2
    ;
  }
  return;
}

