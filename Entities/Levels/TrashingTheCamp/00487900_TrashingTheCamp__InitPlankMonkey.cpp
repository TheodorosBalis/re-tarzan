#include "tarzan_ghidra_types.hpp"

// Address: 0x00487900
// Label: TrashingTheCamp::InitPlankMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitPlankMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3468;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_TrashingTheCampThrownPropControllerScriptDesc);
    CEntities::CreateRuntimeMotionStateAttachment(entry);
    *(undefined4 *)(value + 0x6c) = 0xffffffe2;
  }
  CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

