#include "tarzan_ghidra_types.hpp"

// Address: 0x00442BE0
// Label: CEntities::IsWorldPointInsideEntitySceneObjectBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::IsWorldPointInsideEntitySceneObjectBounds(int entry4,int *sceneObject)

{
  short *value;
  int entry;
  int entry2;
  int entry3;
  short localState11;
  short localState10;
  short localState9;
  uint localState8;
  int localState7;
  int localState6;
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  value = (short *)CEntities::GetEntitySceneObjectCurrentLocalBounds(entry4);
  if (value != (short *)0x0) {
    localState3 = (int)value[1];
    localState2 = (int)value[2];
    entry = (int)value[3];
    localState5 = (int)value[4];
    entry3 = (int)*value;
    localState4 = (int)value[5];
    entry2 = localState2;
    if (*(int *)(entry4 + 0xb4) == 1) {
      entry3 = *(int *)(entry4 + 0xa8) * entry3 >> 0xc;
      localState3 = *(int *)(entry4 + 0xac) * localState3 >> 0xc;
      entry2 = *(int *)(entry4 + 0xb0) * localState2 >> 0xc;
      entry = *(int *)(entry4 + 0xa8) * entry >> 0xc;
      localState5 = *(int *)(entry4 + 0xac) * localState5 >> 0xc;
      localState4 = *(int *)(entry4 + 0xb0) * localState4 >> 0xc;
    }
    localState8 = (*sceneObject - *(int *)(entry4 + 0x14)) - *(int *)(entry4 + 0x3c);
    localState7 = (sceneObject[1] - *(int *)(entry4 + 0x18)) - *(int *)(entry4 + 0x40);
    localState6 = (sceneObject[2] - *(int *)(entry4 + 0x1c)) - *(int *)(entry4 + 0x44);
    if (*(short *)(entry4 + 0xa6) != 3) {
      localState11 = -*(short *)(entry4 + 0xa0);
      localState10 = -*(short *)(entry4 + 0xa2);
      localState9 = -*(short *)(entry4 + 0xa4);
      BuildRotationMatrixFromEulerAngles12Bit(&localState11,localState);
      TransformVectorByBasis(localState,&localState8,&localState8);
    }
    if ((((entry3 <= (int)localState8) && ((int)localState8 <= entry)) && (localState5 <= localState7)) &&
       (((localState7 <= localState3 && (entry2 <= localState6)) && (localState6 <= localState4)))) {
      return 1;
    }
  }
  return 0;
}

