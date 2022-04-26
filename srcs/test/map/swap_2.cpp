#include "../test.hpp"

template <typename T>
void swap_2()
{
    T foo, bar;
 foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  swap(foo,bar);

  std::cout << "foo contains:\n";
  for (typename T::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (typename T::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

int main()
{
  swap_2<NAMESPACE::map<char, int> >();

}