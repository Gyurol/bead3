#ifndef LISTA_HPP
#define LISTA_HPP

#include "widget.hpp"
#include <vector>
#include <string>

class lista : public Widget {
protected:
    std::vector<std::string> _elemek;
    int _lathato_db;
    int _elso_lathato;
    int _kivalasztott;
    bool kijelolve;

public:
    lista(Application *parent, int x, int y, int sx, int sy, std::vector<std::string> elemek, int lathato_db);
    void draw() override;
    void handle(genv::event ev) override;
    bool is_selected(int mouse_x, int mouse_y) override;
    void unselect() override;
    int get_ertek() override;
    void set_elements(const std::vector<std::string>& uj);
    void reset_view();
};

#endif
