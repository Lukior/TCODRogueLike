#include "include/libtcod.hpp"
#include "src/actor.h"
#include "src/map.h"
#include "src/engine.h"

Engine engine;

int main() {
    while ( !TCODConsole::isWindowClosed() ) {
        engine.update();
        engine.render();
        TCODConsole::flush();
    }
    return 0;
}
