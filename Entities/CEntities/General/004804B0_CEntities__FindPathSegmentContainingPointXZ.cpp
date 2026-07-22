#include "tarzan_ghidra_types.hpp"

// Address: 0x004804B0
// Label: CEntities::FindPathSegmentContainingPointXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::FindPathSegmentContainingPointXZ
              (ushort *entry,undefined4 sceneObject,undefined4 attachment)

{
  ushort value;
  int foundIndex;
  int foundIndex2;
  ushort *dataCursor;
  
  dataCursor = entry + 0x18;
  value = *entry;
  foundIndex2 = 0;
  foundIndex = CEntities::IsPointOutsidePathSegmentSpanXZ(dataCursor,sceneObject,attachment);
  while( true ) {
    if (foundIndex == 0) {
      return foundIndex2;
    }
    if ((int)(uint)value < foundIndex2) break;
    if (foundIndex == 1) {
      foundIndex2 = foundIndex2 + 1;
      dataCursor = dataCursor + 0xe;
    }
    foundIndex = CEntities::IsPointOutsidePathSegmentSpanXZ(dataCursor,sceneObject,attachment);
  }
  return -1;
}

