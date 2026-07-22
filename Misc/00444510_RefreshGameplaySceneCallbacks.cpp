#include "tarzan_ghidra_types.hpp"

// Address: 0x00444510
// Label: RefreshGameplaySceneCallbacks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RefreshGameplaySceneCallbacks(void)

{
  char resultFlag;
  
  BuildLevelRuntimeDescriptors();
  CCamera::Update(1);
  resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
  g_CameraFollowFlags = (-(ushort)(resultFlag != '\0') & 0xffa0) + 0x80;
  CCamera::Update(1);
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 0x1c) != (code *)0x0) {
    (**(code **)(g_CurrentLevelRuntimeHookTable + 0x1c))();
  }
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 0x10) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00444557. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(g_CurrentLevelRuntimeHookTable + 0x10))();
    return;
  }
  return;
}

