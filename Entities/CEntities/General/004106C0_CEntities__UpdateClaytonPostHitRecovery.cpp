#include "tarzan_ghidra_types.hpp"

// Address: 0x004106C0
// Label: CEntities::UpdateClaytonPostHitRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateClaytonPostHitRecovery(int entry,int sceneObject)

{
  short shortValue;
  
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 2) {
    CEntities::SelectEntityAnimationAttachmentState(entry,0x11);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    *(undefined2 *)(entry + 0x48) = 0x33;
  }
  if (*(short *)(entry + 0x48) == 0x1d) {
    CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,0x3c);
    *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + -0xf;
  }
  return;
}

