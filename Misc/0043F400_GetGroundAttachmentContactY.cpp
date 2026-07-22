#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F400
// Label: GetGroundAttachmentContactY
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetGroundAttachmentContactY(int arg1,int arg2,undefined4 arg3)

{
  uint value2;
  int value;
  undefined1 localState [8];
  
  _g_SelectMoviePreviewScene_Field001C = 0;
  value2 = *(uint *)(arg1 + 0xc) & 0xc0000000;
  if (value2 == 0) {
    value = IsEntitySceneObjectInsideGroundAttachmentBounds(arg1,arg2,arg3);
    if (value != 0) {
      value = (int)*(short *)(arg1 + 8);
      if (*(int *)(arg2 + 0xb4) == 1) {
        value = value * *(int *)(arg2 + 0xac) >> 0xc;
      }
      return value + *(int *)(arg2 + 0x18);
    }
  }
  else if (value2 == 0x40000000) {
    value = IsEntitySceneObjectNearSurfaceCoordAttachment(arg1,arg2,arg3,1,localState);
    if (value != 0) {
      return (int)*(short *)(arg1 + 8) + *(int *)(arg2 + 0x18);
    }
  }
  return -0x80000000;
}

