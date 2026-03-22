/* Address: 0x0049D840 */

void DoReconfigurationStuffOnWindow(void)

{
  ZeroGlobal723738();
  FUN_0049d070();
  FUN_0049d520(0);
  if (DAT_00723740 != (HMODULE)0x0) {
    if ((DAT_0072373c != 0) && (DAT_0072378c != (code *)0x0)) {
      (*DAT_0072378c)();
    }
    FreeLibrary(DAT_00723740);
    DAT_00723740 = (HMODULE)0x0;
  }
  ReconfigureMainWindowAndMouseIfNeeded(DAT_0072372c);
  DAT_0072373c = 0;
  DAT_00723724 = 0;
  return;
}

