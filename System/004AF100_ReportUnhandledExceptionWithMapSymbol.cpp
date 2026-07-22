#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF100
// Label: ReportUnhandledExceptionWithMapSymbol
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReportUnhandledExceptionWithMapSymbol(undefined4 arg1,undefined4 arg2)

{
  undefined4 value;
  undefined1 localState [1024];
  
  value = ResolveMapSymbolForAddress(arg2);
  LoadSFX(localState,s_Exception__08lX_at__08lX__s_00518fc8,arg1,arg2,value);
  InternalError(localState);
  return;
}

