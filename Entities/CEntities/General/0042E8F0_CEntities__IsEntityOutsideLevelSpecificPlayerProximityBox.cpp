#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E8F0
// Label: CEntities::IsEntityOutsideLevelSpecificPlayerProximityBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::IsEntityOutsideLevelSpecificPlayerProximityBox(int entry2)

{
  int entry;
  
  entry = CEntities::IsPointInsideExpandedLevelSpecificPlayerProximityBox
                    (&g_CameraFocusX,entry2 + 0x14);
  return entry == 0;
}

