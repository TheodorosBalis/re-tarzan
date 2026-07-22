#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CDC0
// Label: InitializeGraphicsModeManager
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 InitializeGraphicsModeManager(int graphicsObject)

{
  int value;
  undefined4 *dataCursor;
  
  if (g_IsGraphicsModeManagerInitialized != 0) {
    return 1;
  }
  if (graphicsObject == 0) {
    return 0;
  }
  dataCursor = &g_GraphicsModeFailureReasonByMode;
  for (value = 6; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  g_GraphicsWindowHandle = graphicsObject;
  g_LastGraphicsModeFailureId = 0;
  g_RequestedGraphicsModePending = 0;
  value = InitBackBufferDIBSection(graphicsObject);
  if (value == 0) {
    ForceSoftwareGraphicsMode();
    InternalError(s_Gfx_Init___00515e20);
    g_IsGraphicsModeManagerInitialized = 0;
    return 0;
  }
  g_CurrentGraphicsMode = 0;
  g_GraphicsModeChangeSerial = 1;
  RequestGraphicsModeChange(5);
  ApplyRequestedGraphicsModeWithFallback();
  BeginFrameBufferWriteForCurrentGraphicsMode(0,0,0);
  ConfirmGraphicsInitialized();
  ShowFrameOnScreen();
  g_IsGraphicsModeManagerInitialized = 1;
  return 1;
}

