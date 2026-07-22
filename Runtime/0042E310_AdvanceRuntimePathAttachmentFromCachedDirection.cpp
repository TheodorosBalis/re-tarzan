#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E310
// Label: AdvanceRuntimePathAttachmentFromCachedDirection
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 AdvanceRuntimePathAttachmentFromCachedDirection(undefined4 arg1)

{
  int value;
  int value2;
  undefined4 value3;
  uint value4;
  uint value5;
  
  value = CEntities::FindEntityAttachmentByFlags(arg1,0x40000000);
  if (value == 0) {
    return 0;
  }
  value5 = (uint)**(ushort **)(value + 0xc);
  if (*(int *)(value + 0x34) == 1) {
    value2 = *(int *)(value + 0x18) + 1;
    *(int *)(value + 0x14) = *(int *)(value + 0x14) + 0x1c;
  }
  else {
    if (*(int *)(value + 0x34) != 2) goto LAB_0042e35b;
    value2 = *(int *)(value + 0x18) + -1;
    *(int *)(value + 0x14) = *(int *)(value + 0x14) + -0x1c;
  }
  *(int *)(value + 0x18) = value2;
LAB_0042e35b:
  value3 = EvaluateRuntimePathAttachmentDirection(*(undefined4 *)(value + 0x14),arg1);
  *(undefined4 *)(value + 0x34) = value3;
  value4 = *(int *)(value + 0xc) + 0x30 + value5 * 0x1c;
  if (value4 < *(uint *)(value + 0x14)) {
    *(uint *)(value + 0x14) = value4;
  }
  value4 = *(int *)(value + 0xc) + 0x30;
  if (*(uint *)(value + 0x14) < value4) {
    *(uint *)(value + 0x14) = value4;
  }
  if ((int)value5 <= *(int *)(value + 0x18)) {
    *(uint *)(value + 0x18) = value5;
  }
  if (*(int *)(value + 0x18) < 1) {
    *(undefined4 *)(value + 0x18) = 0;
  }
  return 0;
}

