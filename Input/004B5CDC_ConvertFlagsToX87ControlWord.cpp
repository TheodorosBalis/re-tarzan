#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5CDC
// Label: ConvertFlagsToX87ControlWord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint ConvertFlagsToX87ControlWord(uint arg1)

{
  uint stateFlags;
  uint stateFlags2;
  
  stateFlags = (uint)((arg1 & 0x10) != 0);
  if ((arg1 & 8) != 0) {
    stateFlags = stateFlags | 4;
  }
  if ((arg1 & 4) != 0) {
    stateFlags = stateFlags | 8;
  }
  if ((arg1 & 2) != 0) {
    stateFlags = stateFlags | 0x10;
  }
  if ((arg1 & 1) != 0) {
    stateFlags = stateFlags | 0x20;
  }
  if ((arg1 & 0x80000) != 0) {
    stateFlags = stateFlags | 2;
  }
  stateFlags2 = arg1 & 0x300;
  if (stateFlags2 != 0) {
    if (stateFlags2 == 0x100) {
      stateFlags = stateFlags | 0x400;
    }
    else if (stateFlags2 == 0x200) {
      stateFlags = stateFlags | 0x800;
    }
    else if (stateFlags2 == 0x300) {
      stateFlags = stateFlags | 0xc00;
    }
  }
  if ((arg1 & 0x30000) == 0) {
    stateFlags = stateFlags | 0x300;
  }
  else if ((arg1 & 0x30000) == 0x10000) {
    stateFlags = stateFlags | 0x200;
  }
  if ((arg1 & 0x40000) != 0) {
    stateFlags = stateFlags | 0x1000;
  }
  return stateFlags;
}

