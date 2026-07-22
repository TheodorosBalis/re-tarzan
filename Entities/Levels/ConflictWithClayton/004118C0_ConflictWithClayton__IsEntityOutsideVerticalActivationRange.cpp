#include "tarzan_ghidra_types.hpp"

// Address: 0x004118C0
// Label: ConflictWithClayton::IsEntityOutsideVerticalActivationRange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ConflictWithClayton::IsEntityOutsideVerticalActivationRange(int arg1)

{
  uint value;
  undefined3 value2;
  
  value = _g_PlayerSequenceFlags;
  if (((_g_PlayerSequenceFlags & 0x8000) == 0) &&
     (value = g_PlayerContactSurfaceThisFrame,
     (*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0)) {
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(arg1 + 0x18);
    value2 = (undefined3)(value >> 8);
    if ((int)value < -0x9c0) {
      return CONCAT31(value2,1);
    }
    if (0x1380 < (int)value) {
      return CONCAT31(value2,1);
    }
  }
  return value & 0xffffff00;
}

