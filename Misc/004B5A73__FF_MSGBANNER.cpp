#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5A73
// Label: _FF_MSGBANNER
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _FF_MSGBANNER(void)

{
  if ((g_CrtRuntimeErrorOutputMode == 1) ||
     ((g_CrtRuntimeErrorOutputMode == 0 && (g_CrtFileHandleTable == 1)))) {
    _NMSG_WRITE(0xfc);
    if (g_CrtFatalMessageBannerState != (code *)0x0) {
      (*g_CrtFatalMessageBannerState)();
    }
    _NMSG_WRITE(0xff);
  }
  return;
}

