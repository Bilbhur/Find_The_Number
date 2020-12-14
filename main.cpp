//
// Created by alexandre majda on 13/12/2020.
//

#include <iostream>
#include "utils.h"
#include <game.h>
#include <string>

int main() {

    Game* game = new Game();
    int propal(0);
    char userAnswer;
    bool replay(true), nok(true);


    while (replay) {
        game->setNewRandom();
        game->startMessage();

        replay = false;

        /*
         * While the user hasn't found the correct number yet
         * the user has to type the number he thinks is correct
         */
        while (propal != game->getNumberToFind()) {

            // Display the last value
            if (propal != 0)
                std::cout << "Last proposition : " << propal << std::endl;
            std::cout << "Enter the number you think is correct : " << std::endl;
            std::cin >> propal;

            // Check User Input
            if(std::cin.fail()) {
                std::cin.clear();
                std::cout << "NaN" << std::endl;
                clearInputBuffer();
                continue;
            }

            // Gameplay
            if (propal < game->getNumberToFind())
                std::cout << "It's more." << std::endl;
            else if (propal > game->getNumberToFind())
                std::cout << "It's less." << std::endl;
        }
        std::cout << "Congrats ! You Win!" << std::endl;

        // Check user input for replaying
        while (nok) {
            std::cout << "Do you want to play again ? (y/n)" << std::endl;
            std::cin >> userAnswer;
            if (userAnswer == 'o'
                || userAnswer == 'O'
                || userAnswer == 'y'
                || userAnswer == 'Y') {
                replay = true;
                nok = false;
                std::cout << "Great, Here we go again !" << std::endl;
            } else if (userAnswer == 'n'
                       || userAnswer == 'N') {
                replay = false;
                nok = false;
                std::cout << "'Kay, Bye !" << std::endl;
            } else {
                std::cout << "Wrong answer, please type 'y' or 'n'." << std::endl;
                nok = true;
            }
        }

        // Restart values
        nok = true;
        propal = 0;
    }

    return 0;
}
