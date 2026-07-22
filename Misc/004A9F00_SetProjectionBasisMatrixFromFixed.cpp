#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9F00
// Label: SetProjectionBasisMatrixFromFixed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetProjectionBasisMatrixFromFixed(short *arg1)

{
  int value;
  float *floatCursor;
  float *floatCursor2;
  float scratchTransform6 [4];
  float scratchTransform5;
  float scratchTransform4;
  float scratchTransform3;
  float scratchTransform2;
  float scratchTransform;
  
  scratchTransform6[0] = (float)(int)*arg1 * _g_FloatProjectionScaleX;
  scratchTransform6[1] = (float)(int)arg1[1] * _g_FloatProjectionScaleX;
  scratchTransform6[2] = (float)(int)arg1[2] * _g_FloatProjectionScaleX;
  scratchTransform6[3] = (float)(int)arg1[3] * _g_FloatProjectionScaleX;
  scratchTransform5 = (float)(int)arg1[4] * _g_FloatProjectionScaleX;
  scratchTransform4 = (float)(int)arg1[5] * _g_FloatProjectionScaleX;
  scratchTransform3 = (float)(int)arg1[6] * _g_FloatProjectionScaleX;
  scratchTransform2 = (float)(int)arg1[7] * _g_FloatProjectionScaleX;
  scratchTransform = (float)(int)arg1[8] * _g_FloatProjectionScaleX;
  floatCursor = scratchTransform6;
  floatCursor2 = (float *)&g_ProjectMatrix00;
  for (value = 9; value != 0; value = value + -1) {
    *floatCursor2 = *floatCursor;
    floatCursor = floatCursor + 1;
    floatCursor2 = floatCursor2 + 1;
  }
  return;
}

