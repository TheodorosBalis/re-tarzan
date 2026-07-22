#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF238
// Label: FillVFtable1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FillVFtable1(void)

{
  g_CrtStderrBuffer = _cropzeros;
  g_CrtStdoutBuffer = __cfltcvt;
  g_CrtStdinBuffer = __fassign;
  g_CrtPrintfBuffer = _forcdecpt;
  g_CrtOutputState = _positive;
  g_CrtInputState = __cfltcvt;
  return;
}

