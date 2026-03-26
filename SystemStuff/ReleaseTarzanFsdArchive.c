// Address: 0x0049A450

void ReleaseTarzanFsdArchive(void)

{
  if (g_TarzanFsdArchiveHandle != 0) {
    FileLoadedEpilogueWithCS(g_TarzanFsdArchiveHandle);
  }
  g_TarzanFsdArchiveHandle = 0;
  g_TarzanFsdInitAttempted = 0;
  return;
}


