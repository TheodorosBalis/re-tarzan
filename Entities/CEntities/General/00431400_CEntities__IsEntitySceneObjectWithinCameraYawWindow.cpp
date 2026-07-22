#include "tarzan_ghidra_types.hpp"

// Address: 0x00431400
// Label: CEntities::IsEntitySceneObjectWithinCameraYawWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::IsEntitySceneObjectWithinCameraYawWindow(int entry2,int sceneObject)

{
  int entry;
  uint value;
  uint3 value2;
  
  entry = GetAngleFromXZVector12Bit(*(undefined4 *)(entry2 + 0x1c),*(undefined4 *)(entry2 + 0x14))
  ;
  value = (entry + 0x400) - (uint)g_CameraYaw & 0xfff;
  value2 = (uint3)(value >> 8);
  if ((int)value < 0x800 - sceneObject) {
    return (uint)value2 << 8;
  }
  return CONCAT31(value2,(int)value <= sceneObject + 0x800);
}

