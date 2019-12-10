#include <iostream>
#include "StateMachine.h"

/// Statemachine Settings!!

namespace GTA{
    void StateMachine::AddState(GTA::StateRef newState, bool isReplacing) {     /// Config for AddState when creating a new state
        this->_isAdding = true;
        this->_isReplacing = isReplacing;

        this->_newState = std::move(newState);
    }

    void StateMachine::RemoveState() {      /// Config for RemoveState when creating a new stateClass
        this->_isRemoving = true;
    }

    void StateMachine::ProcessStateChanges() {          /// Config for statechange
        if(this->_isRemoving && !this->_states.empty()){
            this->_states.pop();

            if (!this->_states.empty()){
                this->_states.top()->Resume();
            }
            this->_isRemoving = false;
        }

        if (this->_isAdding){
            if (!this->_states.empty()){ if (this->_isReplacing){ this->_states.pop(); } else { this->_states.top()->Pause(); } }

            this->_states.push(std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    }

    StateRef &StateMachine::GetActiveState() {         /// Config for Getting last active state
        return this->_states.top();
    }
}