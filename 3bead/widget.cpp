#include "widget.hpp"
#include "application.hpp"
#include "graphics.hpp"
#include <cstdlib>
#include <ctime>

using namespace genv;

Widget::Widget(Application *parent, int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy), _parent(parent)
{
    parent->register_widget(this);
    kijelolve = false;
}

void Widget::unselect()
{
    kijelolve = false;
}

bool Widget::is_selected(int mx, int my)
{
    return (mx>=_x && mx< _size_x + _x && my >= _y && my < _size_y+_y);
}


