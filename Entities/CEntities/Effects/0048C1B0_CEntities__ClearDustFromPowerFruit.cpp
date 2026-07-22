#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C1B0
// Label: CEntities::ClearDustFromPowerFruit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ClearDustFromPowerFruit(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  short shortValue;
  int value2;
  char resultFlag;
  int *intCursor;
  short *value3;
  int *intCursor2;
  char *stringCursor;
  int localState;
  
  if (entity->sceneObjects != 0) {
    for (value2 = *(int *)(entity->sceneObjects + 0x34); value2 != 0;
        value2 = *(int *)(value2 + 0x34)) {
      if (*(char *)(value2 + 0x74) == '\0') {
        if (((*(byte *)(value2 + 0xf) & 0x80) != 0) &&
           (*(short *)(value2 + 0xc) = *(short *)(value2 + 0xc) + 1, 0x205b < *(ushort *)(value2 + 0xc)
           )) {
          *(undefined2 *)(value2 + 0xe) = 0;
        }
      }
      else {
        resultFlag = *(char *)(value2 + 0x74) + -1;
        *(char *)(value2 + 0x74) = resultFlag;
        if (resultFlag == '\0') {
          *(byte *)(value2 + 0xf) = *(byte *)(value2 + 0xf) | 0x80;
        }
      }
    }
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if (value2 != 0) {
      localState = 0;
      value = *(int *)(entity->sceneObjects + 0x38);
      if (value != 0) {
        if (*(short *)(value + 0xc) != 0) {
          stringCursor = (char *)(value2 + 0xfc);
          value3 = (short *)(value2 + 0x110);
          intCursor = (int *)(value2 + 0x10);
          intCursor2 = (int *)(value + 0x1c);
          do {
            shortValue = *value3;
            *value3 = shortValue + -1;
            resultFlag = *stringCursor;
            if (resultFlag == '\0') {
              if ((short)(shortValue + -1) < 0) {
                *stringCursor = '\x01';
                shortValue = RandomModulo(0x14);
                *value3 = shortValue + 0x14;
                *(byte *)((int)intCursor2 + -9) = *(byte *)((int)intCursor2 + -9) | 0x80;
              }
            }
            else if (resultFlag == '\x01') {
              intCursor2[-1] = intCursor2[-1] + intCursor[-1];
              *intCursor2 = *intCursor2 + *intCursor;
              intCursor2[1] = intCursor2[1] + intCursor[1];
              *intCursor = *intCursor + 6;
              if (*value3 < 0) {
                *stringCursor = '\x02';
                *(ushort *)((int)intCursor2 + -10) = *(ushort *)((int)intCursor2 + -10) & 0x7fff;
              }
            }
            else if (resultFlag == '\x02') {
              localState = localState + 1;
            }
            value3 = value3 + 1;
            intCursor = intCursor + 3;
            stringCursor = stringCursor + 1;
            intCursor2 = intCursor2 + 10;
          } while ((int)(stringCursor + (-0xfc - value2)) < (int)(uint)*(ushort *)(value + 0xc));
        }
        if ((int)(*(ushort *)(value + 0xc) - 1) <= localState) {
          CEntities::ReleaseEntityToFreeList((byte *)entry);
        }
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

