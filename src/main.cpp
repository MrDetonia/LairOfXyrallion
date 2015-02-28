#include "game.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Game lox;

    return lox.Execute();
}
