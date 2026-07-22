#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FEC0
// Label: CEntities::GetPlayerDistanceAheadOfClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetPlayerDistanceAheadOfClayton(int entry)

{
  int value;
  
  value = *(int *)(entry + 0x110);
  if (value == *(int *)(g_PlayerEntitySceneObject + 0x110)) {
    return *(int *)(g_PlayerEntitySceneObject + 0x10c) - *(int *)(entry + 0x10c);
  }
  return (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                  g_CollisionSurfaceTable) - *(int *)(entry + 0x10c)) +
         *(int *)(g_PlayerEntitySceneObject + 0x10c);
}

