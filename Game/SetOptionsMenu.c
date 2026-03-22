/* Address: 0x0049E950 */

void SetOptionsMenu(int param_1)

{
  int iVar1;
  
  iVar1 = GetRightFunctionFromJMPtable(param_1);
  if ((iVar1 != -1) && (param_1 != DAT_007241d8)) {
    bIsPaused = 1;
    DAT_007241d4 = param_1;
    DAT_007241dc = 0;
  }
  return;
}

