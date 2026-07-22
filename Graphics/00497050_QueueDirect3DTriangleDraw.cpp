#include "tarzan_ghidra_types.hpp"

// Address: 0x00497050
// Label: QueueDirect3DTriangleDraw
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QueueDirect3DTriangleDraw(undefined4 *arg1)

{
  bool flagByte;
  float edgeSlope;
  undefined *dataCursor;
  int value;
  byte flagByte2;
  ushort value3;
  int value2;
  undefined4 value4;
  
  flagByte = false;
  if (g_Direct3DFrameDirty == 0) {
    return;
  }
  if ((*(byte *)(arg1 + 0xe) & 0x40) == 0) {
    g_Direct3DActiveColorLookupTable = g_Direct3DDefaultColorLookupTable;
  }
  else {
    g_Direct3DActiveColorLookupTable = g_Direct3DModulatedColorLookupTable;
  }
  *(ushort *)(arg1 + 0xe) = *(ushort *)(arg1 + 0xe) & 0xffef;
  if (0x3ff < g_Direct3DViewport + 3) {
    UploadPendingDirect3DFrameBuffer();
  }
  if (g_Direct3DBackBufferPixelFormat == 0) {
    *(undefined1 *)((int)arg1 + 0x2f) = 0xff;
    *(undefined1 *)((int)arg1 + 0x2b) = 0xff;
    *(undefined1 *)((int)arg1 + 0x27) = 0xff;
  }
  if (((*(ushort *)(arg1 + 0xe) & 0x1800) == 0x1000) && (g_Direct3DDisableBlackTransparency == 0)
     ) {
    *(undefined1 *)(arg1 + 0xb) = 0;
    *(undefined1 *)((int)arg1 + 0x2d) = 0;
    *(undefined1 *)((int)arg1 + 0x2e) = 0;
    *(undefined1 *)(arg1 + 10) = 0;
    *(undefined1 *)((int)arg1 + 0x29) = 0;
    *(undefined1 *)((int)arg1 + 0x2a) = 0;
    *(undefined1 *)(arg1 + 9) = 0;
    *(undefined1 *)((int)arg1 + 0x25) = 0;
    *(undefined1 *)((int)arg1 + 0x26) = 0;
  }
  value3 = *(ushort *)(arg1 + 0xe) & 0xe7ff;
  *(ushort *)(arg1 + 0xe) =
       ((byte)(&g_Direct3DTextureBlendModeMap)[((*(ushort *)(arg1 + 0xe) & 0x1800) >> 0xb) * 2] &
       3) << 0xb | value3;
  if (((byte)value3 & 0x1f) != g_Direct3DBackBufferPixelMask) {
    UploadPendingDirect3DFrameBuffer();
    flagByte = true;
    g_Direct3DBackBufferPixelMask = *(byte *)(arg1 + 0xe) & 0x1f;
    if (g_Direct3DDevice != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DDevice + 0x5c))
                     (g_Direct3DDevice,1,
                      (&g_Direct3DTexturePageReadyTable)[*(byte *)(arg1 + 0xe) & 0x1f]);
    }
  }
  flagByte2 = (byte)(*(ushort *)(arg1 + 0xe) >> 6);
  if ((flagByte2 & 1) != g_Direct3DRenderStateCurrentTexturePage) {
    g_Direct3DRenderStateCurrentTexturePage = flagByte2 & 1;
    if (!flagByte) {
      UploadPendingDirect3DFrameBuffer();
      flagByte = true;
    }
    if ((g_Direct3DDevice != (int *)0x0) &&
       (g_Direct3DLastResult =
             (**(code **)(*g_Direct3DDevice + 0x5c))
                       (g_Direct3DDevice,0x11,2 - (uint)((*(byte *)(arg1 + 0xe) & 0x40) != 0)),
       g_Direct3DDevice != (int *)0x0)) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DDevice + 0x5c))
                     (g_Direct3DDevice,0x12,2 - (uint)((*(byte *)(arg1 + 0xe) & 0x40) != 0));
    }
  }
  if (((byte)(*(ushort *)(arg1 + 0xe) >> 0xb) & 3) == g_Direct3DRenderStateDirty)
  goto LAB_004972e7;
  value3 = *(ushort *)(arg1 + 0xe) & 0x1800;
  if (value3 == 0) {
    if (!flagByte) {
      UploadPendingDirect3DFrameBuffer();
    }
    if ((g_Direct3DDevice != (int *)0x0) &&
       (g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x13,5),
       g_Direct3DDevice != (int *)0x0)) {
      value = *g_Direct3DDevice;
      value4 = 6;
      goto LAB_004972ce;
    }
  }
  else if (value3 == 0x800) {
    if (!flagByte) {
      UploadPendingDirect3DFrameBuffer();
    }
    if ((g_Direct3DDevice != (int *)0x0) &&
       (g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x13,2),
       g_Direct3DDevice != (int *)0x0)) {
      value = *g_Direct3DDevice;
      value4 = 2;
      goto LAB_004972ce;
    }
  }
  else if (value3 == 0x1000) {
    if (!flagByte) {
      UploadPendingDirect3DFrameBuffer();
    }
    if ((g_Direct3DDevice != (int *)0x0) &&
       (g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x13,1),
       g_Direct3DDevice != (int *)0x0)) {
      value = *g_Direct3DDevice;
      value4 = 4;
LAB_004972ce:
      g_Direct3DLastResult = (**(code **)(value + 0x5c))(g_Direct3DDevice,0x14,value4);
    }
  }
  else {
    if (!flagByte) {
      UploadPendingDirect3DFrameBuffer();
    }
    if ((g_Direct3DDevice != (int *)0x0) &&
       (g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x5c))(g_Direct3DDevice,0x13,9),
       g_Direct3DDevice != (int *)0x0)) {
      value = *g_Direct3DDevice;
      value4 = 1;
      goto LAB_004972ce;
    }
  }
  g_Direct3DRenderStateDirty = (byte)((ushort)*(undefined2 *)(arg1 + 0xe) >> 0xb) & 3;
LAB_004972e7:
  dataCursor = g_Direct3DActiveColorLookupTable;
  edgeSlope = _g_RenderNearClipDepth;
  if (_g_RenderNearClipDepth < (float)arg1[6]) {
    edgeSlope = _g_RenderNearClipDepth / (float)arg1[6];
  }
  value = g_Direct3DViewport * 0x60;
  *(float *)(&g_Direct3DQueuedTriangleBuffer + value) = edgeSlope;
  (&g_Direct3DQueuedTriangleV0)[g_Direct3DViewport * 0x18] = *arg1;
  (&g_Direct3DQueuedTriangleV1)[g_Direct3DViewport * 0x18] = arg1[3];
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv0 + value) = arg1[9];
  edgeSlope = _g_FloatOneOver65536;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv1 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)((int)arg1 + 0x31) * 4);
  value2 = g_Direct3DViewport * 3 + 1;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv2 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)(arg1 + 0xc) * 4);
  *(float *)(&g_Direct3DQueuedTriangleV2 + value) =
       edgeSlope / *(float *)(&g_Direct3DQueuedTriangleBuffer + value);
  edgeSlope = _g_RenderNearClipDepth;
  if (_g_RenderNearClipDepth < (float)arg1[7]) {
    edgeSlope = _g_RenderNearClipDepth / (float)arg1[7];
  }
  value = value2 * 0x20;
  *(float *)(&g_Direct3DQueuedTriangleBuffer + value) = edgeSlope;
  (&g_Direct3DQueuedTriangleV0)[value2 * 8] = arg1[1];
  (&g_Direct3DQueuedTriangleV1)[value2 * 8] = arg1[4];
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv0 + value) = arg1[10];
  edgeSlope = _g_FloatOneOver65536;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv1 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)((int)arg1 + 0x33) * 4);
  value2 = g_Direct3DViewport * 3 + 2;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv2 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)((int)arg1 + 0x32) * 4);
  *(float *)(&g_Direct3DQueuedTriangleV2 + value) =
       edgeSlope / *(float *)(&g_Direct3DQueuedTriangleBuffer + value);
  edgeSlope = _g_RenderNearClipDepth;
  if (_g_RenderNearClipDepth < (float)arg1[8]) {
    edgeSlope = _g_RenderNearClipDepth / (float)arg1[8];
  }
  value = value2 * 0x20;
  *(float *)(&g_Direct3DQueuedTriangleBuffer + value) = edgeSlope;
  (&g_Direct3DQueuedTriangleV0)[value2 * 8] = arg1[2];
  (&g_Direct3DQueuedTriangleV1)[value2 * 8] = arg1[5];
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv0 + value) = arg1[0xb];
  edgeSlope = _g_FloatOneOver65536;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv1 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)((int)arg1 + 0x35) * 4);
  g_Direct3DViewport = g_Direct3DViewport + 1;
  *(undefined4 *)(&g_Direct3DQueuedTriangleUv2 + value) =
       *(undefined4 *)(dataCursor + (uint)*(byte *)(arg1 + 0xd) * 4);
  *(float *)(&g_Direct3DQueuedTriangleV2 + value) =
       edgeSlope / *(float *)(&g_Direct3DQueuedTriangleBuffer + value);
  return;
}

