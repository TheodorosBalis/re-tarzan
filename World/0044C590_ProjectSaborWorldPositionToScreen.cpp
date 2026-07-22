#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C590
// Label: ProjectSaborWorldPositionToScreen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProjectSaborWorldPositionToScreen
               (undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  localState3 = arg1;
  localState2 = arg2;
  localState = arg3;
  ProjectWorldPositionToScreen(&localState3,&g_CameraFocusX,arg4);
  return;
}

