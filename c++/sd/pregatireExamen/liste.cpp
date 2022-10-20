#include <iostream>

struct Lista
{
      struct node
      {

            explicit node(int data = -1)
            {
                  if (data != -1)
                  {
                        this->info = data;
                  }
            }

            int info;
            node *urm = nullptr;
      };
      node *vf = nullptr;
      void push(int data);
      void print();
};

void Lista::push(int data)
{
      Lista::node *t = new Lista::node(data);
      if (this->vf == nullptr)
      {
            vf = t;
      }
      else
      {
            t->urm = vf;
            vf = t;
      }
}

void Lista::print()
{
      for (Lista::node *t = vf; t != nullptr; t = t->urm)
      {
            std::cout << t->info << " ";
      }
      std::cout << '\n';
}

int main(int argc, char const *argv[])
{
      Lista l;
      l.push(10);
      l.print();
      return 0;
}
