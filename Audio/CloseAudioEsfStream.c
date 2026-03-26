// Address: 0x00498C10

void CloseAudioEsfStream(void)

{
  if (g_AudioEsfStreamHandle != 0) {
    CloseVirtualGameFileHandle(g_AudioEsfStreamHandle);
  }
  g_AudioEsfStreamHandle = 0;
  return;
}


