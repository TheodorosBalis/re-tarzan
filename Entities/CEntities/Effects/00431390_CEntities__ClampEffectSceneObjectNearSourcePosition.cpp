#include "tarzan_ghidra_types.hpp"

// Address: 0x00431390
// Label: CEntities::ClampEffectSceneObjectNearSourcePosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ClampEffectSceneObjectNearSourcePosition(int entry,int sceneObject)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int entry2;
  int entry3;
  int entry4;
  int entry5;
  
  intCursor = *(int **)(entry + 0x34);
  entry2 = entity->sceneObjects;
  entry5 = -sceneObject;
  entry3 = ((EntitySceneObject *)entry2)->x - *intCursor;
  if (entry3 < 0) {
    if (entry3 < entry5) {
      entry4 = -sceneObject;
      goto LAB_004313bc;
    }
  }
  else {
    entry4 = sceneObject;
    if (sceneObject < entry3) {
LAB_004313bc:
      ((EntitySceneObject *)entry2)->x = *intCursor + entry4;
    }
  }
  entry3 = ((EntitySceneObject *)entry2)->y - intCursor[1];
  if (entry3 < 0) {
    if (entry5 <= entry3) goto LAB_004313da;
    entry4 = -sceneObject;
  }
  else {
    entry4 = sceneObject;
    if (entry3 <= sceneObject) goto LAB_004313da;
  }
  ((EntitySceneObject *)entry2)->y = intCursor[1] + entry4;
LAB_004313da:
  entry3 = intCursor[2];
  entry4 = ((EntitySceneObject *)entry2)->z - entry3;
  if (entry4 < 0) {
    if (entry4 < entry5) {
      ((EntitySceneObject *)entry2)->z = entry3 - sceneObject;
    }
  }
  else if (sceneObject < entry4) {
    ((EntitySceneObject *)entry2)->z = entry3 + sceneObject;
    return;
  }
  return;
}

