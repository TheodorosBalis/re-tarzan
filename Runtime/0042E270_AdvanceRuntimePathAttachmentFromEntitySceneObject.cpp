#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E270
// Label: AdvanceRuntimePathAttachmentFromEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 AdvanceRuntimePathAttachmentFromEntitySceneObject(undefined4 arg1)

{
  int entry;
  int entry2;
  uint value;
  uint value2;
  
  entry = CEntities::FindEntityAttachmentByFlags(arg1,0x40000000);
  if (entry == 0) {
    return 0;
  }
  value2 = (uint)**(ushort **)(entry + 0xc);
  entry2 = EvaluateRuntimePathAttachmentDirection(*(undefined4 *)(entry + 0x14),arg1);
  if (entry2 == 1) {
    entry2 = *(int *)(entry + 0x18) + 1;
    *(int *)(entry + 0x14) = *(int *)(entry + 0x14) + 0x1c;
  }
  else {
    if (entry2 != 2) goto LAB_0042e2c5;
    entry2 = *(int *)(entry + 0x18) + -1;
    *(int *)(entry + 0x14) = *(int *)(entry + 0x14) + -0x1c;
  }
  *(int *)(entry + 0x18) = entry2;
LAB_0042e2c5:
  value = *(int *)(entry + 0xc) + 0x30 + value2 * 0x1c;
  if (value < *(uint *)(entry + 0x14)) {
    *(uint *)(entry + 0x14) = value;
  }
  value = *(int *)(entry + 0xc) + 0x30;
  if (*(uint *)(entry + 0x14) < value) {
    *(uint *)(entry + 0x14) = value;
  }
  if ((int)value2 <= *(int *)(entry + 0x18)) {
    *(uint *)(entry + 0x18) = value2;
  }
  if (*(int *)(entry + 0x18) < 1) {
    *(undefined4 *)(entry + 0x18) = 0;
  }
  return 0;
}

