// Address: 0x004ABF80

void ProcessWorldOrMenu(void)

{
  ManageFades();
  ProcessModelLoadQueue();
  UpdateEntity3DSounds();
  GetInputs();
  if (g_ActiveWorldOrMenuProcessFn != (code *)0x0) {
    (*g_ActiveWorldOrMenuProcessFn)();
  }
  DoNothing5();
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  return;
}


