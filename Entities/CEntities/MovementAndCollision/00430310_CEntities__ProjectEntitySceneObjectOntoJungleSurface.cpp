#include "tarzan_ghidra_types.hpp"

// Address: 0x00430310
// Label: CEntities::ProjectEntitySceneObjectOntoJungleSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ProjectEntitySceneObjectOntoJungleSurface
              (int entry,int *sceneObject,int attachment,int flags,byte arg5)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  short shortValue;
  ushort value;
  int entry4;
  int *intCursor;
  int entry5;
  uint value2;
  int entry6;
  int entry7;
  int entry3;
  
  entry2 = entity->sceneObjects;
  if (attachment == -1) {
    entry4 = ((EntitySceneObject *)entry2)->surfacePathIndex * 4 + 4;
    entry4 = *(int *)(entry4 + g_CollisionSurfaceTable) + entry4 + g_CollisionSurfaceTable;
    if (entry4 == 0) goto LAB_00430388;
    entry4 = *(int *)(entry4 + 4);
    if (entry4 < flags) {
      flags = entry4;
    }
  }
  else {
    entry4 = attachment * 4 + 4;
    entry4 = *(int *)(entry4 + g_CollisionSurfaceTable) + entry4 + g_CollisionSurfaceTable;
    if (entry4 == 0) goto LAB_00430388;
    entry4 = *(int *)(entry4 + 4);
    if (entry4 < flags) {
      flags = entry4;
    }
  }
  if (flags < 0) {
    flags = 0;
  }
LAB_00430388:
  intCursor = (int *)GetJungleSurfaceSegment(attachment,flags);
  GetJungleSurfaceSegment(attachment,0);
  if ((intCursor[5] & 0x2000U) != 0) {
    intCursor = intCursor + -7;
  }
  entry3 = intCursor[7] - *intCursor;
  entry4 = intCursor[8] - intCursor[1];
  entry7 = intCursor[9] - intCursor[2];
  entry5 = flags - intCursor[3];
  entry6 = intCursor[10] - intCursor[3];
  *sceneObject = (entry3 * entry5) / entry6 + *intCursor;
  sceneObject[1] = (entry4 * entry5) / entry6 + intCursor[1];
  sceneObject[2] = (entry7 * entry5) / entry6 + intCursor[2];
  if (*(char *)(entry2 + 0x75) == -1) {
    entry3 = -entry3;
    entry4 = -entry4;
    entry7 = -entry7;
  }
  if ((arg5 & 4) != 0) {
    entry5 = GetAngleFromXZVector12Bit(entry3,entry7);
    entry5 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)entry2)->yaw,entry5 - 0x800U & 0xfff);
    ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw + (short)(entry5 >> 4);
  }
  if ((arg5 & 0x20) != 0) {
    shortValue = GetAngleFromXZVector12Bit(entry3,entry7);
    ((EntitySceneObject *)entry2)->yaw = shortValue - 0x800U & 0xfff;
  }
  if ((arg5 & 2) != 0) {
    entry5 = SqrtToInt(entry7 * entry7 + entry3 * entry3);
    value2 = GetAngleFromXZVector12Bit(entry4,entry5 >> 6);
    entry5 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(entry2 + 0xa0),value2 & 0xfff);
    *(short *)(entry2 + 0xa0) = *(short *)(entry2 + 0xa0) + (short)(entry5 >> 4);
  }
  if ((arg5 & 0x10) != 0) {
    entry5 = SqrtToInt(entry7 * entry7 + entry3 * entry3);
    value = GetAngleFromXZVector12Bit(entry4,entry5 >> 6);
    *(ushort *)(entry2 + 0xa0) = value & 0xfff;
  }
  if ((arg5 & 8) != 0) {
    entry5 = GetAngleFromXZVector12Bit(entry3,entry4);
    entry5 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)entry2)->pitch,-entry5 & 0xfff);
    ((EntitySceneObject *)entry2)->pitch = ((EntitySceneObject *)entry2)->pitch + (short)(entry5 >> 4);
  }
  if ((arg5 & 0x40) != 0) {
    shortValue = GetAngleFromXZVector12Bit(entry3,entry4);
    ((EntitySceneObject *)entry2)->pitch = -shortValue & 0xfff;
  }
  return flags;
}

