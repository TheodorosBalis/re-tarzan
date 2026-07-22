#include "tarzan_ghidra_types.hpp"

// Address: 0x00424D50
// Label: ElephantHairDare::InitThrowableCarryingBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitThrowableCarryingBird(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 4;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    ElephantHairDare::InitBirdCommon(entry);
    value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if (value != 0) {
      *(code **)(value + 0xc) = ElephantHairDare::UpdateBirdCarriedThrowable;
      *(undefined2 *)(value + 0x10) = 0x28;
      shortValue = RandomModulo(3);
      *(short *)(value + 0x12) = shortValue + 1;
      *(undefined2 *)(value + 0x14) = 0x28;
      *(undefined2 *)(value + 0x16) = 0;
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 9;
      *(undefined4 *)(entry + 0x50) = 0;
    }
  }
  else {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if ((value != 0) && (*(int *)(value + 0x28) != 0)) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(*(int *)(value + 0x28));
      return;
    }
  }
  return;
}

