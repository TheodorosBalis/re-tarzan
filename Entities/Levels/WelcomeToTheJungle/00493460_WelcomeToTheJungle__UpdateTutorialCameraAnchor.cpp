#include "tarzan_ghidra_types.hpp"

// Address: 0x00493460
// Label: WelcomeToTheJungle::UpdateTutorialCameraAnchor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::UpdateTutorialCameraAnchor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (g_TutorialPickupCameraMoveXTicksRemaining != 0) {
      g_TutorialPickupCameraMoveXTicksRemaining = g_TutorialPickupCameraMoveXTicksRemaining + -1;
      ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + g_TutorialPickupCameraMoveXStep;
    }
    if (g_TutorialPickupCameraMoveYTicksRemaining != 0) {
      g_TutorialPickupCameraMoveYTicksRemaining = g_TutorialPickupCameraMoveYTicksRemaining + -1;
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + g_TutorialPickupCameraMoveYStep;
    }
    if (g_TutorialPickupCameraMoveZTicksRemaining != 0) {
      g_TutorialPickupCameraMoveZTicksRemaining = g_TutorialPickupCameraMoveZTicksRemaining + -1;
      ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + g_TutorialPickupCameraMoveZStep;
    }
    if ((((g_PlayerActionState == 0x39) && (g_TutorialPickupCameraMoveXTicksRemaining == 0)) &&
        (g_TutorialPickupCameraMoveYTicksRemaining == 0)) &&
       (g_TutorialPickupCameraMoveZTicksRemaining == 0)) {
      g_ActiveCameraAnchorEntry = g_ActiveTutorialPickupEntity;
      if (g_ActiveTutorialPickupEntity == 0) {
        g_ActiveCameraAnchorEntry = g_EntityPoolBase;
      }
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
  }
  if (g_PlayerPickupInteractionFlags == 0) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    g_ActiveCameraAnchorEntry = g_EntityPoolBase;
  }
  return;
}

