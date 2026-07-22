#include "tarzan_ghidra_types.hpp"

// Address: 0x004163B0
// Label: ComingOfAge::UpdateBreakableGroundShardBurst
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBreakableGroundShardBurst(int entry)

{
  Entity *entity = (Entity *)entry;
  bool flagByte;
  int value;
  char resultFlag;
  
  flagByte = false;
  if ((entity->sceneObjects != 0) &&
     (value = *(int *)(entity->sceneObjects + 0x34), value != 0)) {
    do {
      if (*(char *)(value + 0x74) == '\0') {
        if ((*(ushort *)(value + 0xe) & 0x8000) != 0) {
          *(short *)(value + 0xc) = *(short *)(value + 0xc) + 1;
          if (0x205b < *(ushort *)(value + 0xc)) {
            *(undefined2 *)(value + 0xe) = 0;
          }
          goto LAB_004163f7;
        }
      }
      else {
        resultFlag = *(char *)(value + 0x74) + -1;
        *(char *)(value + 0x74) = resultFlag;
        if (resultFlag == '\0') {
          *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) | 0x8000;
        }
LAB_004163f7:
        flagByte = true;
      }
      value = *(int *)(value + 0x34);
    } while (value != 0);
    if (flagByte) {
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

