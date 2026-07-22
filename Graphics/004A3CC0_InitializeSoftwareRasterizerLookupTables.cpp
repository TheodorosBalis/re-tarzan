#include "tarzan_ghidra_types.hpp"

// Address: 0x004A3CC0
// Label: InitializeSoftwareRasterizerLookupTables
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitializeSoftwareRasterizerLookupTables(void)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined4 *dataCursor;
  int value6;
  int localState;
  
  value4 = 0;
  dataCursor = &g_SoftwareRasterizerTableArena;
  for (value2 = 0x8c100; value2 != 0; value2 = value2 + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  do {
    value2 = ConvertFpuTopToInt64();
    if (0xfe < value2) {
      value2 = 0xff;
    }
    (&g_RenderPacketShadeLookupTable)[value4] = (char)value2;
    value4 = value4 + 1;
  } while (value4 < 0x100);
  if (g_MmxCpuSupported == 0) {
    g_RasterizeTriangleModulatedFn = RasterizeTriangleModulatedToBackBuffer;
    g_RasterizeTriangleWhiteFastFn = RasterizeTriangleWhiteFastToBackBuffer;
  }
  else {
    g_RasterizeTriangleModulatedFn = RasterizeTriangleModulatedMmxToBackBuffer;
    g_RasterizeTriangleWhiteFastFn = RasterizeTriangleWhiteFastMmxToBackBuffer;
  }
  ConvertGraphicsPageBufferToCurrentPixelLayout();
  value2 = 0;
  do {
    value3 = 0;
    value4 = 0;
    do {
      value3 = value3 + 1;
      *(char *)(g_Modulate5BitBlendLookupTable + value2 * 0x20 + -1 + value3) =
           ((char)(value4 / 0x1f) + (char)(value4 >> 0x1f)) -
           (char)((longlong)value4 * 0x84210843 >> 0x3f);
      value4 = value4 + value2;
    } while (value3 < 0x20);
    value2 = value2 + 1;
  } while (value2 < 0x20);
  value2 = 0;
  do {
    localState = 0;
    value4 = value2 << 10;
    do {
      value3 = 0;
      value6 = 0;
      do {
        value5 = value2 + value6 / 0x1f;
        value = 0x1f;
        if (value5 < 0x20) {
          value = value5;
        }
        *(char *)(g_Additive5BitBlendLookupTable + value4 + value3) = (char)value;
        value5 = value2 - value6 / 0x1f;
        *(byte *)(g_Subtractive5BitBlendLookupTable + value4 + value3) =
             (value5 < 0) - 1U & (byte)value5;
        value3 = value3 + 1;
        value6 = value6 + localState;
      } while (value3 < 0x20);
      value4 = value4 + 0x20;
      localState = localState + 1;
    } while (localState < 0x20);
    value2 = value2 + 1;
  } while (value2 < 0x20);
  BuildBrightnessLookupTable(0x32);
  GeneratePolynomialLookupTable();
  return;
}

