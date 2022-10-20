#include <iostream>

template <class T>
struct NodeStack
{
      T data;
      NodeStack<T> *next;

      NodeStack()
      {
            next = nullptr;
      }

      NodeStack(const T &dt)
      {
            next = nullptr;
            data = dt;
      }
};

template <class T>
struct Stack
{
      NodeStack<T> *head;

      void push(const T &data)
      {
            NodeStack<T> *aux = new NodeStack<T>(data);
            aux->next = head;
            head = aux;
      }

      void pop()
      {
            if (head == nullptr)
                  return;
            NodeStack<T> *aux = head;
            head = head->next;
            delete aux;
      }

      T top()
      {
            if (head == nullptr)
                  return NULL;
            T info = head->data;
            return info;
      }

      bool empty()
      {
            if (head == nullptr)
                  return true;
            return false;
      }

      void erase()
      {
            while (!empty())
                  pop();
      }

      void print()
      {
            while (!empty())
            {
                  std ::cout << head->data << " ";
                  pop();
            }
            std ::cout << '\n';
      }
};

int main(int argc, char const *argv[])
{
      Stack<float> st;
      st.push(2.3);
      st.push(2.222);
      st.print();
      return 0;
}
