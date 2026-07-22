#include "tarzan_ghidra_types.hpp"

// Address: 0x0042EFF0
// Label: CEntities::ProjectPointToXZSegmentAndDistanceSquared
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ProjectPointToXZSegmentAndDistanceSquared
              (int *entry,int *sceneObject,int *attachment,int *flags)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value2 = *sceneObject - *entry;
  value3 = sceneObject[2] - entry[2];
  value = value3 >> 2;
  value4 = value2 >> 2;
  value5 = value4 * value4 + value * value >> 0xc;
  if ((value5 != 0) &&
     (value5 = ((*attachment - *entry >> 2) * value4 + (attachment[2] - entry[2] >> 2) * value) / value5,
     0 < value5)) {
    if (0xfff < value5) {
      *flags = *sceneObject;
      flags[1] = sceneObject[1];
      value = sceneObject[2];
      flags[2] = value;
      value = value - attachment[2];
      return value * value + (*flags - *attachment) * (*flags - *attachment);
    }
    *flags = (value2 * value5 >> 0xc) + *entry;
    flags[1] = entry[1];
    value = (value3 * value5 >> 0xc) + entry[2];
    flags[2] = value;
    value = value - attachment[2];
    return value * value + (*flags - *attachment) * (*flags - *attachment);
  }
  *flags = *entry;
  flags[1] = entry[1];
  value = entry[2];
  flags[2] = value;
  value = value - attachment[2];
  return value * value + (*flags - *attachment) * (*flags - *attachment);
}

