#pragma once

/// Definisjon på hva en state er, denne loades inn i alle andre states

namespace GTA{
    class State {
    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause(){ }
        virtual void Resume(){ }


    };
}