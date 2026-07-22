#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AA40
// Label: CCamera::ProjectForwardPoint
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::ProjectForwardPoint(int *cameraState,int *target)

{
  short shortValue;
  short shortValue2;
  int value;
  int value2;
  
  value = cameraState[5];
  shortValue = (&g_SinCosTable12Bit)[(int)(short)cameraState[0x14] - 0x400U & 0xfff];
  value2 = (short)(&g_SinCosTable12Bit)[(int)(short)cameraState[0x14] & 0xfff] * value >> 0xc;
  shortValue2 = (&g_SinCosTable12Bit)[(int)*(short *)((int)cameraState + 0x52) & 0xfff];
  *target = ((short)(&g_SinCosTable12Bit)[(int)*(short *)((int)cameraState + 0x52) - 0x400U & 0xfff] *
              value2 >> 0xc) + *cameraState;
  target[1] = cameraState[1] + (-(shortValue * value) >> 0xc);
  target[2] = cameraState[2] + (-(shortValue2 * value2) >> 0xc);
  return;
}

