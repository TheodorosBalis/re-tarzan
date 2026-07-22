#include "tarzan_ghidra_types.hpp"

// Address: 0x004568E0
// Label: Stampede::InitElephants
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitElephants(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  short shortValue;
  int value;
  undefined4 value5;
  int value2;
  int value3;
  int value4;
  int *intCursor;
  int *intCursor2;
  
  value2 = *(int *)(g_CollisionSurfaceTable + 8) + 8 + g_CollisionSurfaceTable;
  g_StampedeElephantsEntity = entry;
  value3 = *(int *)(g_CollisionSurfaceTable + 0xc) + 0xc + g_CollisionSurfaceTable;
  *(int *)(entity->sceneObjects + 0x1c) =
       *(int *)(&g_StampedeElephantCheckpointBaseZTable + g_CurrentCheckpointId * 0x24) + 3000;
  *(undefined4 *)(entity->sceneObjects + 0x14) =
       *(undefined4 *)(&g_StampedeElephantCheckpointStartXTable + g_CurrentCheckpointId * 0x24);
  *(undefined4 *)(entity->sceneObjects + 0x18) =
       *(undefined4 *)(&g_StampedeElephantCheckpointStartYTable + g_CurrentCheckpointId * 0x24);
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor | 0x1800;
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0xfd8;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x1800;
  *(undefined4 *)(entity->sceneObjects + 0xac) = 0x1800;
  *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x1800;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503308);
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  g_StampedeElephantStrideTable = CEntities::CreateEntityAttachment(entry,0x148,0x10000000);
  if (g_StampedeElephantStrideTable != 0) {
    *(undefined4 *)(g_StampedeElephantStrideTable + 0x14) = 0;
    *(undefined4 *)(g_StampedeElephantStrideTable + 0x18) = 0x25;
    *(undefined4 *)(g_StampedeElephantStrideTable + 0x10) = 4;
    value = CreateEntityEntitySceneObject((uint *)entry,3);
    if (value != 0) {
      *(int *)(g_StampedeElephantStrideTable + 0x14) = value;
      value = entity->sceneObjects;
      value4 = *(int *)(g_StampedeElephantStrideTable + 0x14);
      *(undefined4 *)(value4 + 0x14) = ((EntitySceneObject *)value)->x;
      *(undefined4 *)(value4 + 0x18) = ((EntitySceneObject *)value)->y;
      *(undefined4 *)(value4 + 0x1c) = ((EntitySceneObject *)value)->z;
      *(undefined2 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xc) =
           *(undefined2 *)(entity->sceneObjects + 0xc);
      *(undefined2 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xe) = 0x8800;
      *(undefined2 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xa6) = 0;
      *(int *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0x10) =
           g_WorldEntitySceneObjectArrayBase + 0x30c0;
      *(undefined4 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xb4) = 1;
      *(undefined4 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xa8) = 0x1800;
      *(undefined4 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xac) = 0x1800;
      *(undefined4 *)(*(int *)(g_StampedeElephantStrideTable + 0x14) + 0xb0) = 0x1800;
    }
    value = CEntities::CreateChildEntitySceneObjectArrayAttachment(entry,0x20000000,4);
    if (value != 0) {
      intCursor = &DAT_005033a4;
      intCursor2 = (int *)(&((EntitySceneObject *)value)->y);
      *(int *)(g_StampedeElephantStrideTable + 0x1c) = value;
      value = 0x40;
      do {
        intCursor2[-1] = g_WorldEntitySceneObjectArrayBase + 0x30c0;
        shortValue = RandomModulo(0x10);
        *(short *)(intCursor2 + -2) = shortValue + 0x2010;
        *intCursor2 = intCursor[-1] << 2;
        intCursor2[1] = *intCursor;
        intCursor2[2] = intCursor[1];
        *(undefined2 *)((int)intCursor2 + -6) = 0x9800;
        *(uint *)(value + -0x20 + g_StampedeElephantStrideTable) = (uint)*(ushort *)(intCursor2 + -2);
        value5 = RandomModulo(0x2000);
        value4 = value + 4;
        intCursor = intCursor + 4;
        *(undefined4 *)(value + g_StampedeElephantStrideTable) = value5;
        intCursor2 = intCursor2 + 10;
        value = value4;
      } while (value4 < 0x50);
    }
  }
  value = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(entry,0x38,0x40000000);
  }
  *(int *)(g_StampedeElephantStrideTable + 0xe4) = value2;
  SnapPathFollowerAttachmentToNearestSegment
            (g_StampedeElephantStrideTable + 0xd8,entity->sceneObjects + 0x14);
  *(int *)(g_StampedeElephantStrideTable + 0x74) = value3;
  SnapPathFollowerAttachmentToNearestSegment
            (g_StampedeElephantStrideTable + 0x68,entity->sceneObjects + 0x14);
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value2 != 0) {
    value3 = *(int *)(g_CollisionSurfaceTable + 0x10) + 0x10 + g_CollisionSurfaceTable;
    *(int *)(value2 + 0xc) = value3;
    value3 = FindRuntimePathSegmentForEntitySceneObject(value3,entity->sceneObjects);
    *(int *)(value2 + 0x10) = value3;
    *(int *)(value2 + 0x18) = value3;
    *(undefined4 *)(value2 + 0x30) = 0;
    *(int *)(value2 + 0x14) = *(int *)(value2 + 0xc) + 0x30 + value3 * 0x1c;
    *(undefined4 *)(value2 + 0x34) = 0;
  }
  return;
}

