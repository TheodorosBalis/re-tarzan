#include "tarzan_ghidra_types.hpp"

// Address: 0x004407F0
// Label: CEntities::FreeEntityAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::FreeEntityAttachment(uint *attachmentPayload)

{
  uint nextPayloadLink;
  uint nextNextPayloadLink;
  uint *nextBlockHeader;
  undefined *freeListNext;
  undefined *nextFreeBlock;
  uint *previousBlockHeader;
  uint *blockHeader;
  undefined *freeListCursor;
  uint mergedBlockSize;
  
  if ((g_EntityAttachmentHeapStart < attachmentPayload) && (attachmentPayload < g_EntityAttachmentHeapEnd)) {
    previousBlockHeader = (uint *)attachmentPayload[-1];
    blockHeader = attachmentPayload + -6;
    mergedBlockSize = attachmentPayload[-2];
    if (previousBlockHeader != (uint *)0x0) {
      *previousBlockHeader = *previousBlockHeader & (uint)((*attachmentPayload & 0xffffff00) == 0);
    }
    nextPayloadLink = attachmentPayload[1];
    if ((nextPayloadLink != 0) && (nextNextPayloadLink = attachmentPayload[2], *(uint *)(nextPayloadLink + 8) = nextNextPayloadLink, nextNextPayloadLink != 0)) {
      *(uint *)(attachmentPayload[2] + 4) = nextPayloadLink;
    }
    previousBlockHeader = (uint *)attachmentPayload[-5];
    freeListCursor = &g_EntityAttachmentHeapSentinel;
    if ((previousBlockHeader != (uint *)0x0) && ((previousBlockHeader[4] & 1) != 0)) {
      mergedBlockSize = mergedBlockSize + 0x18 + (previousBlockHeader[4] & 0xfffffffc);
      *(uint *)(previousBlockHeader[2] + 0xc) = previousBlockHeader[3];
      if (*(int *)(previousBlockHeader[2] + 0xc) != 0) {
        *(uint *)(previousBlockHeader[3] + 8) = previousBlockHeader[2];
      }
      freeListCursor = (undefined *)previousBlockHeader[2];
      previousBlockHeader = (uint *)previousBlockHeader[1];
    }
    nextBlockHeader = (uint *)*blockHeader;
    if ((nextBlockHeader != (uint *)0x0) && ((nextBlockHeader[4] & 1) != 0)) {
      mergedBlockSize = mergedBlockSize + 0x18 + (nextBlockHeader[4] & 0xfffffffc);
      *(uint *)(nextBlockHeader[2] + 0xc) = nextBlockHeader[3];
      if (*(int *)(nextBlockHeader[2] + 0xc) != 0) {
        *(uint *)(nextBlockHeader[3] + 8) = nextBlockHeader[2];
      }
      freeListCursor = (undefined *)nextBlockHeader[2];
      blockHeader = nextBlockHeader;
    }
    blockHeader[4] = mergedBlockSize | 1;
    nextFreeBlock = *(undefined **)(freeListCursor + 0xc);
    while ((freeListNext = nextFreeBlock, freeListNext != (undefined *)0x0 && (*(uint *)(freeListNext + 0x10) <= mergedBlockSize))) {
      freeListCursor = freeListNext;
      nextFreeBlock = *(undefined **)(freeListNext + 0xc);
    }
    blockHeader[1] = (uint)previousBlockHeader;
    if (previousBlockHeader != (uint *)0x0) {
      *previousBlockHeader = (uint)blockHeader;
    }
    mergedBlockSize = *(uint *)(freeListCursor + 0xc);
    blockHeader[3] = mergedBlockSize;
    if (mergedBlockSize != 0) {
      *(uint **)(mergedBlockSize + 8) = blockHeader;
    }
    *(uint **)(freeListCursor + 0xc) = blockHeader;
    blockHeader[2] = (uint)freeListCursor;
  }
  return;
}

