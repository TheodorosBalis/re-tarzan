#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E0F0
// Label: CaptureKInputsInBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CaptureKInputsInBuffer(void)

{
  int value;
  int value2;
  undefined4 *bufferCursor;
  
  bufferCursor = &g_JoystickPreviousButtonMaskByIndex;
  for (value = 0x10; value != 0; value = value + -1) {
    *bufferCursor = 0xffffffff;
    bufferCursor = bufferCursor + 1;
  }
  value2 = 0;
  bufferCursor = &InputBuffer;
  for (value = 0x100; value != 0; value = value + -1) {
    *bufferCursor = 0xffffffff;
    bufferCursor = bufferCursor + 1;
  }
  do {
    GetUserInputAndConvert(value2);
    value2 = value2 + 1;
  } while (value2 < 0x100);
  return;
}

