#include "tarzan_ghidra_types.hpp"

// Address: 0x00461480
// Label: TarzanToTheRescue::InitBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined2 value3;
  int value2;
  
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2002;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x44,0x10000016);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0x30) = 0;
    *(undefined2 *)(entry + 0x48) = 0;
    if (entity->descriptor != 0) {
      value = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value + 4) == 1) {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2005;
        *(undefined4 *)(value2 + 0x30) = 1;
      }
      if (*(int *)(value + 4) == 2) {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2016;
        *(undefined4 *)(value2 + 0x30) = 2;
      }
      if (*(int *)(value + 4) == 3) {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2028;
        *(undefined4 *)(value2 + 0x30) = 3;
      }
      if (*(int *)(value + 8) == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
      if (*(int *)(value + 8) == 1) {
        *(undefined2 *)(entry + 0x48) = 1;
      }
      if (*(int *)(value + 8) == 2) {
        *(undefined2 *)(entry + 0x48) = 2;
      }
      if (*(int *)(value + 8) == 3) {
        *(undefined2 *)(entry + 0x48) = 3;
      }
      if (*(int *)(value + 8) == 4) {
        *(undefined2 *)(entry + 0x48) = 4;
      }
    }
    *(undefined4 *)(value2 + 0xc) = 7;
    *(undefined4 *)(value2 + 0x10) = 0;
    *(undefined4 *)(value2 + 0x14) = 0;
    *(undefined4 *)(value2 + 0x18) = 0;
    *(undefined4 *)(value2 + 0x1c) = 2;
    value3 = RandomModulo(0x1000);
    *(undefined2 *)(entity->sceneObjects + 0xa2) = value3;
    *(undefined4 *)(value2 + 0x20) = 0;
    *(int *)(value2 + 0x24) = (int)*(short *)(entity->sceneObjects + 0xa2);
    *(undefined4 *)(value2 + 0x28) = 0;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

