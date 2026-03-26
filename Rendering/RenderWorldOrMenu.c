// Address: 0x004ABFB0

void RenderWorldOrMenu(void)

{
  if (_CWorld__Render != (code *)0x0) {
    (*_CWorld__Render)();
  }
  UpdateEntity3DSounds();
  FrameCount = FrameCount + 1;
  return;
}


