
void WelcomeToTheJungle__UpdateTutorialCameraAnchor(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    if (g_TutorialPickupCameraMoveXTicksRemaining != 0) {
      g_TutorialPickupCameraMoveXTicksRemaining = g_TutorialPickupCameraMoveXTicksRemaining + -1;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + g_TutorialPickupCameraMoveXStep;
    }
    if (g_TutorialPickupCameraMoveYTicksRemaining != 0) {
      g_TutorialPickupCameraMoveYTicksRemaining = g_TutorialPickupCameraMoveYTicksRemaining + -1;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + g_TutorialPickupCameraMoveYStep;
    }
    if (g_TutorialPickupCameraMoveZTicksRemaining != 0) {
      g_TutorialPickupCameraMoveZTicksRemaining = g_TutorialPickupCameraMoveZTicksRemaining + -1;
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + g_TutorialPickupCameraMoveZStep;
    }
    if ((((g_PlayerActionState == 0x39) && (g_TutorialPickupCameraMoveXTicksRemaining == 0)) &&
        (g_TutorialPickupCameraMoveYTicksRemaining == 0)) &&
       (g_TutorialPickupCameraMoveZTicksRemaining == 0)) {
      g_ActiveCameraAnchorEntry = g_ActiveTutorialPickupRuntimeEntry;
      if (g_ActiveTutorialPickupRuntimeEntry == 0) {
        g_ActiveCameraAnchorEntry = g_RuntimeEntryPoolBase;
      }
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
      return;
    }
  }
  if (g_PlayerInteractionLockFlags == 0) {
    CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
    g_ActiveCameraAnchorEntry = g_RuntimeEntryPoolBase;
  }
  return;
}

