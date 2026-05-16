#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "widget.hpp"
#include <vector>
using namespace std;

class Application{
protected:
    vector<Widget*> _widgets;


public:
    virtual void action(string id) = 0;
    virtual ~Application(){}
    void register_widget(Widget *w);
    void event_loop();
};





#endif // APPLICATION_HPP
