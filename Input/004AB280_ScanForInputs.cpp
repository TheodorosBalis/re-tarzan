#include "tarzan_ghidra_types.hpp"

// Address: 0x004AB280
// Label: ScanForInputs
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

byte ScanForInputs(void)

{
  uint value2;
  int value;
  
  value2 = CheckForJoystickInputs(0);
  if ((value2 & 0xfffffff) != 0) {
    return 1;
  }
  value = IsControlBindingPressed(0x20);
  if (value != 0) {
    return 2;
  }
  value = IsControlBindingPressed(0xd);
  if (value != 0) {
    return 3;
  }
  value = IsControlBindingPressed(0x1b);
  return -(value != 0) & 4;
}

