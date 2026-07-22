#include "tarzan_ghidra_types.hpp"

// Address: 0x00468A00
// Label: TarzanToTheRescue::UpdateFish
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateFish(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 value3;
  short shortValue;
  int value;
  uint value4;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue == 1) {
      value4 = (uint)*(short *)(entity->sceneObjects + 0xa2);
      value3 = *(undefined4 *)(value + 0x1c);
      value2 = *(int *)(value + 0x18) -
              ((short)(&g_SinCosTable12Bit)[value4 - 0x400 & 0xfff] * 0xe6 >> 0xc);
      value = *(int *)(value + 0x20) - ((short)(&g_SinCosTable12Bit)[value4 & 0xfff] * 0xe6 >> 0xc);
      CEntities::SpawnEntityByTypeAtPosition(value2,value3,value,0x193,0x11);
      CEntities::SpawnEntityByTypeAtPosition(value2,value3,value,0x195,0x11);
      value = RandomModulo(3);
      if (value == 0) {
        PlayAudioById(0x3c3,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      if (value == 1) {
        PlayAudioById(0x3c4,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      if (value == 2) {
        PlayAudioById(0x3c5,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
    else if (shortValue == 3) {
      value = RandomModulo(3);
      if (value == 0) {
        PlayAudioById(0x3be,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 1) {
        PlayAudioById(0x3bf,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 2) {
        PlayAudioById(0x3c0,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
    }
  }
  return;
}

