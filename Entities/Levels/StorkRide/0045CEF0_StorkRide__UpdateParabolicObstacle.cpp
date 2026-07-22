#include "tarzan_ghidra_types.hpp"

// Address: 0x0045CEF0
// Label: StorkRide::UpdateParabolicObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateParabolicObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value2;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if (value != 0) {
      if ((*(int *)(value + 0xc) == 5) && (-0x100 < *(int *)(entity->sceneObjects + 0x18))) {
        *(undefined4 *)(value + 0xc) = 6;
        return;
      }
      value2 = (short *)(entity->sceneObjects + 0xa2);
      *value2 = *value2 + 0x40;
    }
  }
  return;
}

