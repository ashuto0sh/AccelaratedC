#pragma once

#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace meow {
	namespace detail {
		struct vectorlike_tag {};
		struct listlike_tag {};
		struct associative_tag {};

		template <typename C> struct container_traits;

		template <typename T, typename A> struct container_traits<std::vector<T, A>> {
			typedef vectorlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::deque<T, A>> {
			typedef vectorlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::list<T, A>> {
			typedef listlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::forward_list<T, A>> {
			typedef listlike_tag category;
		};

		template <typename K, typename T, typename C, typename A> struct container_traits<std::map<K, T, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename T, typename C, typename A> struct container_traits<std::unordered_map<K, T, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename C, typename A> struct container_traits<std::set<K, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename C, typename A> struct container_traits<std::unordered_set<K, C, A>> {
			typedef associative_tag category;
		};

		template <typename Container, typename X> void erase_helper(Container& c, const X& v, vectorlike_tag) {
			c.erase(std::remove(c.begin(), c.end(), x), c.end());
		}

		template <typename Container, typename Pred> void erase_helper(Container& c, Pred f, vectorlike_tag) {
			c.erase(std::remove_if(c.begin(), c.end(), f), c.end());
		}

		template <typename Container, typename X> void erase_helper(Container& c, const X& v, listlike_tag) {
			c.remove(v);
		}

		template <typename Container, typename Pred> void erase_helper(Container& c, Pred f, listlike_tag) {
			c.remove_if(f);
		}

		template <typename Container, typename X> void erase_helper(Container& c, const X& v, associative_tag) {
			c.erase(x);
		}

		template <typename Container, typename Pred> void erase_helper(Container& c, Pred f, associative_tag) {
			for (auto it = c.begin(); it != c.end(); ) {
				if (f(*it))
					c.erase(it);
				else
					++it;
			}
		}
	}

	template <typename Container, typename X> void erase(Container& c, const X& v) {
		detail::erase_helper(c, v, typename detail::container_traits<Container>::category());
	}

	template <typename Container, typename Pred> void erase_if(Container& c, Pred f) {
		detail::erase_helper(c, f, typename detail::container_traits<Container>::category());
	}
}
