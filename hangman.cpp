#include <iostream>

int main() {
	
	std::string word{};
	bool won{ false };
	short guesses{ 6 };
	std::cout << "Player 1, input a word! ";
	std::cin >> word;
	std::cout << "\n";
	std::string display_guess(word.length(), '_');
	std::string failed_guesses{};
	
	char head{ ' ' };
	char body{ ' ' };
	char left_arm{ ' ' };
	char right_arm{ ' ' };
	char left_leg{ ' ' };
	char right_leg{ ' ' };
	
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	while ((not won) && (guesses > 0)) {
		char letter{};
		std::string length_checker{};
		bool guessed_letter{ false };
		std::cout << "Player 2, guess a letter! ";
		std::cin >> length_checker;

		while (length_checker.length() > 1) {
			std::cin >> length_checker;
		}
		letter = length_checker[0];

		for (unsigned int i = 0; i < word.length(); i++) {
			if (letter == word[i]) {
				guessed_letter = true;
				display_guess[i] = letter;
			}
		}
		if (not guessed_letter) {
			guesses--;
			failed_guesses += letter;
		}
		else if (display_guess == word) {
			won = true;
		}
		std::cout << "\n" << guesses << "\n" << failed_guesses << "\n" << display_guess << "\n";
		
		if (guesses < 6) {
			head = 'o';
		}
		if (guesses < 5) {
			body = '|';
		}
		if (guesses < 4) {
			left_arm = '/';
		}
		if (guesses < 3) {
			right_arm = '\\';
		}
		if (guesses < 2) {
			left_leg = '/';
		}
		if (guesses < 1) {
			right_leg = '\\';
		}

		std::cout << "____\n" << " " << head << " |\n" << left_arm << body << right_arm << "|\n" << left_leg << " " << right_leg << "|\n" << "-----\n\n";
	}

	if (won) {
		std::cout << "Congratulation you won";
	}
	else {
		std::cout << "you suck";
	}

}