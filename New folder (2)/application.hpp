#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include <string>

class Application {
protected:
    std::vector<Widget*> _widgets;

public:
    virtual void action(std::string id) = 0;
    Application();
    virtual ~Application() {}
    void register_widget(Widget *w);
    void event_loop();
};

#endif
