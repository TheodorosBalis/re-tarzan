#include "tarzan_ghidra_types.hpp"

// Address: 0x0047A1F0
// Label: JourneyToTheTreeHouse::UpdateAnimatedEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateAnimatedEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  uint value3;
  
  JourneyToTheTreeHouse::AnimatedEffectNoOp(entry);
  value = entity->sceneObjects;
  if (value == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  else {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if ((value2 != 0) &&
       (*(short *)(value2 + 0x38) = *(short *)(value2 + 0x38) + -1, *(short *)(value2 + 0x38) < 0)) {
      value3 = *(ushort *)(value + 0xc) + 1;
      if (*(ushort *)(value2 + 0x32) <= value3) {
        value3 = (uint)*(ushort *)(value2 + 0x30);
      }
      *(short *)(value + 0xc) = (short)value3;
      *(undefined2 *)(value2 + 0x38) = *(undefined2 *)(value2 + 0x34);
      return;
    }
  }
  return;
}

