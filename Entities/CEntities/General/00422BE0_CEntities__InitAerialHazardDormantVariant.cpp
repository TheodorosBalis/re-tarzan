#include "tarzan_ghidra_types.hpp"

// Address: 0x00422BE0
// Label: CEntities::InitAerialHazardDormantVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitAerialHazardDormantVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if (value == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  ((EntitySceneObject *)value)->worldObject = 0;
  if ((entity->descriptor != 0) &&
     (value2 = *(int *)(entity->descriptor + 0x10), value2 != 0)) {
    value2 = *(int *)(value2 + 0x10);
    if (value2 == 0) {
      dataCursor = &DAT_004c6918;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2768;
    }
    else {
      if (value2 != 1) goto LAB_00422c42;
      dataCursor = &DAT_004c6928;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xbc8;
    }
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
  }
LAB_00422c42:
  if (((EntitySceneObject *)value)->worldObject == 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2768;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6918);
  }
  ((EntitySceneObject *)value)->roll = 2;
  *(undefined4 *)(value + 0x40) = 0;
  CEntities::AcquireEntitySceneObjectResourceSet(value);
  *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
  *(undefined2 *)(entry + 0x48) = 0;
  return;
}

