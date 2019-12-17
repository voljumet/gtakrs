#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace GTA{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine{
        std::stack<StateRef> _states;
        StateRef _newState;
        bool _isRemoving{};
        bool _isAdding{};
        bool _isReplacing{};

    public:
        StateMachine()= default;
        ~StateMachine()= default;

        void AddState(StateRef newState, bool isReplacing = true );
        void RemoveState();
        void ProcessStateChanges();

        StateRef &GetActiveState();
    };
}