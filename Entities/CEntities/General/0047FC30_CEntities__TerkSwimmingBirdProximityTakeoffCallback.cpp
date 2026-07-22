#include "tarzan_ghidra_types.hpp"

// Address: 0x0047FC30
// Label: CEntities::TerkSwimmingBirdProximityTakeoffCallback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::TerkSwimmingBirdProximityTakeoffCallback(int entry,int sceneObject)

{
  undefined2 value3;
  short shortValue;
  int value;
  int value2;
  
  if (((((*(byte *)(entry + 0x4a) & 0x40) == 0) &&
       (value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000), value != 0)) &&
      (value2 = CEntities::ComputeEntitySceneObjectDataDistance3D
                         (sceneObject + 0xc,g_PlayerEntitySceneObjectData),
      value2 < *(int *)(value + 0x1c))) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 != 0)) {
    switch(*(undefined2 *)(value + 0x20)) {
    case 0:
    case 2:
    case 5:
      *(undefined4 *)(sceneObject + 0x70) = 0;
      break;
    case 1:
    case 3:
    case 6:
      *(undefined4 *)(sceneObject + 0x70) = 2;
      break;
    case 4:
      *(undefined4 *)(sceneObject + 0x70) = 1;
      break;
    case 7:
      *(undefined4 *)(sceneObject + 0x70) = 3;
    }
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x40;
    CEntities::SelectScriptAttachmentSequence(value2,0);
    value3 = RandomModulo(0xf);
    *(undefined2 *)(value + 0x10) = value3;
    shortValue = RandomModulo(4);
    *(undefined2 *)(value + 0x14) = 0x28;
    *(short *)(value + 0x12) = shortValue + 1;
    *(undefined2 *)(entry + 0x48) = 5;
    value = RandomModulo(3);
    if (value == 0) {
      PlayAudioById(0xe2,(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
    }
    else {
      if (value == 1) {
        PlayAudioById(0xe3,(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
        return;
      }
      if (value == 2) {
        PlayAudioById(0xe4,(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
        return;
      }
    }
  }
  return;
}

