#include "tarzan_ghidra_types.hpp"

// Address: 0x00447A50
// Label: SetHudExtraLifeMeterEnabled
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetHudExtraLifeMeterEnabled(char arg1)

{
  undefined4 *dataCursor;
  
  g_HudExtraLifeMeterEnabled = arg1;
  if (arg1 == '\0') {
    dataCursor = &g_HudExtraLifeMeterPartialSegmentQuad;
    do {
      *dataCursor = 0;
      dataCursor = dataCursor + 0xe;
    } while ((int)dataCursor < 0x532660);
    g_HudExtraLifeMeterIconQuad = 0;
  }
  return;
}

