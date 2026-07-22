#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABB00
// Label: ClassifyLocalBoundsVisibility
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ClassifyLocalBoundsVisibility(undefined2 *arg1)

{
  undefined2 localState27;
  undefined2 localState25;
  undefined2 localState24;
  undefined2 localState23;
  undefined2 localState22;
  undefined2 localState21;
  undefined2 localState20;
  undefined2 localState19;
  undefined2 localState18;
  undefined2 localState17;
  undefined2 localState16;
  undefined2 localState15;
  undefined2 localState14;
  undefined2 localState13;
  undefined2 localState12;
  undefined2 localState11;
  undefined2 localState10;
  undefined2 localState8;
  undefined2 localState7;
  undefined2 localState6;
  undefined2 localState5;
  undefined2 localState4;
  undefined2 localState3;
  undefined2 localState2;
  undefined2 localState;
  undefined2 localState32;
  undefined2 localState31;
  undefined2 localState30;
  undefined2 localState29;
  undefined2 localState28;
  undefined2 localState26;
  undefined2 localState9;
  
  localState27 = *arg1;
  localState25 = arg1[1];
  localState24 = arg1[2];
  localState17 = arg1[4];
  localState20 = arg1[5];
  localState10 = arg1[3];
  localState23 = 0;
  localState19 = 0;
  localState15 = 0;
  localState11 = 0;
  localState6 = 0;
  localState2 = 0;
  localState30 = 0;
  localState9 = 0;
  localState22 = localState27;
  localState21 = localState25;
  localState18 = localState27;
  localState16 = localState24;
  localState14 = localState27;
  localState13 = localState17;
  localState12 = localState20;
  localState8 = localState25;
  localState7 = localState24;
  localState5 = localState10;
  localState4 = localState25;
  localState3 = localState20;
  localState = localState10;
  localState32 = localState17;
  localState31 = localState24;
  localState29 = localState10;
  localState28 = localState17;
  localState26 = localState20;
  ClassifyProjectedBoundsVisibility(&localState27);
  return 0;
}

