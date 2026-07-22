#include "tarzan_ghidra_types.hpp"

// Address: 0x004A15F0
// Label: InitWin9xAuxVolumeFallbackDevices
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitWin9xAuxVolumeFallbackDevices(void)

{
  UINT_PTR uDeviceID;
  MMRESULT messageResult;
  int value;
  _OSVERSIONINFOA *p_Var3;
  tagAUXCAPSA localState2;
  _OSVERSIONINFOA localState;
  
  p_Var3 = &localState;
  for (value = 0x25; value != 0; value = value + -1) {
    p_Var3->dwOSVersionInfoSize = 0;
    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;
  }
  g_Win9xAuxVolumeDeviceCount = 0;
  localState.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&localState);
  if (localState.dwPlatformId != 2) {
    uDeviceID = auxGetNumDevs();
    while ((uDeviceID = uDeviceID - 1, -1 < (int)uDeviceID && (g_Win9xAuxVolumeDeviceCount < 8))) {
      messageResult = auxGetDevCapsA(uDeviceID,&localState2,0x30);
      if ((messageResult == 0) && (((byte)localState2.wTechnology & 3) != 0)) {
        value = g_Win9xAuxVolumeDeviceCount * 8;
        (&g_Win9xAuxVolumeDeviceTable)[g_Win9xAuxVolumeDeviceCount * 2] = uDeviceID;
        auxGetVolume(uDeviceID,(LPDWORD)(&g_Win9xAuxSavedVolumeTable + value));
        g_Win9xAuxVolumeDeviceCount = g_Win9xAuxVolumeDeviceCount + 1;
      }
    }
  }
  return;
}

