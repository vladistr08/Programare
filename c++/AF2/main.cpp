#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

class State
{
public:
      vector<vector<int>> Mat, MatFinala; // the state given
      int Size;                           // the size of the board
      int i, j;                           // coordonates of the blank space

      State(int n, vector<vector<int>> v) // constructor of a State
      {
            this->Size = n;
            for (int i = 0; i < n; i++)
            {
                  this->Mat.push_back(v[i]);
            }
            for (int i = 0; i < this->Size; i++)
            {
                  int ok = 0;
                  for (int j = 0; j < this->Size; j++)
                  {
                        if (v[i][j] == this->Size * this->Size)
                        {
                              ok = 1;
                              this->i = i;
                              this->j = j;
                              break;
                        }
                  }
                  if (ok == 1)
                        break;
            }
            generateFinalState();
      }

      State()
      {
            this->i = -1;
            this->j = -1;
            this->Size = 0;
            generateFinalState();
      }

      State(const State &st)
      {
            this->Size = st.Size;
            for (int i = 0; i < st.Size; i++)
            {
                  this->Mat.push_back(st.Mat[i]);
            }
            this->i = st.i;
            this->j = st.j;
            generateFinalState();
      }

      bool checkIfPossible() // check if the given state is solvable
      {
            int inversions = getInversions();
            if (this->Size % 2 == 1)
            {
                  if (inversions % 2 == 0)
                        return true;
                  return false;
            }
            else
            {
                  if (this->i % 2 == 1)
                  {
                        if (inversions % 2 == 0)
                              return true;
                        return false;
                  }
                  else
                  {
                        if (inversions % 2 == 1)
                              return true;
                        return false;
                  }
            }
      }

      bool moveToDirection(char direction) // move the blank space in one direction
      {
            switch (direction)
            {
            case 'N':
                  return moveNorth();
                  break;
            case 'S':
                  return moveSouth();
                  break;
            case 'W':
                  return moveWest();
                  break;
            case 'E':
                  return moveEast();
                  break;
            default:
                  return true;
                  break;
            }
      }

      State &operator=(const State &st)
      {
            this->Size = st.Size;
            this->Mat.clear();
            for (int i = 0; i < st.Size; i++)
            {
                  this->Mat.push_back(st.Mat[i]);
            }
            this->i = st.i;
            this->j = st.j;
            return *this;
      }

      bool operator==(const State &st)
      {
            if (this->Size != st.Size)
                  return false;
            for (int i = 0; i < this->Size; i++)
            {
                  for (int j = 0; j < this->Size; j++)
                  {
                        if (this->Mat[i][j] != st.Mat[i][j])
                              return false;
                  }
            }
            return true;
      }

      int getDistanceMahatton()
      {
            int distanta = 0;
            pair<int, int> elPozitionat;
            for (int i = 0; i < this->Size; i++)
                  for (int j = 0; j < this->Size; j++)
                        if (this->Mat[i][j] != this->Size * this->Size)
                        {
                              elPozitionat = getPosition(this->Mat[i][j]);
                              distanta += abs(i - elPozitionat.first) + abs(j - elPozitionat.second);
                        }
            return distanta;
      }

      bool checkIfComplete()
      {
            int ant;
            cout << this->Size;
            for (int i = 0; i < this->Size; i++)
            {
                  for (int j = 0; j < this->Size; j++)
                  {
                        cout << this->Mat[i][j] << " ";
                        if (j == 0)
                        {
                              if (i != 0 && this->Mat[i][j] != ant + 1)
                                    return false;
                        }
                        else if (this->Mat[i][j] != this->Mat[i][j - 1] + 1)
                              return false;
                        ant = this->Mat[i][j];
                  }
                  cout << '\n';
            }
            return true;
      }

private:
      void generateFinalState()
      {
            this->MatFinala.clear();
            for (int i = 0; i < this->Size; i++)
            {
                  vector<int> aux;
                  aux.clear();
                  for (int j = 0; j < this->Size; j++)
                  {
                        aux.push_back(i * this->Size + j + 1);
                  }
                  this->MatFinala.push_back(aux);
            }
      }

      pair<int, int> getPosition(int el)
      {
            pair<int, int> returnedPair;
            for (int i = 0; i < this->Size; i++)
            {
                  for (int j = 0; j < this->Size; j++)
                  {
                        if (this->MatFinala[i][j] == el)
                        {
                              returnedPair.first = i;
                              returnedPair.second = j;
                              return returnedPair;
                        }
                  }
            }
            return returnedPair;
      }

      int getInversions()
      {
            vector<int> v;
            for (int i = 0; i < this->Size; i++)
            {
                  for (int j = 0; j < this->Size; j++)
                  {
                        v.push_back(this->Mat[i][j]);
                  }
            }

            int inversions = 0;
            for (int i = 0; i < this->Size * this->Size - 1; i++)
            {
                  if (v[i] == this->Size * this->Size)
                        continue;
                  for (int j = i + 1; j < this->Size * this->Size; j++)
                  {
                        if (v[j] < v[i])
                              inversions++;
                  }
            }
            return inversions;
      }

      bool moveNorth()
      {
            if (this->i == 0)
                  return false;
            swap(this->Mat[this->i][this->j], this->Mat[this->i + 1][this->j]);
            this->i = this->i + 1;
            return true;
      }

      bool moveSouth()
      {
            if (this->i == this->Size - 1)
                  return false;
            swap(this->Mat[this->i][this->j], this->Mat[this->i - 1][this->j]);
            this->i = this->i - 1;
            return true;
      }

      bool moveWest()
      {
            if (this->j == 0)
                  return false;
            swap(this->Mat[this->i][this->j], this->Mat[this->i][this->j - 1]);
            this->j = this->j - 1;
            return true;
      }

      bool moveEast()
      {
            if (this->j == this->Size - 1)
                  return false;
            swap(this->Mat[this->i][this->j], this->Mat[this->i][this->j + 1]);
            this->j = this->j + 1;
            return true;
      }
};

struct Node
{
      Node *Parinte{};
      State Board;      // the given state and the parent from the tree
      char Direction{}; // the direction used to generate
      int Cost{};       // the level in the tree
      Node &operator=(const Node &x)
      {
            this->Board = x.Board;
            this->Direction = x.Direction;
            this->Cost = x.Cost;
            this->Parinte = x.Parinte;
            return *this;
      }
};

State inputReadFile(const string &path)
{
      ifstream fin(path);
      int n, x;
      vector<vector<int>> v;
      fin >> n;
      for (int i = 0; i < n; i++)
      {
            vector<int> aux;
            for (int j = 0; j < n; j++)
            {
                  fin >> x;
                  aux.push_back(x);
            }
            v.push_back(aux);
      }
      State aux(n, v);
      return aux;
}
void outputWriteFile(const string &path, State st)
{
      ofstream fout(path);
      fout << '\n';
      for (int i = 0; i < st.Size; i++)
      {
            for (int j = 0; j < st.Size; j++)
            {
                  if (st.Mat[i][j] == st.Size * st.Size)
                        fout << " ";
                  else
                        fout << st.Mat[i][j] << " ";
            }
            fout << '\n';
      }
      fout << '\n';
}

bool checkIfUsed(vector<State> viz, const State &currentState) // checks if the given state was used in the past
{
      for (auto &i : viz)
      {
            if (i == currentState)
                  return false;
      }
      return true;
}

void generateChildren(Node st, vector<Node> &v, const vector<State> &viz)
{
      v.clear();
      State stN = st.Board, stW = st.Board, stS = st.Board, stE = st.Board;
      bool N = stN.moveToDirection('N'), W = stW.moveToDirection('W'), E = stE.moveToDirection('E'), S = stS.moveToDirection('S');
      if (N && checkIfUsed(viz, stN))
      {
            Node p;
            p.Board = stN;
            p.Direction = 'N';
            p.Parinte = &st;
            p.Cost = st.Cost + 1;
            v.push_back(p);
      }
      if (W && checkIfUsed(viz, stW))
      {
            Node p;
            p.Board = stW;
            p.Direction = 'W';
            p.Parinte = &st;
            p.Cost = st.Cost + 1;
            v.push_back(p);
      }
      if (E && checkIfUsed(viz, stE))
      {
            Node p;
            p.Board = stE;
            p.Direction = 'E';
            p.Parinte = &st;
            p.Cost = st.Cost + 1;
            v.push_back(p);
      }
      if (S && checkIfUsed(viz, stS))
      {
            Node p;
            p.Board = stS;
            p.Direction = 'S';
            p.Parinte = &st;
            p.Cost = st.Cost + 1;
            v.push_back(p);
      }
}

Node getPriorityNode(vector<Node> children)
{
      int dist[children.size()];
      for (int i = 0; i < children.size(); i++)
      {
            dist[i] = children[i].Board.getDistanceMahatton();
            dist[i] += children[i].Cost;
      }
      int mini = 389287356, aux;
      for (int i = 0; i < children.size(); i++)
      {
            if (dist[i] < mini)
                  mini = dist[i];
            aux = i;
      }
      return children[aux];
}

void aStar(Node root, vector<State> &viz, queue<Node> &pq)
{
      Node currentMat = root;
      vector<Node> children;

      viz.push_back(currentMat.Board);
      pq.push(currentMat);
      while (!currentMat.Board.checkIfComplete())
      {
            generateChildren(currentMat, children, viz);
            currentMat = getPriorityNode(children);
            viz.push_back(currentMat.Board);
            pq.push(currentMat);
      }
}

void startSolving(State initialState)
{
      string path = "output.out";
      ofstream fout(path);
      if (!initialState.checkIfPossible())
      {
            fout << "Nu este posibila nicio rezolvare!!!!!";
      }
      else
      {
            vector<State> viz;
            queue<Node> pq;

            Node root;
            root.Cost = 0;
            root.Direction = '0';
            root.Parinte = nullptr;
            root.Board = initialState;

            aStar(root, viz, pq);

            while (!pq.empty())
            {
                  Node aux = pq.front();
                  pq.pop();
                  outputWriteFile(path, aux.Board);
            }
      }
}

int main(int argc, char const *argv[])
{
      State st = inputReadFile("input.in");
      startSolving(st);
      return 0;
}
