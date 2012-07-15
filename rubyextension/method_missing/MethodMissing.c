#include <ruby.h>
#include <stdio.h>

VALUE classMethodMissing;

static VALUE t_method_missing(int argc, VALUE* argv) {
  VALUE name, s;
  rb_scan_args(argc, argv, "10", &name);
  s = rb_funcall(name, rb_intern("to_s"), 0);
  printf("%s\n", StringValueCStr(s));
  return Qnil;
}

static VALUE t_init(VALUE self) {
  return Qnil;
}

void Init_MethodMissing() {
  classMethodMissing = rb_define_class("MethodMissing", rb_cObject);
  rb_define_method(classMethodMissing, "initialize", t_init, 0);
  rb_define_method(classMethodMissing, "method_missing", t_method_missing, -1);
}
