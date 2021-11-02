/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:52:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/26 14:16:18 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    //clang-format off
    template <class T, class Container = ft::vector<T> >
    //clang-format on
    class stack
    {
        public:
            typedef typename Container::value_type value_type;
            typedef Container                      container_type;
            typedef typename Container::size_type  size_type;

        protected:
            Container c;

        public:
            explicit stack(const container_type &ctnr = container_type()) // ctor // DONE
                : c(ctnr)
            { }

            virtual ~stack() { } // dtor //DONE

            bool empty() const // DONE
            {
                return c.empty();
            }

            size_type size() const // DONE
            {
                return c.size();
            }

            value_type &top() // DONE
            {
                return c.back();
            }

            value_type &top() const // DONE
            {
                return c.back();
            }

            void push(const value_type &val) // DONE
            {
                c.push_back(val);
            }

            void pop() // DONE
            {
                c.pop_back();
            }

            template <class Tn, class ContainerN>
            friend bool operator==(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

            template <class Tn, class ContainerN>
            friend bool operator!=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

            template <class Tn, class ContainerN>
            friend bool operator<(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

            template <class Tn, class ContainerN>
            friend bool operator<=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

            template <class Tn, class ContainerN>
            friend bool operator>(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

            template <class Tn, class ContainerN>
            friend bool operator>=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return x.c == y.c;
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return !(x == y);
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return x.c < y.c;
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return !(y < x);
    }

    template <class T, class Container>
    bool operator>(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return y < x;
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container> &x, const stack<T, Container> &y) // DONE
    {
        return !(x < y);
    }
} // namespace ft