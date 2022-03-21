/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:28 by snpark            #+#    #+#             */
/*   Updated: 2022/03/20 17:08:32 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//for referencee
#include <memory>
#include <vector>

namespace ft
{
template <typename T, typename Allocator = std::allocator<T>>
class vector
{
	public:
		typedef T						value_type;
		typedef size_t					size_type; 

		explicit	vector(void) {};
		explicit	vector(size_type n);

		~vector(void) {};

		size_t	capacity() {return static_cast<size_t>(this->_end - this->_beigin);};
	private:
		T*	_begin;
		T*	_end;
		T*	_end_cap;
};
}
