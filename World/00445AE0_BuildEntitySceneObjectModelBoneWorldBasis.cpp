#include "tarzan_ghidra_types.hpp"

// Address: 0x00445AE0
// Label: BuildEntitySceneObjectModelBoneWorldBasis
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * BuildEntitySceneObjectModelBoneWorldBasis(int arg1,int arg2)

{
  uint value;
  undefined4 *dataCursor;
  int entry;
  int *intCursor;
  int entry2;
  bool flagByte;
  undefined2 localState4;
  ushort localState3;
  ushort localState2;
  undefined1 localState [20];
  int localState7;
  int localState6;
  int localState5;
  
  entry2 = *(int *)(*(int *)(arg1 + 0x10) + 0xc);
  entry = *(int *)(entry2 + 4) + 4 + entry2;
  intCursor = (int *)((*(int *)(*(int *)(entry2 + 8) + 0x10 + (*(ushort *)(arg1 + 0xc) & 0xfff) * 4 +
                            entry2) >> 8) + entry2);
  entry2 = *intCursor * 4;
  g_ModelHierarchyCommandCursor = (uint *)(*(int *)(entry2 + entry) + entry2 + entry);
  g_ModelHierarchyPackedTransformCursor = intCursor + 5;
  g_ModelHierarchyTransformStackCursor = &g_ModelHierarchyTransformStackBase;
  do {
    value = *g_ModelHierarchyCommandCursor;
    if ((value & 4) == 0) {
      localState7 = (int)(short)g_ModelHierarchyCommandCursor[2];
      localState6 = (int)*(short *)((int)g_ModelHierarchyCommandCursor + 10);
      localState5 = (int)(short)g_ModelHierarchyCommandCursor[3];
    }
    else {
      localState7 = (*g_ModelHierarchyPackedTransformCursor << 0x15) >> 0x15;
      localState6 = (*g_ModelHierarchyPackedTransformCursor << 10) >> 0x15;
      localState5 = *g_ModelHierarchyPackedTransformCursor >> 0x16;
      g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    }
    TransformVectorByBasis
              (g_ModelHierarchyTransformStackCursor,&localState7,
               g_ModelHierarchyTransformStackCursor + 0xe);
    if ((value & 0x10) == 0) {
      g_ModelHierarchyTransformStackCursor[0xe] =
           g_ModelHierarchyTransformStackCursor[0xe] + g_ModelHierarchyTransformStackCursor[5];
      g_ModelHierarchyTransformStackCursor[0xf] =
           g_ModelHierarchyTransformStackCursor[0xf] + g_ModelHierarchyTransformStackCursor[6];
      g_ModelHierarchyTransformStackCursor[0x10] =
           g_ModelHierarchyTransformStackCursor[0x10] + g_ModelHierarchyTransformStackCursor[7];
      if (*g_ModelHierarchyPackedTransformCursor == 0) {
        ApplyProjectionTranslationFromTransform(g_ModelHierarchyTransformStackCursor + 9);
        dataCursor = g_ModelHierarchyTransformStackCursor;
        if ((value & 8) == 0) {
          g_ModelHierarchyTransformStackCursor[9] = *g_ModelHierarchyTransformStackCursor;
          dataCursor[10] = dataCursor[1];
          dataCursor[0xb] = dataCursor[2];
          dataCursor[0xc] = dataCursor[3];
          *(undefined2 *)(dataCursor + 0xd) = *(undefined2 *)(dataCursor + 4);
LAB_00445d2a:
          g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + 9;
        }
      }
      else {
        entry = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState4 = (undefined2)CONCAT31((int3)(entry >> 0x1c),(char)(entry >> 0x14));
        localState3 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState2 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState4,localState);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,localState,
                   g_ModelHierarchyTransformStackCursor + 9);
        if ((value & 8) == 0) goto LAB_00445d2a;
      }
    }
    else {
      g_ModelHierarchyTransformStackCursor[5] =
           g_ModelHierarchyTransformStackCursor[5] + g_ModelHierarchyTransformStackCursor[0xe];
      g_ModelHierarchyTransformStackCursor[6] =
           g_ModelHierarchyTransformStackCursor[6] + g_ModelHierarchyTransformStackCursor[0xf];
      g_ModelHierarchyTransformStackCursor[7] =
           g_ModelHierarchyTransformStackCursor[7] + g_ModelHierarchyTransformStackCursor[0x10];
      if (*g_ModelHierarchyPackedTransformCursor != 0) {
        entry = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState4 = (undefined2)CONCAT31((int3)(entry >> 0x1c),(char)(entry >> 0x14));
        localState3 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState2 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState4,localState);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,localState,
                   g_ModelHierarchyTransformStackCursor);
      }
      ApplyProjectionTranslationFromTransform(g_ModelHierarchyTransformStackCursor);
      if ((value & 8) != 0) {
        if (g_ModelHierarchyTransformStackCursor <
            (undefined4 *)((int)&g_ModelHierarchyTransformStackBase + 1)) {
          return (undefined4 *)0x0;
        }
        g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + -9;
      }
    }
    g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    g_ModelHierarchyCommandCursor = g_ModelHierarchyCommandCursor + 4;
    flagByte = arg2 == 0;
    arg2 = arg2 + -1;
    if (flagByte) {
      return g_ModelHierarchyTransformStackCursor;
    }
  } while( true );
}

