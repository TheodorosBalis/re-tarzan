#include "tarzan_ghidra_types.hpp"

// Address: 0x0047DD80
// Label: JourneyToTheTreeHouse::InitBat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitBat(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  undefined *dataCursor;
  
  value3 = 0;
  value2 = entity->sceneObjects;
  if (value2 == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  ((EntitySceneObject *)value2)->worldObject = 0;
  value = entity->descriptor;
  if (value != 0) {
    *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(*(int *)(value + 0x10) + 2);
    value3 = *(int *)(value + 0x10);
    if (value3 != 0) {
      if (*(int *)(value3 + 0x10) == 0) {
        dataCursor = &g_JourneyToTheTreeHouseBatScriptDescA;
        ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2768;
      }
      else {
        if (*(int *)(value3 + 0x10) != 1) goto LAB_0047ddee;
        dataCursor = &g_JourneyToTheTreeHouseBatScriptDescB;
        ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xbc8;
      }
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    }
  }
LAB_0047ddee:
  if (((EntitySceneObject *)value2)->worldObject == 0) {
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2768;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_JourneyToTheTreeHouseBatScriptDescA);
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  ((EntitySceneObject *)value2)->roll = 2;
  *(undefined4 *)(value2 + 0x40) = 0;
  CEntities::AcquireEntitySceneObjectResourceSet(value2);
  *(undefined2 *)(entry + 0x48) = 0;
  *(undefined4 *)(entry + 0x4c) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x30,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = ((EntitySceneObject *)value2)->x;
    *(undefined4 *)(value + 0x10) = ((EntitySceneObject *)value2)->y;
    *(undefined4 *)(value + 0x14) = ((EntitySceneObject *)value2)->z;
    if (value3 != 0) {
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value3 + 4);
    }
    if (*(int *)(value + 0x18) == 0) {
      *(undefined4 *)(value + 0x18) = 0x708;
    }
    if (value3 != 0) {
      *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value3 + 8);
    }
    if (*(int *)(value + 0x1c) == 0) {
      if ((*(byte *)(entry + 0x4b) & 2) == 0) {
        value2 = RandomModulo(6);
        *(int *)(value + 0x1c) = value2 + 6;
      }
      else {
        *(undefined4 *)(value + 0x1c) = 0x898;
      }
    }
    if (value3 != 0) {
      *(undefined4 *)(value + 0x20) = *(undefined4 *)(value3 + 0xc);
    }
    if (*(int *)(value + 0x20) == 0) {
      *(undefined4 *)(value + 0x20) = 3000;
      return;
    }
  }
  return;
}

