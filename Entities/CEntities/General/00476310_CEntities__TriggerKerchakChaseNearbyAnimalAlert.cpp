#include "tarzan_ghidra_types.hpp"

// Address: 0x00476310
// Label: CEntities::TriggerKerchakChaseNearbyAnimalAlert
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::TriggerKerchakChaseNearbyAnimalAlert(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  int value2;
  int value3;
  int value4;
  
  value4 = g_KerchakChaseNearbyAnimalAlertListHead;
  if (g_KerchakChaseNearbyAnimalAlertListHead == 0) {
    return 0;
  }
  do {
    value2 = *(int *)(value4 + 0x38);
    value = entity->sceneObjects;
    if ((((value2 != value) &&
         (value3 = ((EntitySceneObject *)value)->x - *(int *)(value2 + 0x14),
         value2 = ((EntitySceneObject *)value)->z - *(int *)(value2 + 0x1c),
         value2 = value2 * value2 + value3 * value3, value2 < 0xd0710)) && (0 < value2)) &&
       ((value2 = CEntities::FindEntityAttachmentByFlags(value4,0x10000000), value2 != 0 &&
        (*(int *)(value2 + 0xc) == 0)))) {
      *(undefined4 *)(value2 + 0xc) = 1;
      PlayAudioById(0x323,0,*(int *)(value4 + 0x38) + 0x14);
    }
    intCursor = (int *)(value4 + 0x20);
    value4 = *intCursor;
  } while (*intCursor != 0);
  return 0;
}

