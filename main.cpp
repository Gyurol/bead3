#include "application.hpp"
#include "board.hpp"
#include "Gomb.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum JatekAllapot { KEZDOKEPERNYO, JATEK, GAMEOVER };

class Myapp : public Application {
    JatekAllapot allapot;
    board *b1;
    Gomb *startGomb;
    Gomb *ujraGomb;

public:
    Myapp() {
        genv::gout.open(1200, 1200);
        allapot = KEZDOKEPERNYO;

        startGomb = new Gomb(this, 500, 500, 200, 50, "Jatek Inditasa", "start_btn");
        b1 = new board(this, 100, 150, 1000, 1000);
        ujraGomb = new Gomb(this, 500, 600, 200, 50, "Ujra", "ujra_btn");

        startGomb->lathato = true;
        b1->lathato = false;
        ujraGomb->lathato = false;
    }

    void action(std::string id) override {
        if (id == "start_btn") {
            int jatekos1 = 1;
            int jatekos2 = 2;
            allapot = JATEK;
            startGomb->lathato = false;
            b1->lathato = true;
            if (b1->nyeres(jatekos1)) {allapot = GAMEOVER;}
            if (b1->nyeres(jatekos2) ){allapot = GAMEOVER;}
        }
        else if (id == "ujra_btn") {
            allapot = JATEK;
            ujraGomb->lathato = false;
            b1->lathato = true;
        }
        else if (id == "jatek_vege") {
            allapot = GAMEOVER;
            ujraGomb->lathato = true;
        }
    }
};

int main()
{
    srand(time(NULL));
    Myapp app;
    app.event_loop();
    return 0;
}
