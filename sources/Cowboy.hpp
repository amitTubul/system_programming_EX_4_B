#pragma once
#include "Character.hpp"


namespace ariel{
    class Cowboy : public Character{
    private:
        int _bulletAmount;

    public:
        Cowboy(std::string name,Point location);
        ~Cowboy() override = default;
        void shoot(Character* other);
        bool hasboolets() const;
        void reload();
        std::string print() const override;
        // for tidy check
        Cowboy(const Cowboy&) = delete;
        Cowboy& operator=(const Cowboy&) = delete;
        Cowboy(Cowboy&&) = delete;
        Cowboy& operator=(Cowboy&&) = delete;

    };
}