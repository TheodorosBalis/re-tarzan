#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2050
// Label: SetTarzanPagePermissions
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetTarzanPagePermissions(void)

{
  char resultFlag;
  int value2;
  UINT value;
  HMODULE value7;
  int value3;
  uint value5;
  uint value6;
  int value4;
  char *stringCursor2;
  char *stringCursor;
  CHAR localState2;
  char localState [7];
  
  if (g_TarzanPagePermissionScratch == 0) {
    g_TarzanPagePermissionScratch = 1;
    GetModuleFileNameA((HMODULE)0x0,&localState2,2);
    value5 = 0xffffffff;
    stringCursor2 = &DAT_005175ec;
    do {
      stringCursor = stringCursor2;
      if (value5 == 0) break;
      value5 = value5 - 1;
      stringCursor = stringCursor2 + 1;
      resultFlag = *stringCursor2;
      stringCursor2 = stringCursor;
    } while (resultFlag != '\0');
    value5 = ~value5;
    stringCursor2 = stringCursor + -value5;
    stringCursor = localState;
    for (value6 = value5 >> 2; value6 != 0; value6 = value6 - 1) {
      *(undefined4 *)stringCursor = *(undefined4 *)stringCursor2;
      stringCursor2 = stringCursor2 + 4;
      stringCursor = stringCursor + 4;
    }
    for (value5 = value5 & 3; value5 != 0; value5 = value5 - 1) {
      *stringCursor = *stringCursor2;
      stringCursor2 = stringCursor2 + 1;
      stringCursor = stringCursor + 1;
    }
    value = GetDriveTypeA(&localState2);
    if ((value == 3) && (value7 = GetModuleHandleA((LPCSTR)0x0), ((uint)value7 & 0x80000000) == 0))
    {
      value2 = value7[0xf].unused;
      SetPageProtectionsForTarzan(value7,*(undefined4 *)((int)&value7[0x15].unused + value2));
      value5 = 0;
      if (*(short *)((int)&value7[1].unused + value2 + 2) != 0) {
        value4 = 0;
        do {
          value3 = (uint)*(ushort *)((int)&value7[5].unused + value2) + value4;
          SetPageProtectionsForTarzan
                    ((int)&value7->unused + *(int *)((int)&value7[9].unused + value2 + value3),
                     *(undefined4 *)((int)&value7[8].unused + value2 + value3));
          value5 = value5 + 1;
          value4 = value4 + 0x28;
        } while (value5 < *(ushort *)((int)&value7[1].unused + value2 + 2));
      }
    }
  }
  return;
}

