#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C720
// Label: GetWindowWidth
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetWindowWidth(void)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    value = GetGlideFrameBufferWidth();
    return value;
  case 2:
    value = GetDirect3DFrameBufferWidth();
    return value;
  case 3:
  case 4:
    value = GetDirectDrawFrameBufferWidth();
    return value;
  case 5:
    value = GetSoftwareFrameBufferWidth();
    return value;
  default:
    return 0;
  }
}

