#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C900
// Label: CampsiteCommotion::InitMovingBoxWithPushers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitMovingBoxWithPushers(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 *dataCursor;
  int value;
  int value2;
  
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    value2 = entity->sceneObjects;
    *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x10004;
    if (value2 != 0) {
      dataCursor = (undefined4 *)(&((EntitySceneObject *)value2)->x);
      *(undefined4 *)(value2 + 0x48) = *dataCursor;
      *(undefined4 *)(value2 + 0x4c) = ((EntitySceneObject *)value2)->y;
      *(undefined4 *)(value2 + 0x50) = ((EntitySceneObject *)value2)->z;
      ((EntitySceneObject *)value2)->worldObject = g_CurrentWorldSceneContext;
      LoadEncodedResourceId(0x102a);
      LoadEncodedResourceId(0x101a);
      *(undefined2 *)(value2 + 0xc) = 0x200b;
      ((EntitySceneObject *)value2)->roll = 1;
      ((EntitySceneObject *)value2)->yaw = 0x18e;
      *(undefined4 *)(value2 + 0x6c) = 0xffffffce;
      value = CEntities::SpawnEntityByTypeAtPosition
                        (*dataCursor,((EntitySceneObject *)value2)->y,((EntitySceneObject *)value2)->z,0x115,
                         0x11);
      if (value != 0) {
        CEntities::AppendEntityToChildChain(entry,value);
      }
      value2 = CEntities::SpawnEntityByTypeAtPosition
                        (*dataCursor,((EntitySceneObject *)value2)->y,((EntitySceneObject *)value2)->z,0x116,
                         0x11);
      if (value2 != 0) {
        CEntities::AppendEntityToChildChain(entry,value2);
      }
    }
    if (*(short *)(entry + 0x44) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
    return;
  }
  value2 = *(int *)(entry + 0x18);
  while (value2 != 0) {
    value = ((EntitySceneObject *)value2)->y;
    CEntities::ReleaseEntityToFreeList((byte *)value2);
    value2 = value;
  }
  UnloadEncodedResourceId(0x102a);
  UnloadEncodedResourceId(0x101a);
  return;
}

