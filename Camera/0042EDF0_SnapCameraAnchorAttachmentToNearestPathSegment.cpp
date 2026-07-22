#include "tarzan_ghidra_types.hpp"

// Address: 0x0042EDF0
// Label: SnapCameraAnchorAttachmentToNearestPathSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SnapCameraAnchorAttachmentToNearestPathSegment(int cameraState,undefined4 target)

{
  uint value3;
  ushort *dataCursor;
  uint value4;
  int value;
  int value2;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  value4 = 0xffffffff;
  value = **(ushort **)(cameraState + 0xc) - 1;
  value2 = 0;
  dataCursor = *(ushort **)(cameraState + 0xc) + 0x18;
  if (0 < value) {
    do {
      value3 = ClosestPointOnSegment3DAndDistanceSq(dataCursor,target,&localState3);
      if (value3 < value4) {
        *(int *)(cameraState + 0x10) = value2;
        *(undefined4 *)(cameraState + 0x14) = localState3;
        *(undefined4 *)(cameraState + 0x18) = localState2;
        *(undefined4 *)(cameraState + 0x1c) = localState;
        value4 = value3;
      }
      dataCursor = dataCursor + 0xe;
      value2 = value2 + 1;
    } while (value2 < value);
  }
  return;
}

