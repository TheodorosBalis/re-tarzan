#include "tarzan_ghidra_types.hpp"

// Address: 0x00436930
// Label: FindPlayerSpecialAttachmentEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindPlayerSpecialAttachmentEntry(void)

{
  int foundIndex;
  int foundIndex2;
  int localState;
  
  foundIndex = GetEntitySceneObjectAttachmentList(g_PlayerEntitySceneObject,&localState);
  if ((foundIndex != 0) && (foundIndex2 = 0, 0 < foundIndex)) {
    do {
      if (((*(uint *)(localState + 0xc) & 0x200) != 0) &&
         ((*(uint *)(localState + 0xc) & 0xc0000000) == 0x80000000)) {
        return localState;
      }
      localState = localState + 0x10;
      foundIndex2 = foundIndex2 + 1;
    } while (foundIndex2 < foundIndex);
  }
  return 0;
}

