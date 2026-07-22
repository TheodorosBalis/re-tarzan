#include "tarzan_ghidra_types.hpp"

// Address: 0x004A4BC0
// Label: ShowFrameAndUpdateAppTime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ShowFrameAndUpdateAppTime(void)

{
  DWORD apiResult;
  
  ShowFrameOnScreen();
  apiResult = timeGetTime();
  _appUpTime = _appUpTime + apiResult;
  return;
}

