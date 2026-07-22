#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A140
// Label: BuildNatureTerrainEntitySceneObjectTransform
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * BuildNatureTerrainEntitySceneObjectTransform(int arg1,int arg2)

{
  Entity *entity = (Entity *)arg1;
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x20) - g_CameraFocusX;
  *(int *)(arg1 + 0x44) = *(int *)(arg1 + 0x24) - g_CameraFocusY;
  *(int *)(arg1 + 0x48) = *(int *)(arg1 + 0x28) - g_CameraFocusZ;
  ComposeFixedPointAffineTransforms
            (arg2 + 0x68,arg1 + 0x2c,&g_ModelHierarchyTransformStackBase);
  SetTransformBasisFromRef(&g_ModelHierarchyTransformStackBase);
  return &g_ModelHierarchyTransformStackBase;
}

