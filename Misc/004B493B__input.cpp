#include "tarzan_ghidra_types.hpp"

// Address: 0x004B493B
// Label: _input
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _input(undefined4 arg1,byte *arg2,undefined4 *arg3)

{
  byte flagByte;
  undefined4 *dataCursor;
  byte flagByte3;
  uint value5;
  undefined4 value6;
  int value;
  uint value7;
  uint value8;
  byte flagByte4;
  byte *value3;
  char *stringCursor;
  char *stringCursor2;
  byte *value4;
  bool flagByte2;
  longlong value2;
  char localState11;
  char localState10 [351];
  byte localState24 [32];
  undefined4 *localState23;
  undefined2 localState22;
  uint localState21;
  byte localState20;
  undefined1 localState19;
  byte localState18;
  int localState17;
  byte *localState16;
  byte *localState15;
  undefined8 localState14;
  int localState13;
  int localState12;
  byte localState9;
  char localState8;
  char localState7;
  char localState6;
  uint localState5;
  char localState4;
  char localState3;
  char localState2;
  int localState;
  char localState26;
  int localState25;
  
  localState6 = '\0';
  flagByte = *arg2;
  localState25 = 0;
  localState17 = 0;
  value3 = arg2;
  do {
    if (flagByte == 0) {
LAB_004b5341:
      if (localState5 == 0xffffffff) {
LAB_004b5347:
        if ((localState17 == 0) && (localState6 == '\0')) {
          localState17 = -1;
        }
      }
      return localState17;
    }
    if (g_CrtLocaleEnabled < 2) {
      value5 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 8;
    }
    else {
      value5 = _isctype(flagByte,8);
    }
    if (value5 != 0) {
      localState25 = localState25 + -1;
      value6 = SkipInputDigits(&localState25,arg1,arg1);
      UngetInputCharacter(value6);
      value = isdigit(value3[1]);
      value4 = value3;
      while (value3 = value4 + 1, value != 0) {
        value = isdigit(value4[2]);
        value4 = value3;
      }
    }
    if (*value3 == 0x25) {
      localState18 = 0;
      localState9 = 0;
      localState8 = '\0';
      localState3 = '\0';
      localState4 = '\0';
      localState7 = '\0';
      value = 0;
      localState26 = '\0';
      localState12 = 0;
      localState13 = 0;
      localState = 0;
      localState2 = '\x01';
      localState16 = (byte *)0x0;
      do {
        value5 = (uint)value3[1];
        arg2 = value3 + 1;
        if (g_CrtLocaleEnabled < 2) {
          value7 = (byte)g_CrtCtypeTable[value5 * 2] & 4;
        }
        else {
          value7 = _isctype(value5,4);
        }
        if (value7 == 0) {
          if (value5 < 0x4f) {
            if (value5 != 0x4e) {
              if (value5 == 0x2a) {
                localState3 = localState3 + '\x01';
              }
              else if (value5 != 0x46) {
                if (value5 == 0x49) {
                  if ((value3[2] != 0x36) || (value3[3] != 0x34)) goto LAB_004b4a96;
                  localState16 = localState16 + 1;
                  localState14 = 0;
                  arg2 = value3 + 3;
                }
                else if (value5 == 0x4c) {
                  localState2 = localState2 + '\x01';
                }
                else {
LAB_004b4a96:
                  localState4 = localState4 + '\x01';
                }
              }
            }
          }
          else if (value5 == 0x68) {
            localState2 = localState2 + -1;
            localState26 = localState26 + -1;
          }
          else {
            if (value5 == 0x6c) {
              localState2 = localState2 + '\x01';
            }
            else if (value5 != 0x77) goto LAB_004b4a96;
            localState26 = localState26 + '\x01';
          }
        }
        else {
          localState13 = localState13 + 1;
          localState = (value5 - 0x30) + localState * 10;
        }
        value3 = arg2;
      } while (localState4 == '\0');
      dataCursor = arg3;
      if (localState3 == '\0') {
        localState15 = (byte *)*arg3;
        dataCursor = arg3 + 1;
        localState23 = arg3;
      }
      arg3 = dataCursor;
      localState4 = '\0';
      if (localState26 == '\0') {
        if ((*arg2 == 0x53) || (*arg2 == 0x43)) {
          localState26 = '\x01';
        }
        else {
          localState26 = -1;
        }
      }
      value5 = *arg2 | 0x20;
      localState21 = value5;
      if (value5 != 0x6e) {
        if ((value5 == 99) || (value5 == 0x7b)) {
          localState25 = localState25 + 1;
          localState5 = GetInputCharacter(arg1);
        }
        else {
          localState5 = SkipInputDigits(&localState25,arg1);
        }
      }
      if ((localState13 != 0) && (localState == 0)) {
LAB_004b5321:
        localState25 = localState25 + -1;
        UngetInputCharacter(localState5,arg1);
        goto LAB_004b5341;
      }
      if (value5 < 0x70) {
        if (value5 == 0x6f) {
LAB_004b504e:
          if (localState5 == 0x2d) {
            localState8 = '\x01';
          }
          else if (localState5 != 0x2b) goto LAB_004b5083;
          localState = localState + -1;
          if ((localState == 0) && (localState13 != 0)) {
            localState4 = '\x01';
          }
          else {
            localState25 = localState25 + 1;
            localState5 = GetInputCharacter(arg1);
          }
          goto LAB_004b5083;
        }
        if (value5 != 99) {
          if (value5 == 100) goto LAB_004b504e;
          if (value5 < 0x65) {
LAB_004b4dc6:
            if (*arg2 != localState5) goto LAB_004b5321;
            localState6 = localState6 + -1;
            if (localState3 == '\0') {
              arg3 = localState23;
            }
            goto LAB_004b52a2;
          }
          if (0x67 < value5) {
            if (value5 == 0x69) {
              value5 = 100;
              goto LAB_004b4b84;
            }
            if (value5 != 0x6e) goto LAB_004b4dc6;
            value = localState25;
            value2 = localState14;
            if (localState3 != '\0') goto LAB_004b52a2;
            goto LAB_004b527c;
          }
          stringCursor = &localState11;
          if (localState5 == 0x2d) {
            localState11 = '-';
            stringCursor = localState10;
LAB_004b4bba:
            localState = localState + -1;
            localState25 = localState25 + 1;
            localState5 = GetInputCharacter(arg1);
          }
          else if (localState5 == 0x2b) goto LAB_004b4bba;
          if ((localState13 == 0) || (0x15d < localState)) {
            localState = 0x15d;
          }
          while( true ) {
            value5 = localState5;
            if (g_CrtLocaleEnabled < 2) {
              value7 = (byte)g_CrtCtypeTable[localState5 * 2] & 4;
            }
            else {
              value7 = _isctype(localState5,4);
            }
            if ((value7 == 0) ||
               (value = localState + -1, flagByte2 = localState == 0, localState = value, flagByte2)) break;
            localState12 = localState12 + 1;
            *stringCursor = (char)value5;
            stringCursor = stringCursor + 1;
            localState25 = localState25 + 1;
            localState5 = GetInputCharacter(arg1);
          }
          if ((g_CrtDecimalPointString == (char)value5) &&
             (value = localState + -1, flagByte2 = localState != 0, localState = value, flagByte2)) {
            localState25 = localState25 + 1;
            value5 = GetInputCharacter(arg1);
            *stringCursor = g_CrtDecimalPointString;
            while( true ) {
              stringCursor = stringCursor + 1;
              localState5 = value5;
              if (g_CrtLocaleEnabled < 2) {
                value7 = (byte)g_CrtCtypeTable[value5 * 2] & 4;
              }
              else {
                value7 = _isctype(value5,4);
              }
              if ((value7 == 0) ||
                 (value = localState + -1, flagByte2 = localState == 0, localState = value, flagByte2)) break;
              localState12 = localState12 + 1;
              *stringCursor = (char)value5;
              localState25 = localState25 + 1;
              value5 = GetInputCharacter(arg1);
            }
          }
          stringCursor2 = stringCursor;
          if ((localState12 != 0) &&
             (((value5 == 0x65 || (value5 == 0x45)) &&
              (value = localState + -1, flagByte2 = localState != 0, localState = value, flagByte2)))) {
            *stringCursor = 'e';
            stringCursor2 = stringCursor + 1;
            localState25 = localState25 + 1;
            value5 = GetInputCharacter(arg1);
            localState5 = value5;
            if (value5 == 0x2d) {
              *stringCursor2 = '-';
              stringCursor2 = stringCursor + 2;
LAB_004b4ce1:
              flagByte2 = localState != 0;
              localState = localState + -1;
              if (flagByte2) goto LAB_004b4cf0;
              localState = 0;
            }
            else if (value5 == 0x2b) goto LAB_004b4ce1;
            while( true ) {
              if (g_CrtLocaleEnabled < 2) {
                value7 = (byte)g_CrtCtypeTable[value5 * 2] & 4;
              }
              else {
                value7 = _isctype(value5,4);
              }
              if ((value7 == 0) ||
                 (value = localState + -1, flagByte2 = localState == 0, localState = value, flagByte2)) break;
              localState12 = localState12 + 1;
              *stringCursor2 = (char)value5;
              stringCursor2 = stringCursor2 + 1;
LAB_004b4cf0:
              localState25 = localState25 + 1;
              value5 = GetInputCharacter(arg1);
              localState5 = value5;
            }
          }
          localState25 = localState25 + -1;
          UngetInputCharacter(value5,arg1);
          if (localState12 != 0) {
            if (localState3 == '\0') {
              localState17 = localState17 + 1;
              *stringCursor2 = '\0';
              (*(code *)g_CrtStdinBuffer)(localState2 + -1,localState15,&localState11);
            }
            goto LAB_004b52a2;
          }
          goto LAB_004b5341;
        }
        if (localState13 == 0) {
          localState = localState + 1;
          localState13 = 1;
        }
        if ('\0' < localState26) {
          localState7 = '\x01';
        }
        stringCursor = &DAT_0051b948;
LAB_004b4ea7:
        localState9 = 0xff;
        value3 = (byte *)stringCursor;
        value4 = arg2;
LAB_004b4eab:
        arg2 = value4;
        memset(localState24,0,0x20);
        if ((localState21 == 0x7b) && (*value3 == 0x5d)) {
          value5 = 0x5d;
          localState24[0xb] = 0x20;
          value3 = value3 + 1;
        }
        else {
          value5 = (uint)localState18;
        }
        while (value4 = localState15, flagByte = *value3, flagByte != 0x5d) {
          if (((flagByte == 0x2d) && (flagByte4 = (byte)value5, flagByte4 != 0)) &&
             (flagByte3 = value3[1], flagByte3 != 0x5d)) {
            if (flagByte3 <= flagByte4) {
              value5 = (uint)flagByte3;
              flagByte3 = flagByte4;
            }
            if ((byte)value5 <= flagByte3) {
              value = (flagByte3 - value5) + 1;
              do {
                localState24[value5 >> 3] = localState24[value5 >> 3] | '\x01' << ((byte)value5 & 7);
                value5 = value5 + 1;
                value = value + -1;
              } while (value != 0);
            }
            value5 = 0;
            value3 = value3 + 2;
          }
          else {
            value5 = (uint)flagByte;
            localState24[flagByte >> 3] = localState24[flagByte >> 3] | '\x01' << (flagByte & 7);
            value3 = value3 + 1;
          }
        }
        if (*value3 == 0) goto LAB_004b5341;
        if (localState21 == 0x7b) {
          arg2 = value3;
        }
        localState25 = localState25 + -1;
        localState16 = localState15;
        UngetInputCharacter(localState5,arg1);
        while( true ) {
          if ((localState13 != 0) &&
             (value = localState + -1, flagByte2 = localState == 0, localState = value, flagByte2))
          goto LAB_004b5010;
          localState25 = localState25 + 1;
          localState5 = GetInputCharacter(arg1);
          if ((localState5 == 0xffffffff) ||
             (flagByte = (byte)localState5,
             ((int)(char)(localState24[(int)localState5 >> 3] ^ localState9) & 1 << (flagByte & 7)) == 0)) break;
          if (localState3 == '\0') {
            if (localState7 == '\0') {
              *value4 = flagByte;
              value4 = value4 + 1;
              localState15 = value4;
            }
            else {
              localState20 = flagByte;
              if ((g_CrtCtypeTable[(localState5 & 0xff) * 2 + 1] & 0x80) != 0) {
                localState25 = localState25 + 1;
                localState19 = GetInputCharacter(arg1);
              }
              mbtowc(&localState22,&localState20,g_CrtLocaleEnabled);
              *(undefined2 *)value4 = localState22;
              value4 = value4 + 2;
              localState15 = value4;
            }
          }
          else {
            localState16 = localState16 + 1;
          }
        }
        localState25 = localState25 + -1;
        UngetInputCharacter(localState5,arg1);
LAB_004b5010:
        if (localState16 == value4) goto LAB_004b5341;
        if ((localState3 == '\0') && (localState17 = localState17 + 1, localState21 != 99)) {
          if (localState7 == '\0') {
            *localState15 = 0;
          }
          else {
            localState15[0] = 0;
            localState15[1] = 0;
          }
        }
      }
      else {
        if (value5 == 0x70) {
          localState2 = '\x01';
          goto LAB_004b504e;
        }
        if (value5 == 0x73) {
          if ('\0' < localState26) {
            localState7 = '\x01';
          }
          stringCursor = s_____0051b940;
          goto LAB_004b4ea7;
        }
        if (value5 == 0x75) goto LAB_004b504e;
        if (value5 != 0x78) {
          if (value5 != 0x7b) goto LAB_004b4dc6;
          if ('\0' < localState26) {
            localState7 = '\x01';
          }
          value3 = arg2 + 1;
          value4 = value3;
          if (*value3 == 0x5e) {
            stringCursor = (char *)(arg2 + 2);
            arg2 = value3;
            goto LAB_004b4ea7;
          }
          goto LAB_004b4eab;
        }
LAB_004b4b84:
        if (localState5 == 0x2d) {
          localState8 = '\x01';
LAB_004b4e13:
          localState = localState + -1;
          if ((localState == 0) && (localState13 != 0)) {
            localState4 = '\x01';
          }
          else {
            localState25 = localState25 + 1;
            localState5 = GetInputCharacter(arg1);
          }
        }
        else if (localState5 == 0x2b) goto LAB_004b4e13;
        if (localState5 == 0x30) {
          localState25 = localState25 + 1;
          localState5 = GetInputCharacter(arg1);
          if (((char)localState5 == 'x') || ((char)localState5 == 'X')) {
            localState25 = localState25 + 1;
            localState5 = GetInputCharacter(arg1);
            value5 = 0x78;
          }
          else {
            localState12 = 1;
            if (value5 == 0x78) {
              localState25 = localState25 + -1;
              UngetInputCharacter(localState5,arg1);
              localState5 = 0x30;
            }
            else {
              value5 = 0x6f;
            }
          }
        }
LAB_004b5083:
        value2 = localState14;
        if (localState16 == (byte *)0x0) {
          if (localState4 == '\0') {
            while ((value7 = localState5, value5 != 0x78 && (value5 != 0x70))) {
              if (g_CrtLocaleEnabled < 2) {
                value8 = (byte)g_CrtCtypeTable[localState5 * 2] & 4;
              }
              else {
                value8 = _isctype(localState5,4);
              }
              if (value8 == 0) goto LAB_004b524a;
              if (value5 == 0x6f) {
                if (0x37 < (int)value7) goto LAB_004b524a;
                value = value << 3;
              }
              else {
                value = value * 10;
              }
LAB_004b5222:
              localState12 = localState12 + 1;
              value = value + -0x30 + value7;
              if ((localState13 != 0) && (localState = localState + -1, value2 = localState14, localState == 0))
              goto LAB_004b5258;
              localState25 = localState25 + 1;
              localState5 = GetInputCharacter(arg1);
            }
            if (g_CrtLocaleEnabled < 2) {
              value8 = (byte)g_CrtCtypeTable[localState5 * 2] & 0x80;
            }
            else {
              value8 = _isctype(localState5,0x80);
            }
            if (value8 != 0) {
              value = value << 4;
              value7 = ConvertHexDigitCharacter(value7);
              localState5 = value7;
              goto LAB_004b5222;
            }
LAB_004b524a:
            localState25 = localState25 + -1;
            UngetInputCharacter(value7,arg1);
            value2 = localState14;
          }
LAB_004b5258:
          if (localState8 != '\0') {
            value = -value;
          }
        }
        else {
          if (localState4 == '\0') {
            while (value7 = localState5, value5 != 0x78) {
              if (g_CrtLocaleEnabled < 2) {
                value8 = (byte)g_CrtCtypeTable[localState5 * 2] & 4;
              }
              else {
                value8 = _isctype(localState5,4);
              }
              if (value8 == 0) goto LAB_004b516c;
              if (value5 == 0x6f) {
                if (0x37 < (int)value7) goto LAB_004b516c;
                value2 = __allshl();
              }
              else {
                value2 = __allmul(localState14,10,0);
              }
LAB_004b513e:
              localState12 = localState12 + 1;
              localState14 = value2 + (int)(value7 - 0x30);
              if ((localState13 != 0) && (localState = localState + -1, value2 = localState14, localState == 0))
              goto LAB_004b517a;
              localState25 = localState25 + 1;
              localState5 = GetInputCharacter(arg1);
            }
            if (g_CrtLocaleEnabled < 2) {
              value8 = (byte)g_CrtCtypeTable[localState5 * 2] & 0x80;
            }
            else {
              value8 = _isctype(localState5,0x80);
            }
            if (value8 != 0) {
              value2 = __allshl();
              localState14 = value2;
              value7 = ConvertHexDigitCharacter(value7);
              localState5 = value7;
              value2 = localState14;
              goto LAB_004b513e;
            }
LAB_004b516c:
            localState25 = localState25 + -1;
            UngetInputCharacter(value7,arg1);
            value2 = localState14;
          }
LAB_004b517a:
          *( undefined4 *)((int)&localState14 + 4) = (int)((ulonglong)value2 >> 0x20);
          *( undefined4 *)((int)&localState14 + 0) = (int)value2;
          if (localState8 != '\0') {
            value2 = CONCAT44(-(*( undefined4 *)((int)&localState14 + 4) + (uint)((int)localState14 != 0)),-(int)localState14);
          }
        }
        if (value5 == 0x46) {
          localState12 = 0;
        }
        if (localState12 == 0) goto LAB_004b5341;
        localState14 = value2;
        if (localState3 == '\0') {
          localState17 = localState17 + 1;
LAB_004b527c:
          localState14 = value2;
          if (localState16 == (byte *)0x0) {
            if (localState2 == '\0') {
              *(short *)localState15 = (short)value;
            }
            else {
              *(int *)localState15 = value;
            }
          }
          else {
            *(longlong *)localState15 = value2;
          }
        }
      }
LAB_004b52a2:
      localState6 = localState6 + '\x01';
      arg2 = arg2 + 1;
    }
    else {
      localState25 = localState25 + 1;
      value5 = GetInputCharacter(arg1);
      arg2 = value3 + 1;
      localState5 = value5;
      if (*value3 != value5) goto LAB_004b5321;
      if ((g_CrtCtypeTable[(value5 & 0xff) * 2 + 1] & 0x80) != 0) {
        localState25 = localState25 + 1;
        value7 = GetInputCharacter(arg1);
        flagByte = *arg2;
        arg2 = value3 + 2;
        if (flagByte != value7) {
          localState25 = localState25 + -1;
          UngetInputCharacter(value7,arg1);
          localState25 = localState25 + -1;
          UngetInputCharacter(value5,arg1);
          goto LAB_004b5341;
        }
        localState25 = localState25 + -1;
      }
    }
    if ((localState5 == 0xffffffff) && ((*arg2 != 0x25 || (arg2[1] != 0x6e)))) goto LAB_004b5347;
    flagByte = *arg2;
    value3 = arg2;
  } while( true );
}

