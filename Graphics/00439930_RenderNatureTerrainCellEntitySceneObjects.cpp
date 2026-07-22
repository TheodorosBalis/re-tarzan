#include "tarzan_ghidra_types.hpp"

// Address: 0x00439930
// Label: RenderNatureTerrainCellEntitySceneObjects
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderNatureTerrainCellEntitySceneObjects(int graphicsObject,undefined4 source2)

{
  int entry;
  int entry2;
  int entry3;
  int entry4;
  short *value;
  int entry5;
  
  value = (short *)(*(int *)(graphicsObject + 4) + 4 + graphicsObject);
  entry4 = g_NatureTerrainEntitySceneObjectOffsetTable;
  entry5 = FrameCount;
  for (entry2 = (int)*(short *)(graphicsObject + 2); entry2 != 0; entry2 = entry2 + -1) {
    entry = *(int *)(entry4 + *value * 4) + 0x10 + value[1] * 0x74 + *value * 4;
    entry3 = entry + entry4;
    if (*(int *)(entry + 0x6c + entry4) != entry5) {
      *(int *)(entry3 + 0x6c) = entry5;
      RenderNatureTerrainEntitySceneObject(entry3,source2);
      entry4 = g_NatureTerrainEntitySceneObjectOffsetTable;
      entry5 = FrameCount;
    }
    value = value + 2;
  }
  return;
}

