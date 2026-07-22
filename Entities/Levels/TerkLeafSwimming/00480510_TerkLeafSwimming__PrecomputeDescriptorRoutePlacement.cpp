#include "tarzan_ghidra_types.hpp"

// Address: 0x00480510
// Label: TerkLeafSwimming::PrecomputeDescriptorRoutePlacement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::PrecomputeDescriptorRoutePlacement(undefined4 *arg1,int arg2)

{
  int value;
  undefined4 value5;
  int value2;
  int value3;
  int value4;
  int localState7;
  undefined4 localState14;
  undefined4 localState13;
  undefined4 localState12;
  undefined4 localState11;
  undefined1 localState2 [12];
  int localState6;
  undefined1 localState [12];
  int localState5;
  undefined1 localState4 [12];
  int localState10;
  int localState9;
  undefined1 localState3 [12];
  int localState8;
  uint localState15;
  
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x0f') {
    value2 = g_LeafSwimmingBoundarySurfaceIndexA * 4 + 4;
    value3 = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    value2 = g_LeafSwimmingBoundarySurfaceIndexB * 4 + 4;
    value = g_LeafSwimmingCenterRouteSurfaceIndex * 4 + 4;
    value4 = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    value2 = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
    if (0 < arg2) {
      localState7 = arg2;
      do {
        localState14 = 0;
        value = arg1[4];
        localState13 = *arg1;
        localState12 = arg1[1];
        localState11 = arg1[2];
        localState6 = value3;
        localState5 = value4;
        localState10 = value3;
        localState8 = value4;
        SnapCameraAnchorAttachmentToNearestPathSegment(localState2,&localState13);
        SnapPathFollowerAttachmentToNearestSegment(localState4,&localState13);
        SnapCameraAnchorAttachmentToNearestPathSegment(localState,&localState13);
        SnapPathFollowerAttachmentToNearestSegment(localState3,&localState13);
        *(uint *)(value + 8) = localState9 << 0x10 | localState15;
        value5 = CEntities::FindPathSegmentContainingPointXZ(value2,&localState13,&localState14);
        *(undefined4 *)(value + 0xc) = value5;
        *(undefined4 *)(value + 0x10) = localState14;
        arg1 = arg1 + 7;
        localState7 = localState7 + -1;
      } while (localState7 != 0);
    }
  }
  return;
}

