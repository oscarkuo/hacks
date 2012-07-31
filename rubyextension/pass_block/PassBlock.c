#include <ruby.h>

static const char* data[3][2] = {
  { "row0", "row0 value" }, 
  { "row1", "row1 value" }, 
  { "row2", "row2 value" }
};
  

static VALUE classPassBlock;

static VALUE t_init(VALUE self) {
  return self;
}

static VALUE t_find(VALUE self) {
  int i;
  char buf[512];
  VALUE result;

  RETURN_ENUMERATOR(self, 0, NULL);

  for (i=0; i<3; ++i) {
    snprintf(buf, 512, "before yield, index: %d", i);
    rb_funcall(rb_stdout, rb_intern("puts"), 1, rb_str_new2(buf));
    result = rb_yield(rb_str_new2(data[i][0]));
    snprintf(buf, 512, "after yield, index: %d", i);
    rb_funcall(rb_stdout, rb_intern("puts"), 1, rb_str_new2(buf));
    if (RTEST(result)) {
      return rb_str_new2(data[i][1]);
    }
  }

  return Qnil;
}

void Init_PassBlock() {
  classPassBlock = rb_define_class("PassBlock", rb_cObject);
  rb_define_method(classPassBlock, "initialize", t_init, 0);
  rb_define_method(classPassBlock, "find", t_find, 0);
}
