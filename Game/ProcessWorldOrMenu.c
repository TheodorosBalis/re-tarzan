/* Address: 0x004ABF80 */

void ProcessWorldOrMenu(void)

{
  ManageFades();
  RequestModels();
  ProcessSoundFromEntities();
  GetInputs();
  if (DAT_00c46050 != (code *)0x0) {
    (*DAT_00c46050)();
  }
  FUN_004abf70();
  FUN_00439360(&DAT_0051d280);
  return;
}

