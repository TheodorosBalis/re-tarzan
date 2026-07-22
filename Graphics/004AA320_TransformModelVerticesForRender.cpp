#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA320
// Label: TransformModelVerticesForRender
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TransformModelVerticesForRender(int *graphicsObject)

{
  byte *value7;
  int value;
  byte flagByte;
  bool flagByte2;
  short *value10;
  ushort value4;
  undefined2 value5;
  uint value6;
  int value2;
  byte *value8;
  undefined4 *dataCursor;
  uint value3;
  short *value9;
  
  if ((graphicsObject != (int *)0x0) && (dataCursor = (undefined4 *)*graphicsObject, dataCursor != (undefined4 *)0x0)) {
    value3 = g_RenderScratchPacketCount & 0xffff;
    value8 = (byte *)((int)graphicsObject + graphicsObject[4] + 0x11);
    flagByte = *value8;
    value10 = (short *)(graphicsObject[3] + 0x4c + (int)graphicsObject);
    while (flagByte != 0xff) {
      _g_ProjectInputX0 = 0;
      _g_ProjectInputY0 = 0;
      _g_ProjectInputZ0 = 0;
      _g_ProjectInputX1 = (float)(int)*value10;
      value9 = value10 + 8;
      _g_ProjectInputY1 = (float)(int)value10[1];
      _g_ProjectInputZ1 = (float)(int)value10[2];
      _g_ProjectInputX2 = (float)(int)value10[4];
      _g_ProjectInputY2 = (float)(int)value10[5];
      _g_ProjectInputZ2 = (float)(int)value10[6];
      ProjectInitialTriangleEdgeVertices();
      graphicsObject = (int *)0x0;
      if (*value8 != 0) {
        do {
          value6 = g_RenderScratchPacketCount & 0xffff;
          g_RenderScratchPacketCount =
               CONCAT22(*( undefined2 *)((int)&g_RenderScratchPacketCount + 2),(short)g_RenderScratchPacketCount + 1) &
               0xffff03ff;
          value = value6 * 0x3c;
          *(undefined2 *)(&DAT_00a348e8 + value) = 0;
          AdvanceProjectedTriangleVertex
                    ((float)(int)*value9,(float)(int)value9[1],(float)(int)value9[2]);
          ProjectTriangleThirdVertex();
          *(undefined4 *)(&DAT_00a348d4 + value) = *dataCursor;
          *(undefined4 *)(&DAT_00a348d8 + value) = dataCursor[1];
          *(undefined4 *)(&DAT_00a348dc + value) = dataCursor[2];
          if (g_FadeBrightnessInverse != 0) {
            (&DAT_00a348d6)[value] =
                 (char)((*g_FadeTintRgbPtr + (uint)(byte)(&DAT_00a348d6)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348d6)[value];
            (&DAT_00a348da)[value] =
                 (char)((*g_FadeTintRgbPtr + (uint)(byte)(&DAT_00a348da)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348da)[value];
            (&DAT_00a348de)[value] =
                 (char)((*g_FadeTintRgbPtr + (uint)(byte)(&DAT_00a348de)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348de)[value];
            (&DAT_00a348d5)[value] =
                 (char)((g_FadeTintRgbPtr[1] + (uint)(byte)(&DAT_00a348d5)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348d5)[value];
            (&DAT_00a348d9)[value] =
                 (char)((g_FadeTintRgbPtr[1] + (uint)(byte)(&DAT_00a348d9)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348d9)[value];
            (&DAT_00a348dd)[value] =
                 (char)((g_FadeTintRgbPtr[1] + (uint)(byte)(&DAT_00a348dd)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348dd)[value];
            (&DAT_00a348d4)[value] =
                 (char)((g_FadeTintRgbPtr[2] + (uint)(byte)(&DAT_00a348d4)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348d4)[value];
            (&DAT_00a348d8)[value] =
                 (char)((g_FadeTintRgbPtr[2] + (uint)(byte)(&DAT_00a348d8)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348d8)[value];
            (&DAT_00a348dc)[value] =
                 (char)((g_FadeTintRgbPtr[2] + (uint)(byte)(&DAT_00a348dc)[value] * -0x10) *
                        g_FadeBrightnessInverse >> 0x10) + (&DAT_00a348dc)[value];
          }
          *(ushort *)(&DAT_00a348e8 + value) =
               *(ushort *)(&DAT_00a348e8 + value) & 0xffe0 | *(byte *)((int)dataCursor + 0x12) & 0xf;
          *(undefined2 *)(&DAT_00a348e0 + value) = *(undefined2 *)(dataCursor + 3);
          *(undefined2 *)(&DAT_00a348e2 + value) = *(undefined2 *)((int)dataCursor + 0xe);
          *(undefined2 *)(&DAT_00a348e4 + value) = *(undefined2 *)(dataCursor + 4);
          if ((*(byte *)((int)dataCursor + 0x12) & 0x10) == 0) {
            value4 = (ushort)g_RenderBlendMode;
          }
          else {
            value4 = 1;
          }
          *(ushort *)(&DAT_00a348e8 + value) =
               (value4 & 3) << 0xb | *(ushort *)(&DAT_00a348e8 + value) & 0xe7ff;
          value5 = ComputeTriangleAverageDepthSortKey();
          *(undefined2 *)(&DAT_00a348e6 + value) = value5;
          value2 = (uint)*(ushort *)(&DAT_00a348e6 + value) + g_DrawWindowXOffset;
          if ((int)((uint)*(ushort *)(&DAT_00a348e6 + value) + g_DrawWindowXOffset) <
              g_DrawWindowMinX) {
            value2 = g_DrawWindowMinX;
          }
          if (g_DrawWindowMaxX < value2) {
            value2 = g_DrawWindowMaxX;
          }
          *(short *)(&DAT_00a348e6 + value) = (short)value2;
          flagByte2 = (g_ProjectScreenX1 - g_ProjectScreenX0) * (g_ProjectScreenY2 - g_ProjectScreenY0)
                  - (g_ProjectScreenX2 - g_ProjectScreenX0) *
                    (g_ProjectScreenY1 - g_ProjectScreenY0) <= _g_FloatZero;
          *(float *)(&g_ModelProjectionScratch + value) = g_ProjectScreenX0;
          *(float *)(&g_ModelProjectionScreenY0 + value) = g_ProjectScreenY0;
          *(float *)(&g_ModelProjectionCameraZ0 + value) = g_ProjectCameraZ0;
          *(float *)(&DAT_00a348b4 + value) = g_ProjectScreenX1;
          *(float *)(&DAT_00a348c0 + value) = g_ProjectScreenY1;
          *(float *)(&DAT_00a348cc + value) = g_ProjectCameraZ1;
          *(float *)(&DAT_00a348b8 + value) = g_ProjectScreenX2;
          *(float *)(&DAT_00a348c4 + value) = g_ProjectScreenY2;
          *(float *)(&DAT_00a348d0 + value) = g_ProjectCameraZ2;
          if ((value9[3] & 4U) == 0) {
            value4 = (byte)~(byte)value9[3] & 1;
          }
          else {
            value4 = 3;
          }
          *(ushort *)(&DAT_00a348e8 + value) =
               value4 << 7 | *(ushort *)(&DAT_00a348e8 + value) & 0xfe7f;
          if ((((((*(byte *)(value9 + 3) & 2) == 0) &&
                (_g_RenderNearClipDepth <= g_ProjectCameraZ0)) &&
               (_g_RenderNearClipDepth <= g_ProjectCameraZ1)) &&
              ((_g_RenderNearClipDepth <= g_ProjectCameraZ2 &&
               (((g_ProjectCameraZ0 <= _g_FloatProjectionScaleY ||
                 (g_ProjectCameraZ1 <= _g_FloatProjectionScaleY)) ||
                (g_ProjectCameraZ2 <= _g_FloatProjectionScaleY)))))) && (value4 != flagByte2)) {
            QueueRenderPacket(&g_ModelProjectionScratch + value);
          }
          graphicsObject = (int *)((int)graphicsObject + 1);
          value9 = value9 + 4;
          dataCursor = dataCursor + 7;
        } while ((int)graphicsObject < (int)(uint)*value8);
      }
      value7 = value8 + 2;
      value8 = value8 + 2;
      value10 = value9;
      flagByte = *value7;
    }
    return value3;
  }
  return 0xffffffff;
}

