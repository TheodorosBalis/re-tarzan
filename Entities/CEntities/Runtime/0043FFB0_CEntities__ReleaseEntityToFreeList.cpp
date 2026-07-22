#include "tarzan_ghidra_types.hpp"

// Address: 0x0043FFB0
// Label: CEntities::ReleaseEntityToFreeList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::ReleaseEntityToFreeList(byte *entry)

{
  Entity *entity = (Entity *)entry;
  ushort *descriptorFlags;
  int sceneObject;
  
  if ((entity->activeFlags & 1) != 0) {
    if ((entity->descriptor != 0) &&
       ((*(byte *)(entity->descriptor + 0x1a) & 0x10) != 0)) {
      return 0;
    }
    entity->releaseFlags = entity->releaseFlags | 0x80;
    if ((entity->behaviorFlags & 4) != 0) {
      entity->Release(entity);
    }
    if (g_PlayerHeldThrowableEntity == entry) {
      g_PlayerHeldThrowableEntity = (byte *)0x0;
    }
    if (g_PendingPlayerDamageSourceEntity == entry) {
      g_PendingPlayerDamageSourceEntity = (byte *)0x0;
    }
    if (entity->descriptor != 0) {
      descriptorFlags = (ushort *)(entity->descriptor + 0x1a);
      *descriptorFlags = *descriptorFlags & 0xfffe;
    }
    for (sceneObject = entity->sceneObjects; sceneObject != 0; sceneObject = ((EntitySceneObject *)sceneObject)->next) {
      if (((EntitySceneObject *)sceneObject)->linkedSceneObject != 0) {
        ((EntitySceneObject *)((EntitySceneObject *)sceneObject)->linkedSceneObject)->linkedSceneObject = 0;
      }
      ((EntitySceneObject *)sceneObject)->linkedSceneObject = 0;
      if ((((EntitySceneObject *)sceneObject)->resourceSet != 0) || (((EntitySceneObject *)sceneObject)->secondaryResourceSet != 0)) {
        CEntities::ReleaseEntitySceneObjectResourceSet(sceneObject);
      }
      CEntities::ReleaseEntitySceneObjectAttachedSound(sceneObject);
    }
    CEntities::ReleaseEntityAttachments(entry);
    CEntities::UnlinkEntityFromSpawnChain(entry);
    CEntities::UnlinkEntityFromProcessingList(entry);
    if (entity->previous != 0) {
      *(undefined4 *)(entity->previous + 0x10) = entity->next;
      if (entity->next == 0) {
        g_ActiveEntityListTail = entity->previous;
      }
      else {
        *(undefined4 *)(entity->next + 0xc) = entity->previous;
      }
    }
    entry[0] = 0;
    entry[1] = 0;
    entry[2] = 0;
    entry[3] = 0;
    if (g_FreeEntityListHead != (byte *)0x0) {
      *(byte **)(g_FreeEntityListHead + 0xc) = entry;
      entity->next = g_FreeEntityListHead;
      g_FreeEntityListHead = entry;
      entry[0xc] = 0;
      entry[0xd] = 0;
      entry[0xe] = 0;
      entry[0xf] = 0;
      return 1;
    }
    g_FreeEntityListHead = entry;
    entry[0x10] = 0;
    entry[0x11] = 0;
    entry[0x12] = 0;
    entry[0x13] = 0;
    entry[0xc] = 0;
    entry[0xd] = 0;
    entry[0xe] = 0;
    entry[0xf] = 0;
  }
  return 1;
}

