#include "State.h"
#include <array>
#include "State.h"

std::vector<State *> states = {
    new State("ç", {}),
    new State("v", {}),
    new State("a", {}),
    new EndState("r", {}, StateLabel::VAR),
    new State("abcdefghijklmnopqrstuvwxyz", {}),
};

StateMachine state_machine(states);
