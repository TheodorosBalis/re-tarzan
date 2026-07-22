#include "tarzan_ghidra_types.hpp"

// Address: 0x00487390
// Label: TrashingTheCamp::UpdateBoxVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TrashingTheCamp::UpdateBoxVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 *dataCursor;
  int value;
  char resultFlag;
  int value2;
  undefined2 upperWord;
  undefined2 upperWord2;
  undefined2 upperWord3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000004);
    if ((value2 != 0) && (((EntitySceneObject *)value)->linkedSceneObject != 0)) {
      dataCursor = (undefined4 *)(&((EntitySceneObject *)value)->x);
      PlayAudioById(0x29a,(int *)0,(undefined4 *)dataCursor);
      _g_CampBoxCameraShakeTimer = 6;
      _g_CampBoxCameraShakeAmplitude = 0x18;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      PlayForceFeedbackEffect_Stub(0,3,0xf8);
      CEntities::SpawnEntityByTypeAtPosition
                (*dataCursor,((EntitySceneObject *)value)->y,((EntitySceneObject *)value)->z,0xf1,0x11);
      CEntities::SpawnMappedPickupOrEffectAtPosition
                (*dataCursor,((EntitySceneObject *)value)->y,((EntitySceneObject *)value)->z,
                 CONCAT22(upperWord3,*(undefined2 *)(value2 + 0x12)),
                 CONCAT22(upperWord2,*(undefined2 *)(value2 + 0x14)),
                 CONCAT22(upperWord,*(undefined2 *)(value2 + 0x16)));
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

