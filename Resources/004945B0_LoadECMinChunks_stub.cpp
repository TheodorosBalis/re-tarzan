#include "tarzan_ghidra_types.hpp"

// Address: 0x004945B0
// Label: LoadECMinChunks_stub
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int LoadECMinChunks_stub(void)

{
  DWORD apiResult;
  int value;
  CHAR scratchBuffer [1024];
  
  apiResult = GetModuleFileNameA((HMODULE)0x0,scratchBuffer,0x400);
  if (apiResult == 0) {
    return -1;
  }
  value = LoadECMinChunks(scratchBuffer);
  if (value == 0) {
    if ((g_EcmLoadedChunkCount != g_EcmStubChunkMarkerLo) ||
       (g_EcmExpectedChunkCount != g_EcmStubChunkMarkerHi)) {
      return -10;
    }
    value = 0;
  }
  return value;
}

