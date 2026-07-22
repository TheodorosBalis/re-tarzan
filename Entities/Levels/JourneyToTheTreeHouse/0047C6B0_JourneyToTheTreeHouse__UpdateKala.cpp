#include "tarzan_ghidra_types.hpp"

// Address: 0x0047C6B0
// Label: JourneyToTheTreeHouse::UpdateKala
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateKala(int entry)

{
  char resultFlag;
  short shortValue;
  uint value;
  undefined4 value2;
  
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0) goto LAB_0047c6f8;
  if (*(short *)(entry + 0x48) == 0x2a) {
LAB_0047c6e7:
    *(undefined2 *)(entry + 0x48) = 0;
    value2 = 0;
  }
  else {
    value = NextRandomValue();
    value = value & 3;
    if (value == 0) goto LAB_0047c6e7;
    if ((value == 0) || (3 < value)) goto LAB_0047c6f8;
    *(undefined2 *)(entry + 0x48) = 0x2a;
    value2 = 1;
  }
  CEntities::SelectEntityAnimationAttachmentState(entry,value2);
LAB_0047c6f8:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

