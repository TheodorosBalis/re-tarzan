#include "tarzan_ghidra_types.hpp"

// Address: 0x00453C60
// Label: PlayAudioById
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * PlayAudioById(uint soundId,int *position,undefined4 *outParams)

{
  undefined4 soundMask;
  int value;
  undefined4 *bufferCursor;
  
  if ((soundId & 0x8000) != 0) {
    PlayStreamingSoundByIndex();
    return (undefined4 *)0x0;
  }
  value = Return1(soundId);
  if (value == 0) {
    return (undefined4 *)0x0;
  }
  if ((position == (int *)0x0) && (outParams == (undefined4 *)0x0)) {
    InitEntitySoundSlotPlayback(soundId,0,0);
    return (undefined4 *)0x0;
  }
  bufferCursor = (undefined4 *)AcquireEntitySoundSlot();
  if (bufferCursor != (undefined4 *)0x0) {
    bufferCursor[5] = 0;
    bufferCursor[6] = g_ActiveEntitySoundSlotList;
    g_ActiveEntitySoundSlotList = bufferCursor;
    *(short *)(bufferCursor + 8) = (short)soundId;
    if (position == (int *)0x0) {
      if (outParams != (undefined4 *)0x0) {
        bufferCursor[1] = *outParams;
        bufferCursor[2] = outParams[1];
        soundMask = outParams[2];
        bufferCursor[4] = bufferCursor + 1;
        bufferCursor[3] = soundMask;
      }
    }
    else {
      if (*position != 0) {
        DetachEntitySoundHandle(position);
      }
      *position = (int)bufferCursor;
      *bufferCursor = position;
      bufferCursor[4] = outParams;
    }
    InitEntitySoundSlotPlayback(soundId,(int)bufferCursor + 0x22,outParams);
  }
  return bufferCursor;
}

