#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C980
// Label: SetSaborAnimationStateAndAdvance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetSaborAnimationStateAndAdvance(undefined4 arg1,undefined4 arg2)

{
  SetSaborAnimationState(arg1,arg2);
  CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  return;
}

