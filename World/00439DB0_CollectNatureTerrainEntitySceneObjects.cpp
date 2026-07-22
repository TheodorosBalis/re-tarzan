#include "tarzan_ghidra_types.hpp"

// Address: 0x00439DB0
// Label: CollectNatureTerrainEntitySceneObjects
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CollectNatureTerrainEntitySceneObjects(int arg1,undefined4 arg2)

{
  int entry;
  int entry2;
  int entry3;
  int entry4;
  int entry5;
  int entry6;
  int localState3;
  int localState2;
  int localState;
  int localState6;
  int localState5;
  int localState4;
  
  entry = arg1;
  ConvertWorldPosToNatureTerrainGridCoords(arg2,&localState3);
  localState3 = localState3 - g_NatureTerrainVisibleGridCellsX / 2;
  localState2 = localState2 - g_NatureTerrainVisibleGridCellsY / 2;
  localState = localState - g_NatureTerrainVisibleGridCellsZ / 2;
  *(undefined4 *)(arg1 + 0x40) = 0;
  ResolveEntitySceneObjectPointers(arg1);
  arg1 = 0;
  entry2 = g_NatureTerrainVisibleGridCellsX;
  entry3 = g_NatureTerrainVisibleGridCellsZ;
  entry4 = g_NatureTerrainVisibleGridCellsY;
  if (0 < g_NatureTerrainVisibleGridCellsZ) {
    do {
      localState4 = localState + arg1;
      entry5 = 0;
      if (0 < entry4) {
        do {
          localState5 = localState2 + entry5;
          entry6 = 0;
          if (0 < entry2) {
            do {
              localState6 = entry6 + localState3;
              entry2 = FindNatureTerrainEntitySceneObjectAtGridCoords(&localState6);
              if (entry2 != 0) {
                *(int *)(entry + 0x44 + *(int *)(entry + 0x40) * 0x14) = entry2;
                entry2 = entry + 0x48 + *(int *)(entry + 0x40) * 0x14;
                *(int *)(entry + 0x48 + *(int *)(entry + 0x40) * 0x14) = localState6;
                *(int *)(entry2 + 4) = localState5;
                *(int *)(entry2 + 8) = localState4;
                *(int *)(entry + 0x40) = *(int *)(entry + 0x40) + 1;
              }
              entry6 = entry6 + 1;
              entry2 = g_NatureTerrainVisibleGridCellsX;
              entry3 = g_NatureTerrainVisibleGridCellsZ;
              entry4 = g_NatureTerrainVisibleGridCellsY;
            } while (entry6 < g_NatureTerrainVisibleGridCellsX);
          }
          entry5 = entry5 + 1;
        } while (entry5 < entry4);
      }
      arg1 = arg1 + 1;
    } while (arg1 < entry3);
  }
  return;
}

