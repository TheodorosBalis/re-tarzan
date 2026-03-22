/* Address: 0x0049A450 */

void FreeDynamicMem1(void)

{
  if (DAT_007222cc != 0) {
    FileLoadedEpilogueWithCS(DAT_007222cc);
  }
  DAT_007222cc = 0;
  DAT_007222d8 = 0;
  return;
}

