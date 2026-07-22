#include "tarzan_ghidra_types.hpp"

// Address: 0x00406F30
// Label: RockinTheBoat::InitDeckKnifeEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitDeckKnifeEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  int value4;
  undefined *dataCursor;
  
  if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) < -0x500) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  value = entity->sceneObjects;
  if (value == 0) {
    return;
  }
  *(undefined2 *)(entry + 0x3e) = 0x230;
  *(undefined2 *)(entry + 0x4a) = 0;
  *(undefined2 *)(entry + 0x48) = 0;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  ((EntitySceneObject *)value)->roll = 0;
  value3 = CEntities::CreateEntityAttachment(entry,200,0x10000000);
  if (value3 == 0) goto LAB_00407101;
  *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7dff | 0x200;
  value4 = g_RockinTheBoatNextKnifeEnemyVariant;
  g_RockinTheBoatNextKnifeEnemyVariant = g_RockinTheBoatNextKnifeEnemyVariant + 1;
  if (6 < g_RockinTheBoatNextKnifeEnemyVariant) {
    g_RockinTheBoatNextKnifeEnemyVariant = 1;
  }
  *(int *)(value3 + 0x58) = value4;
  value2 = g_WorldEntitySceneObjectArrayBase;
  switch(value4) {
  case 1:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x28a0;
    value4 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant1Setup);
    *(undefined4 *)(value + 0x70) = 1;
    *(undefined4 *)(entry + 0x50) = 0x1c;
    break;
  default:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2970;
    *(undefined4 *)(value + 0x70) = 1;
    value4 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant5Setup);
    *(undefined4 *)(entry + 0x50) = 0x30;
    break;
  case 3:
    *(undefined4 *)(value + 0x70) = 1;
    dataCursor = &g_RockinKnifeEnemyVariant6Setup;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x29d8;
    goto LAB_0040709b;
  case 4:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2698;
    *(undefined4 *)(value + 0x70) = 1;
    value4 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant2Setup);
    *(undefined4 *)(entry + 0x50) = 0x1e;
    break;
  case 5:
    *(undefined4 *)(value + 0x70) = 1;
    dataCursor = &g_RockinKnifeEnemyVariant4Setup;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x2700;
LAB_0040709b:
    value4 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    *(undefined4 *)(entry + 0x50) = 0x28;
    break;
  case 6:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2838;
    *(undefined4 *)(value + 0x70) = 1;
    value4 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant3Setup);
    *(undefined4 *)(entry + 0x50) = 0x1c;
  }
  CEntities::AcquireEntitySceneObjectResourceSet(value);
  *(undefined4 *)(value3 + 0xc) = 10;
  *(int *)(value3 + 0x10) = value4;
  if (value4 != 0) {
    CEntities::SelectScriptAttachmentSequence(value4,1);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
LAB_00407101:
  CEntities::LinkEntityIntoProcessingList(&g_ScriptedEnemyEntityListHead,entry);
  return;
}

