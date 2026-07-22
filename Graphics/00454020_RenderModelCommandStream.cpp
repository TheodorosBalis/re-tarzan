#include "tarzan_ghidra_types.hpp"

// Address: 0x00454020
// Label: RenderModelCommandStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderModelCommandStream(void)

{
  uint value2;
  undefined4 *bufferCursor;
  int value;
  undefined4 value3;
  undefined2 localState7;
  ushort localState6;
  ushort localState5;
  undefined2 localState4;
  undefined2 localState3;
  undefined2 localState2;
  undefined1 localState [20];
  int localState10;
  int localState9;
  int localState8;
  
  do {
    value2 = *g_ModelHierarchyCommandCursor;
    if ((value2 & 4) == 0) {
      localState10 = (int)(short)g_ModelHierarchyCommandCursor[2];
      localState9 = (int)*(short *)((int)g_ModelHierarchyCommandCursor + 10);
      localState8 = (int)(short)g_ModelHierarchyCommandCursor[3];
    }
    else {
      localState10 = (*g_ModelHierarchyPackedTransformCursor << 0x15) >> 0x15;
      localState9 = (*g_ModelHierarchyPackedTransformCursor << 10) >> 0x15;
      localState8 = *g_ModelHierarchyPackedTransformCursor >> 0x16;
      g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    }
    localState4 = (undefined2)localState10;
    localState3 = (undefined2)localState9;
    localState2 = (undefined2)localState8;
    TransformVectorByProjectionBasis
              (g_ModelHierarchyTransformStackCursor,&localState4,
               g_ModelHierarchyTransformStackCursor + 0xe);
    if ((value2 & 0x10) == 0) {
      g_ModelHierarchyTransformStackCursor[0xe] =
           g_ModelHierarchyTransformStackCursor[0xe] + g_ModelHierarchyTransformStackCursor[5];
      g_ModelHierarchyTransformStackCursor[0xf] =
           g_ModelHierarchyTransformStackCursor[0xf] + g_ModelHierarchyTransformStackCursor[6];
      g_ModelHierarchyTransformStackCursor[0x10] =
           g_ModelHierarchyTransformStackCursor[0x10] + g_ModelHierarchyTransformStackCursor[7];
      if (*g_ModelHierarchyPackedTransformCursor == 0) {
        SetProjectionTranslationFromTransform(g_ModelHierarchyTransformStackCursor + 9);
        value3 = ProjectAndQueueModelTriangles
                          (g_ModelHierarchyCommandCursor[1] + 4 + (int)g_ModelHierarchyCommandCursor
                           ,g_ModelHierarchyTransformStackCursor[8]);
        g_ModelHierarchyTransformStackCursor[0x11] = value3;
        bufferCursor = g_ModelHierarchyTransformStackCursor;
        if ((value2 & 8) == 0) {
          g_ModelHierarchyTransformStackCursor[9] = *g_ModelHierarchyTransformStackCursor;
          bufferCursor[10] = bufferCursor[1];
          bufferCursor[0xb] = bufferCursor[2];
          bufferCursor[0xc] = bufferCursor[3];
          *(undefined2 *)(bufferCursor + 0xd) = *(undefined2 *)(bufferCursor + 4);
LAB_004542c1:
          g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + 9;
        }
      }
      else {
        value = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState7 = (undefined2)CONCAT31((int3)(value >> 0x1c),(char)(value >> 0x14));
        localState6 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState5 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState7,localState);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,localState,
                   g_ModelHierarchyTransformStackCursor + 9);
        SetTransformBasisFromRef(g_ModelHierarchyTransformStackCursor + 9);
        value3 = ProjectAndQueueModelTriangles
                          (g_ModelHierarchyCommandCursor[1] + 4 + (int)g_ModelHierarchyCommandCursor
                           ,g_ModelHierarchyTransformStackCursor[8]);
        g_ModelHierarchyTransformStackCursor[0x11] = value3;
        if ((value2 & 8) == 0) goto LAB_004542c1;
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
        value = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState7 = (undefined2)CONCAT31((int3)(value >> 0x1c),(char)(value >> 0x14));
        localState6 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState5 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState7,localState);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,localState,
                   g_ModelHierarchyTransformStackCursor);
        SetProjectionBasisMatrixFromFixed(g_ModelHierarchyTransformStackCursor);
      }
      SetProjectionTranslationFromTransform(g_ModelHierarchyTransformStackCursor);
      value3 = ProjectAndQueueModelTriangles
                        (g_ModelHierarchyCommandCursor[1] + 4 + (int)g_ModelHierarchyCommandCursor,
                         g_ModelHierarchyTransformStackCursor[8]);
      g_ModelHierarchyTransformStackCursor[8] = value3;
      if ((value2 & 8) != 0) {
        if (g_ModelHierarchyTransformStackCursor <
            (undefined4 *)((int)&g_ModelHierarchyTransformStackBase + 1)) {
          return;
        }
        g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + -9;
      }
    }
    g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    g_ModelHierarchyCommandCursor = g_ModelHierarchyCommandCursor + 4;
  } while( true );
}

