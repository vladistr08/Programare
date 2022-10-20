#include <iostream>
#include <vector>
#include <climits>

std::pair<int, int> getMaxi(const int &n, const std::vector<std::pair<int, bool>> &a)
{
      int maxi1 = INT_MIN, maxi2 = INT_MIN;
      for (const auto &el : a)
      {
            if (el.first > maxi1)
            {
                  maxi2 = maxi1;
                  maxi1 = el.first;
            }
            else if (el.first > maxi2)
            {
                  maxi2 = el.first;
            }
      }
      return {maxi1, maxi2};
}

std::pair<int, int> getMini(const int &n, const std::vector<std::pair<int, bool>> &a)
{
      int mini1 = INT_MAX, mini2 = INT_MAX;
      for (int i = 0; i < n; i++)
      {
            std::pair<int, bool> el = a[i];
            if (el.second == false)
            {
                  if (el.first < mini1)
                  {
                        mini2 = mini1;
                        mini1 = el.first;
                  }
                  else if (el.first < mini2)
                  {
                        mini2 = el.first;
                  }
            }
      }

      return {mini1, mini2};
}

int findMaxWeight(const int &n, const std::vector<std::pair<int, bool>> &a)
{
      if (n < 2)
            return 0;
      if (n == 2)
            return abs(a[0].first - a[0].second);
      std::pair<int, int> maxi = getMaxi(n, a), mini = getMini(n, a);
      return std::max(maxi.first - mini.first + maxi.second - mini.second, maxi.first - mini.second + maxi.second - mini.first);
}

void input(int &n, std::vector<std::pair<int, bool>> &a)
{
      std::cin >> n;
      int x;
      for (int i = 0; i < n; i++)
      {
            std::cin >> x;
            a.push_back({x, false});
      }
}

void run()
{
      int t, n;
      std::cin >> t;
      for (int i = 0; i < t; i++)
      {
            std::vector<std::pair<int, bool>> a;
            input(n, a);
            std::cout << findMaxWeight(n, a);
      }
}

int main(int argc, char const *argv[])
{
      run();
      return 0;
}
