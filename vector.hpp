#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector 
    {

    // Member types
    typedef T value_type ;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef ft::iterator<value_type> iterator ;
    typedef ft::iterator<const value_type> const_iterator ;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef std::size_t size_type;
    
    // Member fonctions
    vector();
    ~vector();
    vector& operator=( const vector& other );

    /// Iterators

    iterator begin();
    const_iterator cbegin() const;
    iterator end();
    const_iterator cend() const;
    iterator rbegin();
    const_iterator crbegin() const;
    iterator rend();
    const_iterator crend() const;

    /// Capacity

    size_type size() const;
    size_type max_size() const;
    void resize (size_type n, value_type val = value_type());
    size_type capacity() const;
    bool empty() const;
    void reserve (size_type n);
    void shrink_to_fit();

    /// Element access

    reference operator[] (size_type n);const_reference operator[] (size_type n) const;
    reference at (size_type n);const_reference at (size_type n) const;
    reference front();const_reference front() const;
    reference back();const_reference back() const;
    value_type* data() noexcept;const value_type* data() const noexcept;

    /// Modifiers
    void assign (size_type n, const value_type& val);
    void push_back (const value_type& val);
    void pop_back();
    void insert (iterator position, size_type n, const value_type& val);
    iterator erase (iterator position);iterator erase (iterator first, iterator last);
    void swap (vector& x);
    void clear();
    template <class... Args>iterator emplace (const_iterator position, Args&&... args);
    template <class... Args>  void emplace_back (Args&&... args);

    /// Allocator

    allocator_type get_allocator() const;

    // Non-member fonction overloads
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
    } 
}

#endif