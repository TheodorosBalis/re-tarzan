#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C330
// Label: StorkRide::UpdateFallingPickupEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StorkRide::UpdateFallingPickupEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0x40;
  localState2[0] = 0x100;
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (entity->sceneObjects != 0) {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
    if (value != 0) {
      CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
      if (*(short *)(entry + 0x4a) == 0) {
        resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                          (entity->sceneObjects,localState,g_PlayerEntitySceneObject,
                           localState2);
        if (resultFlag != '\0') {
          g_CollectedWaterTokenCount = g_CollectedWaterTokenCount + 1;
          _g_LastCollectedWaterTokenSceneObjectId =
               (uint)*(ushort *)(entity->sceneObjects + 0xc);
          gCurrentTokensCollected = gCurrentTokensCollected + 1;
          _g_WaterTokenCollectionHudUpdatePending = 1;
          _g_WaterTokenCollectionEffectTimer = 0;
          if (g_HudTokenCounterSlideTicks < 0x50) {
            g_HudTokenCounterSlideTicks = 0x50;
          }
          value = entity->sceneObjects;
          if (value != 0) {
            PlayAudioById(0xb5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
            CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_CollectibleCollectedScriptAttachmentDesc);
            *(byte *)(value + 0xe) = *(byte *)(value + 0xe) | 0x21;
            *(undefined4 *)(value + 0x40) = 0xffffff40;
            *(undefined2 *)(entry + 0x4a) = 1;
            return;
          }
          PlayAudioById(0xb5,(int *)0,(undefined4 *)0);
          CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
          return;
        }
      }
      resultFlag = IsEntityOutsideOuterActivationBounds(entry);
      if (resultFlag != '\0') {
        CEntities::ReleaseEntityToFreeList((byte *)entry);
      }
    }
  }
  return;
}

