#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC360
// Label: CaptureInputsInCutscene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CaptureInputsInCutscene(int arg1)

{
  int entry;
  uint value;
  
  if (arg1 == 0) {
    return false;
  }
  entry = IsControlBindingPressed(0xd);
  if (entry != 0) {
    return true;
  }
  entry = IsControlBindingPressed(0x20);
  if (entry != 0) {
    return true;
  }
  entry = IsControlBindingPressed(0x1b);
  if (entry != 0) {
    return true;
  }
  value = CheckForJoystickInputs(0);
  return (value & 0xfffffff) != 0;
}

