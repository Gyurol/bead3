#include "lista.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

lista::lista(Application *parent, int x, int y, int sx, int sy, vector<string> elemek, int lathato_db)
    : Widget(parent, x, y, sx, sy), _elemek(elemek), _lathato_db(lathato_db)
{
    kijelolve = false;
    _elso_lathato = 0;
    _kivalasztott = 0;
}

bool lista::is_selected(int mouse_x, int mouse_y) {
    return mouse_x >= _x && mouse_x < _x + _size_x && mouse_y >= _y && mouse_y < _y + (_size_y * _lathato_db);
}

void lista::draw() {
    for (int i = 0; i < _lathato_db; i++) {
        int y = _y + i * _size_y;

        if (_elso_lathato + i == _kivalasztott)
            gout << color(150,150,255);
        else
            gout << color(255,255,255);

        gout << move_to(_x, y) << box(_size_x, _size_y);

        if (_elso_lathato + i < (int)_elemek.size()) {
            gout << color(0,0,0)
                 << move_to(_x + 5, y + 20)
                 << text(_elemek[_elso_lathato + i]);
        }
    }
}

void lista::handle(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (is_selected(ev.pos_x, ev.pos_y)) {
            kijelolve = true;
            int idx = (ev.pos_y - _y) / _size_y;

            if (_elso_lathato + idx < (int)_elemek.size()) {
                _kivalasztott = _elso_lathato + idx;
            }
        }
    }

    if (kijelolve && ev.type == ev_mouse) {
        if (ev.button == btn_wheelup && _elso_lathato > 0)
            _elso_lathato--;

        if (ev.button == btn_wheeldown && _elso_lathato + _lathato_db < (int)_elemek.size())
            _elso_lathato++;
    }
}

int lista::get_ertek() {
    if (_elemek.empty()) return -1;
    if (_kivalasztott >= (int)_elemek.size()) return -1;
    return _kivalasztott;
}

void lista::set_elements(const vector<string>& uj) {
    _elemek = uj;
    reset_view();
}

void lista::reset_view() {
    _kivalasztott = 0;
    _elso_lathato = 0;
    kijelolve = false;
}

void lista::unselect() {
    kijelolve = false;
}
