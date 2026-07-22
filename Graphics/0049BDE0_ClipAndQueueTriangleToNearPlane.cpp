#include "tarzan_ghidra_types.hpp"

// Address: 0x0049BDE0
// Label: ClipAndQueueTriangleToNearPlane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClipAndQueueTriangleToNearPlane(float *arg1)

{
  float edgeSlope;
  float edgeSlope2;
  float edgeSlope3;
  int value2;
  int value3;
  int value4;
  float edgeSlope4;
  float edgeSlope5;
  undefined1 value7;
  undefined2 value5;
  uint value6;
  int value;
  float localState [9];
  undefined4 localState2;
  undefined2 localState3;
  
  edgeSlope = _g_RenderNearClipDepth;
  value6 = (uint)(g_ProjectCameraZ0 < _g_RenderNearClipDepth) |
           (uint)(g_ProjectCameraZ1 < _g_RenderNearClipDepth) * 2 |
           (uint)(g_ProjectCameraZ2 < _g_RenderNearClipDepth) * 4;
  if (value6 == 0) {
    QueueRenderPacket(arg1);
    return;
  }
  if (value6 != 7) {
    edgeSlope2 = _g_FloatZero;
    if (_g_FloatZero < g_ProjectCameraZ0) {
      edgeSlope2 = g_ProjectCameraZ0;
    }
    if (_g_FloatZero < g_ProjectCameraZ1) {
      edgeSlope2 = edgeSlope2 + g_ProjectCameraZ1;
    }
    if (_g_FloatZero < g_ProjectCameraZ2) {
      edgeSlope2 = edgeSlope2 + g_ProjectCameraZ2;
    }
    if (edgeSlope2 * _g_FloatOneThird <= _g_RenderNearClipDepth) {
      value5 = 1;
    }
    else {
      _g_TriangleNearPlaneClipScratch =
           (double)(edgeSlope2 * _g_FloatOneThird + (float)_g_DoubleToIntRoundingBias);
      value5 = g_TriangleNearPlaneClipScratch;
    }
    value = value6 * 0x1c;
    *(undefined2 *)((int)arg1 + 0x36) = value5;
    value2 = *(int *)(&g_NearPlaneClipCaseFirstEdgeStartIndex + value);
    value3 = *(int *)(&g_NearPlaneClipCaseFirstEdgeEndIndex + value);
    value4 = *(int *)(&g_NearPlaneClipCaseFirstNewVertexIndex + value);
    edgeSlope = (edgeSlope - (&g_ProjectCameraZ0)[value2]) /
            ((&g_ProjectCameraZ0)[value3] - (&g_ProjectCameraZ0)[value2]);
    localState[value4] =
         ((*(float *)(&g_ProjectCameraX0 + value3 * 4) - *(float *)(&g_ProjectCameraX0 + value2 * 4))
          * edgeSlope + *(float *)(&g_ProjectCameraX0 + value2 * 4)) * g_ProjectionDepthScale +
         g_ProjectionScreenOriginX;
    localState[value4 + 3] =
         ((*(float *)(&g_ProjectCameraY0 + value3 * 4) - *(float *)(&g_ProjectCameraY0 + value2 * 4))
          * edgeSlope + *(float *)(&g_ProjectCameraY0 + value2 * 4)) * g_ProjectionDepthScale +
         _g_ProjectionScreenOriginY;
    localState[value4 + 6] = 1.0;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)&localState3 + value4 * 2 + 1) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)(&localState3 + value4) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)&localState2 + value4 * 4 + 2) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)&localState2 + value4 * 4 + 1) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)(&localState2 + value4) = value7;
    value7 = ConvertFpuTopToInt64();
    edgeSlope5 = g_ProjectionDepthScale;
    value2 = *(int *)(&g_NearPlaneClipCaseSecondEdgeStartIndex + value);
    *(undefined1 *)((int)&localState2 + value4 * 4 + 3) = value7;
    value3 = *(int *)(&g_NearPlaneClipCaseSecondEdgeEndIndex + value);
    value4 = *(int *)(&g_NearPlaneClipCaseSecondNewVertexIndex + value);
    edgeSlope4 = (_g_RenderNearClipDepth - (&g_ProjectCameraZ0)[value2]) /
            ((&g_ProjectCameraZ0)[value3] - (&g_ProjectCameraZ0)[value2]);
    edgeSlope = *(float *)(&g_ProjectCameraY0 + value3 * 4);
    edgeSlope2 = *(float *)(&g_ProjectCameraY0 + value2 * 4);
    edgeSlope3 = *(float *)(&g_ProjectCameraY0 + value2 * 4);
    arg1[value4] =
         ((*(float *)(&g_ProjectCameraX0 + value3 * 4) - *(float *)(&g_ProjectCameraX0 + value2 * 4))
          * edgeSlope4 + *(float *)(&g_ProjectCameraX0 + value2 * 4)) * g_ProjectionDepthScale +
         g_ProjectionScreenOriginX;
    arg1[value4 + 3] = edgeSlope5 * ((edgeSlope - edgeSlope2) * edgeSlope4 + edgeSlope3) + _g_ProjectionScreenOriginY;
    arg1[value4 + 6] = 1.0;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)arg1 + value4 * 2 + 0x31) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)arg1 + value4 * 2 + 0x30) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)arg1 + value4 * 4 + 0x26) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)arg1 + value4 * 4 + 0x25) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)(arg1 + value4 + 9) = value7;
    value7 = ConvertFpuTopToInt64();
    *(undefined1 *)((int)arg1 + value4 * 4 + 0x27) = value7;
    if (*(int *)(&g_NearPlaneClipCaseTable + value) == 2) {
      value2 = *(int *)(&g_NearPlaneClipCaseFirstNewVertexIndex + value);
      edgeSlope = localState[value2 + 3];
      arg1[value2] = localState[value2];
      edgeSlope2 = localState[value2 + 6];
      arg1[value2 + 3] = edgeSlope;
      value5 = (&localState3)[value2];
      arg1[value2 + 6] = edgeSlope2;
      edgeSlope = (float)(&localState2)[value2];
      *(undefined2 *)((int)arg1 + value2 * 2 + 0x30) = value5;
      arg1[value2 + 9] = edgeSlope;
    }
    if ((*(ushort *)(arg1 + 0xe) & 0x180) >> 7 !=
        (uint)((arg1[5] - arg1[3]) * (arg1[1] - *arg1) -
               (arg1[4] - arg1[3]) * (arg1[2] - *arg1) <= _g_FloatZero)) {
      if (*(int *)(&g_NearPlaneClipCaseTable + value) == 1) {
        QueueRenderPacket(arg1);
        value2 = *(int *)(&g_NearPlaneClipCaseFirstNewVertexIndex + value);
        edgeSlope = localState[value2 + 3];
        edgeSlope2 = localState[value2 + 6];
        arg1[value2] = localState[value2];
        value5 = (&localState3)[value2];
        arg1[value2 + 3] = edgeSlope;
        edgeSlope = (float)(&localState2)[value2];
        arg1[value2 + 6] = edgeSlope2;
        *(undefined2 *)((int)arg1 + value2 * 2 + 0x30) = value5;
        arg1[value2 + 9] = edgeSlope;
      }
      QueueRenderPacket(arg1);
    }
  }
  return;
}

