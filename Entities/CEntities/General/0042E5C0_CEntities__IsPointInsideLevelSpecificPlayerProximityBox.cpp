#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E5C0
// Label: CEntities::IsPointInsideLevelSpecificPlayerProximityBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::IsPointInsideLevelSpecificPlayerProximityBox(undefined4 entry,int *sceneObject)

{
  int value;
  int value2;
  
  value = *sceneObject - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value2 = sceneObject[2] - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  switch(*( undefined1 *)((int)&g_LevelTransitionContext + 2)) {
  case 4:
    if (((g_LevelProximityBox4MinX < value) && (value < g_LevelProximityBox4MaxX)) &&
       ((g_LevelProximityBox4MinZ < value2 && (value2 < g_LevelProximityBox4MaxZ)))) {
      return 1;
    }
    break;
  case 0xc:
    if ((((g_LevelProximityBox0MinX < value) && (value < g_LevelProximityBox0MaxX)) &&
        (g_LevelProximityBox0MinZ < value2)) && (value2 < g_LevelProximityBox0MaxZ)) {
      return 1;
    }
    break;
  case 0xe:
    if (((g_LevelProximityBox3MinX < value) && (value < g_LevelProximityBox3MaxX)) &&
       ((g_LevelProximityBox3MinZ < value2 && (value2 < g_LevelProximityBox3MaxZ)))) {
      return 1;
    }
    break;
  case 0xf:
    if (((g_LevelProximityBox2MinX < value) && (value < g_LevelProximityBox2MaxX)) &&
       ((g_LevelProximityBox2MinZ < value2 && (value2 < g_LevelProximityBox2MaxZ)))) {
      return 1;
    }
    break;
  case 0x12:
    if ((((g_LevelProximityBox1MinX < value) && (value < g_LevelProximityBox1MaxX)) &&
        (g_LevelProximityBox1MinZ < value2)) && (value2 < g_LevelProximityBox1MaxZ)) {
      return 1;
    }
  }
  return 0;
}

