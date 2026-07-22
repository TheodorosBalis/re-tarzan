#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E3B0
// Label: FindRuntimePathSegmentForEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindRuntimePathSegmentForEntitySceneObject(ushort *arg1,undefined4 arg2)

{
  ushort value;
  int foundIndex;
  int foundIndex2;
  ushort *dataCursor;
  
  dataCursor = arg1 + 0x18;
  value = *arg1;
  foundIndex2 = 0;
  foundIndex = IsEntitySceneObjectOutsidePathSegmentSpan(dataCursor,arg2);
  while( true ) {
    if (foundIndex == 0) {
      return foundIndex2;
    }
    if ((int)(uint)value < foundIndex2) break;
    if (foundIndex == 1) {
      foundIndex2 = foundIndex2 + 1;
      dataCursor = dataCursor + 0xe;
    }
    foundIndex = IsEntitySceneObjectOutsidePathSegmentSpan(dataCursor,arg2);
  }
  return -1;
}

