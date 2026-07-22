#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3833
// Label: HandleCTranscendentalDispatchException
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HandleCTranscendentalDispatchException(void)

{
  char resultFlag;
  ushort value;
  int callerFrameBase;
  ushort fpuStatusWord;
  float10 fpuValue;
  
  *(byte *)(callerFrameBase + -0x2c8) = *(byte *)(callerFrameBase + -0x2c8) & 0xfe;
  if (g_CrtTranscendentalDispatchExceptionCode != 0) {
    return;
  }
  *(double *)(callerFrameBase + -0x2d0) = (double)fpuValue;
  resultFlag = *(char *)(callerFrameBase + -0x90);
  if (resultFlag != '\0') {
    if ((resultFlag != -1) && (resultFlag != -2)) {
      if (resultFlag == '\0') {
        return;
      }
      *(int *)(callerFrameBase + -0x8e) = (int)resultFlag;
      goto LAB_004b3909;
    }
    value = *(ushort *)(callerFrameBase + -0x2ca) & 0x7ff0;
    if (value == 0) {
      *(undefined4 *)(callerFrameBase + -0x8e) = 4;
      fpuValue = (float10)fscale(fpuValue,(float10)_k_CrtTranscendentalExceptionConst3);
      if (ABS(fpuValue) < (float10)_k_CrtTranscendentalExceptionConst1) {
        fpuValue = fpuValue * (float10)_k_CrtTranscendentalExceptionConst5;
      }
      goto LAB_004b3909;
    }
    if (value == 0x7ff0) {
      *(undefined4 *)(callerFrameBase + -0x8e) = 3;
      fpuValue = (float10)fscale(fpuValue,(float10)_k_CrtTranscendentalExceptionConst2);
      if ((float10)_k_CrtTranscendentalExceptionConst0 < ABS(fpuValue)) {
        fpuValue = fpuValue * (float10)_k_CrtTranscendentalExceptionConst4;
      }
      goto LAB_004b3909;
    }
  }
  if ((*(ushort *)(callerFrameBase + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((fpuStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(callerFrameBase + -0x8e) = 8;
LAB_004b3909:
  *(int *)(callerFrameBase + -0x8a) = *(int *)(callerFrameBase + -0x94) + 1;
  if ((*(byte *)(callerFrameBase + -0x2c8) & 1) == 0) {
    *(undefined4 *)(callerFrameBase + -0x86) = *(undefined4 *)(callerFrameBase + 8);
    *(undefined4 *)(callerFrameBase + -0x82) = *(undefined4 *)(callerFrameBase + 0xc);
    if (*(char *)(*(int *)(callerFrameBase + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(callerFrameBase + -0x7e) = *(undefined4 *)(callerFrameBase + 0x10);
      *(undefined4 *)(callerFrameBase + -0x7a) = *(undefined4 *)(callerFrameBase + 0x14);
    }
  }
  *(double *)(callerFrameBase + -0x76) = (double)fpuValue;
  DispatchFloatingPointConversionError
            ((int)*(char *)(*(int *)(callerFrameBase + -0x94) + 0xe),callerFrameBase + -0x8e,callerFrameBase + -0xa4);
  return;
}

