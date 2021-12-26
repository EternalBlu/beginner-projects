#include <stdlib.h>
#include <iostream>
#include <time.h>

enum directions { up = 1, right = 2, down = 3, left = 4 };
enum ships { carrier = 5, battleship = 4, cruiser = 3, submarine = 3, destroyer = 2 };

struct Ship {
    int space{};
    int position[2]{};
    int orientation{};
    int section[5][2]{};

    Ship(int i) {
        space = i;
    }

    void place_ship() {
            
        srand(time(0));
        position[0] = rand() % 9;
        position[1] = rand() % 9;
        orientation = (rand() % 3) + 1;


        if ((orientation == down) && (position[1] > space)) {
            position[1] -= position[1] % space;		}
        
        else if ((orientation == up) && (position[1] < space)) {
            position[1] += position[1] % space;
        }
            
        if ((orientation == right) && (position[0] > space)) {
            position[0] -= position[0] % space;
        }
        else if ((orientation == left) && (position[0] < space)) {
            position[0] += position[0] % space;
        }

        for (int i = 0; i < space; i++) {
            switch (orientation) {
            case (down): {
                section[i][0] = position[0];
                section[i][1] = position[1];
                break;
            }
            case (up): {
                section[i][0] = position[0];
                section[i][1] = position[1] - i;
                break;
            }
            case (left): {
                section[i][0] = position[0] - i;
                section[i][1] = position[1];
                break;
            }
            case (right): {
                section[i][0] = position[0] + i;
                section[i][1] = position[1];
                break;
                }
            }
         
            //std::cout << "(" << section[i][0] << ", " << section[i][1] << ") ";
        }
        std::cout << "\n";
    }
};


int main() {
    int all_section[16][2]{};

    std::cout << "AI is placing their ships...\n";
    Ship ai_carrier(carrier);
    ai_carrier.place_ship();
    std::cout << "Carrier placed...\n";
    Ship ai_battleship(battleship);
    ai_battleship.place_ship();
    std::cout << "Battleship placed...\n";
    Ship ai_cruiser(cruiser);
    ai_cruiser.place_ship();
    std::cout << "Cruiser placed...\n";
    Ship ai_submarine(submarine);
    ai_submarine.place_ship();
    std::cout << "Submarine placed...\n";
    Ship ai_destroyer(destroyer);
    ai_destroyer.place_ship();
    std::cout << "Destroyer placed...\n\n";
    std::cout << ai_cruiser.orientation << "\n";

    for (int i = 0; i < 16; i++) { // smoosh all of the cordinants where the ships will be into one array for printing
        
    }

    int x = 0;
    int y = 10;
    bool first_line{ true };

    for (x; x < 100; x++) {
        bool printed{ false };
        y = floor(x / 10);

        if (((x % 10) == 0) && (y != 0) && !first_line) {
            std::cout << "\n";
        }

        for (int i = 0; i < 16; i++) {
            if ((all_section[i][0] == (x % 10)) && (all_section[i][1] == y)) {
                std::cout << "x ";
                printed = true;
                break;
            }
        }

        if (!printed) {
            std::cout << ". ";
        }
        first_line = false;

    }
    
    std::cout << "\nAll ships placed!\n";

}