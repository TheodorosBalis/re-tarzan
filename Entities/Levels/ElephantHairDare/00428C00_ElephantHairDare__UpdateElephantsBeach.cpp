#include "tarzan_ghidra_types.hpp"

// Address: 0x00428C00
// Label: ElephantHairDare::UpdateElephantsBeach
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateElephantsBeach(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  undefined4 value3;
  
  value2 = entity->sceneObjects;
  if ((value2 != 0) &&
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value != 0)) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value2,0,0);
    value2 = CEntities::HandleAnimalScriptEvent(entry,value2,(int)shortValue);
    if (value2 != 0) {
      value3 = RandomModulo(8);
      switch(value3) {
      case 0:
        CEntities::SelectScriptAttachmentSequence(value,6);
        *(undefined2 *)(entry + 0x48) = 1;
        break;
      case 1:
        CEntities::SelectScriptAttachmentSequence(value,9);
        *(undefined2 *)(entry + 0x48) = 1;
        break;
      case 2:
        CEntities::SelectScriptAttachmentSequence(value,3);
        *(undefined2 *)(entry + 0x48) = 1;
        break;
      case 3:
        CEntities::SelectScriptAttachmentSequence(value,0xc);
        *(undefined2 *)(entry + 0x48) = 1;
        break;
      default:
        CEntities::SelectScriptAttachmentSequence(value,0);
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

