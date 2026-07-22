#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5C4A
// Label: ConvertX87ControlWordToFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint ConvertX87ControlWordToFlags(uint arg1)

{
  uint stateFlags;
  uint stateFlags2;
  
  stateFlags = 0;
  if ((arg1 & 1) != 0) {
    stateFlags = 0x10;
  }
  if ((arg1 & 4) != 0) {
    stateFlags = stateFlags | 8;
  }
  if ((arg1 & 8) != 0) {
    stateFlags = stateFlags | 4;
  }
  if ((arg1 & 0x10) != 0) {
    stateFlags = stateFlags | 2;
  }
  if ((arg1 & 0x20) != 0) {
    stateFlags = stateFlags | 1;
  }
  if ((arg1 & 2) != 0) {
    stateFlags = stateFlags | 0x80000;
  }
  stateFlags2 = arg1 & 0xc00;
  if (stateFlags2 != 0) {
    if (stateFlags2 == 0x400) {
      stateFlags = stateFlags | 0x100;
    }
    else if (stateFlags2 == 0x800) {
      stateFlags = stateFlags | 0x200;
    }
    else if (stateFlags2 == 0xc00) {
      stateFlags = stateFlags | 0x300;
    }
  }
  if ((arg1 & 0x300) == 0) {
    stateFlags = stateFlags | 0x20000;
  }
  else if ((arg1 & 0x300) == 0x200) {
    stateFlags = stateFlags | 0x10000;
  }
  if ((arg1 & 0x1000) != 0) {
    stateFlags = stateFlags | 0x40000;
  }
  return stateFlags;
}

