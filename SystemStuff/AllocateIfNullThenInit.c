/* Address: 0x004AFF00 */

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl AllocateIfNullThenInit(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = (void *)AllocateMemOnOS2(_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_004b360d(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}

