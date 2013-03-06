#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

struct Tile {
    bool canWalk; // can we walk through this tile?
    char tileChar; // ASCII char ?
    TCODColor tileBackgroundColor; //background color
    TCODColor tileForegroundColor; //foreground color
    Tile() : canWalk(true), tileChar('.'), tileBackgroundColor(TCODColor::darkestGrey), tileForegroundColor(TCODColor::grey) {}
};

class Map {	
public :
    // Accessors
	static inline Map &getInstance()
	{
		return *instance;
	}
	
	static inline void initMap(int width, int height)
	{
		instance = new Map(width, height);
	}
	
    bool isPassable(int x, int y) const;
    int getChar (int x, int y) const;
    int getMapWidth () const;
    int getMapHeight () const;
    TCODColor getBackgroundColor (int x, int y) const;
    TCODColor getForegroundColor (int x, int y) const;

    // Modifiers
    void setPassable (int x, int y, bool passable);
    void setChar (int x, int y, int newChar);
    void setBackgroundColor (int x, int y, TCODColor newColor);
    void setForegroundColor (int x, int y, TCODColor newColor);

    // render fct
    void render() const;

private :
	static Map *instance;

	// Constructor, destructor
	Map(int width, int height);
	~Map();

    int width,height;
    Tile *tiles;
    void setWall(int x, int y);
};
#endif // MAP_H_INCLUDED
