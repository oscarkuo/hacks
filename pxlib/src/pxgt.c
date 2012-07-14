#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <paradox.h>

#define MAX_COL_NAME_LEN 64
#define JULIAN_CAL_OFFSET 1721425

int get_longest_column_name_length(pxhead_t* head) {
  int i, result=0;
  pxfield_t* fp = head->px_fields;

  for(i=0; i<head->px_numfields; ++i) {
    int len = strlen(head->px_fields[i].px_fname);
    if (len > result) result = len;
    fp++;
  }

  return (result > MAX_COL_NAME_LEN)? MAX_COL_NAME_LEN : result;
}

void pxdate_to_gregorian(char* buf, size_t size, long value) {
  int year, month, day;
  PX_SdnToGregorian(value + JULIAN_CAL_OFFSET, &year, &month, &day);
  snprintf(buf, size, "%4d-%2d-%2d", year, month, day);
}

void pxtimestamp_to_string(pxdoc_t* doc, char* buf, size_t size, double value) {
  char *str = PX_timestamp2string(doc, value, "Y-m-d H:i:s");
  strncpy(buf, str, size);
  doc->free(doc, str);
}

int to_string(char* buf, size_t size, pxdoc_t* doc, pxval_t* val) {
  if (val->isnull) {
    snprintf(buf, size, "(null)");
    return 0;
  }

  switch(val->type) {
  case pxfAlpha: 
    snprintf(buf, size, "%s", val->value.str.val);
    doc->free(doc, val->value.str.val);
    return 0;

  case pxfDate:
    pxdate_to_gregorian(buf, size, val->value.lval);
    return 0;

  case pxfTime:
  case pxfShort:
  case pxfAutoInc:
  case pxfLong:
  case pxfLogical:
    snprintf(buf, size, "%ld", val->value.lval);
    return 0;

  case pxfTimestamp:
    pxtimestamp_to_string(doc, buf, size, val->value.dval);
    return 0;

  case pxfCurrency:
  case pxfNumber:
    snprintf(buf, size, "%f", val->value.dval);
    return 0;    

  case pxfBLOb:
  case pxfGraphic:
  case pxfOLE:
  case pxfMemoBLOb:
  case pxfBCD:
  case pxfFmtMemoBLOb:
    snprintf(buf, size, "(Binary Data)");
    doc->free(doc, val->value.str.val);
    return 0;
  }

  snprintf(buf, size, "(Unknown Data Type)");
  return 1;
}

int main(int argc, char *argv[]) {
  pxdoc_t *pxdoc;

  if (argc < 3) {
    printf ("Usage: %s <filename>\n", argv[0]);
    return 0;
  }

  PX_boot();
  pxdoc = PX_new();

  if (!PX_open_file(pxdoc, argv[1])) {
    char* pend;
    int i, index = strtol(argv[2], &pend, 10);

    if (index < pxdoc->px_head->px_numrecords) {
      char buf[512], fmt[128];
      pxval_t** row = PX_retrieve_record(pxdoc, index);
      int field_len = get_longest_column_name_length(pxdoc->px_head);

      for (i=0; i<pxdoc->px_head->px_numfields; ++i) {
	to_string(buf, 512, pxdoc, row[i]);
	snprintf(fmt, 128, "%%%ds => %%s\n", field_len);
	printf(fmt, pxdoc->px_head->px_fields[i].px_fname, buf);
      }
    }
  } else {
    printf("Unable to open %s\n", argv[1]);
  }

  PX_delete(pxdoc);
  PX_shutdown();

  return 0;
}
