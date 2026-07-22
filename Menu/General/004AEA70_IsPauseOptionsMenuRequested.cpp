#include "tarzan_ghidra_types.hpp"

// Address: 0x004AEA70
// Label: IsPauseOptionsMenuRequested
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void IsPauseOptionsMenuRequested(void)

{
  int result;
  uint value;
  undefined4 value2;
  uint value3;
  undefined4 value4;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined1 localState2 [4];
  undefined1 localState [32];
  
  if (g_MainWindowActivationState != 2) {
    return;
  }
  if (g_ActiveStreamedWorkHandle == 0) {
    result = IsGamePaused();
    if ((result == 0) && (result = PollVirtualKeyPressedEdge(0x1b), result != 0)) {
      result = IsMainMenuActive();
      if (result == 0) {
        value4 = 8;
      }
      else {
        value4 = 0xd;
      }
      SetOptionsMenu(value4);
    }
    result = PollVirtualKeyPressedEdge(0x70);
    if (result != 0) {
      SetOptionsMenu(1);
    }
    result = PollVirtualKeyPressedEdge(0x71);
    if (result != 0) {
      SetOptionsMenu(2);
    }
    result = PollVirtualKeyPressedEdge(0x73);
    if (result != 0) {
      SetOptionsMenu(8);
    }
    result = PollVirtualKeyPressedEdge(0x72);
    if (result != 0) {
      if ((((g_F3DebugHotkeyCooldownTicks < 0) &&
           (result = AreGameplayDebugHotkeysEnabled(), result != 0)) &&
          (result = IsControlBindingPressed(0x11), result != 0)) &&
         (result = IsControlBindingPressed(0x10), result != 0)) {
        g_F3DebugHotkeyCooldownTicks = 10;
        TogglePlayerInvulnerabilityDebugFlag();
        InitSoundAndNewGameStateFile(0xac);
        PlaySoundID(0xac,100,0,0,0x3fb33333);
      }
      else {
        SetOptionsMenu(0xc);
      }
      g_F3DebugHotkeyCooldownTicks = g_F3DebugHotkeyCooldownTicks + -1;
    }
  }
  result = PollVirtualKeyPressedEdge(0x74);
  value3 = (uint)(result != 0);
  result = PollVirtualKeyPressedEdge(0x75);
  if (result != 0) {
    value3 = 2;
  }
  result = PollVirtualKeyPressedEdge(0x77);
  if (result != 0) {
    value3 = 3;
  }
  result = PollVirtualKeyPressedEdge(0x78);
  if (result != 0) {
    value3 = 4;
  }
  result = PollVirtualKeyPressedEdge(0x79);
  if (result == 0) {
    if (value3 == 0) goto LAB_004aebfd;
  }
  else {
    value3 = 5;
  }
  value = CurrentGraphicsMode();
  if (value != value3) {
    RequestGraphicsModeChange(value3);
  }
LAB_004aebfd:
  result = PollVirtualKeyPressedEdge(0x2c);
  if ((result != 0) &&
     (result = LockCurrentFrameBuffer(0,&localState3,&localState4,&localState5,localState2), result != 0)) {
    PauseAudioLinePlayback();
    StopActiveStreamedWork();
    value4 = GetWindowWidth();
    value2 = GetWindowHeight();
    g_ScreenshotSequenceNumber = g_ScreenshotSequenceNumber + 1;
    if (999 < g_ScreenshotSequenceNumber) {
      g_ScreenshotSequenceNumber = 1;
    }
    LoadSFX(localState,s_grab_03ld_bmp_00518ea0,g_ScreenshotSequenceNumber);
    WriteScreenshotBmp(localState,localState3,localState4,value4,value2,localState5);
    UnlockCurrentFrameBuffer();
    MessageBeep(0xffffffff);
  }
  return;
}

