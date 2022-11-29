#include "ruby/ruby.h"
#include "ruby/encoding.h"
#include "library.h"
#include "heron.h"

static VALUE string(VALUE self, VALUE value) {
    Check_Type(value, T_STRING);
    char* pointer_in = RSTRING_PTR(value);
    char* pointer_out = string_from_library(pointer_in);
    return rb_str_new2(pointer_out);
}

static VALUE number(VALUE self, VALUE value) {
    Check_Type(value, T_FIXNUM);

    int number_in = NUM2INT(value);
    int number_out = number_from_library(number_in);
    return INT2NUM(number_out);
}

static VALUE double(VALUE self, VALUE value) {
    Check_Type(value, T_FLOAT);
    double double_in = DBL2NUM(value);
    double double_out = double_from_library(double_in);
    return FL
}

static VALUE boolean(VALUE self, VALUE value) {
    int boolean_in = RTEST(value);
    int boolean_out = boolean_from_library(boolean_in);
    if (boolean_out == 1) {
        return Qtrue;
    } else {
        return Qfalse;
    }
}

void Init_extension(void) {
    VALUE RHeron = rb_define_module("RHeron");
    VALUE NativeHelpers = rb_define_class_under(RHeron, "NativeHelpers", rb_cObject);

    rb_define_method(RHeron, "heron", number, 1);
    rb_define_method(RHeron, "verify_triangle", boolean, 1);
    rb_define_singleton_method(NativeHelpers, "string", string, 1);
    rb_define_singleton_method(NativeHelpers, "number", number, 1);
    rb_define_singleton_method(NativeHelpers, "boolean", boolean, 1);
}
