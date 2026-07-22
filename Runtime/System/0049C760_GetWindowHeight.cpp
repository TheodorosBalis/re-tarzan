#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C760
// Label: GetWindowHeight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetWindowHeight(void)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    value = GetGlideFrameBufferHeight();
    return value;
  case 2:
    value = GetDirect3DFrameBufferHeight();
    return value;
  case 3:
  case 4:
    value = GetDirectDrawFrameBufferHeight();
    return value;
  case 5:
    value = GetSoftwareFrameBufferHeight();
    return value;
  default:
    return 0;
  }
}

