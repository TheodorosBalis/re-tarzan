#include "tarzan_ghidra_types.hpp"

// Address: 0x00430110
// Label: CEntities::HandleAnimalScriptEvent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::HandleAnimalScriptEvent(int entry,int sceneObject,int attachment)

{
  if (attachment < 0x108) {
    if (attachment == 0x107) {
      *(byte *)(sceneObject + 0x75) = ~*(byte *)(sceneObject + 0x75);
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xffd7;
      CEntities::RefreshAnimalFacingAndCollisionAfterTurn(entry,sceneObject);
      return 0;
    }
    if (attachment < 0x106) {
      if (attachment == 0x105) {
        *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
        return 0;
      }
      if (1 < attachment) {
        if (attachment < 4) {
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfff7;
          return 1;
        }
        if (attachment == 4) {
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
          return 0;
        }
      }
    }
    else if (attachment == 0x106) {
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 2;
      return 0;
    }
  }
  else if (attachment == 0x108) {
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x20;
  }
  else {
    if (attachment == 0x109) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xffdf;
      return 0;
    }
    if (attachment == 0x111) {
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 8;
      return 0;
    }
  }
  return 0;
}

