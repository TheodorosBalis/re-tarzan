#include "tarzan_ghidra_types.hpp"

// Address: 0x0045CCB0
// Label: StorkRide::UpdateScriptedObstacleA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateScriptedObstacleA(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value9;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  int value5;
  uint value8;
  int value6;
  int value7;
  int value;
  int value2;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0xe6;
  localState2[0] = 0x20;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  value4 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value4 == 0) {
    return;
  }
  *(short *)(entity->sceneObjects + 0xa4) =
       (short)(((int)(short)(&g_SinCosTable12Bit)[*(int *)(value4 + 0xc) - 0x400U & 0xfff] << 9) >>
              0xc);
  *(uint *)(value4 + 0xc) = *(int *)(value4 + 0xc) + 0x40U & 0xfff;
  value5 = entity->sceneObjects;
  value2 = ((EntitySceneObject *)value5)->x - *(int *)(g_PlayerEntitySceneObjectData + 8);
  value7 = ((EntitySceneObject *)value5)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
  value = ((EntitySceneObject *)value5)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
  value5 = GetAngleFromXZVector12Bit(value2,value);
  value8 = value5 - 0x800U & 0xfff;
  *(uint *)(value4 + 0x18) = value8;
  value5 = entity->sceneObjects;
  value6 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value5)->yaw,value8);
  value9 = (short *)(&((EntitySceneObject *)value5)->yaw);
  *value9 = *value9 + (short)(value6 >> 3);
  if (((value >> 8) * value + (value7 >> 8) * value7 + (value2 >> 8) * value2 < 0xe10) &&
     (*(int *)(value4 + 0x14) != 0)) {
    *(undefined4 *)(value4 + 0x10) = 8;
  }
  value5 = *(int *)(value4 + 0x10);
  if (value5 != 7) {
    if (value5 != 8) {
      if ((value5 == 9) &&
         (shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry), shortValue == 1)) {
        *(undefined2 *)(value3 + 0x16) = 0xffff;
        *(undefined **)(value3 + 0xc) = &DAT_005040cc;
      }
      goto LAB_0045ce18;
    }
    *(undefined4 *)(value4 + 0x10) = 9;
    *(undefined2 *)(value3 + 0x16) = 0xffff;
    *(undefined **)(value3 + 0xc) = &DAT_0050410c;
    *(undefined4 *)(value4 + 0x14) = 0;
  }
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
LAB_0045ce18:
  resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                    (g_PlayerEntitySceneObject,localState,entity->sceneObjects,localState2
                    );
  if ((resultFlag != '\0') && (*(int *)(value4 + 0x1c) == 0)) {
    *(undefined4 *)(value4 + 0x1c) = 1;
    CPlayerHero::EnterStorkTerrainImpactReaction();
  }
  return;
}

