#include "application.hpp"

using namespace genv;

Application::Application() {}

void Application::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            int uj_focus = -1;

            for (size_t i = 0; i < _widgets.size(); i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    uj_focus = i;
                }
            }

            if (focus != uj_focus) {
                if (focus != -1) {
                    _widgets[focus]->unselect();
                }
                focus = uj_focus;
            }
        }

        if(ev.type == ev_key && ev.keycode == key_enter){
            action("enter");
        }

        if(ev.type == ev_key && ev.keycode == key_space){
            action("space");
        }

        if (focus != -1) {
            _widgets[focus]->handle(ev);
        }

        gout << move_to(0, 0) << color(0, 0, 0) << box(800, 400);

        for (Widget * w : _widgets) {
            w->draw();
        }

        gout << refresh;
    }
}

void Application::register_widget(Widget *w)
{
    _widgets.push_back(w);
}
