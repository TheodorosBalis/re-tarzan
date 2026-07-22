#include "tarzan_ghidra_types.hpp"

// Address: 0x004406F0
// Label: CEntities::AllocEntityAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int
CEntities::AllocEntityAttachment(int entry,int payloadSize,undefined4 payloadTag,undefined4 *existingPayload)

{
  int attachment;
  undefined4 *attachmentPayload;
  int nextLink;
  int attachmentCursor;
  int *splitFreeBlock;
  uint freeBlockSize;
  uint allocatedBlockSize;
  uint alignedPayloadSize;
  
  alignedPayloadSize = payloadSize + 3U & 0xfffffffc;
  allocatedBlockSize = payloadSize + 0x1bU & 0xfffffffc;
  attachment = g_EntityAttachmentFreeBlockHead;
  while( true ) {
    if (attachment == 0) {
      *(byte *)(entry + 0x44) = *(byte *)(entry + 0x44) | 1;
      return (undefined4 *)0x0;
    }
    freeBlockSize = *(uint *)(attachment + 0x10) & 0xfffffffc;
    if ((int)alignedPayloadSize <= (int)freeBlockSize) break;
    attachment = *(int *)(attachment + 0xc);
  }
  if ((int)(allocatedBlockSize + 8) < (int)freeBlockSize) {
    attachmentPayload = *(undefined4 **)(attachment + 4);
    splitFreeBlock = (int *)(attachment + allocatedBlockSize);
    if (attachmentPayload != (undefined4 *)0x0) {
      *attachmentPayload = splitFreeBlock;
    }
    splitFreeBlock[1] = (int)attachmentPayload;
    *splitFreeBlock = attachment;
    *(int **)(attachment + 4) = splitFreeBlock;
    *(uint *)(attachment + 0x10) = alignedPayloadSize;
    splitFreeBlock[4] = freeBlockSize - allocatedBlockSize | 1;
    nextLink = *(int *)(attachment + 8);
    splitFreeBlock[2] = nextLink;
    if (nextLink != 0) {
      *(int **)(nextLink + 0xc) = splitFreeBlock;
    }
    nextLink = *(int *)(attachment + 0xc);
    splitFreeBlock[3] = nextLink;
    if (nextLink != 0) {
      *(int **)(nextLink + 8) = splitFreeBlock;
    }
    *(undefined4 *)(attachment + 8) = 0;
    *(undefined4 *)(attachment + 0xc) = 0;
  }
  else {
    *(uint *)(attachment + 0x10) = freeBlockSize;
    *(undefined4 *)(*(int *)(attachment + 8) + 0xc) = *(undefined4 *)(attachment + 0xc);
    if (*(int *)(*(int *)(attachment + 8) + 0xc) != 0) {
      *(int *)(*(int *)(attachment + 0xc) + 8) = *(int *)(attachment + 8);
    }
    *(undefined4 *)(attachment + 8) = 0;
    *(undefined4 *)(attachment + 0xc) = 0;
  }
  *(int *)(attachment + 0x14) = entry;
  nextLink = *(int *)(entry + 8);
  while (attachmentCursor = nextLink, attachmentCursor != 0) {
    entry = attachmentCursor;
    nextLink = *(int *)(attachmentCursor + 8);
  }
  attachmentPayload = (undefined4 *)(attachment + 0x18);
  if (existingPayload == (undefined4 *)0x0) {
    *attachmentPayload = payloadTag;
    *(int *)(attachment + 0x1c) = entry;
    *(undefined4 *)(attachment + 0x20) = 0;
    *(undefined4 **)(entry + 8) = attachmentPayload;
    return attachmentPayload;
  }
  *existingPayload = payloadTag;
  existingPayload[1] = entry;
  *(undefined4 **)(entry + 8) = attachmentPayload;
  return attachmentPayload;
}

