#include "tarzan_ghidra_types.hpp"

// Address: 0x00429980
// Label: GoingApe::InitBirdCommon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitBirdCommon(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  undefined4 value3;
  undefined *dataCursor;
  int localState2;
  int localState;
  
  localState = 0;
  localState2 = 0;
  if ((entity->descriptor != 0) &&
     (localState = *(int *)(entity->descriptor + 0x10), localState != 0)) {
    localState2 = *(int *)(localState + 4);
  }
  if (localState2 == 0x61) {
    value3 = 4;
LAB_004299d2:
    localState2 = RandomModulo(value3);
  }
  else if (localState2 == 0x62) {
    localState2 = RandomModulo(4);
    localState2 = localState2 + 4;
  }
  else if (localState2 == 99) {
    value3 = 8;
    goto LAB_004299d2;
  }
  value2 = entity->sceneObjects;
  *(undefined2 *)(entry + 0x4a) = 0;
  if (value2 == 0) {
    return;
  }
  switch(localState2) {
  case 0:
    dataCursor = &g_GoingApeBirdScriptDesc_328;
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    goto LAB_00429b77;
  case 1:
    dataCursor = &g_GoingApeBirdScriptDesc_328;
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    goto LAB_00429a61;
  case 2:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
    goto LAB_00429b72;
  case 3:
    dataCursor = &g_GoingApeBirdScriptDesc_338;
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
LAB_00429a61:
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    *(ushort *)(value2 + 0xe) = *(ushort *)(value2 + 0xe) | 0x200;
    *(undefined4 *)(value2 + 0x70) = 2;
    break;
  case 4:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeBirdScriptDesc_318);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x10;
    break;
  case 5:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x820;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeBirdScriptDesc_348);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x10;
    break;
  case 6:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeBirdScriptDesc_318);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x10;
    *(ushort *)(value2 + 0xe) = *(ushort *)(value2 + 0xe) | 0x200;
    *(undefined4 *)(value2 + 0x70) = 2;
    break;
  case 7:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeBirdScriptDesc_318);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x10;
    *(ushort *)(value2 + 0xe) = *(ushort *)(value2 + 0xe) | 0x200;
    *(undefined4 *)(value2 + 0x70) = 3;
    break;
  default:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
LAB_00429b72:
    dataCursor = &g_GoingApeBirdScriptDesc_338;
    goto LAB_00429b77;
  case 0x10:
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x958;
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeBirdScriptDesc_358);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x10;
    break;
  case 0x11:
    dataCursor = &g_GoingApeBirdScriptDesc_368;
    ((EntitySceneObject *)value2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x888;
LAB_00429b77:
    value = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
  }
  ((EntitySceneObject *)value2)->roll = 2;
  *(undefined4 *)(value2 + 0x40) = 0;
  if (value == 0) goto LAB_00429ca2;
  if (localState2 == 0x10) {
    shortValue = RandomModulo(0x10);
    *(short *)(value + 0x16) = shortValue;
    if (7 < shortValue) {
LAB_00429bd0:
      *(short *)(value + 0x16) = shortValue + 2;
    }
  }
  else if (localState2 != 0x11) {
    shortValue = RandomModulo(8);
    *(short *)(value + 0x16) = shortValue;
    if (4 < shortValue) goto LAB_00429bd0;
  }
  value2 = CEntities::CreateEntityAttachment(entry,0x2c,0x10000000);
  if (value2 != 0) {
    *(short *)(value2 + 0x20) = (short)localState2;
    *(undefined4 *)(value2 + 0xc) = 0;
    ((EntitySceneObject *)value2)->z = 1000;
    ((EntitySceneObject *)value2)->x = 0x10;
    ((EntitySceneObject *)value2)->worldObject = 0;
    *(undefined2 *)(value2 + 0x12) = 1;
    *(undefined2 *)(value2 + 0x16) = 0;
    ((EntitySceneObject *)value2)->y = 0;
    *(undefined4 *)(value2 + 0x28) = 0;
    *(undefined2 *)(value2 + 0x22) = 0xfa;
    *(undefined4 *)(value2 + 0x24) = 0;
    value = entity->descriptor;
    *(undefined2 *)(entry + 0x48) = 1;
    *(undefined4 *)(entry + 0x4c) = 0;
    if (value != 0) {
      if ((*(byte *)(*(int *)(value + 0x10) + 3) & 1) != 0) {
        *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 8;
      }
      if ((*(byte *)(*(int *)(value + 0x10) + 2) & 0x20) != 0) {
        *(byte *)(entry + 0x4b) = *(byte *)(entry + 0x4b) | 2;
      }
      if ((*(byte *)(*(int *)(value + 0x10) + 2) & 0x40) != 0) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x20;
      }
    }
    ((EntitySceneObject *)value2)->z = 1000;
    if (localState != 0) {
      ((EntitySceneObject *)value2)->x = *(undefined2 *)(localState + 8);
      ((EntitySceneObject *)value2)->z = *(undefined4 *)(localState + 0xc);
      if (*(int *)(localState + 0xc) == 0) {
        ((EntitySceneObject *)value2)->z = 1000;
      }
      if (*(int *)(localState + 0xc) == 1) {
        ((EntitySceneObject *)value2)->z = 100000;
      }
    }
    if (((EntitySceneObject *)value2)->x != 0) {
      return;
    }
    ((EntitySceneObject *)value2)->x = 0x10;
    return;
  }
LAB_00429ca2:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

