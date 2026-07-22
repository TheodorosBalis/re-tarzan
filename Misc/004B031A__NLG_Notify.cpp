#include "tarzan_ghidra_types.hpp"

// Address: 0x004B031A
// Label: _NLG_Notify
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _NLG_Notify(void)

{
  undefined4 inputEax;
  int callerFrameBase;
  
  DAT_00519058 = *(undefined4 *)(callerFrameBase + 8);
  DAT_00519054 = inputEax;
  DAT_0051905c = callerFrameBase;
  return;
}

