#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C660
// Label: ConsumeGraphicsModeFailure
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ConsumeGraphicsModeFailure(undefined4 *graphicsObject)

{
  int value;
  
  if (graphicsObject != (undefined4 *)0x0) {
    *graphicsObject = (&g_GraphicsModeFailureReasonByMode)[g_LastGraphicsModeFailureId];
  }
  value = g_LastGraphicsModeFailureId;
  g_LastGraphicsModeFailureId = 0;
  return value;
}

