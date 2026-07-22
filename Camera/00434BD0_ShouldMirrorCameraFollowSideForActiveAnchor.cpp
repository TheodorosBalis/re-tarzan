#include "tarzan_ghidra_types.hpp"

// Address: 0x00434BD0
// Label: ShouldMirrorCameraFollowSideForActiveAnchor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool ShouldMirrorCameraFollowSideForActiveAnchor(void)

{
  int value;
  
  if (*(int *)(g_ActiveCameraAnchorEntry + 0x38) != 0) {
    value = GetWrappedSignedAngleDelta12Bit
                      (-g_CameraYaw & 0xfff,
                       *(ushort *)(*(int *)(g_ActiveCameraAnchorEntry + 0x38) + 0xa2) & 0xfff);
    return value < 0;
  }
  return false;
}

