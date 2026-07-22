#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFA50
// Label: LoadSFX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadSFX(undefined1 *arg1,undefined4 arg2)

{
  undefined4 value;
  undefined1 *scratchBuffer4;
  int scratchBuffer3;
  undefined1 *scratchBuffer2;
  undefined4 scratchBuffer;
  
  scratchBuffer2 = arg1;
  scratchBuffer4 = arg1;
  scratchBuffer = 0x42;
  scratchBuffer3 = 0x7fffffff;
  value = _output(&scratchBuffer4,arg2,&stack0x0000000c);
  scratchBuffer3 = scratchBuffer3 + -1;
  if (scratchBuffer3 < 0) {
    _flsbuf(0,&scratchBuffer4);
  }
  else {
    *scratchBuffer4 = 0;
  }
  return value;
}

