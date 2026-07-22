#include "tarzan_ghidra_types.hpp"

// Address: 0x0049DF60
// Label: SetControlKeysOnlyMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetControlKeysOnlyMode(int arg1)

{
  g_ControlKeysOnlyMode = (uint)(arg1 != 0);
  return;
}

