#include "tarzan_ghidra_types.hpp"

// Address: 0x004763A0
// Label: CEntities::InitKerchakChaseNearbyAnimalAlert
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitKerchakChaseNearbyAnimalAlert(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x10,0x10000000);
  if (value != 0) {
    *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200c;
    *(undefined4 *)(value + 0xc) = 0;
    CEntities::LinkEntityIntoProcessingList(&g_KerchakChaseNearbyAnimalAlertListHead,entry);
  }
  return;
}

