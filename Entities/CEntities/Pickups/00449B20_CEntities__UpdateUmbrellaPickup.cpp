#include "tarzan_ghidra_types.hpp"

// Address: 0x00449B20
// Label: CEntities::UpdateUmbrellaPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateUmbrellaPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  char pickupBoundsResult;
  short umbrellaState;
  int umbrellaMotionAttachment;
  int sceneObject;
  undefined4 soundId;
  
  sceneObject = entity->sceneObjects;
  if ((sceneObject == 0) ||
     (umbrellaMotionAttachment = CEntities::FindEntityAttachmentByFlags(entry,0x80000058), umbrellaMotionAttachment == 0))
  goto LAB_00449cd0;
  umbrellaState = *(short *)(entry + 0x48);
  if (umbrellaState != 1) {
    if (umbrellaState == 2) {
      *(short *)(umbrellaMotionAttachment + 0xc) = *(short *)(umbrellaMotionAttachment + 0xc) + -1;
      if (*(short *)(umbrellaMotionAttachment + 0xc) < 0) {
        *(short *)(umbrellaMotionAttachment + 0xe) = *(short *)(umbrellaMotionAttachment + 0xe) + 1;
        if (*(short *)(&g_UmbrellaPickupOpenFrameSequence + *(short *)(umbrellaMotionAttachment + 0xe) * 2) == 0) {
          *(undefined2 *)(entry + 0x48) = 9;
        }
        else {
          *(short *)(sceneObject + 0xc) =
               *(short *)(&g_UmbrellaPickupOpenFrameSequence + *(short *)(umbrellaMotionAttachment + 0xe) * 2);
          *(undefined2 *)(umbrellaMotionAttachment + 0xc) = 0;
        }
      }
    }
    else if (umbrellaState != 9) goto LAB_00449cd0;
    umbrellaState = *(short *)(umbrellaMotionAttachment + 0x14) + 0x44;
    *(short *)(umbrellaMotionAttachment + 0x14) = umbrellaState;
    *(int *)(sceneObject + 0x40) =
         -0x80 - (((int)(short)(&g_SinCosTable12Bit)[(int)umbrellaState - 0x400U & 0xfff] << 6) >> 0xc);
    ((EntitySceneObject *)sceneObject)->yaw = umbrellaState >> 1 & 0xfff;
    *(short *)(sceneObject + 0xa0) =
         (short)(((int)(short)(&g_SinCosTable12Bit)[(ushort)(umbrellaState >> 1) - 0x400 & 0xfff] +
                 (int)(short)(&g_SinCosTable12Bit)[(int)umbrellaState & 0xfff]) * 0xe3 >> 0xd);
    sceneObject = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = sceneObject;
    if (sceneObject < 0) {
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    }
    goto LAB_00449cd0;
  }
  ((EntitySceneObject *)sceneObject)->yaw = 0;
  *(undefined2 *)(sceneObject + 0xa0) = 0;
  if (*(int *)(sceneObject + 0x40) != 0) {
    *(int *)(sceneObject + 0x40) = *(int *)(sceneObject + 0x40) + 1 >> 1;
  }
  pickupBoundsResult = CEntities::IsPlayerWithinPickupTriggerBounds
                    (sceneObject,0x100,0x280,(int)*(short *)(umbrellaMotionAttachment + 0x10));
  if (pickupBoundsResult == '\0') goto LAB_00449cd0;
  PlayAudioById(0xb9,(int *)0,(undefined4 *)0);
  if (_g_PlayerHeroMode == 2) {
LAB_00449cae:
    soundId = 0x1f;
  }
  else if (_g_PlayerHeroMode == 6) {
    soundId = 0x4c1;
  }
  else {
    if (_g_PlayerHeroMode == 9) goto LAB_00449cae;
    soundId = 0x5e;
  }
  PlayAudioById(soundId,(int *)0,(undefined4 *)0);
  *(undefined2 *)(entry + 0x48) = 2;
  _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x4000;
  *(undefined2 *)(umbrellaMotionAttachment + 0xc) = 0xffff;
  *(undefined2 *)(umbrellaMotionAttachment + 0xe) = 0xffff;
LAB_00449cd0:
  if (((_g_PlayerSequenceFlags & 0x4000) == 0) &&
     (pickupBoundsResult = IsEntityOutsideOuterActivationBounds(entry), pickupBoundsResult != '\0')) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

