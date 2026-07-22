#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E450
// Label: CMenu::LevelComplete_SetEntitySceneObjectTripletBatch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_SetEntitySceneObjectTripletBatch
               (int menu,int menuItem,undefined4 selection)

{
  undefined4 *dataCursor;
  
  if (menuItem != 0) {
    dataCursor = (undefined4 *)(menu + 0xa8);
    do {
      dataCursor[3] = 1;
      *dataCursor = selection;
      dataCursor[1] = selection;
      dataCursor[2] = selection;
      dataCursor = dataCursor + 0x51;
      menuItem = menuItem + -1;
    } while (menuItem != 0);
  }
  return;
}

