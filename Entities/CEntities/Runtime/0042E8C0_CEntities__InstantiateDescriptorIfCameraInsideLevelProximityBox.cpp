#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E8C0
// Label: CEntities::InstantiateDescriptorIfCameraInsideLevelProximityBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InstantiateDescriptorIfCameraInsideLevelProximityBox(undefined4 descriptor)

{
  int value;
  
  value = CEntities::IsPointInsideLevelSpecificPlayerProximityBox(&g_CameraFocusX,descriptor);
  if (value != 0) {
    InstantiateEntityFromDescriptor(descriptor);
  }
  return;
}

