#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FD40
// Label: CEntities::UpdateParabolicThrownProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateParabolicThrownProjectile(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value = CEntities::AdvanceEntitySceneObjectParabolicArc
                      (value + 0x18,value + 0xc,value + 0x24,entity->sceneObjects + 0x14);
    if (value != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value = *(int *)(g_PlayerEntitySceneObject + 0x14) - *(int *)(entity->sceneObjects + 0x14);
    value2 = *(int *)(g_PlayerEntitySceneObject + 0x1c) - *(int *)(entity->sceneObjects + 0x1c);
    if (value2 * value2 + value * value < 40000) {
      QueuePlayerDamageEvent(entry,0x2003);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

