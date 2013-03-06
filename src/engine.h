#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

class Engine {
public :
    TCODList<Actor *> actors;
    Actor *player;
    Map &map;

    Engine();
    ~Engine();
    void update();
    void render();
    void closeDoor();
};

extern Engine engine;


#endif // ENGINE_H_INCLUDED
