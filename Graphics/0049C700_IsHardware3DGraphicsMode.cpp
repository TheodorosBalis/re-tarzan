#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C700
// Label: IsHardware3DGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsHardware3DGraphicsMode(void)

{
  int result;
  
  result = CurrentGraphicsMode();
  if (result != 1) {
    result = CurrentGraphicsMode();
    if (result != 2) {
      return 0;
    }
  }
  return 1;
}

