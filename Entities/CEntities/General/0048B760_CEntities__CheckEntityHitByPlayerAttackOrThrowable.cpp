#include "tarzan_ghidra_types.hpp"

// Address: 0x0048B760
// Label: CEntities::CheckEntityHitByPlayerAttackOrThrowable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CEntities::CheckEntityHitByPlayerAttackOrThrowable(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int entry2;
  short *inputEax;
  int entry3;
  undefined3 value;
  undefined3 upperWord;
  int entry4;
  int entry5;
  int entry6;
  int localState10;
  int localState9;
  int localState8;
  short localState7;
  short localState6;
  short localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  entry4 = entity->sceneObjects;
  if (entry4 != 0) {
    localState8 = entry4;
    entry3 = GetEntitySceneObjectAttachmentList(entry4,&localState10);
    inputEax = (short *)0x0;
    if (entry3 != 0) {
      localState7 = -*(short *)(entry4 + 0xa0);
      localState6 = -((EntitySceneObject *)entry4)->yaw;
      localState5 = -((EntitySceneObject *)entry4)->pitch;
      localState9 = entry3;
      BuildRotationBasisFromEulerAngles(&localState7,localState);
      inputEax = (short *)0x0;
      if (g_PlayerAttackHitPositionPtr != (int *)0x0) {
        localState4 = *g_PlayerAttackHitPositionPtr - ((EntitySceneObject *)entry4)->x;
        localState3 = g_PlayerAttackHitPositionPtr[1] - ((EntitySceneObject *)entry4)->y;
        localState2 = g_PlayerAttackHitPositionPtr[2] - ((EntitySceneObject *)entry4)->z;
        inputEax = (short *)TransformVectorByBasis(localState,&localState4,&localState4);
        entry5 = 0;
        if (0 < entry3) {
          inputEax = (short *)(localState10 + 6);
          do {
            if (((((*(uint *)(inputEax + 3) & 0x200) != 0) && (inputEax[-3] + -0x40 <= localState4)) &&
                (localState4 <= *inputEax + 0x40)) &&
               (((inputEax[1] + -0x40 <= localState3 && (localState3 <= inputEax[-2] + 0x40)) &&
                ((inputEax[-1] + -0x40 <= localState2 && (localState2 <= inputEax[2] + 0x40)))))) {
              entry4 = CONCAT22((short)((uint)inputEax >> 0x10),*(short *)(entry + 0x3e));
              if (-1 < *(short *)(entry + 0x3e)) {
                entry4 = entry4 + -0xa0;
                *(short *)(entry + 0x3e) = (short)entry4;
              }
              value = (undefined3)((uint)entry4 >> 8);
              if (g_PlayerAttackHitSfxPlayed == '\0') {
                PlayAudioById(0xba,(int *)0,(undefined4 *)0);
                value = upperWord;
              }
              g_PlayerAttackHitSfxPlayed = 1;
              *(byte *)(entry + 0x43) = *(byte *)(entry + 0x43) | 0x10;
              return CONCAT31(value,1);
            }
            inputEax = inputEax + 8;
            entry5 = entry5 + 1;
            entry3 = localState9;
            entry4 = localState8;
          } while (entry5 < localState9);
        }
      }
      entry5 = g_ActiveThrowableEntityList;
      if (g_ActiveThrowableEntityList != 0) {
        do {
          if (*(short *)(entry5 + 0x48) != 5) {
            for (entry2 = *(int *)(entry5 + 0x38); entry2 != 0; entry2 = *(int *)(entry2 + 0x34)) {
              localState4 = *(int *)(entry2 + 0x14) - ((EntitySceneObject *)entry4)->x;
              localState3 = (*(int *)(entry2 + 0x40) + *(int *)(entry2 + 0x18)) - ((EntitySceneObject *)entry4)->y;
              localState2 = *(int *)(entry2 + 0x1c) - ((EntitySceneObject *)entry4)->z;
              inputEax = (short *)TransformVectorByBasis(localState,&localState4,&localState4);
              entry6 = 0;
              if (0 < entry3) {
                inputEax = (short *)(localState10 + 6);
                do {
                  if (((((*(uint *)(inputEax + 3) & 0x200) != 0) && (inputEax[-3] + -0x40 <= localState4))
                      && ((localState4 <= *inputEax + 0x40 &&
                          (((inputEax[1] + -0x40 <= localState3 && (localState3 <= inputEax[-2] + 0x40)) &&
                           (inputEax[-1] + -0x40 <= localState2)))))) && (localState2 <= inputEax[2] + 0x40))
                  {
                    *(undefined2 *)(entry5 + 0x48) = 6;
                    shortValue = *(short *)(entry + 0x3e);
                    entry4 = CONCAT22((short)((uint)entry5 >> 0x10),shortValue);
                    if ((*(byte *)(entry5 + 0x4a) & 2) == 0) {
                      if (-1 < shortValue) {
                        entry4 = entry4 + -0x80;
                        *(short *)(entry + 0x3e) = (short)entry4;
                      }
                    }
                    else if (-1 < shortValue) {
                      *(short *)(entry + 0x3e) = (short)(entry4 + -0x200);
                      return CONCAT31((int3)((uint)(entry4 + -0x200) >> 8),1);
                    }
                    return CONCAT31((int3)((uint)entry4 >> 8),1);
                  }
                  inputEax = inputEax + 8;
                  entry6 = entry6 + 1;
                  entry3 = localState9;
                  entry4 = localState8;
                } while (entry6 < localState9);
              }
            }
          }
          entry5 = *(int *)(entry5 + 0x20);
          if (entry5 == 0) {
            return (uint)inputEax & 0xffffff00;
          }
        } while( true );
      }
    }
  }
  return (uint)inputEax & 0xffffff00;
}

