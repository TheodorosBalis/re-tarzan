#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2250
// Label: InitializeSinCosLookupTable12Bit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeSinCosLookupTable12Bit(void)

{
  undefined2 value2;
  int value;
  undefined2 *dataCursor;
  undefined4 *dataCursor2;
  int localState;
  
  localState = 0;
  dataCursor2 = &DAT_0077e790;
  for (value = 8; value != 0; value = value + -1) {
    *dataCursor2 = 0;
    dataCursor2 = dataCursor2 + 1;
  }
  dataCursor = &g_SinCosTable12Bit;
  do {
    fcos((float10)localState * (float10)_g_DoubleAngleStepRadians12Bit);
    value2 = ConvertFpuTopToInt64();
    *dataCursor = value2;
    dataCursor = dataCursor + 1;
    localState = localState + 1;
  } while ((int)dataCursor < 0x77e788);
  return;
}

