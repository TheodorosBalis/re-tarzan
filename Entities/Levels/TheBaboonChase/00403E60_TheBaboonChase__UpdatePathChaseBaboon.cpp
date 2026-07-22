#include "tarzan_ghidra_types.hpp"

// Address: 0x00403E60
// Label: TheBaboonChase::UpdatePathChaseBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdatePathChaseBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value7;
  int value;
  int value2;
  uint value6;
  int value3;
  int value4;
  int value5;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    value5 = (*(int *)(value2 + 0x18) * 0x8c) / 0xf;
    value6 = *(ushort *)(entity->sceneObjects + 0xa2) + 0x400 & 0xfff;
    *(int *)(entity->sceneObjects + 0x3c) =
         -((short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * value5) >> 0xc;
    *(int *)(entity->sceneObjects + 0x44) =
         -((short)(&g_SinCosTable12Bit)[value6] * value5) >> 0xc;
    value5 = value5 + value5 / 2;
    value6 = -value5 & 0xfff;
    *(int *)(entity->sceneObjects + 0x40) =
         -((short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * value5) >> 0xc;
    *(short *)(entity->sceneObjects + 0xa4) = (short)value6;
    value5 = *(int *)(value2 + 0xc);
    if (value5 == 0) {
      value5 = *(int *)(g_PlayerEntitySceneObject + 0x10c);
      value3 = *(int *)(entity->sceneObjects + 0x10c);
      value7 = (byte *)(entity->sceneObjects + 0xf);
      *value7 = *value7 | 0x80;
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles
                (entry,g_PlayerSurfaceMotionSpeed + 0x14);
      value = entity->sceneObjects;
      value4 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value4;
      if (value5 - value3 < 800) {
        *(undefined4 *)(value2 + 0xc) = 2;
        value5 = RandomModulo(0x40);
        *(int *)(value2 + 0x14) = value5 + 0x40;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    else if (value5 == 1) {
      if (2000 < *(int *)(g_PlayerEntitySceneObject + 0x10c) -
                 *(int *)(entity->sceneObjects + 0x10c)) {
        *(undefined4 *)(value2 + 0xc) = 0;
        return;
      }
    }
    else if (value5 == 2) {
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles
                (entry,g_PlayerSurfaceMotionSpeed + -10);
      value5 = entity->sceneObjects;
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value5);
      ((EntitySceneObject *)value5)->y = ((EntitySceneObject *)value5)->y + value3;
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value5 = *(int *)(value2 + 0x14);
      *(int *)(value2 + 0x14) = value5 + -1;
      if (value5 < 0) {
        *(undefined4 *)(value2 + 0xc) = 0;
        return;
      }
    }
  }
  return;
}

