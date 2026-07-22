#include "tarzan_ghidra_types.hpp"

// Address: 0x004B05D7
// Label: FastRuntimeErrorExit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FastRuntimeErrorExit(undefined4 arg1)

{
  if (g_CrtRuntimeErrorOutputMode == 1) {
    _FF_MSGBANNER();
  }
  _NMSG_WRITE(arg1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xff);
}

