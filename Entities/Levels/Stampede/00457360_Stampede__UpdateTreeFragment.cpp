#include "tarzan_ghidra_types.hpp"

// Address: 0x00457360
// Label: Stampede::UpdateTreeFragment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stampede::UpdateTreeFragment(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  short *value7;
  int value;
  int value2;
  int value3;
  int *intCursor;
  int value4;
  int value5;
  undefined4 value6;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) {
    return;
  }
  value3 = *(int *)(value2 + 0xc);
  if (value3 == 7) {
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) - *(int *)(value2 + 0x18);
    *(int *)(entity->sceneObjects + 0x1c) =
         *(int *)(entity->sceneObjects + 0x1c) - *(int *)(value2 + 0x24);
    *(int *)(entity->sceneObjects + 0x18) =
         (*(int *)(value2 + 0x2c) * *(int *)(value2 + 0x28) -
         ((int)((&g_ParabolicArcHeightOffsetTable)[*(int *)(value2 + 0x1c)] << 9) >> 0xc)) +
         *(int *)(value2 + 0x30);
    *(uint *)(value2 + 0x1c) = *(int *)(value2 + 0x20) + *(int *)(value2 + 0x1c) & 0xff;
    value7 = (short *)(entity->sceneObjects + 0xa2);
    *value7 = *value7 + 0x100;
    value7 = (short *)(entity->sceneObjects + 0xa0);
    *value7 = *value7 + 0x20;
    if (*(int *)(value2 + 0x1c) != 0) {
      return;
    }
    *(undefined4 *)(value2 + 0xc) = 0xc;
    return;
  }
  if (value3 == 10) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  if (value3 != 0xc) {
    return;
  }
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  _g_CampBoxCameraShakeTimer = 0x20;
  _g_CampBoxCameraShakeAmplitude = 0x10;
  PlayForceFeedbackEffect_Stub(0,2,0xf);
  value3 = RandomModulo(10);
  if (value3 == 0) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1c7;
  }
  else if (value3 == 1) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1c8;
  }
  else if (value3 == 2) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1c9;
  }
  else if (value3 == 3) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1ca;
  }
  else if (value3 == 4) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1cb;
  }
  else if (value3 == 5) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1cc;
  }
  else if (value3 == 6) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1cd;
  }
  else if (value3 == 7) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1ce;
  }
  else if (value3 == 8) {
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1cf;
  }
  else {
    if (value3 != 9) goto LAB_004574b0;
    value3 = entity->sceneObjects + 0x14;
    value6 = 0x1d0;
  }
  PlayAudioById(value6,(int *)0,(undefined4 *)value3);
LAB_004574b0:
  value3 = entity->sceneObjects;
  intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + 0x100,
                             ((EntitySceneObject *)value3)->z,0x178,0x11);
  if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
    *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
    *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2038;
    value3 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
    if (value3 != 0) {
      value = *(int *)(entity->sceneObjects + 0x18);
      *(undefined4 *)(value3 + 0x524) = 0x100;
      ((EntitySceneObject *)value3)->next = value + 0x200;
    }
  }
  value3 = entity->sceneObjects;
  value3 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                     ((EntitySceneObject *)value3)->z + -0x200,0x15e,0x11);
  if (value3 != 0) {
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 0x2134;
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 0x2134;
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 0x2134;
  }
  value3 = entity->sceneObjects;
  value = *(int *)(g_PlayerEntity + 0x38);
  value4 = *(int *)(value + 0x14) - ((EntitySceneObject *)value3)->x;
  value5 = *(int *)(value + 0x18) - ((EntitySceneObject *)value3)->y;
  value3 = *(int *)(value + 0x1c) - ((EntitySceneObject *)value3)->z;
  if (value3 * value3 + value5 * value5 + value4 * value4 < 0x1de84) {
    QueuePlayerDamageEvent(entry,4);
  }
  *(undefined4 *)(value2 + 0xc) = 10;
  return;
}

