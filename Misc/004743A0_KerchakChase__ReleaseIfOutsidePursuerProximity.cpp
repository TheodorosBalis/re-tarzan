#include "tarzan_ghidra_types.hpp"

// Address: 0x004743A0
// Label: KerchakChase::ReleaseIfOutsidePursuerProximity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::ReleaseIfOutsidePursuerProximity(undefined4 arg1)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(arg1,0x200);
  if (value != 0) {
    value = CEntities::IsPointInsideExpandedLevelSpecificPlayerProximityBox
                      (&g_CameraFocusX,*(int *)(value + 0x18) + 0x20);
    if (value == 0) {
      CEntities::ReleaseEntityToFreeList((byte *)arg1);
    }
  }
  return;
}

