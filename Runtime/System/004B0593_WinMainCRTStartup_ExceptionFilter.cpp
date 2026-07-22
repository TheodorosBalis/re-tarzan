#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0593
// Label: WinMainCRTStartup_ExceptionFilter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WinMainCRTStartup_ExceptionFilter(void)

{
  undefined4 value;
  int callerFrameBase;
  
  value = *(undefined4 *)**(undefined4 **)(callerFrameBase + -0x14);
  *(undefined4 *)(callerFrameBase + -0x68) = value;
  _XcptFilter(value,*(undefined4 **)(callerFrameBase + -0x14));
  return;
}

