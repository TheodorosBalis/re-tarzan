#include "tarzan_ghidra_types.hpp"

// Address: 0x00449280
// Label: CEntities::MoveEntitySceneObjectAlongJungleSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectAlongJungleSurface(int entry3,int sceneObject)

{
  undefined4 *dataCursor;
  int entry;
  int entry2;
  undefined4 value;
  
  entry2 = *(int *)(entry3 + 0x110) * 4 + 4;
  entry2 = *(int *)(entry2 + g_CollisionSurfaceTable) + entry2 + g_CollisionSurfaceTable;
  sceneObject = *(int *)(entry3 + 0x10c) + sceneObject;
  *(int *)(entry3 + 0x10c) = sceneObject;
  if (sceneObject < 0) {
    *(undefined4 *)(entry3 + 0x10c) = 0;
  }
  entry = *(int *)(entry2 + 4);
  if (entry < *(int *)(entry3 + 0x10c)) {
    *(int *)(entry3 + 0x10c) = entry;
  }
  value = FindJungleSurfaceSegmentAtCoord(entry2,*(undefined4 *)(entry3 + 0x10c));
  dataCursor = (undefined4 *)(entry3 + 0x120);
  *(undefined4 *)(entry3 + 0x114) = value;
  SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(entry3 + 0x10c),value,dataCursor);
  UpdateEntitySceneObjectSurfaceAnglesFromSegment(value,dataCursor);
  *(undefined4 *)(entry3 + 0x14) = *dataCursor;
  *(undefined4 *)(entry3 + 0x18) = *(undefined4 *)(entry3 + 0x124);
  *(undefined4 *)(entry3 + 0x1c) = *(undefined4 *)(entry3 + 0x128);
  return;
}

