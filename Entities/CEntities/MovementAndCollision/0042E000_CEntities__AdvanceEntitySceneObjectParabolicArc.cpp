#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E000
// Label: CEntities::AdvanceEntitySceneObjectParabolicArc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::AdvanceEntitySceneObjectParabolicArc(int *entry4,int *sceneObject,int attachment,int *flags)

{
  Entity *entity3 = (Entity *)attachment;
  int entry;
  uint value;
  uint value2;
  int entry2;
  int entry3;
  
  if (entity3->next == 0) {
    entry3 = *sceneObject - *entry4;
    entry2 = sceneObject[2] - entry4[2];
    entry = SqrtToInt(entry2 * entry2 + entry3 * entry3);
    entry = (int)(CONCAT44(entry >> 0x1f,entry >> 6) / (longlong)*(int *)(attachment + 0x50));
    if (entry == 0) {
      return 1;
    }
    entry = (sceneObject[1] - entry4[1]) / entry - (entry >> 1) * entity3->previous;
    *(int *)(attachment + 0x18) = entry;
    *(int *)(attachment + 0x20) = entry;
    value = GetAngleFromXZVector12Bit(entry3,entry2);
    *(uint *)(attachment + 0x30) = value & 0xfff;
    entity3->next = 1;
  }
  entry = flags[1];
  if (*(int *)(attachment + 0x24) <= entry) {
    value = entry - *(int *)(attachment + 0x24);
    value2 = (int)value >> 0x1f;
    flags[1] = entry - ((value ^ value2) - value2);
    return 1;
  }
  flags[1] = entry + *(int *)(attachment + 0x20);
  *(int *)(attachment + 0x20) = *(int *)(attachment + 0x20) + entity3->previous;
  entry = (int)(short)(&g_SinCosTable12Bit)[*(uint *)(attachment + 0x30) - 0x400 & 0xfff] *
          *(int *)(attachment + 0x50) >> 0xc;
  *(int *)(attachment + 0x40) = entry;
  *(int *)(attachment + 0x44) =
       (int)(short)(&g_SinCosTable12Bit)[*(uint *)(attachment + 0x30) & 0xfff] *
       *(int *)(attachment + 0x50) >> 0xc;
  *flags = *flags + entry;
  flags[2] = flags[2] + *(int *)(attachment + 0x44);
  return 0;
}

