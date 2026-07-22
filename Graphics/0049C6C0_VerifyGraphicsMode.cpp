#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C6C0
// Label: VerifyGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 VerifyGraphicsMode(void)

{
  int value;
  
  value = CurrentGraphicsMode();
  if (value != 1) {
    value = CurrentGraphicsMode();
    if (value != 2) {
      value = CurrentGraphicsMode();
      if (value != 3) {
        value = CurrentGraphicsMode();
        if (value != 4) {
          return 0;
        }
      }
    }
  }
  return 1;
}

