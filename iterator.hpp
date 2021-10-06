/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:31:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/06 02:04:42 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    struct input_iterator_tag { };
    struct outpout_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_acces_iterator_tag : public bidirectional_iterator_tag { };

    /**
     * @brief Traits class defining properties of iterators.
     * @details Standard algorithms determine certain properties of the
     * iterators passed to them and the range they represent by using the
     * members of the corresponding iterator_traits instantiation.
     */
    template <class Iterator>
    struct iterator_traits {
        typedef typename Iter::difference_type   differencet_type;
        typedef typename Iter::value_type        value_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    /**
     * @brief Traits class specialized for pointers (T*).
     */
    template <class T>
    struct iterator_traits<T *> {
        typedef std::ptrdiff_t                 differencet_type;
        typedef T                              value_type;
        typedef T *                            pointer;
        typedef T &                            reference;
        typedef std::random_acces_iterator_tag iterator_category;
    };

    /**
     * @brief Traits class specialized for pointers to const (const T*).
     */
    template <class T>
    struct iterator_traits<const T *> {
        typedef std::ptrdiff_t                 differencet_type;
        typedef T                              value_type;
        typedef T *                            pointer;
        typedef T &                            reference;
        typedef std::random_acces_iterator_tag iterator_category;
    };

    /**
     * @brief This is a base class template that can be used to derive iterator
     * classes from it. It is not an iterator class and does not provide any of
     * the functionality an iterator is expected to have.
     * @details This base class only provides some member types, which in fact
     * are not required to be present in any iterator type (iterator types have
     * no specific member requirements), but they might be useful, since they
     * define the members needed for the default iterator_traits class template
     * to generate the appropriate instantiation automatically (and such
     * instantiation is required to be valid for all iterator types).
     */
    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    template <class Iterator>
    class reverse_iterator {
      public:
        typename Iterator                                     iterator_type;
        typename iterator_traits<Iterator>::iterator_category iterator_category;
        typename iterator_traits<Iterator>::value_type        value_type;
        typename iterator_traits<Iterator>::difference_type   difference_type;
        typename iterator_traits<Iterator>::pointer           pointer;
        typename iterator_traits<Iterator>::reference         reference;

      protected:
        Iterator current;

      public:
        reverse_iterator() :
            current() { } /// default

        explicit reverse_iterator(iterator_type it) :
            current(it) { } // initialization

        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) :
            current(rev_it.base())
        { } // copy / type-cast

        iterator_type base() const
        {
            return current;
        }

        reference operator*() const
        {
            Iterator tmp = current;
            return *--tmp;
        }
        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(current - n);
        }
        reverse_iterator &operator++() // pre
        {
            --current;
            return *this;
        }
        reverse_iterator operator++(int) // post
        {
            reverse_iterator tmp = *this;
            --current;
            return tmp;
        }
        reverse_iterator &operator+=(difference_type n)
        {
            current -= n;
            return *this;
        }
        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator(current + n);
        }
        reverse_iterator &operator--() // pre
        {
            ++current;
            return *this;
        }
        reverse_iterator operator--(int) // post
        {
            reverse_iterator tmp = *this;
            ++current;
            return tmp;
        }
        reverse_iterator &operator-=(difference_type n) const
        {
            cyrrent += n;
            return *this;
        }
        pointer operator->() const
        {
            return &(operator*());
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.base() == y.base();
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return !(x == y);
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return y.base() < x.base();
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return !(y < x);
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return y < x;
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return !(x < y);
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return rev_it + n;
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return y.base() - x.base();
    }

}; // namespace ft
#endif