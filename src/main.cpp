#include "common.hpp"
#include "state.hpp"
#include "menu_main.hpp"
#include "game.hpp"

int main(/*int argc, char* argv[]*/) {
    /* initialise random seed */
    srand(time(NULL));

    /* initialise state machine */
    State* states[STATE_EXIT];
    MenuMain menu;
    Game lox;

    states[0] = &menu;
    states[1] = &lox;

    /* game loop */
    while(states[0]->_State() != STATE_EXIT) {
        states[states[0]->_State()]->Draw();
        states[states[0]->_State()]->Update();
    }
}
