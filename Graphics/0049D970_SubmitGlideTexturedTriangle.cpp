#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D970
// Label: SubmitGlideTexturedTriangle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SubmitGlideTexturedTriangle(float *graphicsObject)

{
  byte flagByte;
  ushort value2;
  int value;
  undefined4 value3;
  undefined4 value4;
  undefined4 value5;
  float localState31;
  float localState30;
  undefined4 localState29;
  undefined4 localState28;
  undefined4 localState27;
  undefined4 localState26;
  undefined4 localState25;
  undefined4 localState24;
  float localState23;
  float localState3 [6];
  float localState22;
  float localState20;
  undefined4 localState19;
  undefined4 localState18;
  undefined4 localState17;
  undefined4 localState16;
  undefined4 localState15;
  undefined4 localState14;
  float localState13;
  float localState2 [6];
  float localState12;
  float localState11;
  undefined4 localState10;
  undefined4 localState9;
  undefined4 localState8;
  undefined4 localState7;
  undefined4 localState6;
  undefined4 localState5;
  float localState4;
  float localState [6];
  float localState21;
  
  if (g_GlideWindowStateNeedsRestore != 0) {
    g_GlideGammaTable = (undefined *)&DAT_00722e68;
    if (((uint)graphicsObject[0xe] & 0x40) == 0) {
      g_GlideGammaTable = (undefined *)&DAT_007229a8;
    }
    *(ushort *)(graphicsObject + 0xe) = *(ushort *)(graphicsObject + 0xe) & 0xffef;
    if (((byte)*(ushort *)(graphicsObject + 0xe) & 0x1f) != g_GlideCurrentTexturePageIndex) {
      value = 0;
      if (0 < *(int *)(&g_GlideTextureUploadScratch + (*(ushort *)(graphicsObject + 0xe) & 0x1f) * 8)) {
        do {
          (*g_GlideTexCombineProc)(value,3,8,3,8,0,0);
          value = value + 1;
        } while (value < *(int *)(&g_GlideTextureUploadScratch +
                                 (*(byte *)(graphicsObject + 0xe) & 0x1f) * 8));
      }
      (*g_GlideTexCombineProc)(value,1,0,1,0,0,0);
      (*g_GlideProcTable_Field0080)
                (value,*(undefined4 *)
                        (&g_GlideTextureMemoryRanges + (*(byte *)(graphicsObject + 0xe) & 0x1f) * 8),3,
                 &g_GlideViewportLeft);
      g_GlideCurrentTexturePageIndex = *(byte *)(graphicsObject + 0xe) & 0x1f;
    }
    flagByte = (byte)(*(ushort *)(graphicsObject + 0xe) >> 6);
    if ((flagByte & 1) != g_GlideCurrentTextureModulationMode) {
      g_GlideCurrentTextureModulationMode = flagByte & 1;
      if ((*(ushort *)(graphicsObject + 0xe) >> 6 & 1) == 0) {
        value = 0;
        if (0 < g_GlideRenderStateColorCombine) {
          do {
            (*g_GlideTexClampModeProc)(value,1,1);
            value = value + 1;
          } while (value < g_GlideRenderStateColorCombine);
        }
      }
      else {
        value = 0;
        if (0 < g_GlideRenderStateColorCombine) {
          do {
            (*g_GlideTexClampModeProc)(value,0,0);
            value = value + 1;
          } while (value < g_GlideRenderStateColorCombine);
        }
      }
    }
    if (((byte)(*(ushort *)(graphicsObject + 0xe) >> 0xb) & 3) != g_GlideFrameBufferStride) {
      value2 = *(ushort *)(graphicsObject + 0xe) & 0x1800;
      if (value2 == 0) {
        value5 = 0;
        value4 = 5;
        value3 = 1;
      }
      else if (value2 == 0x800) {
        value5 = 4;
        value4 = 4;
        value3 = 4;
      }
      else {
        value5 = 0;
        if (value2 == 0x1000) {
          value4 = 6;
          value3 = 0;
        }
        else {
          value4 = 0;
          value3 = 2;
        }
      }
      (*g_GlideAlphaBlendFunctionProc)(value3,value4,value5,0);
      g_GlideFrameBufferStride = (byte)((ushort)*(undefined2 *)(graphicsObject + 0xe) >> 0xb) & 3;
    }
    localState31 = (*graphicsObject + 786432.0) - 786432.0;
    localState30 = (graphicsObject[3] + 786432.0) - 786432.0;
    if (_g_RenderNearClipDepth < graphicsObject[6]) {
      localState23 = _g_RenderNearClipDepth / graphicsObject[6];
    }
    else {
      localState23 = 1.0;
    }
    localState21 = 786432.0;
    localState24 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x27)];
    localState28 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x26)];
    localState27 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x25)];
    localState26 = (&g_GlideTriangleVertexScratch)[*(byte *)(graphicsObject + 9)];
    value = *(int *)(&g_GlideTextureUploadScratch + (*(byte *)(graphicsObject + 0xe) & 0x1f) * 8);
    flagByte = *(byte *)(graphicsObject + 0xc);
    localState3[value * 3] =
         localState23 * *(float *)(g_GlideGammaTable + (uint)*(byte *)((int)graphicsObject + 0x31) * 4);
    localState3[value * 3 + 1] = localState23 * *(float *)(g_GlideGammaTable + (uint)flagByte * 4);
    localState25 = 0;
    localState29 = 0;
    localState22 = (graphicsObject[1] + localState21) - localState21;
    localState20 = (graphicsObject[4] + 786432.0) - 786432.0;
    if (_g_RenderNearClipDepth < graphicsObject[7]) {
      localState13 = _g_RenderNearClipDepth / graphicsObject[7];
    }
    else {
      localState13 = 1.0;
    }
    localState21 = 786432.0;
    localState14 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x2b)];
    localState18 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x2a)];
    localState17 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x29)];
    localState16 = (&g_GlideTriangleVertexScratch)[*(byte *)(graphicsObject + 10)];
    value = *(int *)(&g_GlideTextureUploadScratch + (*(byte *)(graphicsObject + 0xe) & 0x1f) * 8);
    flagByte = *(byte *)((int)graphicsObject + 0x32);
    localState2[value * 3] =
         localState13 * *(float *)(g_GlideGammaTable + (uint)*(byte *)((int)graphicsObject + 0x33) * 4);
    localState2[value * 3 + 1] = localState13 * *(float *)(g_GlideGammaTable + (uint)flagByte * 4);
    localState15 = 0;
    localState19 = 0;
    localState12 = (graphicsObject[2] + localState21) - localState21;
    localState21 = 786432.0;
    localState11 = (graphicsObject[5] + 786432.0) - 786432.0;
    if (_g_RenderNearClipDepth < graphicsObject[8]) {
      localState4 = _g_RenderNearClipDepth / graphicsObject[8];
    }
    else {
      localState4 = 1.0;
    }
    localState5 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x2f)];
    localState9 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x2e)];
    localState8 = (&g_GlideTriangleVertexScratch)[*(byte *)((int)graphicsObject + 0x2d)];
    localState7 = (&g_GlideTriangleVertexScratch)[*(byte *)(graphicsObject + 0xb)];
    value = *(int *)(&g_GlideTextureUploadScratch + (*(byte *)(graphicsObject + 0xe) & 0x1f) * 8);
    flagByte = *(byte *)(graphicsObject + 0xd);
    localState[value * 3] =
         localState4 * *(float *)(g_GlideGammaTable + (uint)*(byte *)((int)graphicsObject + 0x35) * 4);
    localState[value * 3 + 1] = localState4 * *(float *)(g_GlideGammaTable + (uint)flagByte * 4);
    localState6 = 0;
    localState10 = 0;
    (*g_GlideProcTable_Field0084)(&localState31,&localState22,&localState12);
  }
  return;
}

