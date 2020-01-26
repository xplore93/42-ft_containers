/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/26 18:39:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "test/test.hpp"
# include <functional>
# include <map>
# include <vector>

template<typename key_type, typename value_type>
void test_Map(void)
{
	std::cout << "---basic\n\n";

	ft::Map<key_type, value_type> empty_map;
	if (empty_map.begin() == empty_map.end())
		std::cout << "[begin] == [end] on empty map" << '\n';
	else
		std::cout << "!!! [begin] != [end] on empty map !!!" << '\n';
	std::cout << "max_size = " << empty_map.max_size() << '\n';
	std::cout << "empty? " << empty_map.empty() << '\n';
	std::cout << "empty map size = " << empty_map.size() << '\n';

	ft::Map<key_type, value_type> mp;
	mp[5] = 42;
	mp[7] = 28;
	mp[9] = 44;

	std::cout << "map [5:42, 7:28, 9:44].size() = " << mp.size() << '\n';
	typename ft::Map<key_type, value_type>::iterator it = mp.begin();
	std::cout << "[5:42, 7:28, 9:44].[5] = " << mp[5] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';
	it = --mp.end();
	std::cout << "[5:42, 7:28, 9:44].[9] = " << mp[9] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';

	ft::Map<key_type, value_type> mp2 = mp;

	display_container("copied map2 [5:42, 7:28, 9:44]:", mp2);
	mp2.clear();
	display_container("cleared map2 []:", mp2);

	display_container("map [5:42, 7:28, 9:44]:", mp);
	mp.erase(7);
	display_container("map [5:42, 9:44]:", mp);
	mp.erase(5);
	display_container("map [9:44]:", mp);
	mp.erase(9);
	display_container("map []:", mp);

	std::cout << "\n---basic (bigger map)\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5, 5));
		mp.insert(std::make_pair(6, 6));
		mp.insert(std::make_pair(7, 7));
		mp.insert(std::make_pair(8, 8));
		mp.insert(std::make_pair(9, 9));
		mp.insert(std::make_pair(10, 10));
		mp.insert(std::make_pair(11, 11));

		display_container("map [5:5, ..., 11:11]:", mp);
		mp.erase(7);
		display_container("map no 7 [5:5, ..., 11:11]:", mp);
		mp.erase(5);
		display_container("map no 7, 5 [5:5, ..., 11:11]:", mp);
		mp.erase(++mp.begin(), --mp.end());
		display_container("map [6:6, 11:11]:", mp);

		mp.key_comp();
		mp.value_comp();
	}
}

template<typename key_type, typename value_type>
void ah(void)
{
	/*std::map<int, int> mapp;
	mapp.insert(std::make_pair(5, 42));
	std::cout << mapp[5] << std::endl;*/

	ft::Map<int, int> map;

	std::cout << "empty map iterator check: ";
	if (map.begin() == map.end())
		std::cout << "begin == end, OK\n";
	else
		std::cout << "!!! begin != end !!!\n";

	map[5] = 42;
	std::cout << "42 => " << map[5] << std::endl;
	map[5] = 43;
	std::cout << "43 => " << map[5] << std::endl;
	map[10] = 42;
	std::cout << "42 => " << map[10] << std::endl;

	map[6] = 44;
	map[7] = 45;
	map[8] = 46;
	map[9] = 47;
	map[11] = 48;
	map[12] = 49;

	std::cout << "[5 => 43, 6 => 44, 7 => 45, 8 => 46, 9 => 47, 10 => 42, 11 => 48, 12 => 49]:\n";

	ft::Map<int, int>::iterator it = map.begin();
	ft::Map<int, int>::iterator ite = map.end();
	while (it != ite)
	{
		std::cout << "it.first " << it->first << " it.second " << it->second << '\n';
		++it;
	}

	it = map.lower_bound(6);
	std::cout << "lower_bound(6)[44]: " << (*it).second << std::endl;
	it = map.lower_bound(2);
	std::cout << "lower_bound(2)[43]: " << (*it).second << std::endl;
	it = map.lower_bound(99);
	std::cout << "lower_bound(99)[end]: " << ((it == map.end()) ? "== end()" : "!!! != end() !!!") << std::endl;

	it = map.upper_bound(6);
	std::cout << "upper_bound(6)[45]: " << (*it).second << std::endl;
	it = map.upper_bound(2);
	std::cout << "upper_bound(2)[43]: " << (*it).second << std::endl;
	it = map.upper_bound(99);
	std::cout << "upper_bound(99)[end]: " << ((it == map.end()) ? "== end()" : "!!! != end() !!!") << std::endl;
}

#endif
