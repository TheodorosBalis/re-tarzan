#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA890
// Label: RenderSceneAssetTriangles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderSceneAssetTriangles(int *graphicsObject)

{
  undefined4 value5;
  int entry;
  short *value3;
  char resultFlag;
  ushort value6;
  int entry2;
  byte flagByte;
  int entry3;
  short *value4;
  undefined4 *dataCursor;
  float *floatCursor;
  byte *value;
  byte *value2;
  float *floatCursor2;
  int localState31;
  char localState29;
  char localState28;
  float localState26 [4];
  float localState24;
  float localState23;
  float localState22;
  float localState21;
  float localState20;
  char localState19;
  char localState9;
  char localState8;
  char localState7;
  char localState18;
  char localState6;
  char localState5;
  char localState4;
  char localState17;
  char localState3;
  char localState2;
  char localState;
  char localState16;
  undefined1 localState36;
  undefined2 localState15;
  undefined2 localState14;
  undefined2 localState13;
  ushort localState35;
  byte *localState12;
  float localState10 [12];
  char localState34;
  char localState33;
  char localState32;
  char localState30;
  char localState27;
  char localState25;
  ushort localState11;
  
  localState29 = '\0';
  localState28 = '\0';
  if ((graphicsObject != (int *)0x0) && (dataCursor = (undefined4 *)*graphicsObject, dataCursor != (undefined4 *)0x0)) {
    value2 = (byte *)((int)graphicsObject + graphicsObject[4] + 0x11);
    flagByte = *(byte *)((int)graphicsObject + graphicsObject[4] + 0x11);
    value3 = (short *)(graphicsObject[3] + 0x4c + (int)graphicsObject);
    while (flagByte != 0xff) {
      _g_ProjectInputX0 = 0;
      _g_ProjectInputY0 = 0;
      _g_ProjectInputZ0 = 0;
      _g_ProjectInputX1 = (float)(int)*value3;
      value4 = value3 + 8;
      _g_ProjectInputY1 = (float)(int)value3[1];
      _g_ProjectInputZ1 = (float)(int)value3[2];
      _g_ProjectInputX2 = (float)(int)value3[4];
      _g_ProjectInputY2 = (float)(int)value3[5];
      _g_ProjectInputZ2 = (float)(int)value3[6];
      localState12 = value2;
      ProjectInitialTriangleEdgeVertices();
      entry2 = IsHardware3DGraphicsMode();
      if (entry2 != 0) {
        if (_g_FloatProjectionDepthBias <= g_ProjectCameraZ1) {
          if (g_ProjectCameraZ1 <= _g_FloatProjectionScaleY) {
            _g_RenderSceneTriangleScratch =
                 (double)((g_ProjectCameraZ1 - _g_FloatProjectionDepthBias) *
                          _g_FloatHardwareDepthShadeScale + (float)_g_DoubleToIntRoundingBias);
            localState29 = g_RenderSceneTriangleScratch;
          }
          else {
            localState29 = -2;
          }
        }
        else {
          localState29 = '\0';
        }
        localState29 = -1 - localState29;
        if (_g_FloatProjectionDepthBias <= g_ProjectCameraZ2) {
          if (g_ProjectCameraZ2 <= _g_FloatProjectionScaleY) {
            _g_RenderSceneTriangleScratch =
                 (double)((g_ProjectCameraZ2 - _g_FloatProjectionDepthBias) *
                          _g_FloatHardwareDepthShadeScale + (float)_g_DoubleToIntRoundingBias);
            localState28 = g_RenderSceneTriangleScratch;
          }
          else {
            localState28 = -2;
          }
        }
        else {
          localState28 = '\0';
        }
        localState28 = -1 - localState28;
      }
      localState31 = 0;
      value = value2;
      if (*value2 != 0) {
        do {
          resultFlag = localState29;
          AdvanceProjectedTriangleVertexWithWorld
                    ((float)(int)*value4,(float)(int)value4[1],(float)(int)value4[2]);
          ProjectTriangleThirdVertex();
          value5 = *dataCursor;
          localState19 = (char)value5;
          localState9 = (char)((uint)value5 >> 8);
          localState8 = (char)((uint)value5 >> 0x10);
          localState7 = (char)((uint)value5 >> 0x18);
          value5 = dataCursor[1];
          localState18 = (char)value5;
          localState6 = (char)((uint)value5 >> 8);
          localState5 = (char)((uint)value5 >> 0x10);
          localState4 = (char)((uint)value5 >> 0x18);
          value5 = dataCursor[2];
          localState17 = (char)value5;
          localState3 = (char)((uint)value5 >> 8);
          localState2 = (char)((uint)value5 >> 0x10);
          localState = (char)((uint)value5 >> 0x18);
          entry2 = IsHardware3DGraphicsMode();
          if (entry2 != 0) {
            localState29 = localState28;
            localState4 = localState28;
            localState7 = resultFlag;
            if (_g_FloatProjectionDepthBias <= g_ProjectCameraZ2) {
              if (g_ProjectCameraZ2 <= _g_FloatProjectionScaleY) {
                _g_RenderSceneTriangleScratch =
                     (double)((g_ProjectCameraZ2 - _g_FloatProjectionDepthBias) *
                              _g_FloatHardwareDepthShadeScale + (float)_g_DoubleToIntRoundingBias);
                localState28 = g_RenderSceneTriangleScratch;
              }
              else {
                localState28 = -2;
              }
            }
            else {
              localState28 = '\0';
            }
            localState28 = -1 - localState28;
            localState = localState28;
          }
          flagByte = (g_ProjectCameraZ1 < _g_RenderNearClipDepth) +
                  (g_ProjectCameraZ2 < _g_RenderNearClipDepth) +
                  (g_ProjectCameraZ0 < _g_RenderNearClipDepth);
          if ((flagByte < 3) &&
             (((g_ProjectCameraZ0 <= _g_FloatProjectionScaleY ||
               (g_ProjectCameraZ1 <= _g_FloatProjectionScaleY)) ||
              (g_ProjectCameraZ2 <= _g_FloatProjectionScaleY)))) {
            if ((value4[3] & 4U) == 0) {
              value6 = (byte)~(byte)value4[3] & 1;
            }
            else {
              value6 = 3;
            }
            localState35 = value6 << 7;
            if (((flagByte != 0) || (value6 == 3)) ||
               (value6 != (g_ProjectScreenX1 - g_ProjectScreenX0) *
                         (g_ProjectScreenY2 - g_ProjectScreenY0) -
                         (g_ProjectScreenX2 - g_ProjectScreenX0) *
                         (g_ProjectScreenY1 - g_ProjectScreenY0) <= _g_FloatZero)) {
              localState26[0] = g_ProjectScreenX0;
              localState26[3] = g_ProjectScreenY0;
              localState26[1] = g_ProjectScreenX1;
              localState22 = g_ProjectCameraZ0;
              localState26[2] = g_ProjectScreenX2;
              localState24 = g_ProjectScreenY1;
              localState21 = g_ProjectCameraZ1;
              localState23 = g_ProjectScreenY2;
              localState20 = g_ProjectCameraZ2;
              if (g_FadeBrightnessInverse != 0) {
                localState8 = localState8 +
                            (char)((*g_FadeTintRgbPtr +
                                   (CONCAT12(localState18,CONCAT11(localState7,localState8)) & 0xff) * -0x10
                                   ) * g_FadeBrightnessInverse >> 0x10);
                localState5 = localState5 +
                            (char)((*g_FadeTintRgbPtr +
                                   (CONCAT12(localState17,CONCAT11(localState4,localState5)) & 0xff) * -0x10
                                   ) * g_FadeBrightnessInverse >> 0x10);
                localState2 = localState2 +
                            (char)((*g_FadeTintRgbPtr +
                                   (CONCAT12(localState16,CONCAT11(localState,localState2)) & 0xff) * -0x10
                                   ) * g_FadeBrightnessInverse >> 0x10);
                localState9 = localState9 +
                            (char)((g_FadeTintRgbPtr[1] +
                                   (CONCAT12(localState7,CONCAT11(localState8,localState9)) & 0xff) *
                                   -0x10) * g_FadeBrightnessInverse >> 0x10);
                localState6 = localState6 +
                            (char)((g_FadeTintRgbPtr[1] +
                                   (CONCAT12(localState4,CONCAT11(localState5,localState6)) & 0xff) *
                                   -0x10) * g_FadeBrightnessInverse >> 0x10);
                localState3 = localState3 +
                            (char)((g_FadeTintRgbPtr[1] +
                                   (CONCAT12(localState,CONCAT11(localState2,localState3)) & 0xff) *
                                   -0x10) * g_FadeBrightnessInverse >> 0x10);
                localState19 = localState19 +
                           (char)((g_FadeTintRgbPtr[2] +
                                  (CONCAT12(localState8,CONCAT11(localState9,localState19)) & 0xff) * -0x10)
                                  * g_FadeBrightnessInverse >> 0x10);
                localState18 = localState18 +
                           (char)((g_FadeTintRgbPtr[2] +
                                  (CONCAT12(localState5,CONCAT11(localState6,localState18)) & 0xff) * -0x10)
                                  * g_FadeBrightnessInverse >> 0x10);
                localState17 = localState17 +
                           (char)((g_FadeTintRgbPtr[2] +
                                  (CONCAT12(localState2,CONCAT11(localState3,localState17)) & 0xff) * -0x10)
                                  * g_FadeBrightnessInverse >> 0x10);
              }
              localState16 = (char)*(undefined2 *)(dataCursor + 3);
              localState36 = (undefined1)((ushort)*(undefined2 *)(dataCursor + 3) >> 8);
              localState15 = *(undefined2 *)((int)dataCursor + 0xe);
              localState14 = *(undefined2 *)(dataCursor + 4);
              if ((*(byte *)((int)dataCursor + 0x12) & 0x10) == 0) {
                value6 = (ushort)g_RenderBlendMode;
              }
              else {
                value6 = 1;
              }
              localState35 = (value6 & 3) << 0xb | localState35 | *(byte *)((int)dataCursor + 0x12) & 0xf;
              value6 = ComputeTriangleAverageDepthSortKey();
              entry2 = (uint)value6 + g_DrawWindowXOffset;
              if ((int)((uint)value6 + g_DrawWindowXOffset) < g_DrawWindowMinX) {
                entry2 = g_DrawWindowMinX;
              }
              if (g_DrawWindowMaxX < entry2) {
                entry2 = g_DrawWindowMaxX;
              }
              localState13 = (short)entry2;
              entry2 = dataCursor[5];
              if (entry2 == 0) {
                floatCursor = localState26;
              }
              else {
                entry = dataCursor[6];
                floatCursor = localState26;
                floatCursor2 = localState10;
                for (entry3 = 0xf; entry3 != 0; entry3 = entry3 + -1) {
                  *floatCursor2 = *floatCursor;
                  floatCursor = floatCursor + 1;
                  floatCursor2 = floatCursor2 + 1;
                }
                entry2 = *(int *)(entry2 + 4) + entry * 0x26;
                if (*(char *)(entry2 + 0x14) == '\0') {
                  if (*(int *)(entry2 + 0x16) != 0) {
                    localState11 = (ushort)(*(uint *)(entry2 + 0x1e) >> 1) & 0xf | localState35 & 0xffe0;
                    resultFlag = (char)(*(uint *)(entry2 + 0x1e) >> 10) * '\b';
                    localState34 = localState34 + resultFlag;
                    localState32 = localState32 + resultFlag;
                    localState27 = localState27 + resultFlag;
                    resultFlag = (char)(*(uint *)(entry2 + 0x1e) >> 5) * '\b';
                    localState33 = localState33 + resultFlag;
                    localState30 = localState30 + resultFlag;
                    localState25 = localState25 + resultFlag;
                  }
                  floatCursor = localState10;
                }
                else {
                  localState34 = *(char *)(entry2 + 0x15) + localState16;
                  localState32 = localState32 + *(char *)(entry2 + 0x15);
                  localState27 = localState27 + *(char *)(entry2 + 0x15);
                  floatCursor = localState10;
                }
              }
              ClipAndQueueTriangleToNearPlane(floatCursor);
            }
          }
          localState31 = localState31 + 1;
          value4 = value4 + 4;
          dataCursor = dataCursor + 7;
          value = localState12;
        } while (localState31 < (int)(uint)*localState12);
      }
      value2 = value + 2;
      value3 = value4;
      flagByte = value[2];
    }
  }
  return;
}

