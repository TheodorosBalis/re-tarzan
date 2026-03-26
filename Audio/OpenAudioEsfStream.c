// Address: 0x00498980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint OpenAudioEsfStream(undefined4 param_1,int *param_2,int *param_3,uint *param_4)

{
  CloseAudioEsfStream();
  DAT_00719e50 = 0;
  g_AudioEsfStreamFlagsAndSize = 0;
  g_AudioEsfStreamHandle = OpenVirtualGameFileByPath(param_1,&DAT_005156bc);
  ReadVirtualGameFileIntoBuffer(&DAT_00719e50,8,1,g_AudioEsfStreamHandle);
  if (DAT_00719e50 != 0x8465345) {
    InternalError(s_ESF_Open___00515850);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = (-(uint)((g_AudioEsfStreamFlagsAndSize & 0x10000000) != 0) & 8) + 8;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = (-(uint)((g_AudioEsfStreamFlagsAndSize & 0x20000000) != 0) & 0x2b11) + 0x2b11;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = g_AudioEsfStreamFlagsAndSize >> 0x1e & 1;
  }
  SeekVirtualGameFileHandle(g_AudioEsfStreamHandle,8,0);
  g_AudioEsfStreamReadOffset = 0;
  _DAT_00719e60 = 0;
  g_AudioEsfStreamXorKey = 0;
  return g_AudioEsfStreamFlagsAndSize & 0xfffffff;
}


