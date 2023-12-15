#pragma once
#include <string>
#include <vector>

enum StateLabel
{
    UNDEFINED,
    VAR
};

class State
{
public:
    State(std::string name, std::vector<State *> next_states, StateLabel label = StateLabel::UNDEFINED)
    {
        this->name = name;
        this->next_states = next_states;
    }

    std::vector<State *> next_states;
    StateLabel label;
    std::string name;

    StateLabel finish()
    {
        return label;
    };

    void link(State *next_state)
    {
        this->next_states.push_back(next_state);
    }
};

class EndState : public State
{
public:
    EndState(char *name, std::vector<State *> next_states, StateLabel label) : State(name, next_states)
    {
        this->label = label;
    }
};

void link_states(std::vector<State *> &states)
{
    states[0]->link(states[1]);
    states[1]->link(states[2]);
    states[2]->link(states[3]);
    states[3]->link(states[4]);
}

class StateMachine
{
public:
    StateMachine(std::vector<State *> states)
    {
        this->states = states;
        current_state = states[0];
        link_states(states);
    }

    std::vector<State *> states;
    State *current_state;
};
