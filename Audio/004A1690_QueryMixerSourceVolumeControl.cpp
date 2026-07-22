#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1690
// Label: QueryMixerSourceVolumeControl
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

MMRESULT QueryMixerSourceVolumeControl(void)

{
  uint value3;
  DWORD apiResult;
  MMRESULT messageResult;
  UINT value;
  int value2;
  int *intCursor;
  DWORD *value4;
  undefined4 *dataCursor;
  DWORD incomingStackArg;
  DWORD incomingStackArg2;
  DWORD incomingStackArg3;
  DWORD incomingStackArg4;
  DWORD incomingStackArg5;
  DWORD *incomingStackArg6;
  DWORD incomingStackArg7;
  
  messageResult = SafeCheckStackPtr();
  if (incomingStackArg6 != (DWORD *)0x0) {
    value4 = incomingStackArg6;
    for (value2 = 0x10a; value2 != 0; value2 = value2 + -1) {
      *value4 = 0;
      value4 = value4 + 1;
    }
    incomingStackArg6[2] = 0x32;
    *incomingStackArg6 = incomingStackArg7;
    value = mixerGetNumDevs();
    messageResult = 0;
    if (value != 0) {
      incomingStackArg3 = *incomingStackArg6;
      incomingStackArg = 0xa8;
      messageResult = mixerGetLineInfoA((HMIXEROBJ)0x0,(LPMIXERLINEA)&stack0x00000018,3);
      if (messageResult == 0) {
        dataCursor = (undefined4 *)registerFrame;
        for (value2 = 6; apiResult = incomingStackArg5, value2 != 0; value2 = value2 + -1) {
          *dataCursor = 0;
          dataCursor = dataCursor + 1;
        }
        messageResult = mixerGetLineControlsA((HMIXEROBJ)0x0,(LPMIXERLINECONTROLSA)&stack0x00000000,0);
        if (messageResult == 0) {
          value2 = 0;
          if (0 < (int)apiResult) {
            intCursor = (int *)&stack0x000000c8;
            do {
              if (*intCursor == 0x50030001) break;
              value2 = value2 + 1;
              intCursor = intCursor + 0x25;
            } while (value2 < (int)apiResult);
          }
          ((LPMIXERCONTROLDETAILS)(incomingStackArg6 + 4))->cbStruct = 0x18;
          incomingStackArg6[5] = *(DWORD *)(&stack0x000000c4 + value2 * 0x94);
          incomingStackArg6[6] = incomingStackArg4;
          incomingStackArg6[7] = 0;
          incomingStackArg6[8] = 4;
          incomingStackArg6[9] = (DWORD)(incomingStackArg6 + 10);
          messageResult = mixerGetControlDetailsA
                            ((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)(incomingStackArg6 + 4),0);
          if (messageResult == 0) {
            value3 = incomingStackArg6[10];
            messageResult = value3 * -0x6fc7b815;
            incomingStackArg6[1] = 1;
            incomingStackArg6[2] = value3 / 0x28f;
          }
        }
      }
    }
  }
  return messageResult;
}

