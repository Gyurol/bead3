#include "graphics.hpp"
#include "board.hpp"
#include "widget.hpp"
#include <algorithm>
#include <cstdlib>
#include "application.hpp"
using namespace std;
using namespace genv;




board::board(Application *parent, int x, int y, int sx, int sy) : Widget(parent, x, y, sx, sy)
{
    kijelolve = false;
    palya = vector<vector<int>>(6, vector<int>(7, 0));
    aktualis_jatekos = (rand() % 2) + 1;

    hover_sor = -1;
    hover_oszlop = -1;
}

void board::draw()
{
    gout << color(255, 255, 255) << move_to(_x, _y) << box(_size_x, _size_y);

    int cell_w = _size_x / 7;
    int cell_h = _size_y / 6;

    for (int sor = 0; sor < 6; sor++) {
        for (int oszlop = 0; oszlop < 7; oszlop++) {
            int cell_x = _x + (oszlop * cell_w);
            int cell_y = _y + (sor * cell_h);

            int cella_tipus = palya[sor][oszlop];

            if (cella_tipus == 0 && oszlop == hover_oszlop) {
                if (sor == 5 || palya[sor + 1][oszlop] != 0) {
                    if (aktualis_jatekos == 1) cella_tipus = 3;
                    else if (aktualis_jatekos==0) cella_tipus=0;
                    else cella_tipus = 4;
                }
            }

            if (cella_tipus == 0) {
                gout << color(50, 50, 50);
            } else if (cella_tipus == 1) {
                gout << color(200, 0, 0);
            } else if (cella_tipus == 2) {
                gout << color(0, 0, 200);
            } else if (cella_tipus == 3) {
                gout << color(100, 0, 0);
            } else if (cella_tipus == 4) {
                gout << color(0, 0, 100);
            }

            int sugar = min(cell_w, cell_h) / 2 - 4;
            int cx = cell_x + cell_w / 2;
            int cy = cell_y + cell_h / 2;

            for (int i = -sugar; i <= sugar; i++) {
                for (int j = -sugar; j <= sugar; j++) {
                    if (i*i + j*j <= sugar*sugar) {
                        gout << move_to(cx + i, cy + j) << dot;
                    }
                }
            }
        }
    }
}

void board::handle(event ev)
{
    if (ev.type == ev_mouse) {
        if (is_selected(ev.pos_x, ev.pos_y)) {
            int cell_w = _size_x / 7;
            hover_oszlop = (ev.pos_x - _x) / cell_w;

            if (ev.button == btn_left) {
                for (int i = 5; i >= 0; i--) {
                    if (palya[i][hover_oszlop] == 0) {
                        palya[i][hover_oszlop] = aktualis_jatekos;
                        if (nyeres(aktualis_jatekos)){
                                _parent->action("jatek_vege");
                        }
                        aktualis_jatekos = (aktualis_jatekos == 1) ? 2 : 1;
                        break;
                    }
                }
            }
            }
        } else {
            hover_oszlop = -1;
        }

    }

bool board::check_vizszintes(int jatekos) {
    for (int sor = 0; sor < 6; sor++) {
        for (int oszlop = 0; oszlop < 4; oszlop++) {
            if (palya[sor][oszlop] == jatekos &&
                palya[sor][oszlop+1] == jatekos &&
                palya[sor][oszlop+2] == jatekos &&
                palya[sor][oszlop+3] == jatekos) {
                return true;
            }
        }
    }
    return false;
}

bool board::check_fuggoleges(int jatekos) {
    for (int sor = 0; sor < 3; sor++) {
        for (int oszlop = 0; oszlop < 7; oszlop++) {
            if (palya[sor][oszlop] == jatekos &&
                palya[sor+1][oszlop] == jatekos &&
                palya[sor+2][oszlop] == jatekos &&
                palya[sor+3][oszlop] == jatekos) {
                return true;
            }
        }
    }
    return false;
}

bool board::check_atlo_1(int jatekos) {
    for (int sor = 0; sor < 3; sor++) {
        for (int oszlop = 0; oszlop < 4; oszlop++) {
            if (palya[sor][oszlop] == jatekos &&
                palya[sor+1][oszlop+1] == jatekos &&
                palya[sor+2][oszlop+2] == jatekos &&
                palya[sor+3][oszlop+3] == jatekos) {
                return true;
            }
        }
    }
    return false;
}

bool board::check_atlo_2(int jatekos) {
    for (int sor = 3; sor < 6; sor++) {
        for (int oszlop = 0; oszlop < 4; oszlop++) {
            if (palya[sor][oszlop] == jatekos &&
                palya[sor-1][oszlop+1] == jatekos &&
                palya[sor-2][oszlop+2] == jatekos &&
                palya[sor-3][oszlop+3] == jatekos) {
                return true;
            }
        }
    }
    return false;
}



bool board::nyeres(int jatekos) {
    if (check_vizszintes(jatekos)) return true;
    if (check_fuggoleges(jatekos)) return true;
    if (check_atlo_1(jatekos)) return true;
    if (check_atlo_2(jatekos)) return true;

    return false;
}


int board::get_ertek(int sor, int oszlop) {
    return palya[sor][oszlop];
}

void board::board_ujra()
{
    for (int sor = 0; sor < 6; sor++) {
        for (int oszlop = 0; oszlop < 7; oszlop++) {
            palya[sor][oszlop] = 0;
        }
    }
    aktualis_jatekos = (rand() % 2) + 1;
    hover_sor = -1;
    hover_oszlop = -1;
}
