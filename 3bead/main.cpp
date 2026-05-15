#include "graphics.hpp"
#include "application.hpp"
#include "board.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Myapp : public Application {
    board *b1;


public:
    Myapp(){
        b1 = new board(this, 100, 150, 1000, 1000);
    //mezok meghivasa, deklaralasa



    }
// lehetseges fgvnyek
void action(std::string id) override {};

};



int main()
{
    srand(time(NULL));
    gout.open(1200,1200);
    Myapp app;
    app.event_loop();

}
