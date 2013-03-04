#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class Actor {
public :

    // Constructor, destructor
    Actor(int x, int y, int actorChar, const TCODColor &actorColor);
    Actor(int x, int y, int actorChar, const TCODColor &actorColor, bool isClosed);

    // Accessors
    int getPosx() const;
    int getPosy() const;
    int getChar() const;
    TCODColor getColor() const;

    //Modifiers
    void setPosx(int newX);
    void setPosy(int newY);
    void setChar(int newChar);
    void setColor(TCODColor newColor);

    //Walk fcts
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    //Use fcts
    void setClosed();

    // render fonction
    void render() const;

private :

    bool isClosed;
    int x,y; // position on map
    int actorChar; // ascii code
    TCODColor actorColor; // color

};


#endif // ACTOR_H_INCLUDED
