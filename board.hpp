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
    bool nyeres(int o);
    bool check_vizszintes(int c);
    bool check_fuggoleges(int k);
    bool check_atlo_1(int n);
    bool check_atlo_2(int v);
};




#endif // BOARD_HPP
