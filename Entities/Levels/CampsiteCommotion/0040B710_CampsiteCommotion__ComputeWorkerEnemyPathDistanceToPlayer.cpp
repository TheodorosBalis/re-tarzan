#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B710
// Label: CampsiteCommotion::ComputeWorkerEnemyPathDistanceToPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::ComputeWorkerEnemyPathDistanceToPlayer
               (int arg1,uint *arg2,uint *arg3)

{
  int value;
  int value2;
  uint value3;
  
  value2 = g_CampsiteCommotionWorkerEnemyListHead;
  do {
    if (value2 == 0) {
      return;
    }
    value = *(int *)(value2 + 0x38);
    if (((value != 0) && (arg1 != value)) &&
       (*(int *)(arg1 + 0x110) == *(int *)(value + 0x110))) {
      value3 = *(int *)(arg1 + 0x10c) - *(int *)(value + 0x10c);
      if ((int)value3 < 0) {
        value3 = ~value3 + 1;
        if (*(char *)(arg1 + 0x75) == '\0') {
LAB_0040b76c:
          if ((int)value3 < (int)*arg2) {
            *arg2 = value3;
          }
        }
        else if ((int)value3 < (int)*arg3) {
LAB_0040b778:
          *arg3 = value3;
        }
      }
      else {
        if (*(char *)(arg1 + 0x75) != '\0') goto LAB_0040b76c;
        if ((int)value3 < (int)*arg3) goto LAB_0040b778;
      }
    }
    value2 = *(int *)(value2 + 0x20);
  } while( true );
}

