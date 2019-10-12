#pragma once

class PipRelay 
{
    public:
        PipRelay(const int pin);
        virtual ~PipRelay();

        void on();
        void off();
        
    private:
        int    m_pin;
};
