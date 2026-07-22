#include "tarzan_ghidra_types.hpp"

// Address: 0x00495E20
// Label: ResetDirect3DRendererGlobals
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetDirect3DRendererGlobals(void)

{
  int value;
  undefined4 *dataCursor;
  int scratchRect;
  
  g_DirectDrawSelectedDriverGuid = 0;
  dataCursor = &g_Direct3DTexturePageReadyTable;
  for (value = 0x10; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = &g_Direct3DTexturePageSurfaceTable;
  for (value = 0x10; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = &g_Direct3DTextureSurfaceTable;
  for (value = 0x10; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = &g_Direct3DQueuedTriangleV0;
  for (value = 0x6000; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  g_Direct3DFrameDirty = 0;
  g_Direct3DLastResult = 0;
  g_Direct3DFrameBufferLocked = 0;
  scratchRect = 0;
  do {
    value = scratchRect + 1;
    *(float *)(&g_Direct3DRendererResetState_Field0000 + value * 4) = (float)scratchRect;
    *(float *)(&g_DefaultDirectDrawSurfaceDesc555_Field0068 + value * 4) =
         (float)scratchRect * _g_FloatOneOver256;
    (&g_SavedWindowStyleBeforeDirect3D)[value] =
         ((float)scratchRect + _g_FloatRenderHalfPixelOffset) * _g_FloatOneOver256;
    scratchRect = value;
  } while (value < 0x100);
  g_Direct3DModulatedColorLookupTable = (undefined *)&DAT_0053acf4;
  g_Direct3DDefaultColorLookupTable = (undefined *)&DAT_0053a808;
  g_Direct3DActiveColorLookupTable = (undefined *)&DAT_0053a808;
  g_DirectDrawLibraryHandle = 0;
  return;
}

