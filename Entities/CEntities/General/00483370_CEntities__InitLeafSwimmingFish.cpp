#include "tarzan_ghidra_types.hpp"

// Address: 0x00483370
// Label: CEntities::InitLeafSwimmingFish
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingFish(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  int value2;
  undefined4 value3;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x38,0x40000000);
  if (value != 0) {
    value2 = g_LeafSwimmingCenterRouteSurfaceIndex * 4 + 4;
    value2 = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,entity->sceneObjects);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
  }
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_LeafSwimmingFishAnimationScript);
  value = CEntities::CreateEntityAttachment(entry,0x70,0x10000018);
  if (entity->descriptor != 0) {
    *(uint *)(value + 0x14) = *(uint *)(*(int *)(entity->descriptor + 0x10) + 8) >> 0x10;
  }
  value2 = g_LeafSwimmingBoundarySurfaceIndexA * 4 + 4;
  *(int *)(value + 0xc) =
       *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
  value = CEntities::CreateEntityAttachment(entry,0x70,0x10000019);
  if (entity->descriptor != 0) {
    *(uint *)(value + 0x14) = *(uint *)(*(int *)(entity->descriptor + 0x10) + 8) & 0xffff;
  }
  value2 = g_LeafSwimmingBoundarySurfaceIndexB * 4 + 4;
  *(int *)(value + 0xc) =
       *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x800;
    intCursor = (int *)(entity->sceneObjects + 0x18);
    *intCursor = *intCursor + 0x60;
    value3 = RandomModulo(0x1000);
    *(undefined4 *)(value + 0x30) = value3;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2490;
    value2 = RandomModulo(0x40);
    *(int *)(value + 0x44) = value2 + 0x10;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x4c) = 0;
    *(undefined4 *)(value + 0x50) = 0x800;
    *(undefined4 *)(value + 0x58) = 0;
    *(undefined4 *)(value + 0x5c) = 0;
    *(undefined4 *)(value + 0x28) = 0;
  }
  return;
}

