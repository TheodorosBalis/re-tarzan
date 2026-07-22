#include "tarzan_ghidra_types.hpp"

// Address: 0x004448F0
// Label: CEntities::UpdateSourceLinkedFrameAnimator
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSourceLinkedFrameAnimator(undefined4 entry)

{
  char resultFlag;
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if ((value != 0) &&
     (*(short *)(value + 0x28) = *(short *)(value + 0x28) + -1, *(short *)(value + 0x28) < 0)) {
    value2 = *(short *)(value + 0x2a) + 1;
    if ((int)(uint)*(ushort *)(value + 0x32) <= value2) {
      value2 = 0;
    }
    *(short *)(value + 0x2a) = (short)value2;
    if (*(int *)(value + 0x18) != 0) {
      *(char *)(*(int *)(value + 0x18) + 3) = (char)value2;
    }
    if (*(ushort *)(value + 0x34) == 0) {
      *(undefined2 *)(value + 0x28) = 0;
    }
    else {
      *(short *)(value + 0x28) =
           (short)(0x14 / (ulonglong)(longlong)(int)(uint)*(ushort *)(value + 0x34)) + -1;
    }
  }
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

