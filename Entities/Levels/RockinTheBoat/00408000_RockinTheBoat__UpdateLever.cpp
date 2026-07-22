#include "tarzan_ghidra_types.hpp"

// Address: 0x00408000
// Label: RockinTheBoat::UpdateLever
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateLever(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if ((value != 0) && (*( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2) == 0)) {
    resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds(value,0xf0,0,0);
    if (resultFlag != '\0') {
      *( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2) = 1;
      PlayAudioById(0x360,(int *)0,(undefined4 *)0);
      *(ushort *)(entry + 0x48) = (ushort)*( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2);
      *(undefined2 *)(value + 0xc) = 0x2010;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

