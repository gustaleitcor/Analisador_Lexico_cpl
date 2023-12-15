#include <iostream>
#include <fstream>
#include "State.cpp"

extern StateMachine state_machine;

int main()
{

    char c;
    std::fstream file("code.txt");
    unsigned int line = 1;

    while (!file.eof())
    {
        file.get(c);

        if (c == '\n')
        {
            line++;
        }

        if (c == ' ' || c == '\n') // numero:=12
        {
            if (state_machine.current_state->finish() != StateLabel::UNDEFINED)
            {
                std::cout << "Comando reconhecido" << std::endl;
                state_machine.current_state = state_machine.states[0];
                continue;
            }
            else
            {
                std::cout << "terminou em estado não reconhecido" << std::endl;
            }
        }

        for (auto state : state_machine.current_state->next_states)
        {
            if (state->name.find(c) != std::string::npos)
            {
                state_machine.current_state = state;
                std::cout << state->name << " : " << c << std::endl;
                break;
            }
            else
            {
                std::cout << "me perdi: " << c << std::endl;
            }
        }
    }

    std::cout << std::endl;
}