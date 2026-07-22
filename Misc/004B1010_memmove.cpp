#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1010
// Label: memmove
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * memmove_004B1010(undefined4 *arg1,undefined4 *arg2,uint arg3)

{
  uint value;
  undefined4 *dataCursor;
  
  if ((arg2 < arg1) && (arg1 < (undefined4 *)(arg3 + (int)arg2))) {
    arg2 = (undefined4 *)((arg3 - 4) + (int)arg2);
    dataCursor = (undefined4 *)((arg3 - 4) + (int)arg1);
    if (((uint)dataCursor & 3) == 0) {
      value = arg3 >> 2;
      arg3 = arg3 & 3;
      if (7 < value) {
        for (; value != 0; value = value - 1) {
          *dataCursor = *arg2;
          arg2 = arg2 + -1;
          dataCursor = dataCursor + -1;
        }
        switch(arg3) {
        case 0:
          return arg1;
        case 2:
          goto switchD_004b11c7_caseD_2;
        case 3:
          goto switchD_004b11c7_caseD_3;
        }
        goto switchD_004b11c7_caseD_1;
      }
    }
    else {
      switch(arg3) {
      case 0:
        goto switchD_004b11c7_caseD_0;
      case 1:
        goto switchD_004b11c7_caseD_1;
      case 2:
        goto switchD_004b11c7_caseD_2;
      case 3:
        goto switchD_004b11c7_caseD_3;
      default:
        value = arg3 - ((uint)dataCursor & 3);
        switch((uint)dataCursor & 3) {
        case 1:
          arg3 = value & 3;
          *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
          arg2 = (undefined4 *)((int)arg2 + -1);
          value = value >> 2;
          dataCursor = (undefined4 *)((int)dataCursor - 1);
          if (7 < value) {
            for (; value != 0; value = value - 1) {
              *dataCursor = *arg2;
              arg2 = arg2 + -1;
              dataCursor = dataCursor + -1;
            }
            switch(arg3) {
            case 0:
              return arg1;
            case 2:
              goto switchD_004b11c7_caseD_2;
            case 3:
              goto switchD_004b11c7_caseD_3;
            }
            goto switchD_004b11c7_caseD_1;
          }
          break;
        case 2:
          arg3 = value & 3;
          *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
          value = value >> 2;
          *(undefined1 *)((int)dataCursor + 2) = *(undefined1 *)((int)arg2 + 2);
          arg2 = (undefined4 *)((int)arg2 + -2);
          dataCursor = (undefined4 *)((int)dataCursor - 2);
          if (7 < value) {
            for (; value != 0; value = value - 1) {
              *dataCursor = *arg2;
              arg2 = arg2 + -1;
              dataCursor = dataCursor + -1;
            }
            switch(arg3) {
            case 0:
              return arg1;
            case 2:
              goto switchD_004b11c7_caseD_2;
            case 3:
              goto switchD_004b11c7_caseD_3;
            }
            goto switchD_004b11c7_caseD_1;
          }
          break;
        case 3:
          arg3 = value & 3;
          *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
          *(undefined1 *)((int)dataCursor + 2) = *(undefined1 *)((int)arg2 + 2);
          value = value >> 2;
          *(undefined1 *)((int)dataCursor + 1) = *(undefined1 *)((int)arg2 + 1);
          arg2 = (undefined4 *)((int)arg2 + -3);
          dataCursor = (undefined4 *)((int)dataCursor - 3);
          if (7 < value) {
            for (; value != 0; value = value - 1) {
              *dataCursor = *arg2;
              arg2 = arg2 + -1;
              dataCursor = dataCursor + -1;
            }
            switch(arg3) {
            case 0:
              return arg1;
            case 2:
              goto switchD_004b11c7_caseD_2;
            case 3:
              goto switchD_004b11c7_caseD_3;
            }
            goto switchD_004b11c7_caseD_1;
          }
        }
      }
    }
    switch(value) {
    case 7:
      dataCursor[7 - value] = arg2[7 - value];
    case 6:
      dataCursor[6 - value] = arg2[6 - value];
    case 5:
      dataCursor[5 - value] = arg2[5 - value];
    case 4:
      dataCursor[4 - value] = arg2[4 - value];
    case 3:
      dataCursor[3 - value] = arg2[3 - value];
    case 2:
      dataCursor[2 - value] = arg2[2 - value];
    case 1:
      dataCursor[1 - value] = arg2[1 - value];
      arg2 = arg2 + -value;
      dataCursor = dataCursor + -value;
    }
    switch(arg3) {
    case 1:
switchD_004b11c7_caseD_1:
      *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
      return arg1;
    case 2:
switchD_004b11c7_caseD_2:
      *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
      *(undefined1 *)((int)dataCursor + 2) = *(undefined1 *)((int)arg2 + 2);
      return arg1;
    case 3:
switchD_004b11c7_caseD_3:
      *(undefined1 *)((int)dataCursor + 3) = *(undefined1 *)((int)arg2 + 3);
      *(undefined1 *)((int)dataCursor + 2) = *(undefined1 *)((int)arg2 + 2);
      *(undefined1 *)((int)dataCursor + 1) = *(undefined1 *)((int)arg2 + 1);
      return arg1;
    }
switchD_004b11c7_caseD_0:
    return arg1;
  }
  dataCursor = arg1;
  if (((uint)arg1 & 3) == 0) {
    value = arg3 >> 2;
    arg3 = arg3 & 3;
    if (7 < value) {
      for (; value != 0; value = value - 1) {
        *dataCursor = *arg2;
        arg2 = arg2 + 1;
        dataCursor = dataCursor + 1;
      }
      switch(arg3) {
      case 0:
        return arg1;
      case 2:
        goto switchD_004b1045_caseD_2;
      case 3:
        goto switchD_004b1045_caseD_3;
      }
      goto switchD_004b1045_caseD_1;
    }
  }
  else {
    switch(arg3) {
    case 0:
      goto jpt_memmove_004B1064;
    case 1:
      goto switchD_004b1045_caseD_1;
    case 2:
      goto switchD_004b1045_caseD_2;
    case 3:
      goto switchD_004b1045_caseD_3;
    default:
      value = (arg3 - 4) + ((uint)arg1 & 3);
      switch((uint)arg1 & 3) {
      case 1:
        arg3 = value & 3;
        *(undefined1 *)arg1 = *(undefined1 *)arg2;
        *(undefined1 *)((int)arg1 + 1) = *(undefined1 *)((int)arg2 + 1);
        value = value >> 2;
        *(undefined1 *)((int)arg1 + 2) = *(undefined1 *)((int)arg2 + 2);
        arg2 = (undefined4 *)((int)arg2 + 3);
        dataCursor = (undefined4 *)((int)arg1 + 3);
        if (7 < value) {
          for (; value != 0; value = value - 1) {
            *dataCursor = *arg2;
            arg2 = arg2 + 1;
            dataCursor = dataCursor + 1;
          }
          switch(arg3) {
          case 0:
            return arg1;
          case 2:
            goto switchD_004b1045_caseD_2;
          case 3:
            goto switchD_004b1045_caseD_3;
          }
          goto switchD_004b1045_caseD_1;
        }
        break;
      case 2:
        arg3 = value & 3;
        *(undefined1 *)arg1 = *(undefined1 *)arg2;
        value = value >> 2;
        *(undefined1 *)((int)arg1 + 1) = *(undefined1 *)((int)arg2 + 1);
        arg2 = (undefined4 *)((int)arg2 + 2);
        dataCursor = (undefined4 *)((int)arg1 + 2);
        if (7 < value) {
          for (; value != 0; value = value - 1) {
            *dataCursor = *arg2;
            arg2 = arg2 + 1;
            dataCursor = dataCursor + 1;
          }
          switch(arg3) {
          case 0:
            return arg1;
          case 2:
            goto switchD_004b1045_caseD_2;
          case 3:
            goto switchD_004b1045_caseD_3;
          }
          goto switchD_004b1045_caseD_1;
        }
        break;
      case 3:
        arg3 = value & 3;
        *(undefined1 *)arg1 = *(undefined1 *)arg2;
        arg2 = (undefined4 *)((int)arg2 + 1);
        value = value >> 2;
        dataCursor = (undefined4 *)((int)arg1 + 1);
        if (7 < value) {
          for (; value != 0; value = value - 1) {
            *dataCursor = *arg2;
            arg2 = arg2 + 1;
            dataCursor = dataCursor + 1;
          }
          switch(arg3) {
          case 0:
            return arg1;
          case 2:
            goto switchD_004b1045_caseD_2;
          case 3:
            goto switchD_004b1045_caseD_3;
          }
          goto switchD_004b1045_caseD_1;
        }
      }
    }
  }
  switch(value) {
  case 7:
    dataCursor[value - 7] = arg2[value - 7];
  case 6:
    dataCursor[value - 6] = arg2[value - 6];
  case 5:
    dataCursor[value - 5] = arg2[value - 5];
  case 4:
    dataCursor[value - 4] = arg2[value - 4];
  case 3:
    dataCursor[value - 3] = arg2[value - 3];
  case 2:
    dataCursor[value - 2] = arg2[value - 2];
  case 1:
    dataCursor[value - 1] = arg2[value - 1];
    arg2 = arg2 + value;
    dataCursor = dataCursor + value;
  }
  switch(arg3) {
  case 1:
switchD_004b1045_caseD_1:
    *(undefined1 *)dataCursor = *(undefined1 *)arg2;
    return arg1;
  case 2:
switchD_004b1045_caseD_2:
    *(undefined1 *)dataCursor = *(undefined1 *)arg2;
    *(undefined1 *)((int)dataCursor + 1) = *(undefined1 *)((int)arg2 + 1);
    return arg1;
  case 3:
switchD_004b1045_caseD_3:
    *(undefined1 *)dataCursor = *(undefined1 *)arg2;
    *(undefined1 *)((int)dataCursor + 1) = *(undefined1 *)((int)arg2 + 1);
    *(undefined1 *)((int)dataCursor + 2) = *(undefined1 *)((int)arg2 + 2);
    return arg1;
  }
jpt_memmove_004B1064:
  return arg1;
}

