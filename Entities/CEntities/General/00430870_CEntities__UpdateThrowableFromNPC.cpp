#include "tarzan_ghidra_types.hpp"

// Address: 0x00430870
// Label: CEntities::UpdateThrowableFromNPC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateThrowableFromNPC(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value2;
  int *intCursor;
  uint value6;
  uint value7;
  int value3;
  int value4;
  int *intCursor2;
  int value;
  short *value5;
  ushort *dataCursor;
  char *stringCursor;
  int localState;
  short *localState2;
  
  value3 = entity->sceneObjects;
  if ((value3 != 0) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000), value2 != 0)) {
    intCursor2 = (int *)(&((EntitySceneObject *)value3)->x);
    *intCursor2 = ((EntitySceneObject *)value3)->x - *(int *)(value2 + 0xc);
    ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y - *(int *)(value2 + 0x10);
    ((EntitySceneObject *)value3)->z = ((EntitySceneObject *)value3)->z - *(int *)(value2 + 0x14);
    resultFlag = *(char *)(value2 + 0x20);
    if (resultFlag == '\0') {
      *(int *)(value2 + 0x10) = *(int *)(value2 + 0x10) - *(int *)(value2 + 0x1c);
      ((EntitySceneObject *)value3)->pitch = ((EntitySceneObject *)value3)->pitch + 0x100;
      resultFlag = CEntities::CheckPlayerDamageContact(value3);
      *(short *)(value2 + 0x18) = *(short *)(value2 + 0x18) + -1;
      value6 = ((EntitySceneObject *)value3)->y - *(int *)(value3 + 0x4c);
      value7 = (int)value6 >> 0x1f;
      if (0x1000 < (int)((value6 ^ value7) - value7)) {
        *(undefined2 *)(value2 + 0x18) = 0;
      }
      if ((*(short *)(value2 + 0x18) == 0) || (resultFlag != '\0')) {
        ((EntitySceneObject *)value3)->roll = 3;
        *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) & 0x6fff | 0x1000;
        *(int *)(value2 + 0x14) = *(int *)(value2 + 0x14) >> 1;
        *(undefined1 *)(value2 + 0x20) = 1;
        *(int *)(value2 + 0xc) = *(int *)(value2 + 0xc) >> 1;
        *(int *)(value2 + 0x10) = -*(int *)(value2 + 0x10) >> 2;
        value4 = CEntities::CreateChildEntitySceneObjectArrayAttachment(entry,1,8);
        if (value4 != 0) {
          localState2 = (short *)(value2 + 0x8c);
          value = 0;
          dataCursor = (ushort *)(value4 + 0x12);
          do {
            *dataCursor = *dataCursor & 0x6fff | 0x1000;
            *(undefined1 *)(value + 0x84 + value2) = 0;
            shortValue = RandomModulo(4);
            *localState2 = shortValue + 1;
            dataCursor[-1] = 0x2011;
            localState2 = localState2 + 1;
            value = value + 1;
            *(int *)(dataCursor + 1) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
            dataCursor = dataCursor + 0x14;
          } while (value < 8);
        }
        CEntities::SpawnEntityByTypeAtPosition
                  (*intCursor2,((EntitySceneObject *)value3)->y,((EntitySceneObject *)value3)->z,0x13,0x11);
        PlayAudioById(0xb7,(int *)0,(undefined4 *)intCursor2);
        if ((resultFlag != '\0') && (g_PlayerBlockDamageGuardActive == 0)) {
          QueuePlayerDamageEvent(entry,0x2005);
        }
      }
    }
    else if (resultFlag == '\x01') {
      stringCursor = (char *)(value2 + 0x84);
      value5 = (short *)(value2 + 0x8c);
      localState = 0;
      intCursor = (int *)(*(int *)(entity->sceneObjects + 0x38) + 0x1c);
      intCursor2 = (int *)(value2 + 0x28);
      do {
        shortValue = *value5;
        *value5 = shortValue + -1;
        resultFlag = *stringCursor;
        if (resultFlag == '\0') {
          if ((short)(shortValue + -1) == 0) {
            *stringCursor = '\x01';
            shortValue = RandomModulo(0x14);
            *value5 = shortValue + 0x14;
            value6 = RandomModulo(0x1000);
            value7 = RandomModulo(0x400);
            value3 = RandomModulo(10);
            value4 = RandomModulo(0x10);
            intCursor2[-1] = (int)(short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * (&((EntitySceneObject *)value3)->y)
                         >> 0xc;
            intCursor2[1] = (int)(short)(&g_SinCosTable12Bit)[value6 & 0xfff] * (&((EntitySceneObject *)value3)->y) >> 0xc;
            *intCursor2 = -((int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value4 + 0x20)) >> 0xc;
            *(byte *)((int)intCursor + -9) = *(byte *)((int)intCursor + -9) | 0x80;
          }
        }
        else if (resultFlag == '\x01') {
          intCursor[-1] = intCursor[-1] + intCursor2[-1];
          *intCursor = *intCursor + *intCursor2;
          intCursor[1] = intCursor[1] + intCursor2[1];
          *intCursor2 = *intCursor2 + *(int *)(value2 + 0x1c);
          if (*value5 == 0) {
            *stringCursor = '\x02';
            *(ushort *)((int)intCursor + -10) = *(ushort *)((int)intCursor + -10) & 0x7fff;
          }
        }
        else if (resultFlag == '\x02') {
          localState = localState + 1;
        }
        value5 = value5 + 1;
        stringCursor = stringCursor + 1;
        intCursor2 = intCursor2 + 3;
        intCursor = intCursor + 10;
      } while ((int)(stringCursor + (-0x84 - value2)) < 8);
      if (localState == 8) {
        CEntities::ReleaseEntityToFreeList((byte *)entry);
      }
    }
    else if (resultFlag == '\x02') {
      *(int *)(value2 + 0x10) = *(int *)(value2 + 0x10) - *(int *)(value2 + 0x1c);
      ((EntitySceneObject *)value3)->pitch = ((EntitySceneObject *)value3)->pitch + 0x100;
      *(short *)(value2 + 0x18) = *(short *)(value2 + 0x18) + -1;
      if (*(short *)(value2 + 0x18) == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)entry);
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

