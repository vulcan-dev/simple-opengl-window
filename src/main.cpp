#include "window/window.h"

int main() {
    window c_window(800, 600, "Hello World");
    while (c_window.isRunning()) {
        c_window.update();
        c_window.render();
    }

    return 0;
}
