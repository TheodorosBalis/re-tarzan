#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF2A1
// Label: _fclose_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 _fclose_lk(FILE *arg1)

{
  int value;
  undefined4 value2;
  
  value2 = 0xffffffff;
  if ((arg1->_flag & 0x83) != 0) {
    value2 = _flush(arg1);
    __freebuf(arg1);
    value = _close(arg1->_file);
    if (value < 0) {
      value2 = 0xffffffff;
    }
    else if (arg1->_tmpfname != (char *)0x0) {
      free(arg1->_tmpfname);
      arg1->_tmpfname = (char *)0x0;
    }
  }
  arg1->_flag = 0;
  return value2;
}

