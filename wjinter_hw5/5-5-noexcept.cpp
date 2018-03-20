//noexcept(true) and noexcept(false) provide sementic of cases that it can be true or false conditionally since c++ 17
//The result is false if the expression contains at least one of the following potentially evaluated constructs:
//The result is true if the set of potential exceptions of the expression is empty, and false otherwise.

//The purpose of noexcept(true), noexcept(false), noexcept is similar as const, throw()
//allowing programmer detect at compile-time if a function throw an exception or not
//"compile-time checks for noexcept violation can be performed on demand rather than being always forced."
//in case of destructors noexcepts are implicitly noexcept(true) unless we declare them noexcept(false)

//I re-illustrated my own thought out response per my research below
//by analysing the attached example below from cppreference.com
//http://en.cppreference.com/w/cpp/language/noexcept

//as it covers the questions asking in 5-5 in various cases
//even some of them had not asked, ie throughly

#include <iostream>
#include <utility>
#include <vector>

void may_throw();
void no_throw() noexcept;
auto lmay_throw = []{};
auto lno_throw = []() noexcept {};
class T{
public:
  ~T(){} // dtor prevents move ctor
         // copy ctor is noexcept
};
class U{
public:
  ~U(){} // dtor prevents move ctor
         // copy ctor is noexcept(false)
  std::vector<int> v;
};
class V{
public:
  std::vector<int> v;
};

int main()
{
 T t;
 U u;
 V v;

 std::cout << std::boolalpha
           // no since it didn't use noexcept in constructor
           << "Is may_throw() noexcept? " << noexcept(may_throw()) << '\n'
           // yes it did use noexcept in constructor
           << "Is no_throw() noexcept? " << noexcept(no_throw()) << '\n'
           // no since it didn't use noexcept in constructor
           << "Is lmay_throw() noexcept? " << noexcept(lmay_throw()) << '\n'
           // yes it did use noexcept in constructor
           << "Is lno_throw() noexcept? " << noexcept(lno_throw()) << '\n'

           << "Is ~T() noexcept? " << noexcept(std::declval<T>().~T()) << '\n'
           // note: the following tests also require that ~T() is noexcept because
           // the expression within noexcept constructs and destroys a temporary

           // yes because copy ctor is noexcept
           << "Is T(rvalue T) noexcept? " << noexcept(T(std::declval<T>())) << '\n'
           << "Is T(lvalue T) noexcept? " << noexcept(T(t)) << '\n'

           // no because copy ctor is noexcept(false)
           << "Is U(rvalue U) noexcept? " << noexcept(U(std::declval<U>())) << '\n'

           // no because copy ctor is noexcept(false)
           << "Is U(lvalue U) noexcept? " << noexcept(U(u)) << '\n'

           // yes and no because default is noexcept(true)
           << "Is V(rvalue V) noexcept? " << noexcept(V(std::declval<V>())) << '\n'
           << "Is V(lvalue V) noexcept? " << noexcept(V(v)) << '\n';
}