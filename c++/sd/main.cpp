#include <iostream>

// adaugare inserare si print

template <typename T>
class List
{
public:
      struct Node
      {
            explicit Node(const T &element)
            {
                  data = element;
            }
            T data = NULL;
            Node *next = nullptr, *prev = nullptr;
      };

      // insert a value after the specified Node
      void insert(Node *t, const T &__valueToInsert)
      {
            Node *aux = new Node(__valueToInsert);
            if (t == nullptr)
                  return;
            if (t == _last)
            {
                  _last->next = aux;
                  aux->prev = _last;
                  aux->next = nullptr;
                  _last = aux;
            }
            else
            {
                  aux->prev = t;
                  aux->next = t->next;
                  aux->next->prev = aux;
                  t->next = aux;
            }
            _size++;
      }

      void push_back(const T &__valueToAdd)
      {
            Node *aux = new Node(__valueToAdd);
            if (_last == nullptr)
            {
                  _last = aux;
                  _first = aux;
            }
            else
            {
                  _last->next = aux;
                  aux->prev = _last;
                  _last = aux;
            }
            _size++;
      }

      void print()
      {
            std::cout << '\n';
            for (Node *t = _first; t != nullptr; t = t->next)
            {
                  std::cout << t->data << " ";
            }
            std::cout << '\n';
      }

      Node *find(const T &__valueToFind)
      {
            for (Node *t = _first; t != nullptr; t = t->next)
            {
                  if (t->data == __valueToFind)
                        return t;
            }
            return nullptr;
      }

private:
      Node *_first = nullptr, *_last = nullptr;
      int _size;
};

int main(int argc, char const *argv[])
{
      List<int> L;
      L.push_back(0);
      L.push_back(1);
      L.push_back(2);
      L.push_back(3);
      L.insert(L.find(2), 33);
      L.insert(L.find(3), 44);
      L.print();
      return 0;
}
