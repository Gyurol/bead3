#include "graphics.hpp"
#include "application.hpp"
#include <vector>

using namespace genv;

void Application::event_loop()
{
    gout.open(1200, 1200);
    event ev;
    int focus = -1;

    if (!_widgets.empty()) {
        focus = 0;
    }

    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (size_t i = 0; i < _widgets.size(); i++) {
                if (_widgets[i]->lathato && _widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                }
            }
        }

        if (ev.type == ev_mouse) {
            for (Widget * w : _widgets) {
                if (w->lathato) {
                    w->handle(ev);
                }
            }
        } else {
            if (focus != -1 && _widgets[focus]->lathato) {
                _widgets[focus]->handle(ev);
            }
        }

        gout << move_to(0, 0) << color(0, 0, 0) << box(1200, 1200);

        for (Widget * w : _widgets) {
            if (w->lathato) {
                w->draw();
            }
        }

        gout << refresh;
    }
}

void Application::register_widget(Widget *w)
{
    _widgets.push_back(w);
}
