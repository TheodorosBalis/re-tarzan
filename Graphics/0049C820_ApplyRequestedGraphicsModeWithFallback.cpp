#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C820
// Label: ApplyRequestedGraphicsModeWithFallback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyRequestedGraphicsModeWithFallback(void)

{
  undefined4 value2;
  int value;
  int *intCursor;
  int localState [6];
  
  intCursor = (int *)&stack0xffffffe4;
  value2 = CurrentGraphicsMode();
  if ((bLastTimeCrashed == 0) || (g_RequestedGraphicsMode == 5)) {
    if (g_RequestedGraphicsMode == 7) {
      do {
        intCursor = intCursor + 1;
        value = *intCursor;
        if (value == 0) {
          InternalError(s_GFX_HandleDisplayRequest_1__00515e04);
        }
        RequestGraphicsModeChange(value);
        value = TryApplyRequestedGraphicsMode();
      } while (value < 0);
      ConsumeGraphicsModeFailure(0);
      return;
    }
    value = TryApplyRequestedGraphicsMode();
    if (value < 0) {
      RequestGraphicsModeChange(value2);
      value = TryApplyRequestedGraphicsMode();
      if (value < 0) {
        RequestGraphicsModeChange(5);
        value = TryApplyRequestedGraphicsMode();
        if (value < 0) {
          InternalError(s_GFX_HandleDisplayRequest_2__00515de8);
        }
      }
    }
  }
  return;
}

