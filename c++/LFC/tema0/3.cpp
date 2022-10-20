#include <iostream>
#include <string>
#include <regex>

void inputUser(std::string &userInput)
{
      std::cout << "The main string:";
      std::getline(std::cin, userInput);
}

void inputSubstring(std::string &s1, std::string &s2)
{
      std::cout << "s1:";
      std::cin >> s1;

      std::cout << "s2:";
      std::cin >> s2;
}

/*
!!!!!!!!!!! FIND AND REPLACE WITH REGEX !!!!!!!!!!!!!!!!!!
std::string findAndReplace(const std::string &str, const std::string &s1, const std::string &s2)
{
      std::regex regexp(s1);
      return std::regex_replace(str, regexp, s2);
}
*/

std::string findAndReplace(std::string &strArg, const std::string &s1, const std::string &s2)
{
      std::string str = strArg;
      int s2Lenght = s2.length(), s1Lenght = s1.length();
      auto lastPosFound = str.find(s1);
      while (lastPosFound != std::string::npos)
      {
            str.replace(lastPosFound, s1Lenght, s2);
            lastPosFound = str.find(s1, lastPosFound + 1);
      }
      return str;
}

int main(int argc, char const *argv[])
{
      std::string userInput;
      inputUser(userInput);
      std::string reverseInput = std::string(userInput.rbegin(), userInput.rend());

      std::string s1, s2;
      inputSubstring(s1, s2);

      std::string newStr = findAndReplace(reverseInput, s1, s2);
      std::cout << newStr;

      return 0;
}
