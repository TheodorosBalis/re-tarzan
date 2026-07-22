#include "tarzan_ghidra_types.hpp"

// Address: 0x00407F90
// Label: RockinTheBoat::InitLever
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitLever(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined4 *)(value + 0x3c) = 0xffffff00;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->yaw = 0x400;
    *(undefined4 *)(value + 0x6c) = 0xffffffe2;
    *(ushort *)(entry + 0x48) = (ushort)*( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2);
    if (*( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2) == 0) {
      *(undefined2 *)(value + 0xc) = 0x200f;
    }
    else {
      *(undefined2 *)(value + 0xc) = 0x2010;
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

