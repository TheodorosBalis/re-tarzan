#include "tarzan_ghidra_types.hpp"

// Address: 0x00475C00
// Label: KerchakChase::UpdateBouncingObstacleDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::UpdateBouncingObstacleDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value = CEntities::AdvanceBounceMotionAndReturnImpact
                      (entity->sceneObjects,value + 0x10);
    if (value != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

