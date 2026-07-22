#include "tarzan_ghidra_types.hpp"

// Address: 0x00445160
// Label: RenderSceneModelNode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderSceneModelNode(int graphicsObject)

{
  int entry;
  int *intCursor;
  int entry2;
  int entry3;
  int entry4;
  char resultFlag;
  int *intCursor2;
  int entry5;
  
  entry2 = *(int *)(graphicsObject + 0x10);
  entry3 = *(int *)(entry2 + 0xc);
  entry = *(int *)(entry3 + 8) + 8 + entry3;
  entry5 = *(int *)(entry + 8 + (*(ushort *)(graphicsObject + 0xc) & 0xfff) * 4);
  resultFlag = (char)entry5;
  entry4 = entry3;
  if ((resultFlag == '\0') || (entry4 = *(int *)(entry2 + 0x28 + resultFlag * 8), entry4 != 0)) {
    intCursor2 = (int *)((entry5 >> 8) + entry4);
    intCursor = (int *)(*(int *)(entry3 + 4) + 4 + entry3);
    if ((*(ushort *)(graphicsObject + 0xe) & 0x200) == 0) {
      entry5 = *intCursor2;
    }
    else {
      if ((int *)(*intCursor + (int)intCursor) <= intCursor + *(int *)(graphicsObject + 0x70)) {
        *(undefined4 *)(graphicsObject + 0x70) = 0;
      }
      entry5 = *(int *)(graphicsObject + 0x70);
    }
    g_ModelHierarchyCommandCursor = intCursor[entry5] + entry5 * 4 + (int)intCursor;
    if (*(short *)(graphicsObject + 0x78) == 0) {
      g_RenderModelCurrentFlags = *(short *)(graphicsObject + 0x7a);
      if (g_RenderModelCurrentFlags < 1) {
        g_RenderModelCurrentFlags = 0;
      }
      else {
        g_ModelHierarchyRotationOverrideCursor = graphicsObject + 0x80;
      }
      RenderModelHierarchy(intCursor2,intCursor2,*(undefined2 *)(graphicsObject + 0xe));
    }
    else {
      entry = *(int *)(entry + 8 + (*(ushort *)(graphicsObject + 0x76) & 0xfff) * 4);
      resultFlag = (char)entry;
      if ((resultFlag == '\0') || (entry3 = *(int *)(entry2 + 0x28 + resultFlag * 8), entry3 != 0)) {
        RenderInterpolatedModelHierarchy
                  (intCursor2,(entry >> 8) + entry3,(int)*(short *)(graphicsObject + 0x78),
                   &g_ModelHierarchyTransformStackBase,*(ushort *)(graphicsObject + 0xe) & 0x800);
        return;
      }
    }
  }
  return;
}

