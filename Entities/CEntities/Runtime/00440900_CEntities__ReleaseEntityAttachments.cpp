#include "tarzan_ghidra_types.hpp"

// Address: 0x00440900
// Label: CEntities::ReleaseEntityAttachments
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ReleaseEntityAttachments(uint *entry)

{
  uint value;
  uint *dataCursor;
  uint *dataCursor2;
  uint *dataCursor3;
  
  dataCursor3 = (uint *)entry[2];
  dataCursor = entry;
  while (dataCursor2 = dataCursor3, dataCursor2 != (uint *)0x0) {
    dataCursor = dataCursor2;
    dataCursor3 = (uint *)dataCursor2[2];
  }
  value = dataCursor[1];
  while (value != 0) {
    CEntities::FreeEntityAttachment(dataCursor);
    dataCursor = (uint *)dataCursor[1];
    value = dataCursor[1];
  }
  *entry = *entry & 0xff;
  return;
}

