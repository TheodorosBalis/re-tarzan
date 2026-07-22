#include "tarzan_ghidra_types.hpp"

// Address: 0x00456C20
// Label: Stampede::UpdateElephants
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateElephants(int *entry)

{
  int value;
  int *intCursor2;
  char resultFlag;
  int value2;
  int value3;
  int value4;
  undefined4 value7;
  int value5;
  int *intCursor3;
  int *intCursor;
  uint value6;
  int localState;
  undefined4 localState3;
  undefined4 localState2;
  
  intCursor2 = entry;
  AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
  value2 = CEntities::FindEntityAttachmentByFlags(intCursor2,0x40000000);
  if (value2 != 0) {
    value6 = -*(int *)(value2 + 0x1c) - 0x800U & 0xfff;
    value3 = CEntities::FindEntityAttachmentByFlags(intCursor2,0x10000000);
    if (value3 != 0) {
      value4 = intCursor2[0xe];
      value = *(int *)(value3 + 0x1c);
      value5 = *(int *)(value3 + 0x14);
      *(undefined4 *)(value5 + 0x14) = *(undefined4 *)(value4 + 0x14);
      *(undefined4 *)(value5 + 0x18) = *(undefined4 *)(value4 + 0x18);
      *(undefined4 *)(value5 + 0x1c) = *(undefined4 *)(value4 + 0x1c);
      *(undefined2 *)(*(int *)(value3 + 0x14) + 0xc) = *(undefined2 *)(intCursor2[0xe] + 0xc);
      entry = *(int **)(value3 + 0x14);
      value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)((int)entry + 0xa2),value6);
      *(short *)((int)entry + 0xa2) = *(short *)((int)entry + 0xa2) + (short)(value4 >> 2);
      value4 = intCursor2[0xe];
      if (((byte)g_GameplayRuntimeFlags & 8) == 0) {
        *(int *)(value4 + 0x14) = *(int *)(value4 + 0x14) + *(int *)(value2 + 0x20);
        *(int *)(intCursor2[0xe] + 0x1c) =
             *(int *)(intCursor2[0xe] + 0x1c) -
             ((int)(short)(&g_SinCosTable12Bit)[value6] * *(int *)(value3 + 0x18) >> 0xc);
        *(undefined4 *)(intCursor2[0xe] + 0x18) = *(undefined4 *)(value2 + 0x24);
      }
      else {
        *(int *)(value4 + 0x14) = *(int *)(value4 + 0x14) + *(int *)(value2 + 0x20);
        *(int *)(intCursor2[0xe] + 0x1c) = *(int *)(g_PlayerEntitySceneObject + 0x1c) + 3000;
        *(undefined4 *)(intCursor2[0xe] + 0x18) = *(undefined4 *)(value2 + 0x24);
      }
      value2 = intCursor2[0xe];
      value4 = *(int *)(value2 + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14);
      value5 = *(int *)(value2 + 0x18) - *(int *)(g_PlayerEntitySceneObject + 0x18);
      value2 = *(int *)(value2 + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c);
      value6 = SqrtToInt(value2 * value2 + value5 * value5 + value4 * value4);
      if ((int)(value6 & 0xffffffc0) < 0x2ee01) {
        *(undefined4 *)(value3 + 0x18) = 0x38;
        resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                          (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value3 + 0x14),0x200,
                           &entry,&localState);
        if ((resultFlag != '\0') && (g_PlayerActionState != 8)) {
          *(undefined4 *)(value3 + 0x18) = 0x1e;
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 8;
          (*(code *)g_StampedeEnterFatalDamageSequenceHandlerPtr)();
        }
      }
      else if (g_PlayerActionState != 8) {
        *(undefined4 *)(value3 + 0x18) = 0x46;
      }
      if (g_StampedeElephantRideState == 1) {
        *(undefined4 *)(value3 + 0x18) = 0x14;
      }
      if (g_StampedeElephantRideState == 2) {
        *(undefined4 *)(value3 + 0x18) = 0;
      }
      entry = &DAT_005033a0;
      intCursor3 = (int *)(value + 0x18);
      intCursor = (int *)(value3 + 0x20);
      do {
        value2 = *intCursor;
        *intCursor = value2 + 1;
        if (0x2026 < value2 + 1) {
          *intCursor = 0x2010;
        }
        *(short *)(intCursor3 + -2) = (short)*intCursor;
        localState = ((short)(&g_SinCosTable12Bit)[intCursor[8] - 0x400U & 0xfff] * 0x163 >> 0xc) +
                    *entry;
        *intCursor3 = localState;
        value2 = intCursor2[0xe];
        localState = *(int *)(value2 + 0x14) + localState;
        localState3 = *(undefined4 *)(value2 + 0x18);
        localState2 = *(undefined4 *)(value2 + 0x1c);
        value7 = Stampede::ProjectPointToNearestElephantPathSegment(value3 + 0xd8,&localState);
        value2 = SqrtToInt(value7);
        value7 = Stampede::ProjectPointToNearestElephantPathSegment(value3 + 0x68,&localState);
        value4 = SqrtToInt(value7);
        if (value2 >> 6 < 0x19c) {
          *intCursor3 = *intCursor3 + (0x19c - (value2 >> 6));
        }
        if (value4 >> 6 < 0x19c) {
          *intCursor3 = *intCursor3 + (value4 >> 6) + -0x19c;
        }
        entry = entry + 4;
        intCursor3 = intCursor3 + 10;
        intCursor[8] = intCursor[8] + 0x10U & 0xfff;
        intCursor = intCursor + 1;
      } while ((int)entry < 0x5033e0);
    }
    CEntities::UpdateScriptedEntitySceneObjectAttachment(intCursor2);
  }
  return;
}

