#include "tarzan_ghidra_types.hpp"

// Address: 0x00498A70
// Label: ReadAudioEsfStreamBytes
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReadAudioEsfStreamBytes(undefined4 *soundId,uint position)

{
  undefined1 *bufferCursor;
  undefined1 soundMask;
  int value;
  uint soundMask2;
  undefined4 *bufferCursor2;
  int value2;
  
  if (((g_AudioEsfStreamHandle != 0) && (soundId != (undefined4 *)0x0)) && (0 < (int)position)) {
    if ((int)(g_AudioEsfStreamFlagsAndSize & 0xfffffff) <
        (int)(g_AudioEsfStreamReadOffset + position)) {
      soundMask = (undefined1)((~g_AudioEsfStreamFlagsAndSize >> 0x1c & 1) << 7);
      bufferCursor2 = soundId;
      for (soundMask2 = position >> 2; soundMask2 != 0; soundMask2 = soundMask2 - 1) {
        *bufferCursor2 = CONCAT22(CONCAT11(soundMask,soundMask),CONCAT11(soundMask,soundMask));
        bufferCursor2 = bufferCursor2 + 1;
      }
      for (position = position & 3; position != 0; position = position - 1) {
        *(undefined1 *)bufferCursor2 = soundMask;
        bufferCursor2 = (undefined4 *)((int)bufferCursor2 + 1);
      }
      position = (g_AudioEsfStreamFlagsAndSize & 0xfffffff) - g_AudioEsfStreamReadOffset;
    }
    g_AudioEsfStreamReadOffset = g_AudioEsfStreamReadOffset + position;
    if ((g_AudioEsfStreamFlagsAndSize & 0x10000000) == 0) {
      ReadVirtualGameFileIntoBuffer(soundId,position,1,g_AudioEsfStreamHandle);
      value = 0;
      if (0 < (int)position) {
        do {
          *(byte *)(value + (int)soundId) =
               *(byte *)(value + (int)soundId) ^ (byte)g_AudioEsfStreamXorKey;
          g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
          value = value + 1;
        } while (value < (int)position);
      }
    }
    else {
      if ((g_AudioEsfStreamFlagsAndSize & 0x80000000) != 0) {
        value2 = (int)(position + ((int)position >> 0x1f & 3U)) >> 2;
        bufferCursor = (undefined1 *)((int)soundId + position + (-1 - value2));
        ReadVirtualGameFileIntoBuffer(bufferCursor,value2,1,g_AudioEsfStreamHandle);
        value = 0;
        if (0 < value2) {
          do {
            bufferCursor[value] = bufferCursor[value] ^ (byte)g_AudioEsfStreamXorKey;
            g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
            value = value + 1;
          } while (value < value2);
        }
        DecodeImaAdpcmNibblesToPcm(bufferCursor,soundId,position,&g_AudioEsfStreamState_Field0010);
        return;
      }
      ReadVirtualGameFileIntoBuffer(soundId,position,1,g_AudioEsfStreamHandle);
      value = 0;
      if (0 < (int)position) {
        do {
          *(byte *)(value + (int)soundId) =
               *(byte *)(value + (int)soundId) ^ (byte)g_AudioEsfStreamXorKey;
          g_AudioEsfStreamXorKey = g_AudioEsfStreamXorKey + 1;
          value = value + 1;
        } while (value < (int)position);
        return;
      }
    }
  }
  return;
}

