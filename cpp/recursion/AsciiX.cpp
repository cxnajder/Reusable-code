#include <iostream>

void r(int n)
{
    static const int cN = n;
    for (int i = 1; i <= cN; i++)
        if (i == n || i == 1 + cN - n)
            std::cout << '*';
        else
            std::cout << ' ';
    std::cout << '\n';
    if (n > 1)
        r(--n);
}

void ff(const int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i == j || j + i == n + 1)
                std::cout << '*';
            else
                std::cout << ' ';
        std::cout << '\n';
    }
}

void f(const int n)
{
    int x = 0;
    for (int i = 0; i < n * n; i++) {
        bool printed = false;
        if (i % n == 0 + x || i % n == n - 1 - x)
            std::cout << '*';
        else
            std::cout << ' ';

        if (i % n == n - 1) {
            std::cout << '\n';
            ++x;
        }
    }
}

int main()
{
    const int n = 30;

    std::cout << "recursion:\n";
    r(n);

    std::cout << "function1:\n";
    f(n);

    std::cout << "function2:\n";
    ff(n);
}


/* Output:


recursion:
*                            *
 *                          *
  *                        *
   *                      *
    *                    *
     *                  *
      *                *
       *              *
        *            *
         *          *
          *        *
           *      *
            *    *
             *  *
              **
              **
             *  *
            *    *
           *      *
          *        *
         *          *
        *            *
       *              *
      *                *
     *                  *
    *                    *
   *                      *
  *                        *
 *                          *
*                            *
function1:
*                            *
 *                          *
  *                        *
   *                      *
    *                    *
     *                  *
      *                *
       *              *
        *            *
         *          *
          *        *
           *      *
            *    *
             *  *
              **
              **
             *  *
            *    *
           *      *
          *        *
         *          *
        *            *
       *              *
      *                *
     *                  *
    *                    *
   *                      *
  *                        *
 *                          *
*                            *
function2:
*                            *
 *                          *
  *                        *
   *                      *
    *                    *
     *                  *
      *                *
       *              *
        *            *
         *          *
          *        *
           *      *
            *    *
             *  *
              **
              **
             *  *
            *    *
           *      *
          *        *
         *          *
        *            *
       *              *
      *                *
     *                  *
    *                    *
   *                      *
  *                        *
 *                          *
*                            *


*/