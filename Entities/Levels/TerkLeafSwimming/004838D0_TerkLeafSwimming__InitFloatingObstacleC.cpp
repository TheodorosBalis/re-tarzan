#include "tarzan_ghidra_types.hpp"

// Address: 0x004838D0
// Label: TerkLeafSwimming::InitFloatingObstacleC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::InitFloatingObstacleC(int entry)

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
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050e490);
  value = CEntities::CreateEntityAttachment(entry,0x60,0x10000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0;
    intCursor = (int *)(entity->sceneObjects + 0x18);
    *intCursor = *intCursor + -0x40;
    value3 = RandomModulo(0x1000);
    *(undefined4 *)(value + 0x30) = value3;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x24f8;
    value2 = RandomModulo(0x40);
    *(int *)(value + 0x44) = value2 + 0x10;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(value + 0x38) = 0;
  }
  return;
}

