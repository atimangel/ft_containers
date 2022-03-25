/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:28 by snpark            #+#    #+#             */
/*   Updated: 2022/03/25 16:25:00 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//for referencee
#include <iterator>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ft
{

/* ************************************************************************** */
/* ************************************************************************** */
//template <bool>
//class	vector_base_common
//{
//protected:
//	vector_base_common() {}
//	void	throw_length_error() const throw (std::length_error);
//	void	throw_out_of_range() const throw (std::out_of_range);
//};
//
//template <bool b>
//void	ft::vector_base_common<b>::throw_length_error() const throw (std::length_error)
//{
//	std::length_error("vector");
//}
//
//template <bool b>
//void	ft::vector_base_common<b>::throw_out_of_range() const throw (std::out_of_range)
//{
//	std::out_of_range("vector");
//}
///* ************************************************************************** */
///* ************************************************************************** */
//template <typename T>
//class	vector_base
//	: protected vector_base_common<true>
//{
//public:
//	typedef std::allocator<T>							allocator_type;
//	typedef typename allocator_type::size_type			size_type;
//protected:
//	typedef T											value_type;
//	typedef typename allocator_type::reference			reference;
//	typedef typename allocator_type::const_reference	const_reference;
//	typedef typename allocator_type::difference_type	difference_type;
//	typedef typename allocator_type::pointer			pointer;
//	typedef typename allocator_type::const_pointer		const_pointer;
//	typedef	pointer										iterator;
//	typedef const_pointer								const_iterator;
//
//	size_type	_capacity;
//	pointer		_begin;
//	pointer		_end;
//// 무슨 용도인지 모르겠음
////	std::__compressed_pair<pointer, allocator_type> _end_cap;
////	
////	allocator_type&			alloc()			throw()
////	{
////		return (_end_cap.second());
////	}
////	const allocator_type&	alloc() const	throw()
////	{
////		return (_end_cap.second());
////	}
////	pointer&				end_cap()		throw()
////	{
////		return (_end_cap.first());
////	}
////	const pointer&			end_cap() const	throw()
////	{
////		return (_end_cap.first());
////	}
////
//	vector_base() throw();
//	vector_base(const allocator_type& __a);
//	~vector_base();
//
//	void		clear()				throw()
//	{
//		while (_end == _begin)
//			allocator_type::destroy(--_end);
//	}
//	size_type	capacity() const	throw()
//	{
//		return (_capacity);
//	}
//};
//template <typename T>
//vector_base<T>::vector_base(void) throw()
//	:	_capacity(0),
//		_begin(nullptr),
//		_end(nullptr)
//{
//}
//
//template <typename T>
//vector_base<T>::vector_base(void) throw()
//	:	_capacity(0),
//		_begin(nullptr),
//		_end(nullptr)
//{
//}

/* ************************************************************************** */
/* ************************************************************************** */
template <typename T>
class	vector
{
public:
	typedef T											value_type;
	typedef std::allocator<T>							allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
//	typedef typename random access iterator to value_type iterator
//	typedef typename random access iterator to const value_type const_iterator
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef typename std::reverse_iterator<iterator>	reverse_iterator;
	typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::size_type			size_type;

//constructor
// (1) empty container constructor (defalut constructor)
	explicit vector(void) {}
// (2) fill constructor
	explicit vector(size_type n, const value_type& val);
// (3) range constructor
template<class InputIterator>
	vector (InputIterator first, InputIterator last);
// (4) copy constructor
	vector (const vector& x);
//destructor
	~vector(void);
//operator =
	vector<T> &operator=(const vector& x); 
//member function
	iterator begin();
	const_iterator begin() const;
//Capacity
/*
 * size();
 * max_size();
 * empty();
 * resize();
 * capacity();
 * reserve();
*/
    size_type size() const throw ();
    size_type max_size() const throw ();
	size_type	capacity() const throw ();
    bool empty() const throw ();
    void reserve(size_type n);
    void shrink_to_fit() throw ();
//Modifires
/*
 * assign();
 * insert();
 * erase();
 * push_back();
 * pop_back();
 * clear();
 * swap();
*/
//Observers
/*
 * get_allocator();
*/
	private:
		size_type	_capacity;
		size_type	_size;
		pointer		_begin;
		pointer		_end;
};

}
/*
    vector synopsis

namespace std
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n);
    explicit vector(size_type n, const allocator_type&); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    value_type*       data() noexcept;
    const value_type* data() const noexcept;

    void push_back(const value_type& x);
    void push_back(value_type&& x);
    template <class... Args>
        reference emplace_back(Args&&... args); // reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    bool __invariants() const;
};

template <class InputIterator, class Allocator = allocator<typename iterator_traits<InputIterator>::value_type>>
   vector(InputIterator, InputIterator, Allocator = Allocator())
   -> vector<typename iterator_traits<InputIterator>::value_type, Allocator>;

template <class Allocator> struct hash<std::vector<bool, Allocator>>;

template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class T, class Allocator, class U>
typename vector<T, Allocator>::size_type
erase(vector<T, Allocator>& c, const U& value);       // C++20
template <class T, class Allocator, class Predicate>
typename vector<T, Allocator>::size_type
erase_if(vector<T, Allocator>& c, Predicate pred);    // C++20

}  // std

*/
