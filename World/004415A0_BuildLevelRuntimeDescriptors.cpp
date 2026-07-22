#include "tarzan_ghidra_types.hpp"

// Address: 0x004415A0
// Label: BuildLevelRuntimeDescriptors
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildLevelRuntimeDescriptors(void)

{
  uint *dataCursor;
  ushort *dataCursor2;
  uint *dataCursor3;
  ushort value3;
  int value;
  int value2;
  undefined4 *dataCursor4;
  uint *dataCursor5;
  undefined4 *dataCursor6;
  bool flagByte;
  int localState5;
  undefined4 localState4 [5];
  uint localState3;
  uint localState2;
  uint localState;
  int localState10;
  int localState9;
  undefined4 localState8;
  uint localState7;
  uint localState6;
  
  dataCursor4 = &g_HudEntitySceneObjectTemplate;
  dataCursor6 = localState4;
  for (value = 0x51; value != 0; value = value + -1) {
    *dataCursor6 = *dataCursor4;
    dataCursor4 = dataCursor4 + 1;
    dataCursor6 = dataCursor6 + 1;
  }
  value = **(int **)(g_CurrentLevelStartPositionX + 0x10);
  value3 = *(ushort *)(*(int **)(g_CurrentLevelStartPositionX + 0x10) + 1);
  localState8 = 1;
  g_RuntimeDescriptorCount = *g_LevelRuntimeDescriptorSourceTable;
  if (g_RuntimeDescriptorCount != 0) {
    flagByte = g_RuntimeDescriptorArray == (uint *)0x0;
    if (flagByte) {
      g_RuntimeDescriptorArray =
           (uint *)CompactAndAllocModelHeapBlock
                             (g_RuntimeDescriptorCount * 0x1c,&g_ModelLoadHeapState);
    }
    if (g_RuntimeDescriptorArray == (uint *)0x0) {
      g_RuntimeDescriptorCount = 0;
    }
    else {
      localState5 = 0;
      if (0 < g_RuntimeDescriptorCount) {
        value2 = 0;
        dataCursor5 = g_RuntimeDescriptorArray;
        do {
          dataCursor = (uint *)((int)g_LevelRuntimeDescriptorSourceTable + value2 + 4);
          dataCursor2 = (ushort *)
                   ((*(uint *)((int)g_LevelRuntimeDescriptorSourceTable + value2 + 0x10) & 0xfffffffc
                    ) + 0xc + (int)dataCursor);
          dataCursor5[4] = (uint)dataCursor2;
          if ((flagByte) || ((dataCursor2[1] & 8) != 0)) {
            dataCursor5[3] = 0x1ff;
            *(ushort *)((int)dataCursor5 + 0x16) = (byte)dataCursor[3] & 3;
            switch(dataCursor[3] & 3) {
            case 0:
              *dataCursor5 = *dataCursor;
              dataCursor5[1] = dataCursor[1];
              dataCursor5[2] = dataCursor[2];
              break;
            case 1:
              localState = 0;
              localState3 = 0;
              localState2 = dataCursor[1];
              localState6 = (dataCursor[2] ^ dataCursor5[3]) & 0x1ff ^ dataCursor5[3];
              dataCursor5[3] = localState6;
              localState6 = localState6 & 0x1ff;
              localState7 = *dataCursor;
              dataCursor5[3] = localState7 << 9 | dataCursor5[3] & 0x1ff;
              localState7 = localState7 & 0x7fffff;
              UpdateEntityEntitySceneObjectTransformFromPlacement(localState4);
              localState3 = localState3 + localState10;
              localState = localState + localState9;
              *dataCursor5 = localState3;
              dataCursor5[1] = localState2;
              dataCursor5[2] = localState;
              break;
            case 2:
            case 3:
              dataCursor3 = (uint *)(*dataCursor + 0x20 + (int)dataCursor);
              *dataCursor5 = *dataCursor3;
              dataCursor5[1] = dataCursor3[1];
              dataCursor5[2] = dataCursor3[2];
              dataCursor5[3] = (uint)dataCursor;
            }
            if ((uint)*dataCursor2 < (uint)value3) {
              *(undefined2 *)(dataCursor5 + 6) = *(undefined2 *)(value + (uint)*dataCursor2 * 2);
            }
            else {
              *(undefined2 *)(dataCursor5 + 6) = 0;
            }
            *(ushort *)((int)dataCursor5 + 0x1a) = (dataCursor2[1] & 0x7ff) << 4;
            *(ushort *)(dataCursor5 + 5) = dataCursor2[2];
          }
          localState5 = localState5 + 1;
          value2 = value2 + 0x10;
          dataCursor5 = dataCursor5 + 7;
        } while (localState5 < g_RuntimeDescriptorCount);
      }
      if ((code *)*g_CurrentLevelRuntimeHookTable != (code *)0x0) {
        (*(code *)*g_CurrentLevelRuntimeHookTable)
                  (g_RuntimeDescriptorArray,g_RuntimeDescriptorCount);
        return;
      }
    }
  }
  return;
}

