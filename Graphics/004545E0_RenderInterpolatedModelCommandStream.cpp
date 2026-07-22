#include "tarzan_ghidra_types.hpp"

// Address: 0x004545E0
// Label: RenderInterpolatedModelCommandStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderInterpolatedModelCommandStream(void)

{
  uint value2;
  undefined4 *bufferCursor;
  undefined4 value3;
  int value;
  short localState27;
  ushort localState26;
  ushort localState25;
  undefined2 localState24;
  undefined2 localState23;
  undefined2 localState22;
  short localState21;
  short localState20;
  short localState19;
  short localState18;
  short localState17;
  short localState16;
  short localState15;
  short localState14;
  short localState13;
  int localState12;
  int localState11;
  int localState10;
  short localState9;
  short localState8;
  short localState7;
  short localState6;
  short localState5;
  short localState4;
  short localState3;
  short localState2;
  short localState;
  
  do {
    value2 = *g_ModelHierarchyCommandCursor;
    if ((value2 & 4) == 0) {
      localState12 = (int)(short)g_ModelHierarchyCommandCursor[2];
      localState11 = (int)*(short *)((int)g_ModelHierarchyCommandCursor + 10);
      localState10 = (int)(short)g_ModelHierarchyCommandCursor[3];
    }
    else {
      value = (int)g_ModelHierarchyBlendAmount;
      localState12 = (*g_ModelHierarchyPackedTransformCursor << 0x15) >> 0x15;
      localState12 = ((((*g_ModelHierarchyCommandEnd << 0x15) >> 0x15) - localState12) * value >> 8) +
                 localState12;
      localState11 = (*g_ModelHierarchyPackedTransformCursor << 10) >> 0x15;
      localState11 = ((((*g_ModelHierarchyCommandEnd << 10) >> 0x15) - localState11) * value >> 8) +
                 localState11;
      localState10 = (((*g_ModelHierarchyCommandEnd >> 0x16) -
                  (*g_ModelHierarchyPackedTransformCursor >> 0x16)) * value >> 8) +
                 (*g_ModelHierarchyPackedTransformCursor >> 0x16);
      g_ModelHierarchyCommandEnd = g_ModelHierarchyCommandEnd + 1;
      g_ModelHierarchyPackedTransformCursor = g_ModelHierarchyPackedTransformCursor + 1;
    }
    localState22 = (undefined2)localState10;
    localState24 = (undefined2)localState12;
    localState23 = (undefined2)localState11;
    TransformVectorByProjectionBasis
              (g_ModelHierarchyTransformStackCursor,&localState24,
               g_ModelHierarchyTransformStackCursor + 0xe);
    if ((value2 & 0x10) == 0) {
      g_ModelHierarchyTransformStackCursor[0xe] =
           g_ModelHierarchyTransformStackCursor[0xe] + g_ModelHierarchyTransformStackCursor[5];
      g_ModelHierarchyTransformStackCursor[0xf] =
           g_ModelHierarchyTransformStackCursor[0xf] + g_ModelHierarchyTransformStackCursor[6];
      g_ModelHierarchyTransformStackCursor[0x10] =
           g_ModelHierarchyTransformStackCursor[0x10] + g_ModelHierarchyTransformStackCursor[7];
      if ((*g_ModelHierarchyPackedTransformCursor == 0) && (*g_ModelHierarchyCommandEnd == 0)) {
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
LAB_00454b8d:
          g_ModelHierarchyTransformStackCursor = g_ModelHierarchyTransformStackCursor + 9;
        }
      }
      else {
        value = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState27 = (short)CONCAT31((int3)(value >> 0x1c),(char)(value >> 0x14));
        localState26 = (ushort)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14) & 0xfffe;
        localState25 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState27,&localState21);
        localState27 = (short)((*g_ModelHierarchyCommandEnd << 0x15) >> 0x14);
        localState26 = (ushort)((*g_ModelHierarchyCommandEnd << 10) >> 0x14) & 0xfffe;
        localState25 = (ushort)(*g_ModelHierarchyCommandEnd >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState27,&localState9);
        value = (int)g_ModelHierarchyBlendAmount;
        localState21 = localState21 + (short)((uint)(((int)localState9 - (int)localState21) * value) >> 8);
        localState20 = localState20 + (short)((uint)(((int)localState8 - (int)localState20) * value) >> 8);
        localState19 = localState19 + (short)((uint)(((int)localState7 - (int)localState19) * value) >> 8);
        localState18 = localState18 + (short)((uint)(((int)localState6 - (int)localState18) * value) >> 8);
        localState17 = localState17 + (short)((uint)(((int)localState5 - (int)localState17) * value) >> 8);
        localState16 = localState16 + (short)((uint)(((int)localState4 - (int)localState16) * value) >> 8);
        localState15 = localState15 + (short)((uint)(((int)localState3 - (int)localState15) * value) >> 8);
        localState14 = localState14 + (short)((uint)(((int)localState2 - (int)localState14) * value) >> 8);
        localState13 = localState13 + (short)((uint)(((int)localState - (int)localState13) * value) >> 8);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,&localState21,
                   g_ModelHierarchyTransformStackCursor + 9);
        SetTransformBasisFromRef(g_ModelHierarchyTransformStackCursor + 9);
        value3 = ProjectAndQueueModelTriangles
                          (g_ModelHierarchyCommandCursor[1] + 4 + (int)g_ModelHierarchyCommandCursor
                           ,g_ModelHierarchyTransformStackCursor[8]);
        g_ModelHierarchyTransformStackCursor[0x11] = value3;
        if ((value2 & 8) == 0) goto LAB_00454b8d;
      }
    }
    else {
      g_ModelHierarchyTransformStackCursor[5] =
           g_ModelHierarchyTransformStackCursor[5] + g_ModelHierarchyTransformStackCursor[0xe];
      g_ModelHierarchyTransformStackCursor[6] =
           g_ModelHierarchyTransformStackCursor[6] + g_ModelHierarchyTransformStackCursor[0xf];
      g_ModelHierarchyTransformStackCursor[7] =
           g_ModelHierarchyTransformStackCursor[7] + g_ModelHierarchyTransformStackCursor[0x10];
      if ((*g_ModelHierarchyPackedTransformCursor != 0) || (*g_ModelHierarchyCommandEnd != 0)) {
        value = *g_ModelHierarchyPackedTransformCursor << 0x15;
        localState27 = (short)CONCAT31((int3)(value >> 0x1c),(char)(value >> 0x14));
        localState26 = (ushort)CONCAT31((int3)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x1c),
                                    (char)((*g_ModelHierarchyPackedTransformCursor << 10) >> 0x14))
                   & 0xfffe;
        localState25 = (ushort)(*g_ModelHierarchyPackedTransformCursor >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState27,&localState21);
        localState27 = (short)((*g_ModelHierarchyCommandEnd << 0x15) >> 0x14);
        localState26 = (ushort)((*g_ModelHierarchyCommandEnd << 10) >> 0x14) & 0xfffe;
        localState25 = (ushort)(*g_ModelHierarchyCommandEnd >> 0x14) & 0xfffc;
        BuildRotationBasisFromEulerAngles(&localState27,&localState9);
        value = (int)g_ModelHierarchyBlendAmount;
        localState21 = localState21 + (short)((uint)(((int)localState9 - (int)localState21) * value) >> 8);
        localState20 = localState20 + (short)((uint)(((int)localState8 - (int)localState20) * value) >> 8);
        localState19 = localState19 + (short)((uint)(((int)localState7 - (int)localState19) * value) >> 8);
        localState18 = localState18 + (short)((uint)(((int)localState6 - (int)localState18) * value) >> 8);
        localState17 = localState17 + (short)((uint)(((int)localState5 - (int)localState17) * value) >> 8);
        localState16 = localState16 + (short)((uint)(((int)localState4 - (int)localState16) * value) >> 8);
        localState15 = localState15 + (short)((uint)(((int)localState3 - (int)localState15) * value) >> 8);
        localState14 = localState14 + (short)((uint)(((int)localState2 - (int)localState14) * value) >> 8);
        localState13 = localState13 + (short)((uint)(((int)localState - (int)localState13) * value) >> 8);
        MultiplyBasisMatrices
                  (g_ModelHierarchyTransformStackCursor,&localState21,
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
    g_ModelHierarchyCommandEnd = g_ModelHierarchyCommandEnd + 1;
    g_ModelHierarchyCommandCursor = g_ModelHierarchyCommandCursor + 4;
  } while( true );
}

