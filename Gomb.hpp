#ifndef GOMB_HPP
#define GOMB_HPP

#include "widget.hpp"
#include <string>

using namespace genv;
using namespace std;

class Gomb : public Widget{
protected:
    string _szoveg;
    bool kattintva;
    string _id;

public:
    Gomb(Application *parent,int x,int y,int sx,int sy,string szoveg,string id);
    void draw() override;
    void handle(event ev) override;
    bool is_selected(int mouse_x, int mouse_y) override;
    void unselect() override;
    int get_ertek(int d, int a) override;
};

#endif
