#include <iostream>

class Player {
    int score = 5;
public:
    Player() {
        score = 10;
    }
    // Player(int _score) {
    //     score = _score;
    // }
    // Player(const Player& other) {
    //     score = other.score;
    // }
    // Player& operator=(const Player& other) {
    //     if (this != &other) {
    //         score = other.score;
    //     }
    //     return *this;
    // }
    void setScore(int _score) {
        score = _score;
    }
    int getScore() const {
        return score;
    }
    void present() {
        std::cout << "Player: score: " << score << '\n';  
    }
    virtual void print() {
        std::cout << "Hi, I am a PLayer!" << '\n';
    }
    bool operator>(const Player& other) {
        return score > other.score;
    }
};

class Hero : public Player {
    int power = 15;
public:
    Hero() {
        power = 20;
    }
    // Hero(int _power) {
    //     power = _power;
    // }
    // Hero(const Hero& other):Player(other) {
    //     power = other.power;
    // }
    Hero& operator=(const Hero& other) {
        if (this != &other) {
            power = other.power;
        }
        return *this;
    }
    void setPower(int _power) {
        power = _power;
    }
    int getPower() const {
        return power;
    }
    void present() {
        Player::present();
        std::cout << "Hero: power: " << power << '\n';
    }
    void print() {
        // Player::print();
        std::cout << "Hi, I am a Hero!" << '\n';
    }
};

int main() {
    // Player p2;
    // Player p1(12);
    Hero h1;
    h1.setScore(30);
    // Hero h2(h1);
    h1.setPower(50);
    Hero h2 = h1;
    h2.setScore(20);
    // h2.present();

    Player* pp = new Hero();
    // pp->present(); // only Player present

    Player* tp = &h1;
    // tp->present(); // only Player present

    // pp->print();

    // std::cout << (h1 > h2) << '\n';

    Player testP = h1;
    h1.print();

    return 0;
}