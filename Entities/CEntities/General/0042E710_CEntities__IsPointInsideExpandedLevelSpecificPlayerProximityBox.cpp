#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E710
// Label: CEntities::IsPointInsideExpandedLevelSpecificPlayerProximityBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Type propagation algorithm not settling */

undefined4
CEntities::IsPointInsideExpandedLevelSpecificPlayerProximityBox(undefined4 entry,int *sceneObject)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  
  value4 = *sceneObject - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value5 = sceneObject[2] - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  switch(*( undefined1 *)((int)&g_LevelTransitionContext + 2)) {
  case 4:
    value = g_LevelProximityBox4MaxX;
    value2 = g_LevelProximityBox4MinZ;
    value6 = g_LevelProximityBox4MaxZ;
    value3 = g_LevelProximityBox4MinX;
    break;
  default:
    goto switchD_0042e745_caseD_5;
  case 0xc:
    if (value4 <= g_LevelProximityBox0MinX) {
      return 0;
    }
    if (g_LevelProximityBox0MaxX <= value4) {
      return 0;
    }
    if (value5 <= g_LevelProximityBox0MinZ + -0x1000) {
      return 0;
    }
    value6 = g_LevelProximityBox0MaxZ + 0x1000;
    goto LAB_0042e884;
  case 0xe:
    value = g_LevelProximityBox3MaxX;
    value2 = g_LevelProximityBox3MinZ;
    value6 = g_LevelProximityBox3MaxZ;
    value3 = g_LevelProximityBox3MinX;
    break;
  case 0xf:
    if (value4 <= g_LevelProximityBox2MinX + -1000) {
      return 0;
    }
    if (g_LevelProximityBox2MaxX + 1000 <= value4) {
      return 0;
    }
    if (value5 <= g_LevelProximityBox2MinZ + -1000) {
      return 0;
    }
    value6 = g_LevelProximityBox2MaxZ + 1000;
    goto LAB_0042e884;
  case 0x12:
    value = g_LevelProximityBox1MaxX;
    value2 = g_LevelProximityBox1MinZ;
    value6 = g_LevelProximityBox1MaxZ;
    value3 = g_LevelProximityBox1MinX;
  }
  if (((value3 + -0x2000 < value4) && (value4 < value + 0x2000)) && (value2 + -0x2000 < value5)) {
    value6 = value6 + 0x2000;
LAB_0042e884:
    if (value5 < value6) {
      return 1;
    }
  }
switchD_0042e745_caseD_5:
  return 0;
}

