#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0A24
// Label: __cfltcvt
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t value;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    value = _cftoe(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      value = _cftof(arg,buffer,format);
      return value;
    }
    value = _cftog(arg,buffer,format,precision);
  }
  return value;
}

