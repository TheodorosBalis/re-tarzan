#include "tarzan_ghidra_types.hpp"

// Address: 0x00493F70
// Label: LoadECMFilesAndInit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadECMFilesAndInit(void)

{
  int value;
  undefined1 *dataCursor;
  MCIERROR messageResult;
  undefined1 scratchBuffer6;
  undefined1 scratchBuffer10;
  undefined1 scratchBuffer5;
  undefined1 scratchBuffer4 [8];
  undefined4 scratchBuffer3;
  undefined4 scratchBuffer2;
  MCIDEVICEID scratchBuffer;
  undefined4 scratchBuffer9;
  undefined1 *scratchBuffer8;
  undefined4 scratchBuffer7;
  
  if (g_BackgroundMusicMciDeviceOpen != 0) {
LAB_00494041:
    scratchBuffer3 = 5;
    mciSendCommandA(g_BackgroundMusicMciDeviceId,0x814,0x100,(DWORD_PTR)scratchBuffer4);
    return 1;
  }
  scratchBuffer = 0;
  scratchBuffer2 = 0;
  scratchBuffer9 = 0x204;
  scratchBuffer8 = (undefined1 *)0x0;
  scratchBuffer7 = 0;
  value = LoadECMfile(s_stranger_ecm_005156dc);
  if (value != 0) {
    value = LoadECMfile(s_disney_ecm_005156d0);
    if (value != 0) {
      dataCursor = (undefined1 *)LoadECMfile(s_EurocomEcmFileName);
      if (dataCursor != (undefined1 *)0x0) {
        scratchBuffer5 = g_EcmInitStatusByte;
        scratchBuffer8 = &scratchBuffer6;
        _local_28 = CONCAT11((char)((ushort)s_EcmFallbackDrivePrefix >> 8),*dataCursor);
        messageResult = mciSendCommandA(0,0x803,0x3302,(DWORD_PTR)&scratchBuffer2);
        g_BackgroundMusicMciDeviceOpen = (uint)(messageResult == 0);
        g_BackgroundMusicMciDeviceId = scratchBuffer;
        goto LAB_00494041;
      }
    }
  }
  return 0;
}

