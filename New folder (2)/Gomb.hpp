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
    virtual void draw() override;
    virtual void handle(event ev) override;
    virtual bool is_selected(int mouse_x, int mouse_y) override;
    virtual int get_ertek() override;
    virtual void unselect() override;
};

#endif
