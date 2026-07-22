#include "tarzan_ghidra_types.hpp"

// Address: 0x00468800
// Label: TarzanToTheRescue::UpdateFishSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateFishSpawner(undefined4 entry)

{
  char resultFlag;
  int value;
  uint value3;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value != 0) &&
     (value2 = *(int *)(value + 0x14), *(int *)(value + 0x14) = value2 + -1, value2 < 0)) {
    value3 = RandomModulo(0x1000);
    value2 = RandomModulo(0x200);
    CEntities::SpawnEntityByTypeAtPosition
              (((int)(short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * (value2 + 0x80) >> 0xc) +
               *(int *)(value + 0x18),*(undefined4 *)(value + 0x1c),
               ((int)(short)(&g_SinCosTable12Bit)[value3 & 0xfff] * (value2 + 0x80) >> 0xc) +
               *(int *)(value + 0x20),0x179,0x11);
    value2 = RandomModulo(0x1e);
    *(int *)(value + 0x14) = value2 + 0x18;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

