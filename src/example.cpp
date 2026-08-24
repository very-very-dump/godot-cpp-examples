#include "example.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

void Test::_bind_methods() {
    ClassDB::bind_method(D_METHOD("say_hello"), &Test::say_hello);

    ClassDB::bind_method(D_METHOD("get_manega"), &Test::get_manega);
    ClassDB::bind_method(D_METHOD("set_manega", "newType"), &Test::set_manega);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "manega"), "set_manega", "get_manega");
}

void Test::say_hello() {
    UtilityFunctions::print("Hello");
}

String Test::get_manega() const {
    return manega;
}

void Test::set_manega(const String &newType) {
    manega = newType;
}
