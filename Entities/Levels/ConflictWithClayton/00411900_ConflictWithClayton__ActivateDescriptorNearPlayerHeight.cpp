#include "tarzan_ghidra_types.hpp"

// Address: 0x00411900
// Label: ConflictWithClayton::ActivateDescriptorNearPlayerHeight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConflictWithClayton::ActivateDescriptorNearPlayerHeight(int arg1)

{
  int value;
  
  if ((((_g_PlayerSequenceFlags & 0x8000) == 0) &&
      ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0)) &&
     (g_ClaytonBattleBehaviorState == 0)) {
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(arg1 + 4);
    if ((-0x681 < value) && (value < 0xd01)) {
      InstantiateEntityFromDescriptor(arg1);
    }
  }
  return;
}

