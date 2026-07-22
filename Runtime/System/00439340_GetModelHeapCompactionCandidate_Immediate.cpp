#include "tarzan_ghidra_types.hpp"

// Address: 0x00439340
// Label: GetModelHeapCompactionCandidate_Immediate
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

byte * GetModelHeapCompactionCandidate_Immediate(undefined4 value)

{
  byte *value2;
  
  value2 = (byte *)GetModelHeapCompactionCandidate_Stub(value);
  if ((value2 != (byte *)0x0) && ((*value2 & 2) != 0)) {
    value2 = (byte *)0x0;
  }
  return value2;
}

