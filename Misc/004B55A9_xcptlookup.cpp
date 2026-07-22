#include "tarzan_ghidra_types.hpp"

// Address: 0x004B55A9
// Label: xcptlookup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int * xcptlookup(int arg1,int *arg2)

{
  int *intCursor;
  
  intCursor = arg2;
  if (*arg2 != arg1) {
    do {
      intCursor = intCursor + 3;
      if (arg2 + g_CrtExceptionLookupTable * 3 <= intCursor) break;
    } while (*intCursor != arg1);
  }
  if ((arg2 + g_CrtExceptionLookupTable * 3 <= intCursor) || (*intCursor != arg1)) {
    intCursor = (int *)0x0;
  }
  return intCursor;
}

