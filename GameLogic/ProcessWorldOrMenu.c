// Address: 0x004ABF80

void ProcessWorldOrMenu(void)

{
  ManageFades();
  ProcessModelLoadQueue();
  UpdateEntity3DSounds();
  GetInputs();
  if (DAT_00c46050 != (code *)0x0) {
    (*DAT_00c46050)();
  }
  DoNothing5();
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  return;
}


