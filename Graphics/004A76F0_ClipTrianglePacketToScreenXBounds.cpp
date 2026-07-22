#include "tarzan_ghidra_types.hpp"

// Address: 0x004A76F0
// Label: ClipTrianglePacketToScreenXBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort ClipTrianglePacketToScreenXBounds(void)

{
  char resultFlag;
  bool flagByte;
  float edgeSlope;
  float edgeSlope2;
  ushort value7;
  ushort value8;
  int value2;
  ushort value9;
  char *stringCursor;
  uint value3;
  int value;
  ushort value4;
  uint value5;
  float *floatCursor;
  float *floatCursor2;
  ushort value6;
  float *floatCursor3;
  char *localState2;
  int localState;
  int localState4;
  char localState3 [8];
  
  value6 = 3;
  g_CurrentClippedTriangleVertexBuffer = (float *)&g_RasterizerTriangleVertexBuffer;
  localState4 = 2;
  value8 = 3;
  edgeSlope = 2.8026e-45;
  g_SourceClippedTriangleVertexBuffer = (float *)&g_RasterizerTriangleVertexBuffer;
  g_DestClippedTriangleVertexBuffer = (float *)&DAT_0079e8a0;
  localState = 2;
  floatCursor = (float *)&DAT_0079e8a0;
  do {
    floatCursor2 = floatCursor;
    if (localState == 2) {
      if (g_TriangleVerticesPastRightEdgeCount != 0) {
        stringCursor = localState3;
        _g_TriangleClipInputVertexCursor = g_CurrentClippedTriangleVertexBuffer;
        edgeSlope = _g_RenderWindowWidthF;
        if (value6 != 0) {
          value5 = (uint)value6;
          do {
            *stringCursor = _g_RenderWindowWidthF < *g_CurrentClippedTriangleVertexBuffer;
            stringCursor = stringCursor + 1;
            g_CurrentClippedTriangleVertexBuffer = g_CurrentClippedTriangleVertexBuffer + 8;
            value5 = value5 - 1;
            _g_TriangleClipInputVertexCursor = g_CurrentClippedTriangleVertexBuffer;
            edgeSlope = _g_RenderWindowWidthF;
          } while (value5 != 0);
        }
        goto LAB_004a77e9;
      }
    }
    else {
      if (localState == 4) {
        if (g_ClippedTriangleVertexScratch == 0) goto LAB_004a7986;
        stringCursor = localState3;
        _g_TriangleClipInputVertexCursor = g_CurrentClippedTriangleVertexBuffer;
        edgeSlope = _g_FloatZero;
        if (value6 != 0) {
          value5 = (uint)value6;
          do {
            *stringCursor = *g_CurrentClippedTriangleVertexBuffer < _g_FloatZero;
            stringCursor = stringCursor + 1;
            g_CurrentClippedTriangleVertexBuffer = g_CurrentClippedTriangleVertexBuffer + 8;
            value5 = value5 - 1;
            _g_TriangleClipInputVertexCursor = g_CurrentClippedTriangleVertexBuffer;
          } while (value5 != 0);
        }
      }
LAB_004a77e9:
      value2 = 0;
      value4 = value6 - 1;
      flagByte = value6 != 0;
      value6 = 0;
      if (flagByte) {
        localState2 = localState3;
        value9 = 0;
        do {
          value7 = value9;
          value5 = (uint)value4;
          resultFlag = *localState2;
          if (localState3[value5] != resultFlag) {
            value3 = (uint)value6;
            floatCursor[value3 * 8] = edgeSlope;
            value6 = value6 + 1;
            floatCursor = (float *)(value2 + 4 + (int)g_SourceClippedTriangleVertexBuffer);
            edgeSlope2 = (edgeSlope - *(float *)(value2 + (int)g_SourceClippedTriangleVertexBuffer)) /
                    (g_SourceClippedTriangleVertexBuffer[value5 * 8] -
                    *(float *)(value2 + (int)g_SourceClippedTriangleVertexBuffer));
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 1] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 1] - *floatCursor) * edgeSlope2 + *floatCursor
            ;
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 2] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 2] -
                 *(float *)(value2 + 8 + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 8 + (int)g_SourceClippedTriangleVertexBuffer);
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 3] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 3] -
                 *(float *)(value2 + 0xc + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 0xc + (int)g_SourceClippedTriangleVertexBuffer);
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 4] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 4] -
                 *(float *)(value2 + 0x10 + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 0x10 + (int)g_SourceClippedTriangleVertexBuffer);
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 5] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 5] -
                 *(float *)(value2 + 0x14 + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 0x14 + (int)g_SourceClippedTriangleVertexBuffer);
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 6] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 6] -
                 *(float *)(value2 + 0x18 + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 0x18 + (int)g_SourceClippedTriangleVertexBuffer);
            g_DestClippedTriangleVertexBuffer[value3 * 8 + 7] =
                 (g_SourceClippedTriangleVertexBuffer[value5 * 8 + 7] -
                 *(float *)(value2 + 0x1c + (int)g_SourceClippedTriangleVertexBuffer)) * edgeSlope2 +
                 *(float *)(value2 + 0x1c + (int)g_SourceClippedTriangleVertexBuffer);
            floatCursor = g_DestClippedTriangleVertexBuffer;
          }
          if (resultFlag == '\0') {
            value5 = (uint)value6;
            value6 = value6 + 1;
            floatCursor2 = (float *)(value2 + (int)g_SourceClippedTriangleVertexBuffer);
            floatCursor3 = floatCursor + value5 * 8;
            for (value = 8; floatCursor = g_DestClippedTriangleVertexBuffer, value != 0;
                value = value + -1) {
              *floatCursor3 = *floatCursor2;
              floatCursor2 = floatCursor2 + 1;
              floatCursor3 = floatCursor3 + 1;
            }
          }
          value9 = value7 + 1;
          localState2 = localState2 + 1;
          value2 = value2 + 0x20;
          value4 = value7;
        } while (value9 < value8);
      }
      g_DestClippedTriangleVertexBuffer = g_SourceClippedTriangleVertexBuffer;
      floatCursor2 = g_SourceClippedTriangleVertexBuffer;
      g_CurrentClippedTriangleVertexBuffer = floatCursor;
      g_SourceClippedTriangleVertexBuffer = floatCursor;
      _g_LastClippedTriangleVertexBuffer = floatCursor;
      value8 = value6;
    }
LAB_004a7986:
    localState = localState + 2;
    localState4 = localState4 + -1;
    floatCursor = floatCursor2;
    if (localState4 == 0) {
      return value6;
    }
  } while( true );
}

