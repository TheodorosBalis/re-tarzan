#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AFE0
// Label: DrawHardwareInfoOverlayAtStartup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DrawHardwareInfoOverlayAtStartup(void)

{
  char resultFlag;
  int value;
  undefined4 value3;
  int value2;
  uint value4;
  uint value5;
  char *stringCursor;
  char *stringCursor2;
  
  value = GetGraphicsModeRevision();
  if (value != g_DrawHardwareInfoOverlayAtStartup_Global_00515C50) {
    g_HardwareInfoOverlayFramesRemaining = 0x78;
    g_DrawHardwareInfoOverlayAtStartup_Global_00515C50 = value;
  }
  g_HardwareInfoOverlayFramesRemaining = g_HardwareInfoOverlayFramesRemaining + -1;
  if (g_HardwareInfoOverlayFramesRemaining < 0) {
    return;
  }
  value3 = CurrentGraphicsMode();
  switch(value3) {
  case 1:
    stringCursor = s_GLIDE_3D_CARD_00515cec;
    break;
  case 2:
    value4 = 0xffffffff;
    stringCursor = s_DIRECT3D_CARD_00515cdc;
    do {
      stringCursor2 = stringCursor;
      if (value4 == 0) break;
      value4 = value4 - 1;
      stringCursor2 = stringCursor + 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor2;
    } while (resultFlag != '\0');
    value4 = ~value4;
    stringCursor = stringCursor2 + -value4;
    stringCursor2 = (char *)&g_GraphicsTextScratchBuffer;
    for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
      *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
      stringCursor = stringCursor + 4;
      stringCursor2 = stringCursor2 + 4;
    }
    goto LAB_0049b097;
  case 3:
    stringCursor = s_SOFTWARE_LOW_RES_00515cc8;
    break;
  case 4:
    value4 = 0xffffffff;
    stringCursor = s_SOFTWARE_HIGH_RES_00515cb4;
    do {
      stringCursor2 = stringCursor;
      if (value4 == 0) break;
      value4 = value4 - 1;
      stringCursor2 = stringCursor + 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor2;
    } while (resultFlag != '\0');
    value4 = ~value4;
    stringCursor = stringCursor2 + -value4;
    stringCursor2 = (char *)&g_GraphicsTextScratchBuffer;
    for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
      *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
      stringCursor = stringCursor + 4;
      stringCursor2 = stringCursor2 + 4;
    }
    goto LAB_0049b097;
  case 5:
    stringCursor = s_SOFTWARE_WINDOW_00515ca4;
    break;
  default:
    goto switchD_0049b01e_default;
  }
  value4 = 0xffffffff;
  do {
    stringCursor2 = stringCursor;
    if (value4 == 0) break;
    value4 = value4 - 1;
    stringCursor2 = stringCursor + 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor2;
  } while (resultFlag != '\0');
  value4 = ~value4;
  stringCursor = stringCursor2 + -value4;
  stringCursor2 = (char *)&g_GraphicsTextScratchBuffer;
  for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
LAB_0049b097:
  for (value4 = value4 & 3; value4 != 0; value4 = value4 - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  value = Return6();
  value2 = GetWindowHeight(&g_GraphicsTextScratchBuffer);
  value = Return6_2(value2 - value);
  value4 = 0xffffffff;
  stringCursor = (char *)&g_GraphicsTextScratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  value2 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(value2 - value * (~value4 - 1));
  value = IsDirectSoundAvailable();
  if (value == 0) {
    stringCursor = s_NO_SOUND_CARD_FOUND_00515c6c;
  }
  else {
    value = IsEaxSoundAvailable();
    stringCursor = s_EAX_SOUND_CARD_00515c94;
    if (value == 0) {
      stringCursor = s_DIRECTSOUND_CARD_00515c80;
    }
  }
  LoadSFX(&g_GraphicsTextScratchBuffer,&DAT_00515c68,stringCursor);
  value = Return6(&g_GraphicsTextScratchBuffer);
  value2 = GetWindowHeight();
  value = Return6_2(value2 + value * -2);
  value4 = 0xffffffff;
  stringCursor = (char *)&g_GraphicsTextScratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  value2 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(value2 - value * (~value4 - 1));
  stringCursor = s_MMX_CPU_00515c60;
  if (g_MmxCpuSupported == 0) {
    stringCursor = &DAT_00515c58;
  }
  value4 = 0xffffffff;
  do {
    stringCursor2 = stringCursor;
    if (value4 == 0) break;
    value4 = value4 - 1;
    stringCursor2 = stringCursor + 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor2;
  } while (resultFlag != '\0');
  value4 = ~value4;
  stringCursor = stringCursor2 + -value4;
  stringCursor2 = (char *)&g_GraphicsTextScratchBuffer;
  for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
  for (value4 = value4 & 3; value4 != 0; value4 = value4 - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  value = Return6(&g_GraphicsTextScratchBuffer);
  value2 = GetWindowHeight();
  value = Return6_2(value2 + value * -3);
  value4 = 0xffffffff;
  stringCursor = (char *)&g_GraphicsTextScratchBuffer;
  do {
    if (value4 == 0) break;
    value4 = value4 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  value2 = GetWindowWidth();
  DrawGraphicsTextInMem_stub(value2 - value * (~value4 - 1));
switchD_0049b01e_default:
  return;
}

