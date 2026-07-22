#include "tarzan_ghidra_types.hpp"

// Address: 0x00488A20
// Label: TrashingTheCamp::UpdateRunningGorillaC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateRunningGorillaC(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  
  if (entity->sceneObjects != 0) {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (value != 0) {
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      if (shortValue == 8) {
        if (*(short *)(entry + 0x48) == 0) {
          value2 = RandomModulo(6);
          if (value2 == 0) {
            CEntities::SelectScriptAttachmentSequence(value,4);
            *(undefined2 *)(entry + 0x48) = 1;
          }
        }
        else {
          value2 = RandomModulo(8);
          if (value2 == 0) {
            CEntities::SelectScriptAttachmentSequence(value,6);
            *(undefined2 *)(entry + 0x48) = 0;
          }
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

