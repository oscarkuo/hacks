#include <stdio.h>
#include <paradox.h>

int main(int argc, char *argv[]) {
  pxdoc_t *pxdoc;

  if (argc < 2) {
    printf ("Usage: %s <filename>\n", argv[0]);
    return 0;
  }

  PX_boot();
  pxdoc = PX_new();

  if (!PX_open_file(pxdoc, argv[1])) {
    printf("%s has %d records\n", argv[1], pxdoc->px_head->px_numrecords);
  } else {
    printf("Unable to open %s\n", argv[1]);
  }

  PX_delete(pxdoc);
  PX_shutdown();

  return 0;
}
