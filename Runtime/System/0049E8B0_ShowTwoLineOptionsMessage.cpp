#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E8B0
// Label: ShowTwoLineOptionsMessage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShowTwoLineOptionsMessage(char *arg1,char *arg2)

{
  char resultFlag;
  uint value;
  uint value2;
  char *stringCursor;
  char *stringCursor2;
  
  value = 0xffffffff;
  stringCursor = arg1;
  do {
    if (value == 0) break;
    value = value - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  if (~value - 1 < 0x29) {
    value = 0xffffffff;
    stringCursor = arg2;
    do {
      if (value == 0) break;
      value = value - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    if (~value - 1 < 0x29) {
      SetOptionsMenu(0xe);
      value = 0xffffffff;
      do {
        stringCursor = arg1;
        if (value == 0) break;
        value = value - 1;
        stringCursor = arg1 + 1;
        resultFlag = *arg1;
        arg1 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      stringCursor2 = g_TwoLineMessageMenuEntryTable;
      for (value2 = value >> 2; value2 != 0; value2 = value2 - 1) {
        *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
        stringCursor = stringCursor + 4;
        stringCursor2 = stringCursor2 + 4;
      }
      for (value = value & 3; value != 0; value = value - 1) {
        *stringCursor2 = *stringCursor;
        stringCursor = stringCursor + 1;
        stringCursor2 = stringCursor2 + 1;
      }
      value = 0xffffffff;
      do {
        stringCursor = arg2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = arg2 + 1;
        resultFlag = *arg2;
        arg2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      stringCursor2 = g_TwoLineMessageMenuSecondLineEntryText;
      for (value2 = value >> 2; value2 != 0; value2 = value2 - 1) {
        *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
        stringCursor = stringCursor + 4;
        stringCursor2 = stringCursor2 + 4;
      }
      for (value = value & 3; value != 0; value = value - 1) {
        *stringCursor2 = *stringCursor;
        stringCursor = stringCursor + 1;
        stringCursor2 = stringCursor2 + 1;
      }
    }
  }
  return;
}

