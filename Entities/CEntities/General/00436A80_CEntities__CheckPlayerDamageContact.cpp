#include "tarzan_ghidra_types.hpp"

// Address: 0x00436A80
// Label: CEntities::CheckPlayerDamageContact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::CheckPlayerDamageContact(int entry)

{
  int value;
  uint value4;
  int value2;
  uint value5;
  int value3;
  
  value = entry;
  value4 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(entry + 0x14);
  value5 = (int)value4 >> 0x1f;
  if ((((((int)((value4 ^ value5) - value5) < 0x1001) &&
        (value4 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(entry + 0x18),
        value5 = (int)value4 >> 0x1f, (int)((value4 ^ value5) - value5) < 0x1001)) &&
       (value4 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - *(int *)(entry + 0x1c),
       value5 = (int)value4 >> 0x1f, (int)((value4 ^ value5) - value5) < 0x1001)) &&
      ((*(int *)(entry + 0x60) == 0 || ((g_PlayerCollisionContactFlags & 0x200000) == 0)))) &&
     ((g_PlayerSpecialAttachmentEntry != 0 &&
      ((value2 = GetEntitySceneObjectAttachmentList(entry,&entry), value2 != 0 &&
       (value3 = 0, 0 < value2)))))) {
    do {
      if (((*(uint *)(entry + 0xc) & 0x600) != 0) &&
         ((*(uint *)(entry + 0xc) & 0xc0000000) == 0)) {
        g_PlayerDamageContactPushDistance =
             CEntities::ComputePlayerAttachmentPenetrationDepth
                       (g_PlayerEntitySceneObject,g_PlayerSpecialAttachmentEntry,value,entry);
        if (g_PlayerDamageContactPushDistance != 0) {
          return 1;
        }
        g_PlayerDamageContactPushDistance = 0;
      }
      entry = entry + 0x10;
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  return 0;
}

