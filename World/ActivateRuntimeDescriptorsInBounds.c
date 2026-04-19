// 0x004418a0

void ActivateRuntimeDescriptorsInBounds(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = g_RuntimeDescriptorArray;
  pcVar1 = *(code **)(DAT_00534004 + 8);
  if (*(code **)(DAT_00534004 + 4) == (code *)0x0) {
    BuildDefaultRuntimeActivationBounds(&g_RuntimeActivationBounds,&g_RuntimeOuterActivationBounds);
  }
  else {
    (**(code **)(DAT_00534004 + 4))();
  }
  iVar2 = 0;
  if (0 < g_RuntimeDescriptorCount) {
    do {
      if ((*(ushort *)((int)piVar3 + 0x1a) & 0x8001) == 0) {
        if (pcVar1 == (code *)0x0) {
          if ((((g_RuntimeActivationBounds < *piVar3) && (*piVar3 < g_RuntimeActivationMaxX)) &&
              (g_RuntimeActivationMinZ < piVar3[2])) && (piVar3[2] < g_RuntimeActivationMaxZ)) {
            InstantiateRuntimeEntryFromDescriptor(piVar3);
          }
        }
        else {
          (*pcVar1)(piVar3);
        }
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 7;
    } while (iVar2 < g_RuntimeDescriptorCount);
  }
  return;
}