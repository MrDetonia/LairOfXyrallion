#include "common.hpp"
#include "state.hpp"
#include "game.hpp"

int main(/*int argc, char* argv[]*/) {
    /* initialise random seed */
    srand(time(NULL));

    /* initialise state machine */
    std::vector<State*> states;
    Game lox;
    states.push_back(&lox);

    /* game loop */
    while(states[0]->_State() != STATE_EXIT) {
        states[states[0]->_State()]->Draw();
        states[states[0]->_State()]->Update();
    }
}
