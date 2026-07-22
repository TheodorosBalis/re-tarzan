#include "tarzan_ghidra_types.hpp"

// Address: 0x004036C0
// Label: CEntities::UpdateJaneSurfingTransitionProxy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateJaneSurfingTransitionProxy(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value9;
  int value;
  int value2;
  uint value7;
  uint value8;
  int value3;
  int value4;
  int value5;
  int value6;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(value + 0xc) == 0) {
      value2 = entity->sceneObjects;
      value5 = ((EntitySceneObject *)value2)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
      value4 = ((EntitySceneObject *)value2)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
      value6 = (((EntitySceneObject *)value2)->y - *(int *)(g_PlayerEntitySceneObject + 0x18)) + 0x100;
      value2 = SqrtToInt(value5 * value5 + value4 * value4);
      value7 = GetAngleFromXZVector12Bit(value5,value4);
      value8 = GetAngleFromXZVector12Bit(value6,value2 >> 6);
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value7 & 0xfff);
      value9 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value9 = *value9 + (short)(value3 >> 1);
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value2 + 0xa0),-(value8 & 0xfff));
      value9 = (short *)(value2 + 0xa0);
      *value9 = *value9 + (short)(value3 >> 1);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->x =
           ((EntitySceneObject *)value2)->x -
           ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw - 0x400 & 0xfff] * 100 >> 0xc);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->z =
           ((EntitySceneObject *)value2)->z -
           ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw & 0xfff] * 100 >> 0xc);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->y =
           ((EntitySceneObject *)value2)->y +
           ((short)(&g_SinCosTable12Bit)[*(ushort *)(value2 + 0xa0) - 0x400 & 0xfff] * 100 >> 0xc);
      value2 = SqrtToInt(value6 * value6 + value5 * value5 + value4 * value4);
      if ((value2 >> 6 < 0x80) && (0 < value2 >> 6)) {
        PlayAudioById(0x226,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        if (g_JaneGroundShadowEntitySceneObject != 0) {
          *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) =
               *(ushort *)(g_JaneGroundShadowEntitySceneObject + 0xe) & 0x7fff;
        }
        if ((*(ushort *)(g_PlayerEntitySceneObject + 0xe) & 0x8000) != 0) {
          *(ushort *)(g_PlayerEntitySceneObject + 0xe) =
               *(ushort *)(g_PlayerEntitySceneObject + 0xe) & 0x7fff;
        }
        *(undefined4 *)(value + 0xc) = 1;
        SelectBackgroundMusicTrackForLevel(1);
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200e;
        g_JaneScriptedFollowActive = 1;
        *(ushort *)(g_PlayerEntitySceneObject + 0xe) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xe) & 0x7fff;
      }
    }
    else if (*(int *)(value + 0xc) == 1) {
      value2 = entity->sceneObjects;
      value6 = ((EntitySceneObject *)value2)->x + -0x180;
      value4 = ((EntitySceneObject *)value2)->z + 0xc200;
      value5 = ((EntitySceneObject *)value2)->y + 0x800;
      value2 = SqrtToInt(value6 * value6 + value4 * value4);
      value7 = GetAngleFromXZVector12Bit(value6,value4);
      value8 = GetAngleFromXZVector12Bit(value5,value2 >> 6);
      *(ushort *)(g_PlayerEntitySceneObject + 0xe) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xe) & 0x7fff;
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value7 & 0xfff);
      value9 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value9 = *value9 + (short)(value3 >> 1);
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value2 + 0xa0),-(value8 & 0xfff));
      value9 = (short *)(value2 + 0xa0);
      *value9 = *value9 + (short)(value3 >> 1);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->x =
           ((EntitySceneObject *)value2)->x -
           ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw - 0x400 & 0xfff] * 100 >> 0xc);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->z =
           ((EntitySceneObject *)value2)->z -
           ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw & 0xfff] * 100 >> 0xc);
      value2 = entity->sceneObjects;
      ((EntitySceneObject *)value2)->y =
           ((EntitySceneObject *)value2)->y +
           ((short)(&g_SinCosTable12Bit)[*(ushort *)(value2 + 0xa0) - 0x400 & 0xfff] * 100 >> 0xc);
      value7 = SqrtToInt(value5 * value5 + value6 * value6 + value4 * value4);
      if ((int)(value7 & 0xffffffc0) < 0x4000) {
        PlayAudioById(0x23e,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        UnloadEncodedResourceId(5);
        UnloadEncodedResourceId(0x1015);
        UnloadEncodedResourceId(0x18);
        g_PlayerFacingCurrentCollisionSurface = 0;
        g_PendingPlayerDamage = 0;
        *( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) = 0;
        g_PendingPlayerDamageSourceEntity = 0;
        g_PlayerSequenceFlags = 0;
        g_CameraOverrideTargetPtr = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
        *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
        *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
        g_PlayerCurrentCollisionMode =
             CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject(g_PlayerEntitySceneObject,(int)&DAT_004bc670);
        value3 = g_PlayerEntitySceneObjectData;
        value2 = g_PlayerEntitySceneObject;
        g_PlayerMoveHeadingAngle = *(short *)(g_PlayerEntitySceneObject + 0xa2) + 0x800;
        *(undefined4 *)(g_PlayerEntitySceneObject + 0x48) =
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
        *(undefined4 *)(value2 + 0x4c) = *(undefined4 *)(value3 + 0xc);
        *(undefined4 *)(value2 + 0x50) = *(undefined4 *)(value3 + 0x10);
        CPlayerHero::EnterTarzanSurfingWithJaneMode();
        CCamera::Update(1);
        *(undefined4 *)(value + 0xc) = 2;
        *(byte *)(g_PlayerEntitySceneObject + 0xf) =
             *(byte *)(g_PlayerEntitySceneObject + 0xf) | 0x80;
        CEntities::ReleaseEntityToFreeList((byte *)entry);
        return;
      }
    }
  }
  return;
}

