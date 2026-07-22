#include "tarzan_ghidra_types.hpp"

// Address: 0x00439310
// Label: GetModelHeapCompactionCandidate_FrameFiltered
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

ushort * GetModelHeapCompactionCandidate_FrameFiltered(undefined4 arg1)

{
  ushort *dataCursor;
  
  dataCursor = (ushort *)GetModelHeapCompactionCandidate_Stub(arg1);
  if (((dataCursor != (ushort *)0x0) && ((*dataCursor & 2) != 0)) && ((*dataCursor & 1) == (FrameCount & 1))) {
    dataCursor = (ushort *)0x0;
  }
  return dataCursor;
}

