#include <stdio.h>
#include <paradox.h>
 
char* get_column_type_name(char ftype) {
  switch (ftype) {
  case pxfAlpha:
    return "Alpha";
  case pxfDate: 
    return "Date";
  case pxfShort: 
    return "Short";
  case pxfAutoInc:
    return "AutoInc";
  case pxfLong: 
    return "Long";
  case pxfTimestamp: 
    return "Timestamp";
  case pxfTime:
    return "Time";
  case pxfCurrency:
    return "Currency";
  case pxfNumber:
    return "Number";
  case pxfLogical:
    return "Logical";
  case pxfBLOb:
    return "BlOb";
  case pxfGraphic:
    return "Graphic";
  case pxfOLE:
    return "OLE";
  case pxfMemoBLOb:
    return "MemoBLOb";
  case pxfFmtMemoBLOb:
    return "FmtMemoBLOb";
  case pxfBCD: 
    return "BCD";
  case pxfBytes:
    return "Bytes";
  default:
    return "(Unknown)";
  }
}

void dump_table(pxhead_t* head) {
  int i;
  pxfield_t* fp = head->px_fields;
  for(i=0; i<head->px_numfields; ++i) {
    printf("%12s %6d %s\n", 
	   get_column_type_name(fp->px_ftype),
	   fp->px_flen,
	   fp->px_fname);
    fp++;
  }
}

int main(int argc, char *argv[]) {
  pxdoc_t *pxdoc;

  if (argc < 2) {
    printf ("Usage: %s <filename>\n", argv[0]);
    return 0;
  }

  PX_boot();
  pxdoc = PX_new();

  if (!PX_open_file(pxdoc, argv[1])) {
    dump_table(pxdoc->px_head);
  } else {
    printf("Unable to open %s\n", argv[1]);
  }

  PX_delete(pxdoc);
  PX_shutdown();

  return 0;
}
