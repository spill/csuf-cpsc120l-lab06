// Ruben Armenta
// CPSC 120-06
// 2022-10-19
// raarmenta@csu.fullerton.edu
// @rubenarmenta
//
// Lab 07-02
// Partners: @rtrinh02
//
// blackjack using functions
//

#include <iostream>
#include <string>
#include <vector>

bool IsAce(const std::string& card_name) {
  if (card_name == "A") {
    return true;
  }
  return false;
}

bool IsFaceCard(const std::string& card_name) {
  if ((card_name == "K") || (card_name == "J") || (card_name == "Q")) {
    return true;
  }
  return false;
}

bool IsNumberCard(const std::string& card_name) {
  if (card_name == "2" || card_name == "3" || card_name == "4" ||
      card_name == "5" || card_name == "6" || card_name == "7" ||
      card_name == "8" || card_name == "9" || card_name == "10") {
    return true;
  }
  return false;
}

bool IsCardName(const std::string& str) {
  if (IsAce(str) || IsFaceCard(str) || IsNumberCard(str)) {
    return true;
  }
  return false;
}

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  for (int i{1}; i < arguments.size(); ++i) {
    if (!IsCardName(arguments.at(i))) {
      return false;
    }
  }
  return true;
}

int CardPoints(const std::string& card_name) {
  int card_points{0};
  if (IsAce(card_name)) {
    card_points = 1;
  } else if (IsFaceCard(card_name)) {
    card_points = 10;
  } else {
    card_points = stoi(card_name);
  }
  return card_points;
}

bool HandContainsAce(const std::vector<std::string>& arguments) {
  for (int i{1}; i < arguments.size(); ++i) {
    if (IsAce(arguments.at(i))) {
      return true;
    }
  }
  return false;
}

bool IsBust(int score) {
  if (score > 21) {
    return true;
  }
  return false;
}

int HandScore(const std::vector<std::string>& arguments) {
  int score{0};
  for (int i{1}; i < arguments.size(); ++i) {
    int points = CardPoints(arguments.at(i));
    if ((IsAce(arguments.at(i))) && (!IsBust(score + 11))) {
      points += 10;
    }
    score += points;
  }
  return score;
}

void PrintScore(int score) {
  if (IsBust(score)) {
    std::cout << "Score is " << score << ", BUST\n";
  } else {
    std::cout << "Score is " << score << "\n";
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (AllArgumentsValid(arguments)) {
    PrintScore(HandScore(arguments));
  } else {
    std::cout << "error: invalid card\n";
    return 1;
  }
  return 0;
}
