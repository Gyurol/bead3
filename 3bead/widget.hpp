#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include <string>
#include "graphics.hpp"
class Application;

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    bool kijelolve;
    Application * _parent;
public:
    Widget(Application *parent, int x, int y, int sx, int sy);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void unselect();
    virtual int get_ertek(int d, int a) = 0;

};

#endif // WIDGETS_HPP_INCLUDED
