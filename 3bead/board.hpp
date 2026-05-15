#ifndef BOARD_HPP
#define BOARD_HPP
#include "widget.hpp"
#include <string>
using namespace genv;
using namespace std;
class board : public Widget
{
protected:
    std::vector<std::vector<int>> palya;
    int aktualis_jatekos;
    int hover_sor, hover_oszlop;
public:
    board(Application *parent, int, int, int, int);
    void draw() override;
    void handle(genv::event) override;
    int get_ertek(int d, int a);
    int turn();
};




#endif // BOARD_HPP
