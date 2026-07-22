#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C0F0
// Label: DoOrientedEntitySceneObjectAttachmentBoxesOverlap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint DoOrientedEntitySceneObjectAttachmentBoxesOverlap
               (int arg1,short *arg2,int arg3,short *arg4)

{
  int entry;
  int entry2;
  int entry3;
  int entry4;
  int *intCursor;
  int *intCursor2;
  short localState15;
  short localState14;
  short localState13;
  short localState12;
  short localState11;
  short localState10;
  short localState9;
  short localState8;
  short localState7;
  short localState6;
  short localState5;
  short localState4;
  int localState3;
  int localState2;
  int localState;
  uint localState26;
  int localState25;
  int localState24;
  int *localState23;
  int localState22;
  short localState21;
  short localState20;
  short localState19;
  undefined1 localState18 [32];
  int localState17 [24];
  int localState16 [24];
  
  intCursor = (int *)0x0;
  localState23 = (int *)0x0;
  localState25 = 0;
  localState24 = 0;
  localState22 = 0;
  do {
    if (localState22 == 0) {
      localState23 = localState17;
      localState25 = arg1;
      localState11 = arg2[1];
      localState24 = arg3;
      localState12 = *arg2;
      localState10 = arg2[2];
      localState15 = arg2[3];
      localState14 = arg2[4];
      localState13 = arg2[5];
      localState9 = *arg4;
      localState8 = arg4[1];
      localState7 = arg4[2];
      localState6 = arg4[3];
      localState5 = arg4[4];
      localState4 = arg4[5];
      intCursor2 = localState17;
    }
    else {
      intCursor2 = intCursor;
      if (localState22 == 1) {
        localState23 = localState16;
        localState25 = arg3;
        localState12 = *arg4;
        localState24 = arg1;
        localState11 = arg4[1];
        localState10 = arg4[2];
        localState15 = arg4[3];
        localState14 = arg4[4];
        localState13 = arg4[5];
        localState9 = *arg2;
        localState8 = arg2[1];
        localState7 = arg2[2];
        localState6 = arg2[3];
        localState5 = arg2[4];
        localState4 = arg2[5];
        intCursor2 = localState16;
      }
    }
    intCursor = localState23;
    entry = (int)localState12;
    entry2 = (int)localState11;
    entry3 = (int)localState10;
    *intCursor2 = entry;
    intCursor2[1] = entry2;
    intCursor2[2] = entry3;
    intCursor2[5] = (int)localState13;
    intCursor2[3] = entry;
    entry4 = (int)localState14;
    intCursor2[4] = entry2;
    intCursor2[6] = entry;
    intCursor2[7] = entry4;
    intCursor2[8] = entry3;
    intCursor2[9] = entry;
    intCursor2[10] = entry4;
    localState26 = (uint)localState13;
    intCursor2[0xb] = localState26;
    entry = (int)localState15;
    intCursor2[0xc] = entry;
    intCursor2[0xd] = entry2;
    intCursor2[0xe] = entry3;
    intCursor2[0x10] = entry2;
    intCursor2[0xf] = entry;
    intCursor2[0x11] = localState26;
    intCursor2[0x12] = entry;
    intCursor2[0x13] = entry4;
    intCursor2[0x14] = entry3;
    intCursor2[0x15] = entry;
    intCursor2[0x16] = entry4;
    intCursor2[0x17] = localState26;
    if (*(short *)(localState24 + 0xa6) != 3) {
      localState21 = -*(short *)(localState24 + 0xa0);
      localState20 = -*(short *)(localState24 + 0xa2);
      localState19 = -*(short *)(localState24 + 0xa4);
      BuildRotationBasisFromEulerAngles(&localState21,localState18);
    }
    localState26 = 0;
    do {
      entry = localState25;
      localState3 = *intCursor;
      localState2 = intCursor[1];
      localState = intCursor[2];
      if (*(short *)(localState25 + 0xa6) != 3) {
        TransformVectorByBasis(localState25 + 0xb8,&localState3,&localState3);
      }
      localState3 = (localState3 + *(int *)(entry + 0x14)) - *(int *)(localState24 + 0x14);
      localState2 = (localState2 + *(int *)(entry + 0x18)) - *(int *)(localState24 + 0x18);
      localState = (localState + *(int *)(entry + 0x1c)) - *(int *)(localState24 + 0x1c);
      if (*(short *)(localState24 + 0xa6) != 3) {
        TransformVectorByBasis(localState18,&localState3,&localState3);
      }
      if ((((localState9 <= localState3) && (localState3 <= localState6)) && (localState5 <= localState2)) &&
         (((localState2 <= localState8 && (localState7 <= localState)) && (localState <= localState4)))) {
        return CONCAT31((int3)(char)((ushort)localState4 >> 8),1);
      }
      intCursor = intCursor + 3;
      localState26 = localState26 + 1;
    } while ((int)localState26 < 8);
    localState22 = localState22 + 1;
    if (1 < localState22) {
      return localState26 & 0xffffff00;
    }
  } while( true );
}

