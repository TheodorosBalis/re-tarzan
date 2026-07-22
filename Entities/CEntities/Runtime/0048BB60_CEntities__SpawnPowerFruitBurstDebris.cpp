#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BB60
// Label: CEntities::SpawnPowerFruitBurstDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SpawnPowerFruitBurstDebris(int entry,int sceneObject)

{
  Entity *entity2 = (Entity *)sceneObject;
  undefined1 value6;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value = entry;
  value2 = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(entry + 0x14),*(int *)(entry + 0x18) + -0x60,
                     *(undefined4 *)(entry + 0x1c),0x13,0x11);
  if ((value2 != 0) && (value2 = *(int *)(value2 + 0x38), value2 != 0)) {
    *(undefined4 *)(value2 + 0x20) = 0x1000;
    *(undefined4 *)(value2 + 0x24) = 0x800;
    *(undefined4 *)(value2 + 0x28) = 0x800;
    *(undefined4 *)(value2 + 0x30) = 0;
  }
  PlayAudioById(0xc1,(int *)0,(undefined4 *)entry + 0x14);
  entry = 5;
  do {
    value3 = CEntities::SpawnEntityByTypeAtPosition
                      (*(undefined4 *)(value + 0x14),*(undefined4 *)(value + 0x18),
                       *(undefined4 *)(value + 0x1c),0x11,0x11);
    value2 = g_WorldEntitySceneObjectArrayBase;
    if (value3 != 0) {
      value4 = *(int *)(value3 + 0x38);
      if (value4 != 0) {
        *(undefined2 *)(value4 + 0xc) = 0x202d;
        *(undefined2 *)(value4 + 0xa6) = 0;
        *(int *)(value4 + 0x10) = value2 + 0x3a8;
        *(undefined4 *)(value4 + 0x110) = *(undefined4 *)(value + 0x110);
        *(undefined4 *)(value4 + 0x10c) = *(undefined4 *)(value + 0x10c);
        *(undefined4 *)(value4 + 0x108) = *(undefined4 *)(value + 0x108);
        *(uint *)(value4 + 0x13c) = *(uint *)(value4 + 0x13c) | 1;
        value6 = *(undefined1 *)(value + 0x75);
        *(byte *)(value4 + 0xe) = *(byte *)(value4 + 0xe) | 0x10;
        *(undefined1 *)(value4 + 0x75) = value6;
        *(undefined4 *)(value4 + 0x40) = 0xffffffe0;
        *(undefined1 *)(value4 + 0x74) = 0x3f;
        value2 = CEntities::CreateRuntimeMotionStateAttachment(value3);
        if (value2 != 0) {
          *(undefined4 *)(value2 + 0x10) = entity2->next;
          *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(sceneObject + 0x1c);
          *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(sceneObject + 0x14);
          *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(sceneObject + 0x18);
          value4 = RandomModulo(0x20);
          *(int *)(value2 + 0x20) = value4 + 0x10 + *(int *)(sceneObject + 0x20);
          *(undefined4 *)(value2 + 0x2c) = *(undefined4 *)(sceneObject + 0x2c);
          value4 = RandomModulo(2);
          *(char *)(value2 + 0xd) = -(value4 != 0);
          if (-(value4 != 0) == '\0') {
            value5 = RandomModulo(4);
            value4 = *(int *)(sceneObject + 0x24);
            *(undefined4 *)(value2 + 0x28) = 0;
            *(int *)(value2 + 0x24) = value5 + 2 + value4;
          }
          else {
            *(undefined4 *)(value2 + 0x24) = 0;
            value4 = RandomModulo(4);
            *(int *)(value2 + 0x28) = value4 + 2 + *(int *)(sceneObject + 0x28);
          }
        }
      }
      *(undefined2 *)(value3 + 0x48) = 2;
      CEntities::LinkEntityIntoProcessingList(&g_ActiveThrowableEntityList,value3);
    }
    entry = entry + -1;
  } while (entry != 0);
  return;
}

