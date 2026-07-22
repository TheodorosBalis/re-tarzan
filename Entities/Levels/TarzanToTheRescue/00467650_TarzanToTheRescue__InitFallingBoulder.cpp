#include "tarzan_ghidra_types.hpp"

// Address: 0x00467650
// Label: TarzanToTheRescue::InitFallingBoulder
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitFallingBoulder(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  int value2;
  int value3;
  undefined4 value4;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x90,0x10000000);
  if (value2 == 0) {
    return;
  }
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor | 0x1421;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2020;
  if (entity->descriptor != 0) {
    *(undefined4 *)(value2 + 0x20) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
  }
  value3 = RandomModulo(3);
  if (value3 == 0) {
    value4 = 0x3c9;
  }
  else if (value3 == 1) {
    value4 = 0x3ca;
  }
  else {
    if (value3 != 2) goto LAB_004676e1;
    value4 = 0x3cb;
  }
  PlayAudioById(value4,(int *)0,(undefined4 *)0);
LAB_004676e1:
  *(undefined4 *)(value2 + 0x30) = 1;
  *(undefined4 *)(value2 + 0x3c) = 0x4b;
  *(undefined4 *)(value2 + 0x34) = 0;
  *(undefined4 *)(value2 + 0x68) = 0;
  if (*(int *)(value2 + 0x20) == 0) {
    *(undefined4 *)(value2 + 100) = 0xffffffba;
  }
  if (*(int *)(value2 + 0x20) == 1) {
    *(undefined4 *)(value2 + 100) = 0x46;
  }
  *(undefined4 *)(value2 + 0x50) = 0;
  *(undefined4 *)(value2 + 0x48) = 0x7fff;
  *(undefined4 *)(value2 + 0x14) = 8;
  value3 = CreateEntityEntitySceneObject((uint *)entry,4);
  if (value3 != 0) {
    *(int *)(value2 + 0x10) = value3;
    value = entity->sceneObjects;
    *(undefined4 *)(value3 + 0x14) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value3 + 0x18) = ((EntitySceneObject *)value)->y;
    *(undefined4 *)(value3 + 0x1c) = ((EntitySceneObject *)value)->z;
    *(int *)(value3 + 0x6c) = *(int *)(value3 + 0x6c) + -0x200;
    value = g_WorldEntitySceneObjectArrayBase;
    *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) | 0x1421;
    *(int *)(value3 + 0x10) = value + 0x2630;
    *(undefined2 *)(value3 + 0xc) = 0x201f;
    *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(entity->sceneObjects + 0x18);
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined4 *)(value2 + 0x1c) = 0;
    *(undefined4 *)(value2 + 0x84) = *(undefined4 *)(entity->sceneObjects + 0x14);
    *(int *)(value2 + 0x88) = *(int *)(entity->sceneObjects + 0x18) + -0x5dc;
    value4 = *(undefined4 *)(entity->sceneObjects + 0x1c);
    *(undefined4 *)(value2 + 0x14) = 0;
    *(undefined4 *)(value2 + 0x8c) = value4;
    CEntities::AdvanceBounceMotionAndReturnImpact(entity->sceneObjects,value2 + 0x24);
  }
  return;
}

