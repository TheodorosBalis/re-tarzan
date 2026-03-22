/* Address: 0x004ABFB0 */

void RenderWorldOrMenu(void)

{
  if (DAT_00c46054 != (code *)0x0) {
    (*DAT_00c46054)();
  }
  ProcessSoundFromEntities();
  FrameCount = FrameCount + 1;
  return;
}

