#include "tarzan_ghidra_types.hpp"

// Address: 0x00444470
// Label: EnterGameplayRuntimeState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnterGameplayRuntimeState(void)

{
  char resultFlag;
  
  _g_RuntimeProcessingPhase = 0;
  g_EntityTypeCallbackTable = &PTR_CEntities__NoOpEntityCallback_00510330;
  g_EntityTypeCount = 0x1e8;
  InitiateFade(0x11,0x80);
  _g_DeathRespawnFadeState = 9;
  g_AllSketchPiecesNewlyCompleted = 0;
  CCamera::Update(1);
  resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
  g_CameraFollowFlags = (-(ushort)(resultFlag != '\0') & 0xffa0) + 0x80;
  CCamera::Update(1);
  CreateLevelStartupEntities();
  return;
}

