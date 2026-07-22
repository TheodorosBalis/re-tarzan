#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FF10
// Label: CEntities::GetClaytonDistanceAheadOfPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetClaytonDistanceAheadOfPlayer(int entry)

{
  int value;
  
  value = *(int *)(g_PlayerEntitySceneObject + 0x110);
  if (*(int *)(entry + 0x110) == value) {
    return *(int *)(entry + 0x10c) - *(int *)(g_PlayerEntitySceneObject + 0x10c);
  }
  return (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                  g_CollisionSurfaceTable) - *(int *)(g_PlayerEntitySceneObject + 0x10c)) +
         *(int *)(entry + 0x10c);
}

