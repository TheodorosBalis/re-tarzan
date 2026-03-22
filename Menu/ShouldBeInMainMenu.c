/* Address: 0x004ABC50 */

undefined4 ShouldBeInMainMenu(void)

{
  if ((DAT_00533fe0._2_1_ == '\x16') && (ptrToDecideWhichMenu == &PTR_PTR_004f1fc0)) {
    return 1;
  }
  return 0;
}

