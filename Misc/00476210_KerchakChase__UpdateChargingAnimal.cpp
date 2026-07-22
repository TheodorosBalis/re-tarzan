#include "tarzan_ghidra_types.hpp"

// Address: 0x00476210
// Label: KerchakChase::UpdateChargingAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::UpdateChargingAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value4;
  char resultFlag;
  int value;
  int value2;
  int value3;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(value + 0xc) == 0) {
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
              *(int *)(entity->sceneObjects + 0x14);
      value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
              *(int *)(entity->sceneObjects + 0x1c);
      value2 = value2 * value2 + value3 * value3;
      if ((value2 < 0xd0710) && (0 < value2)) {
        *(undefined4 *)(value + 0xc) = 1;
        PlayAudioById(0x324,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        PlayAudioById(0x325,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      }
    }
    else if (*(int *)(value + 0xc) == 1) {
      CEntities::TriggerKerchakChaseNearbyAnimalAlert(entry);
      CEntities::MoveEntityForwardAndEaseFacingYaw(entry,0x55);
      value = entity->sceneObjects;
      value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value2;
      *(int *)(entity->sceneObjects + 0x18) = *(int *)(entity->sceneObjects + 0x18) + -0x19c
      ;
      if (*(int *)(entity->sceneObjects + 0x18) < 300) {
        value4 = (short *)(entity->sceneObjects + 0xa0);
        *value4 = *value4 + -0x40;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

