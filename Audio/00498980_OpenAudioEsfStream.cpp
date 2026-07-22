#include "tarzan_ghidra_types.hpp"

// Address: 0x00498980
// Label: OpenAudioEsfStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint OpenAudioEsfStream(undefined4 soundId,int *position,int *outParams,uint *flags)

{
  CloseAudioEsfStream();
  g_AudioEsfStreamState_Field0000 = 0;
  g_AudioEsfStreamFlagsAndSize = 0;
  g_AudioEsfStreamHandle = OpenVirtualGameFileByPath(soundId,&s_FileModeReadBinary);
  ReadVirtualGameFileIntoBuffer(&g_AudioEsfStreamState_Field0000,8,1,g_AudioEsfStreamHandle);
  if (g_AudioEsfStreamState_Field0000 != 0x8465345) {
    InternalError(s_ESF_Open___00515850);
  }
  if (position != (int *)0x0) {
    *position = (-(uint)((g_AudioEsfStreamFlagsAndSize & 0x10000000) != 0) & 8) + 8;
  }
  if (outParams != (int *)0x0) {
    *outParams = (-(uint)((g_AudioEsfStreamFlagsAndSize & 0x20000000) != 0) & 0x2b11) + 0x2b11;
  }
  if (flags != (uint *)0x0) {
    *flags = g_AudioEsfStreamFlagsAndSize >> 0x1e & 1;
  }
  SeekVirtualGameFileHandle(g_AudioEsfStreamHandle,8,0);
  g_AudioEsfStreamReadOffset = 0;
  _g_AudioEsfStreamState_Field0010 = 0;
  g_AudioEsfStreamXorKey = 0;
  return g_AudioEsfStreamFlagsAndSize & 0xfffffff;
}

