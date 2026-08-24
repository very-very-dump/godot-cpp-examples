#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {
    class Test : public Node {
        GDCLASS(Test, Node)
        protected:
            static void _bind_methods();
        private:
            String manega = "Blud Bald Bold Belt";
        public:
            String get_manega() const;
            void set_manega(const String &newType);
            void say_hello();
    };
}


