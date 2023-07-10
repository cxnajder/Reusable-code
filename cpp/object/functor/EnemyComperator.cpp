#include <iostream>
#include <vector>
#include <algorithm>

class Enemy{
    int health;
    int strength;
public:
    Enemy(int h, int s) : health(h), strength(s) {}

    bool operator < ( const Enemy & R_enemy){
        return (this-> health < R_enemy.health);
    }

    friend std::ostream & operator << (std::ostream & ostr, const Enemy & en);
    friend class EnemyStrengthComperator;  
};

std::ostream & operator << (std::ostream & ostr, const Enemy & en)
{
    ostr << "hp : " << en.health << ", dmg : " << en.strength;
    return ostr;
}


class EnemyStrengthComperator
{
public:
    bool operator()(const Enemy & left_enem, const Enemy & right_enem) const
    {
        return ( left_enem.strength < right_enem.strength );
    }
};

int main(void)
{
    std::vector<Enemy> enems = {
        Enemy(99, 99),
        Enemy(12, 80),
        Enemy(80, 11),
        Enemy(3, 3)
    };

    std::cout << "Unsorted enemies:\n";

    for(auto en : enems)
        std::cout << en << '\n';


    std::sort(enems.begin(), enems.end());
    std::cout << "Enemies sorted by HP:\n";

    for(auto en : enems)
        std::cout << en << '\n';


    std::sort(enems.begin(), enems.end(), EnemyStrengthComperator());
    std::cout << "Enemies sorted by DMG:\n";

    for(auto en : enems)
        std::cout << en << '\n';

    return 0;
}
