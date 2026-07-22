#include "tarzan_ghidra_types.hpp"

// Address: 0x00430D40
// Label: CEntities::IsTargetEntityInFront
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::IsTargetEntityInFront(int entry,int sceneObject)

{
  Entity *entity2 = (Entity *)sceneObject;
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  ushort localState9;
  ushort localState8;
  ushort localState7;
  int localState6;
  int localState5;
  int localState4;
  undefined1 localState3 [8];
  int localState2;
  undefined1 localState [32];
  
  entry2 = entity->sceneObjects;
  entry3 = entity2->sceneObjects;
  localState6 = ((EntitySceneObject *)entry3)->x - ((EntitySceneObject *)entry2)->x;
  localState5 = ((EntitySceneObject *)entry3)->y - ((EntitySceneObject *)entry2)->y;
  localState4 = ((EntitySceneObject *)entry3)->z - ((EntitySceneObject *)entry2)->z;
  localState9 = -*(short *)(entry2 + 0xa0) & 0xfff;
  localState8 = -((EntitySceneObject *)entry2)->yaw & 0xfff;
  localState7 = -((EntitySceneObject *)entry2)->pitch & 0xfff;
  BuildRotationBasisFromEulerAngles(&localState9,localState);
  TransformVectorByBasis(localState,&localState6,localState3);
  return localState2 < 0;
}

