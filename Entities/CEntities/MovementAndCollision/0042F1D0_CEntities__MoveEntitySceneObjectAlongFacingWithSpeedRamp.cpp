#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F1D0
// Label: CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp(int entry3,int *sceneObject,int attachment)

{
  short shortValue;
  int entry;
  int entry2;
  
  entry = sceneObject[3];
  entry2 = *sceneObject;
  if (entry != entry2) {
    if (entry2 < entry) {
      sceneObject[3] = entry - sceneObject[2];
      if (entry2 <= entry - sceneObject[2]) goto LAB_0042f1fb;
    }
    else {
      sceneObject[3] = entry + sceneObject[1];
      if (entry + sceneObject[1] <= entry2) goto LAB_0042f1fb;
    }
    sceneObject[3] = entry2;
  }
LAB_0042f1fb:
  if (attachment == 0) {
    entry = sceneObject[3];
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(entry3 + 0xa2) & 0xfff];
    *(int *)(entry3 + 0x14) =
         *(int *)(entry3 + 0x14) -
         ((short)(&g_SinCosTable12Bit)[(int)*(short *)(entry3 + 0xa2) - 0x400U & 0xfff] * entry >>
         0xc);
    *(int *)(entry3 + 0x1c) = *(int *)(entry3 + 0x1c) - (shortValue * entry >> 0xc);
  }
  return;
}

