#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E0E0
// Label: CheckForJoystickInputs
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CheckForJoystickInputs(void)

{
  PollJoystickButtonEdgeFlags(g_SelectedJoystickIndex);
  return 0;
}

