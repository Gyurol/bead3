#include "graphics.hpp"
#include "application.hpp"
#include "lista.hpp"
#include "gomb.hpp"

#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace genv;

struct Rent {
    string car;
    string client;

    Rent(string c, string cl) {
        car = c;
        client = cl;
    }
};

vector<string> rent2str(vector<Rent> v) {
    vector<string> out;

    for (auto r : v)
        out.push_back(r.car + " - " + r.client);

    return out;
}

class MyApp : public Application {
    lista *l1, *l2, *l3;
    vector<string> kocsik;
    vector<string> berlok;
    vector<Rent> eredmeny;

    Gomb *g1, *g2;

public:
    MyApp() {
        betolt();

        berlok = {
            "ugyfel1","ugyfel2","ugyfel3","ugyfel4","ugyfel5"
        };

        l1 = new lista(this, 50, 50, 150, 30, kocsik, 5);
        l2 = new lista(this, 250, 50, 150, 30, berlok, 5);
        l3 = new lista(this, 450, 50, 200, 30, rent2str(eredmeny), 5);

        g1 = new Gomb(this, 100, 250, 100, 40, "berel", "to2");
        g2 = new Gomb(this, 250, 250, 100, 40, "vissza", "to1");
    }

    void rent() {
        int ci = l1->get_ertek();
        int ui = l2->get_ertek();

        if (ci != -1 && ui != -1) {
            eredmeny.push_back(Rent(kocsik[ci], berlok[ui]));
            kocsik.erase(kocsik.begin() + ci);
        }
    }

void back() {
        int ri = l3->get_ertek();

        if (ri != -1 && ri < eredmeny.size()) {
            kocsik.insert(kocsik.begin(), eredmeny[ri].car);
            eredmeny.erase(eredmeny.begin() + ri);
        }
    }

    void update() {
        l1->set_elements(kocsik);
        l3->set_elements(rent2str(eredmeny));
    }

    void action(string id) override {
        if (id == "to2") {
            rent();
            update();
        }

        if (id == "to1") {
            back();
            update();
        }
    }

    void betolt() {
        ifstream f("cars.csv");
        string s;
        getline(f, s);

        while (getline(f, s))
            kocsik.push_back(s);
    }
};

int main() {
    gout.open(800, 400);
    MyApp app;
    app.event_loop();
}
