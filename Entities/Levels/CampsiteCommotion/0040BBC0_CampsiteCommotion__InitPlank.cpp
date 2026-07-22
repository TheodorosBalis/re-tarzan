#include "tarzan_ghidra_types.hpp"

// Address: 0x0040BBC0
// Label: CampsiteCommotion::InitPlank
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitPlank(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value3;
  int value2;
  
  value = entity->sceneObjects;
  *(undefined1 *)(entry + 0x3d) = 0x2a;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) ^ 3;
  value3 = g_CurrentWorldSceneContext;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2007;
    ((EntitySceneObject *)value)->worldObject = value3;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->pitch = 0xff01;
  }
  value2 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                     ((EntitySceneObject *)value)->z,0x101,0x11);
  if ((value2 != 0) && (value2 = *(int *)(value2 + 0x38), value2 != 0)) {
    *(undefined4 *)(value2 + 0x108) = 1;
    *(undefined4 *)(value2 + 0x110) = ((EntitySceneObject *)value)->surfacePathIndex;
    *(int *)(value2 + 0x10c) = ((EntitySceneObject *)value)->surfaceIndex * 2 + -0xfa;
    UpdateEntityEntitySceneObjectTransformFromPlacement(value2);
  }
  CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

