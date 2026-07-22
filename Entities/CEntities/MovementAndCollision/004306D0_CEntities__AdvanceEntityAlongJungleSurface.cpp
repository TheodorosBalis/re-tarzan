#include "tarzan_ghidra_types.hpp"

// Address: 0x004306D0
// Label: CEntities::AdvanceEntityAlongJungleSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::AdvanceEntityAlongJungleSurface(int entry,int sceneObject,int attachment,undefined4 flags)

{
  if (*(char *)(sceneObject + 0x75) != '\0') {
    attachment = -attachment;
  }
  attachment = *(int *)(entry + 0x50) + attachment;
  *(int *)(entry + 0x50) = attachment;
  CEntities::ProjectEntitySceneObjectOntoJungleSurface
            (entry,sceneObject + 0x14,*(undefined4 *)(sceneObject + 0x110),attachment,flags,0);
  return 0;
}

