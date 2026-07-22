#include "tarzan_ghidra_types.hpp"

// Address: 0x004B360D
// Label: _callnewh
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _callnewh(undefined4 arg1)

{
  int value;
  
  if (g_CrtNewHandlerPtr != (code *)0x0) {
    value = (*g_CrtNewHandlerPtr)(arg1);
    if (value != 0) {
      return 1;
    }
  }
  return 0;
}

