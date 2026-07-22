#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9300
// Label: GeneratePolynomialLookupTable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GeneratePolynomialLookupTable(void)

{
  undefined2 value;
  undefined2 *dataCursor;
  
  UpdateGameLoopFlag(0);
  dataCursor = &g_RenderPacketSortTable;
  do {
    value = ConvertFpuTopToInt64();
    *dataCursor = value;
    dataCursor = dataCursor + 1;
  } while ((int)dataCursor < 0xa04a80);
  ResetRenderPacketCount();
  return;
}

