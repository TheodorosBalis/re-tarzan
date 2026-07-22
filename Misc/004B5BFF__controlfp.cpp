#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5BFF
// Label: _controlfp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _controlfp(uint arg1,uint arg2)

{
  uint value;
  
  value = ConvertX87ControlWordToFlags();
  value = value & ~arg2 | arg1 & arg2;
  ConvertFlagsToX87ControlWord(value);
  return value;
}

