#include "tarzan_ghidra_types.hpp"

// Address: 0x0049F200
// Label: SetOptionsMenuEntryValueText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetOptionsMenuEntryValueText(int *menu,char *menuItem)

{
  char *stringCursor;
  int menuIndex;
  int menuIndex2;
  char *stringCursor2;
  char resultFlag;
  
  if (menuItem != (char *)0x0) {
    menuIndex2 = 0;
    stringCursor = (char *)*menu;
    resultFlag = *stringCursor;
    while (resultFlag != '\0') {
      if (resultFlag == ':') {
        menuIndex2 = menuIndex2 + 2;
        goto LAB_0049f22e;
      }
      menuIndex = menuIndex2 + 1;
      menuIndex2 = menuIndex2 + 1;
      resultFlag = stringCursor[menuIndex];
    }
    menuIndex2 = 0;
LAB_0049f22e:
    stringCursor2 = stringCursor + menuIndex2;
    resultFlag = stringCursor[menuIndex2];
    while (resultFlag != '\0') {
      resultFlag = *menuItem;
      if (resultFlag == '\0') {
        resultFlag = ' ';
      }
      else {
        menuItem = menuItem + 1;
      }
      *stringCursor2 = resultFlag;
      menuIndex2 = menuIndex2 + 1;
      stringCursor2 = (char *)(*menu + menuIndex2);
      resultFlag = *stringCursor2;
    }
  }
  return;
}

