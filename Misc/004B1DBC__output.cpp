#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1DBC
// Label: _output
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _output(undefined4 arg1,byte *arg2,undefined4 *arg3)

{
  byte *value4;
  short shortValue;
  uint value8;
  short *value5;
  short *value6;
  undefined4 value9;
  int *intCursor;
  int value2;
  byte flagByte;
  int value;
  undefined1 *dataCursor;
  ulonglong value7;
  longlong value3;
  undefined1 localState8 [511];
  undefined1 localState19;
  undefined4 localState18;
  undefined4 localState17;
  int localState16;
  int localState15;
  undefined1 localState14 [4];
  undefined4 localState13;
  int localState12;
  int localState11;
  int localState10;
  int localState9;
  int localState7;
  int localState6;
  undefined1 localState5;
  char localState4;
  int localState3;
  int localState2;
  undefined1 *localState;
  short *localState21;
  uint localState20;
  
  localState12 = 0;
  flagByte = *arg2;
  localState = (undefined1 *)0x0;
  localState3 = 0;
  value4 = arg2;
  do {
    if ((flagByte == 0) || (arg2 = value4 + 1, localState3 < 0)) {
      return localState3;
    }
    if (((char)flagByte < ' ') || ('x' < (char)flagByte)) {
      value8 = 0;
    }
    else {
      value8 = (byte)"GAIsProcessorFeaturePresent"[(char)flagByte + 0x12] & 0xf;
    }
    localState12 = (int)(char)(&k_CrtOutputTinyDoubleLimit)[value8 * 8 + localState12] >> 4;
    switch(localState12) {
    case 0:
switchD_004b1e2a_caseD_0:
      localState9 = 0;
      if ((g_CrtCtypeTable[(uint)flagByte * 2 + 1] & 0x80) != 0) {
        WriteCharacterToStreamAndCount((int)(char)flagByte,arg1,&localState3);
        flagByte = *arg2;
        arg2 = value4 + 2;
      }
      WriteCharacterToStreamAndCount((int)(char)flagByte,arg1,&localState3);
      break;
    case 1:
      localState2 = -1;
      localState13 = 0;
      localState10 = 0;
      localState7 = 0;
      localState6 = 0;
      localState20 = 0;
      localState9 = 0;
      break;
    case 2:
      if (flagByte == 0x20) {
        localState20 = localState20 | 2;
      }
      else if (flagByte == 0x23) {
        localState20 = localState20 | 0x80;
      }
      else if (flagByte == 0x2b) {
        localState20 = localState20 | 1;
      }
      else if (flagByte == 0x2d) {
        localState20 = localState20 | 4;
      }
      else if (flagByte == 0x30) {
        localState20 = localState20 | 8;
      }
      break;
    case 3:
      if (flagByte == 0x2a) {
        localState7 = GetNextIntArgument(&arg3);
        if (localState7 < 0) {
          localState20 = localState20 | 4;
          localState7 = -localState7;
        }
      }
      else {
        localState7 = (char)flagByte + -0x30 + localState7 * 10;
      }
      break;
    case 4:
      localState2 = 0;
      break;
    case 5:
      if (flagByte == 0x2a) {
        localState2 = GetNextIntArgument(&arg3);
        if (localState2 < 0) {
          localState2 = -1;
        }
      }
      else {
        localState2 = (char)flagByte + -0x30 + localState2 * 10;
      }
      break;
    case 6:
      if (flagByte == 0x49) {
        if ((*arg2 != 0x36) || (value4[2] != 0x34)) {
          localState12 = 0;
          goto switchD_004b1e2a_caseD_0;
        }
        arg2 = value4 + 3;
        localState20 = localState20 | 0x8000;
      }
      else if (flagByte == 0x68) {
        localState20 = localState20 | 0x20;
      }
      else if (flagByte == 0x6c) {
        localState20 = localState20 | 0x10;
      }
      else if (flagByte == 0x77) {
        localState20 = localState20 | 0x800;
      }
      break;
    case 7:
      value6 = localState21;
      if ((char)flagByte < 'h') {
        if ((char)flagByte < 'e') {
          if ((char)flagByte < 'Y') {
            if (flagByte == 0x58) {
LAB_004b223b:
              localState11 = 7;
LAB_004b2242:
              localState = (undefined1 *)0x10;
              if ((localState20 & 0x80) != 0) {
                localState5 = 0x30;
                localState4 = (char)localState11 + 'Q';
                localState6 = 2;
              }
              goto LAB_004b22ac;
            }
            if (flagByte != 0x43) {
              if ((flagByte != 0x45) && (flagByte != 0x47)) {
                if (flagByte == 0x53) {
                  if ((localState20 & 0x830) == 0) {
                    localState20 = localState20 | 0x800;
                  }
                  goto LAB_004b1fe9;
                }
                goto LAB_004b23c6;
              }
              localState13 = 1;
              flagByte = flagByte + 0x20;
              goto LAB_004b204a;
            }
            if ((localState20 & 0x830) == 0) {
              localState20 = localState20 | 0x800;
            }
LAB_004b2077:
            if ((localState20 & 0x810) == 0) {
              localState8[0] = GetNextIntArgument(&arg3);
              localState = (undefined1 *)0x1;
            }
            else {
              value9 = GetNextShortArgument();
              localState = (undefined1 *)wctomb(localState8,value9);
              if ((int)localState < 0) {
                localState10 = 1;
              }
            }
            value6 = (short *)localState8;
          }
          else if (flagByte == 0x5a) {
            value5 = (short *)GetNextIntArgument(&arg3);
            if ((value5 == (short *)0x0) ||
               (value6 = *(short **)(value5 + 2), value6 == (short *)0x0)) {
              localState21 = (short *)g_CrtOutputFormatFlags;
              value6 = (short *)g_CrtOutputFormatFlags;
              goto LAB_004b21bc;
            }
            if ((localState20 & 0x800) == 0) {
              localState9 = 0;
              localState = (undefined1 *)(int)*value5;
            }
            else {
              localState9 = 1;
              localState = (undefined1 *)((uint)(int)*value5 >> 1);
            }
          }
          else {
            if (flagByte == 99) goto LAB_004b2077;
            if (flagByte == 100) goto LAB_004b22a1;
          }
        }
        else {
LAB_004b204a:
          localState20 = localState20 | 0x40;
          value6 = (short *)localState8;
          if (localState2 < 0) {
            localState2 = 6;
          }
          else if ((localState2 == 0) && (flagByte == 0x67)) {
            localState2 = 1;
          }
          localState18 = *arg3;
          localState17 = arg3[1];
          arg3 = arg3 + 2;
          localState21 = value6;
          (*(code *)g_CrtStdoutBuffer)(&localState18,localState8,(int)(char)flagByte,localState2,localState13);
          value8 = localState20 & 0x80;
          if ((value8 != 0) && (localState2 == 0)) {
            (*(code *)g_CrtPrintfBuffer)(localState8);
          }
          if ((flagByte == 0x67) && (value8 == 0)) {
            (*(code *)g_CrtStderrBuffer)(localState8);
          }
          if (localState8[0] == '-') {
            localState20 = localState20 | 0x100;
            value6 = (short *)(localState8 + 1);
            localState21 = value6;
          }
LAB_004b21bc:
          localState = (undefined1 *)strlen((char *)value6);
          value6 = localState21;
        }
      }
      else {
        if (flagByte == 0x69) {
LAB_004b22a1:
          localState20 = localState20 | 0x40;
        }
        else {
          if (flagByte == 0x6e) {
            intCursor = (int *)GetNextIntArgument(&arg3);
            if ((localState20 & 0x20) == 0) {
              *intCursor = localState3;
            }
            else {
              *(undefined2 *)intCursor = (undefined2)localState3;
            }
            localState10 = 1;
            break;
          }
          if (flagByte == 0x6f) {
            localState = (undefined1 *)0x8;
            if ((localState20 & 0x80) != 0) {
              localState20 = localState20 | 0x200;
            }
            goto LAB_004b22ac;
          }
          if (flagByte == 0x70) {
            localState2 = 8;
            goto LAB_004b223b;
          }
          if (flagByte == 0x73) {
LAB_004b1fe9:
            value = localState2;
            if (localState2 == -1) {
              value = 0x7fffffff;
            }
            value5 = (short *)GetNextIntArgument(&arg3);
            if ((localState20 & 0x810) == 0) {
              value6 = value5;
              if (value5 == (short *)0x0) {
                value5 = (short *)g_CrtOutputFormatFlags;
                value6 = (short *)g_CrtOutputFormatFlags;
              }
              for (; (value != 0 && ((char)*value5 != '\0')); value5 = (short *)((int)value5 + 1))
              {
                value = value + -1;
              }
              localState = (undefined1 *)((int)value5 - (int)value6);
            }
            else {
              if (value5 == (short *)0x0) {
                value5 = (short *)g_CrtOutputFormatBuffer;
              }
              localState9 = 1;
              for (value6 = value5; (value != 0 && (*value6 != 0)); value6 = value6 + 1) {
                value = value + -1;
              }
              localState = (undefined1 *)((int)value6 - (int)value5 >> 1);
              value6 = value5;
            }
            goto LAB_004b23c6;
          }
          if (flagByte != 0x75) {
            if (flagByte != 0x78) goto LAB_004b23c6;
            localState11 = 0x27;
            goto LAB_004b2242;
          }
        }
        localState = (undefined1 *)0xa;
LAB_004b22ac:
        if ((localState20 & 0x8000) == 0) {
          if ((localState20 & 0x20) == 0) {
            if ((localState20 & 0x40) == 0) {
              value8 = GetNextIntArgument(&arg3);
              value7 = (ulonglong)value8;
              goto LAB_004b22ff;
            }
            value8 = GetNextIntArgument(&arg3);
          }
          else if ((localState20 & 0x40) == 0) {
            value8 = GetNextIntArgument(&arg3);
            value8 = value8 & 0xffff;
          }
          else {
            shortValue = GetNextIntArgument(&arg3);
            value8 = (uint)shortValue;
          }
          value7 = (ulonglong)(int)value8;
        }
        else {
          value7 = GetNextInt64Argument(&arg3);
        }
LAB_004b22ff:
        if ((((localState20 & 0x40) != 0) && ((longlong)value7 < 0x100000000)) && ((longlong)value7 < 0))
        {
          value7 = CONCAT44(-((int)(value7 >> 0x20) + (uint)((int)value7 != 0)),-(int)value7);
          localState20 = localState20 | 0x100;
        }
        value = (int)(value7 >> 0x20);
        if ((localState20 & 0x8000) == 0) {
          value = 0;
        }
        value3 = CONCAT44(value,(int)value7);
        if (localState2 < 0) {
          localState2 = 1;
        }
        else {
          localState20 = localState20 & 0xfffffff7;
        }
        if ((int)value7 == 0 && value == 0) {
          localState6 = 0;
        }
        localState21 = (short *)&localState19;
        while ((value = localState2 + -1, 0 < localState2 || (value3 != 0))) {
          localState15 = (int)localState >> 0x1f;
          localState16 = (int)localState;
          localState2 = value;
          value = __aullrem(value3,localState,localState15);
          value = value + 0x30;
          value3 = __aulldiv(value3,localState16,localState15);
          if (0x39 < value) {
            value = value + localState11;
          }
          value6 = (short *)((int)localState21 + -1);
          *(char *)localState21 = (char)value;
          localState21 = value6;
        }
        value2 = -(int)localState21;
        localState = &localState19 + value2;
        value6 = (short *)((int)localState21 + 1);
        localState2 = value;
        if (((localState20 & 0x200) != 0) &&
           ((*(char *)value6 != '0' || (localState == (undefined1 *)0x0)))) {
          *(char *)localState21 = '0';
          localState = (undefined1 *)((int)&localState18 + value2);
          value6 = localState21;
        }
      }
LAB_004b23c6:
      localState21 = value6;
      value8 = localState20;
      if (localState10 == 0) {
        if ((localState20 & 0x40) != 0) {
          if ((localState20 & 0x100) == 0) {
            if ((localState20 & 1) == 0) {
              if ((localState20 & 2) == 0) goto LAB_004b23fe;
              localState5 = 0x20;
            }
            else {
              localState5 = 0x2b;
            }
          }
          else {
            localState5 = 0x2d;
          }
          localState6 = 1;
        }
LAB_004b23fe:
        value = (localState7 - localState6) - (int)localState;
        if ((localState20 & 0xc) == 0) {
          _write_char(0x20,value,arg1,&localState3);
        }
        _write_string(&localState5,localState6,arg1,&localState3);
        if (((value8 & 8) != 0) && ((value8 & 4) == 0)) {
          _write_char(0x30,value,arg1,&localState3);
        }
        if ((localState9 == 0) || (dataCursor = localState, value6 = localState21, (int)localState < 1)) {
          _write_string(localState21,localState,arg1,&localState3);
        }
        else {
          do {
            dataCursor = dataCursor + -1;
            value2 = wctomb(localState14,*value6);
            if (value2 < 1) break;
            _write_string(localState14,value2,arg1,&localState3);
            value6 = value6 + 1;
          } while (dataCursor != (undefined1 *)0x0);
        }
        if ((localState20 & 4) != 0) {
          _write_char(0x20,value,arg1,&localState3);
        }
      }
    }
    flagByte = *arg2;
    value4 = arg2;
  } while( true );
}

