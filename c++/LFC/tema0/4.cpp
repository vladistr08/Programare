#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> createWordVector(const std::string &word)
{
      std::vector<std::string> wordVect;
      for (size_t i = 0; i < word.length(); i++)
      {
            wordVect.push_back(std::string(word.begin(), word.begin() + i));
      }
      return wordVect;
}

void printVector(const std::vector<std::string> &wordVect)
{
      for (auto preWord : wordVect)
      {
            std::cout << preWord << '\n';
      }
}

int main(int argc, char const *argv[])
{
      std::vector<std::string> wordVect = createWordVector("ANANAS");
      printVector(wordVect);
      return 0;
}
