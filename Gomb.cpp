#include "gomb.hpp"
#include <string>
#include "application.hpp"

using namespace genv;
using namespace std;

Gomb::Gomb(Application *parent, int x, int y, int sx, int sy, string szoveg, string id)
    : Widget(parent, x, y, sx, sy), _szoveg(szoveg), _id(id)
{
    kattintva = false;
}

bool Gomb::is_selected(int mouse_x, int mouse_y) {
    return mouse_x >= _x && mouse_x < _x + _size_x && mouse_y >= _y && mouse_y < _y + (_size_y);
}

void Gomb::draw() {
    if(kattintva){
        gout << color(122,122,255)
             << move_to(_x+2, _y+2)
             << box(_size_x+2, _size_y+2);

        gout << color(0,0,0)
             << move_to(_x + 12, _y + _size_y/2 +2)
             << text(_szoveg);
    } else {
        gout << color(60,60,60)
             << move_to(_x+2, _y+2)
             << box(_size_x+2, _size_y+2);

        gout << color(122,122,255)
             << move_to(_x, _y)
             << box(_size_x, _size_y);

        gout << color(0,0,0)
             << move_to(_x + 10, _y + _size_y/2)
             << text(_szoveg);
    }
}

void Gomb::unselect() {
    kattintva = false;
}

void Gomb::handle(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left) {
        if(is_selected(ev.pos_x, ev.pos_y)) {
            kattintva = true;
            _parent->action(_id);
        }
    }
    else if(ev.type == ev_mouse && ev.button == -btn_left) {
        kattintva = false;
    }
}
int Gomb::get_ertek(int d, int a) {
    return 0;
}
