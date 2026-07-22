#include "tarzan_ghidra_types.hpp"

// Address: 0x00497A10
// Label: CreateDirectDrawPrimaryAndBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CreateDirectDrawPrimaryAndBackBuffer(void)

{
  int value;
  undefined4 *bufferCursor;
  undefined4 scratchRect7;
  undefined4 scratchRect8 [4];
  int scratchRect3;
  int scratchRect2;
  int scratchRect;
  undefined4 scratchRect6 [5];
  undefined4 scratchRect5;
  undefined4 scratchRect4;
  
  bufferCursor = scratchRect6;
  for (value = 0x1b; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  scratchRect6[0] = 0x6c;
  scratchRect6[1] = 0x21;
  scratchRect4 = 0xa18;
  scratchRect5 = 2;
  if (g_DirectDrawObject != (int *)0x0) {
    g_DirectDrawLastResult =
         (**(code **)(*g_DirectDrawObject + 0x18))
                   (g_DirectDrawObject,scratchRect6,&g_DirectDrawPrimarySurface,0);
  }
  if ((g_DirectDrawLastResult != 0) && (scratchRect5 = 1, g_DirectDrawObject != (int *)0x0)) {
    g_DirectDrawLastResult =
         (**(code **)(*g_DirectDrawObject + 0x18))
                   (g_DirectDrawObject,scratchRect6,&g_DirectDrawPrimarySurface,0);
  }
  scratchRect7 = 4;
  if (g_DirectDrawPrimarySurface != (int *)0x0) {
    g_DirectDrawLastResult =
         (**(code **)(*g_DirectDrawPrimarySurface + 0x30))
                   (g_DirectDrawPrimarySurface,&scratchRect7,&g_DirectDrawBackBufferSurface);
  }
  bufferCursor = scratchRect8;
  for (value = 8; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  scratchRect8[0] = 0x20;
  if (g_DirectDrawPrimarySurface != (int *)0x0) {
    g_DirectDrawLastResult =
         (**(code **)(*g_DirectDrawPrimarySurface + 0x54))(g_DirectDrawPrimarySurface,scratchRect8);
  }
  if (scratchRect3 == 0xf800) {
    if (scratchRect2 != 0x7e0) {
      return 0;
    }
    if (scratchRect != 0x1f) {
      return 0;
    }
    g_DirectDrawBackBufferIsRgb565 = 1;
  }
  else {
    if (scratchRect3 != 0x7c00) {
      return 0;
    }
    if (scratchRect2 != 0x3e0) {
      return 0;
    }
    if (scratchRect != 0x1f) {
      return 0;
    }
    g_DirectDrawBackBufferIsRgb565 = 0;
  }
  if ((g_DirectDrawPrimarySurface != (int *)0x0) && (g_DirectDrawBackBufferSurface != 0)) {
    return 1;
  }
  return 0;
}

