#include "tarzan_ghidra_types.hpp"

// Address: 0x00457230
// Label: Stampede::InitTreeFragment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitTreeFragment(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  short shortValue2;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x1e8,0x10000000);
  if (value2 != 0) {
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff];
    shortValue2 = (&g_SinCosTable12Bit)
            [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x400U & 0xfff];
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2027;
    value5 = entity->sceneObjects;
    value = ((EntitySceneObject *)value5)->z;
    value3 = (((EntitySceneObject *)value5)->x - *(int *)(g_PlayerEntitySceneObject + 0x14)) +
            (shortValue2 * 0x890 >> 0xc);
    value4 = ((EntitySceneObject *)value5)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
    value5 = *(int *)(g_PlayerEntitySceneObject + 0x1c);
    *(undefined4 *)(value2 + 0x14) = 0x20;
    *(undefined4 *)(value2 + 0x1c) = 0;
    *(undefined4 *)(value2 + 0x2c) = 0;
    value5 = (value - value5) + (shortValue * 0x890 >> 0xc);
    *(undefined4 *)(value2 + 0x20) = 8;
    *(int *)(value2 + 0x18) = (int)(value3 + (value3 >> 0x1f & 0x1fU)) >> 5;
    *(int *)(value2 + 0x24) = (int)(value5 + (value5 >> 0x1f & 0x1fU)) >> 5;
    *(int *)(value2 + 0x28) = (int)(value4 + (value4 >> 0x1f & 0x1fU)) >> 5;
    value5 = *(int *)(entity->sceneObjects + 0x18);
    *(undefined4 *)(value2 + 0xc) = 7;
    *(int *)(value2 + 0x30) = value5 + 0x40;
    value5 = entity->sceneObjects;
    *(undefined4 *)(value2 + 0x3c) = ((EntitySceneObject *)value5)->x;
    *(undefined4 *)(value2 + 0x40) = ((EntitySceneObject *)value5)->y;
    *(undefined4 *)(value2 + 0x44) = ((EntitySceneObject *)value5)->z;
  }
  return;
}

