#include "tarzan_ghidra_types.hpp"

// Address: 0x004449D0
// Label: CPlayerHero::ApplySurfaceResourceTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApplySurfaceResourceTrigger(uint arg1)

{
  if ((g_PlayerSurfaceTriggerPacket & 0x4000) != 0) {
    UnloadEncodedResourceId
              (*(undefined2 *)(&g_SurfaceTriggerResourceIdTable + (arg1 & 0xff) * 2));
    return;
  }
  LoadEncodedResourceId
            (CONCAT22((short)(g_PlayerSurfaceTriggerPacket >> 0x10),
                      *(undefined2 *)(&g_SurfaceTriggerResourceIdTable + (arg1 & 0xff) * 2)));
  return;
}

