#include "tarzan_ghidra_types.hpp"

// Address: 0x00454300
// Label: RenderAnimatedModelCommandStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderAnimatedModelCommandStream(void)

{
  int value;
  undefined4 value3;
  undefined4 *bufferCursor;
  uint value4;
  int value2;
  undefined4 *bufferCursor2;
  undefined2 *bufferCursor3;
  undefined2 localState7;
  undefined2 localState6;
  undefined2 localState5;
  undefined2 localState4;
  ushort localState3;
  ushort localState2;
  undefined1 localState [20];
  int localState10;
  int localState9;
  int localState8;
  
  value2 = 0;
  do {
    value4 = *g_ModelHierarchyCommandCursor;
    if ((value4 & 4) == 0) {
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
    localState7 = (undefined2)localState10;
    localState6 = (undefined2)localState9;
    localState5 = (undefined2)localState8;
    TransformVectorByProjectionBasis
              (g_ModelHierarchyTransformStackCursor,&localState7,
               g_ModelHierarchyTransformStackCursor + 0xe);
    if (g_RenderModelCurrentFlags == 0) {
      if (*g_ModelHierarchyPackedTransformCursor != 0) {
        value = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState4 = (undefined2)CONCAT31((int3)(value >> 0x1c),(char)(value >> 0x14));
        localState3 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState2 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        bufferCursor3 = &localState4;
        goto LAB_004543f0;
      }
      value4 = value4 | 0x20;
    }
    else {
      g_RenderModelCurrentFlags = g_RenderModelCurrentFlags + -1;
      bufferCursor3 = g_ModelHierarchyRotationOverrideCursor;
      if (g_RenderModelCurrentFlags == 0) {
LAB_004543f0:
        BuildRotationBasisFromEulerAngles(bufferCursor3,localState);
      }
      else {
        value4 = value4 | 0x20;
      }
    }
    if ((value4 & 0x10) == 0) {
      g_ModelHierarchyTransformStackCursor[0xe] =
           g_ModelHierarchyTransformStackCursor[0xe] + g_ModelHierarchyTransformStackCursor[5];
      g_ModelHierarchyTransformStackCursor[0xf] =
           g_ModelHierarchyTransformStackCursor[0xf] + g_ModelHierarchyTransformStackCursor[6];
      g_ModelHierarchyTransformStackCursor[0x10] =
           g_ModelHierarchyTransformStackCursor[0x10] + g_ModelHierarchyTransformStackCursor[7];
      if ((value4 & 0x20) == 0) {
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,localState,
                   g_ModelHierarchyTransformStackCursor + 9);
        SetProjectionBasisMatrixFromFixed(g_ModelHierarchyTransformStackCursor + 9);
      }
      SetProjectionTranslationFromTransform(g_ModelHierarchyTransformStackCursor + 9);
      value3 = ProjectAndQueueModelTriangles
                        (g_ModelHierarchyCommandCursor[1] + 4 + (int)g_ModelHierarchyCommandCursor,
                         g_ModelHierarchyTransformStackCursor[8]);
      g_ModelHierarchyTransformStackCursor[0x11] = value3;
      bufferCursor = g_ModelHierarchyTransformStackCursor;
      if ((value4 & 8) == 0) {
        if ((value4 & 0x20) != 0) {
          g_ModelHierarchyTransformStackCursor[9] = *g_ModelHierarchyTransformStackCursor;
          bufferCursor[10] = bufferCursor[1];
          bufferCursor[0xb] = bufferCursor[2];
          bufferCursor[0xc] = bufferCursor[3];
          *(undefined2 *)(bufferCursor + 0xd) = *(undefined2 *)(bufferCursor + 4);
        }
        bufferCursor2 = g_ModelHierarchyTransformStackCursor + 9;
        bufferCursor = g_ModelHierarchyTransformStackCursor + -0x290e3f;
        g_ModelHierarchyTransformStackCursor = bufferCursor2;
        if (value2 < (int)bufferCursor / 0x24) {
          value2 = (int)bufferCursor / 0x24;
        }
      }
    }
    else {
      g_ModelHierarchyTransformStackCursor[5] =
           g_ModelHierarchyTransformStackCursor[5] + g_ModelHierarchyTransformStackCursor[0xe];
      g_ModelHierarchyTransformStackCursor[6] =
           g_ModelHierarchyTransformStackCursor[6] + g_ModelHierarchyTransformStackCursor[0xf];
      g_ModelHierarchyTransformStackCursor[7] =
           g_ModelHierarchyTransformStackCursor[7] + g_ModelHierarchyTransformStackCursor[0x10];
      if ((value4 & 0x20) == 0) {
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
      if ((value4 & 8) != 0) {
        if (g_ModelHierarchyTransformStackCursor <
            (undefined4 *)((int)&g_ModelHierarchyTransformStackBase + 1)) {
          return;
        }
        g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + -9;
      }
    }
    if (g_RenderModelCurrentFlags == 0) {
      g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    }
    g_ModelHierarchyCommandCursor = g_ModelHierarchyCommandCursor + 4;
  } while( true );
}

