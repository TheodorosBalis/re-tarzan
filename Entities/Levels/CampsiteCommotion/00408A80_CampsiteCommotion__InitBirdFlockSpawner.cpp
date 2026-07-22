#include "tarzan_ghidra_types.hpp"

// Address: 0x00408A80
// Label: CampsiteCommotion::InitBirdFlockSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBirdFlockSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 *dataCursor;
  int value;
  int value2;
  int value3;
  
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    value3 = entity->sceneObjects;
    *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 4;
    if (value3 != 0) {
      *(undefined2 *)(value3 + 0xe) = 0;
      dataCursor = (undefined4 *)(&((EntitySceneObject *)value3)->x);
      value2 = 8;
      do {
        value = CEntities::SpawnEntityByTypeAtPosition
                          (*dataCursor,((EntitySceneObject *)value3)->y,((EntitySceneObject *)value3)->z,0x112
                           ,0x11);
        if (value != 0) {
          CEntities::AppendEntityToChildChain(entry,value);
        }
        value2 = value2 + -1;
      } while (value2 != 0);
      *(undefined4 *)(entry + 0x4c) = 0;
      PlayAudioById(0x29b,(int *)&g_CampsiteCommotionBirdFlockSoundHandleA,(undefined4 *)dataCursor);
      PlayAudioById(0x29c,(int *)&g_CampsiteCommotionBirdFlockSoundHandleB,(undefined4 *)dataCursor);
    }
    if (*(short *)(entry + 0x44) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  else {
    DetachEntitySoundHandle(&g_CampsiteCommotionBirdFlockSoundHandleA);
    DetachEntitySoundHandle(&g_CampsiteCommotionBirdFlockSoundHandleB);
    value3 = *(int *)(entry + 0x18);
    if (*(int *)(entry + 0x18) != 0) {
      do {
        value2 = ((EntitySceneObject *)value3)->y;
        CEntities::ReleaseEntityToFreeList((byte *)value3);
        value3 = value2;
      } while (value2 != 0);
      return;
    }
  }
  return;
}

