#include "tarzan_ghidra_types.hpp"

// Address: 0x00428F70
// Label: ElephantHairDare::UpdateElephantWaterSplashRing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateElephantWaterSplashRing(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value2 != 0) && (*(int *)(value2 + 0xc) == 0)) {
    if (*(short *)(entry + 0x48) == 0) {
      ((EntitySceneObject *)value2)->worldObject = ((EntitySceneObject *)value2)->worldObject + 0x80;
      *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + -0x80;
      value = entity->sceneObjects;
      if (*(int *)(value + 0x30) == 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      *(int *)(value + 0xa8) = *(int *)(value + 0xa8) + 0x100;
      *(int *)(entity->sceneObjects + 0xb0) = *(int *)(entity->sceneObjects + 0xb0) + 0x100;
      if (0x4000 < *(int *)(entity->sceneObjects + 0xa8)) {
        *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x4000;
      }
      if (0x4000 < *(int *)(entity->sceneObjects + 0xb0)) {
        *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x4000;
      }
    }
    if (*(short *)(entry + 0x48) == 1) {
      ((EntitySceneObject *)value2)->worldObject = ((EntitySceneObject *)value2)->worldObject + 0x40;
      *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + -0x40;
      value2 = entity->sceneObjects;
      if (*(int *)(value2 + 0x30) == 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      *(int *)(value2 + 0xa8) = *(int *)(value2 + 0xa8) + 0x80;
      *(int *)(entity->sceneObjects + 0xb0) = *(int *)(entity->sceneObjects + 0xb0) + 0x80;
      if (0x4000 < *(int *)(entity->sceneObjects + 0xa8)) {
        *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x4000;
      }
      if (0x4000 < *(int *)(entity->sceneObjects + 0xb0)) {
        *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x4000;
      }
    }
  }
  return;
}

