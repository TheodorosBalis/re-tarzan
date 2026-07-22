#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A320
// Label: RenderNatureTerrainEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderNatureTerrainEntitySceneObject(char *graphicsObject,undefined4 source2)

{
  char resultFlag;
  undefined4 value;
  int *intCursor;
  int entry;
  
  resultFlag = *graphicsObject;
  if (resultFlag == '\0') {
    entry = ResolveSceneAssetRelativePointerEntry(graphicsObject + *(int *)(graphicsObject + 4) + 4);
    if (entry != 0) {
      RenderNatureTerrainModelEntry(graphicsObject,entry,source2);
    }
  }
  else {
    if (resultFlag == '\x01') {
      value = BuildNatureTerrainEntitySceneObjectTransform(graphicsObject,source2);
      SetTransformBasisFromRef(value);
      entry = *(int *)(g_NatureTerrainRenderContext + 0xc);
      intCursor = (int *)((*(int *)(graphicsObject + *(int *)(graphicsObject + 4) + 4 + graphicsObject[3] * 4) >> 8) + entry
                      );
      entry = *(int *)(entry + 4) + 4 + entry;
      g_RenderModelCurrentFlags = 0;
      g_ModelHierarchyCommandCursor = *(int *)(*intCursor * 4 + entry) + *intCursor * 4 + entry;
      RenderModelHierarchy(intCursor,intCursor,0);
      return;
    }
    if (resultFlag == '\x02') {
      RenderNatureTerrainModelEntry(graphicsObject,*(undefined4 *)(graphicsObject + 4),source2);
      return;
    }
  }
  return;
}

