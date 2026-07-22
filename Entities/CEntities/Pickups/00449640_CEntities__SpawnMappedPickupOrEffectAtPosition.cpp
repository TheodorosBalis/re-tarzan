#include "tarzan_ghidra_types.hpp"

// Address: 0x00449640
// Label: CEntities::SpawnMappedPickupOrEffectAtPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SpawnMappedPickupOrEffectAtPosition
               (undefined4 entry,undefined4 sceneObject,undefined4 attachment,uint flags,ushort arg5
               )

{
  undefined2 value3;
  int value;
  int value2;
  uint value4;
  
  value3 = *(undefined2 *)(&g_CollectibleScriptIdToEntityTypeTable + (flags & 0xffff) * 2);
  value2 = CEntities::SpawnEntityByTypeAtPosition(entry,sceneObject,attachment,value3,0x11);
  if (value2 != 0) {
    switch(value3) {
    case 4:
    case 6:
    case 7:
      value2 = *(int *)(value2 + 0x38);
      if (value2 != 0) {
        *(uint *)(value2 + 0x18) = *(int *)(value2 + 0x18) - (uint)arg5;
        return;
      }
      break;
    case 5:
      value = *(int *)(value2 + 0x38);
      if (value != 0) {
        *(int *)(value2 + 0x4c) = 1 << ((byte)arg5 & 0x1f);
        switch(arg5) {
        case 0:
          *(undefined2 *)(value + 0xc) = 0x2012;
          return;
        case 1:
        case 4:
          *(undefined2 *)(value + 0xc) = 0x2013;
          return;
        case 2:
          *(undefined2 *)(value + 0xc) = 0x2014;
          return;
        case 3:
          *(undefined2 *)(value + 0xc) = 0x2015;
          return;
        case 5:
          *(undefined2 *)(value + 0xc) = 0x2016;
          return;
        }
      }
      break;
    case 0xe:
      value = *(int *)(value2 + 0x38);
      if (value != 0) {
        value4 = (uint)arg5;
        *(uint *)(value2 + 0x4c) = value4;
        if (value4 != 1) {
          if (value4 == 2) {
            *(undefined2 *)(value + 0xc) = 0x2025;
            return;
          }
          if (value4 != 10) {
            *(undefined2 *)(value + 0xc) = 0x2023;
            return;
          }
          *(undefined2 *)(value + 0xc) = 0x2028;
          return;
        }
        *(undefined2 *)(value + 0xc) = 0x2024;
      }
    }
  }
  return;
}

