#include "tarzan_ghidra_types.hpp"

// Address: 0x00418550
// Label: ComingOfAge::InitScriptedScenePropVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitScriptedScenePropVariant(int entry3)

{
  Entity *entity = (Entity *)entry3;
  short shortValue;
  int entry;
  int entry2;
  undefined4 value;
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
    value = 4;
LAB_004185a2:
    localState2 = RandomModulo(value);
  }
  else if (localState2 == 0x62) {
    localState2 = RandomModulo(4);
    localState2 = localState2 + 4;
  }
  else if (localState2 == 99) {
    value = 8;
    goto LAB_004185a2;
  }
  entry2 = entity->sceneObjects;
  *(undefined2 *)(entry3 + 0x4a) = 0;
  if (entry2 == 0) {
    return;
  }
  switch(localState2) {
  case 0:
    dataCursor = &DAT_004c39d8;
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    goto LAB_00418747;
  case 1:
    dataCursor = &DAT_004c39d8;
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    goto LAB_00418631;
  case 2:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
    goto LAB_00418742;
  case 3:
    dataCursor = &DAT_004c39e8;
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
LAB_00418631:
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)dataCursor);
    *(ushort *)(entry2 + 0xe) = *(ushort *)(entry2 + 0xe) | 0x200;
    *(undefined4 *)(entry2 + 0x70) = 2;
    break;
  case 4:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c39c8);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 0x10;
    break;
  case 5:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x820;
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c39f8);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 0x10;
    break;
  case 6:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c39c8);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 0x10;
    *(ushort *)(entry2 + 0xe) = *(ushort *)(entry2 + 0xe) | 0x200;
    *(undefined4 *)(entry2 + 0x70) = 2;
    break;
  case 7:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x750;
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c39c8);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 0x10;
    *(ushort *)(entry2 + 0xe) = *(ushort *)(entry2 + 0xe) | 0x200;
    *(undefined4 *)(entry2 + 0x70) = 3;
    break;
  default:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
LAB_00418742:
    dataCursor = &DAT_004c39e8;
    goto LAB_00418747;
  case 0x10:
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x958;
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c3a08);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 0x10;
    break;
  case 0x11:
    dataCursor = &DAT_004c3a18;
    ((EntitySceneObject *)entry2)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x888;
LAB_00418747:
    entry = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)dataCursor);
  }
  ((EntitySceneObject *)entry2)->roll = 2;
  *(undefined4 *)(entry2 + 0x40) = 0;
  if (entry == 0) goto LAB_00418872;
  if (localState2 == 0x10) {
    shortValue = RandomModulo(0x10);
    *(short *)(entry + 0x16) = shortValue;
    if (7 < shortValue) {
LAB_004187a0:
      *(short *)(entry + 0x16) = shortValue + 2;
    }
  }
  else if (localState2 != 0x11) {
    shortValue = RandomModulo(8);
    *(short *)(entry + 0x16) = shortValue;
    if (4 < shortValue) goto LAB_004187a0;
  }
  entry2 = CEntities::CreateEntityAttachment(entry3,0x2c,0x10000000);
  if (entry2 != 0) {
    *(short *)(entry2 + 0x20) = (short)localState2;
    *(undefined4 *)(entry2 + 0xc) = 0;
    ((EntitySceneObject *)entry2)->z = 1000;
    ((EntitySceneObject *)entry2)->x = 0x10;
    ((EntitySceneObject *)entry2)->worldObject = 0;
    *(undefined2 *)(entry2 + 0x12) = 1;
    *(undefined2 *)(entry2 + 0x16) = 0;
    ((EntitySceneObject *)entry2)->y = 0;
    *(undefined4 *)(entry2 + 0x28) = 0;
    *(undefined2 *)(entry2 + 0x22) = 0xfa;
    *(undefined4 *)(entry2 + 0x24) = 0;
    entry = entity->descriptor;
    *(undefined2 *)(entry3 + 0x48) = 1;
    *(undefined4 *)(entry3 + 0x4c) = 0;
    if (entry != 0) {
      if ((*(byte *)(*(int *)(entry + 0x10) + 3) & 1) != 0) {
        *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 8;
      }
      if ((*(byte *)(*(int *)(entry + 0x10) + 2) & 0x20) != 0) {
        *(byte *)(entry3 + 0x4b) = *(byte *)(entry3 + 0x4b) | 2;
      }
      if ((*(byte *)(*(int *)(entry + 0x10) + 2) & 0x40) != 0) {
        *(ushort *)(entry3 + 0x4a) = *(ushort *)(entry3 + 0x4a) | 0x20;
      }
    }
    ((EntitySceneObject *)entry2)->z = 1000;
    if (localState != 0) {
      ((EntitySceneObject *)entry2)->x = *(undefined2 *)(localState + 8);
      ((EntitySceneObject *)entry2)->z = *(undefined4 *)(localState + 0xc);
      if (*(int *)(localState + 0xc) == 0) {
        ((EntitySceneObject *)entry2)->z = 1000;
      }
      if (*(int *)(localState + 0xc) == 1) {
        ((EntitySceneObject *)entry2)->z = 100000;
      }
    }
    if (((EntitySceneObject *)entry2)->x != 0) {
      return;
    }
    ((EntitySceneObject *)entry2)->x = 0x10;
    return;
  }
LAB_00418872:
  CEntities::ReleaseEntityToFreeList((byte *)entry3);
  return;
}

