#include "tarzan_ghidra_types.hpp"

// Address: 0x00485B30
// Label: TrashingTheCamp::InitRandomAmbientBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitRandomAmbientBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined2 value4;
  int value2;
  int value3;
  undefined4 value5;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if ((value == 0) ||
     (value2 = CEntities::CreateMotionStateAttachmentAndFlagEntry(entry), value2 == 0))
  goto LAB_00485c59;
  ((EntitySceneObject *)value)->roll = 1;
  value3 = RandomModulo(0x200);
  *(int *)(value2 + 0x20) = value3 + -0x500;
  value3 = RandomModulo(0x30);
  *(int *)(value2 + 0x10) = value3 + 0x20;
  value5 = RandomModulo(0x1000);
  *(undefined4 *)(value2 + 0xc) = value5;
  value3 = RandomModulo(0x20);
  *(int *)(value2 + 0x18) = value3 + 0x50;
  value5 = RandomModulo(0x1000);
  *(undefined4 *)(value2 + 0x14) = value5;
  value3 = RandomModulo(0x180);
  *(int *)(value2 + 0x1c) = value3 + 0x200;
  value5 = RandomModulo(4);
  switch(value5) {
  case 0:
    dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_B;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    goto LAB_00485c33;
  case 1:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
    break;
  case 2:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x7b8;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TrashingTheCampAmbientBirdScriptDesc_B);
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
    *(undefined4 *)(value + 0x70) = 2;
    goto LAB_00485c3e;
  case 3:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x6e8;
    break;
  default:
    goto switchD_00485bc9_default;
  }
  dataCursor = &g_TrashingTheCampAmbientBirdScriptDesc_A;
LAB_00485c33:
  value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
LAB_00485c3e:
  if (value2 != 0) {
    value4 = RandomModulo(9);
    *(undefined2 *)(value2 + 0x16) = value4;
  }
switchD_00485bc9_default:
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
LAB_00485c59:
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

