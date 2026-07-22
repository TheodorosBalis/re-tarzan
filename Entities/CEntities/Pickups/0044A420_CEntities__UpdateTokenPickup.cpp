#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A420
// Label: CEntities::UpdateTokenPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateTokenPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int sceneObject;
  char pickupResult;
  uint collectedVariant;
  
  sceneObject = entity->sceneObjects;
  if ((sceneObject != 0) &&
     (CEntities::UpdateScriptedEntitySceneObjectAttachment(entry), *(short *)(entry + 0x48) != 0
     )) {
    pickupResult = CEntities::IsPlayerWithinPickupTriggerBounds
                      (sceneObject,g_PlayerPickupTriggerRadius,
                       (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
    if ((pickupResult != '\0') && (pickupResult = CEntities::CanStartPickupCollection(entry), pickupResult != '\0')) {
      gCurrentTokensCollected = gCurrentTokensCollected + 1;
      if (g_HudTokenCounterSlideTicks < 0x50) {
        g_HudTokenCounterSlideTicks = 0x50;
      }
      PlayAudioById(0xb5,(int *)0,(undefined4 *)&((EntitySceneObject *)sceneObject)->x);
      CEntities::SetEntitySceneObjectScriptAttachment
                (entry,&g_CollectibleCollectedScriptAttachmentDesc);
      collectedVariant = *(uint *)(entry + 0x50) & 0xf0;
      if (collectedVariant != 0) {
        *(undefined4 *)(sceneObject + 0xb4) = 1;
        collectedVariant = (uint)*(ushort *)(&g_CollectibleCollectedVariantFrameTable + ((int)collectedVariant >> 4) * 2);
        *(uint *)(sceneObject + 0xb0) = collectedVariant;
        *(uint *)(sceneObject + 0xac) = collectedVariant;
        *(uint *)(sceneObject + 0xa8) = collectedVariant;
      }
      *(byte *)(sceneObject + 0xe) = *(byte *)(sceneObject + 0xe) | 0x21;
      *(undefined2 *)(entry + 0x48) = 0;
      return;
    }
    pickupResult = CEntities::UpdateBouncingPickupMotionAndLifetime(entry);
    if ((pickupResult != '\0') || (pickupResult = IsEntityOutsideOuterActivationBounds(entry), pickupResult != '\0')) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

