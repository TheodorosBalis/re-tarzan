#include "tarzan_ghidra_types.hpp"

// Address: 0x00454CB0
// Label: Stampede::SpawnElephantsEntity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::SpawnElephantsEntity(void)

{
  g_StampedeElephantsEntity = CEntities::SpawnEntityByTypeAtPosition(0,0,0,0x87,0x11);
  return;
}

