#ifndef PAIR_H
#define PAIR_H
#include "Set.h"
#include "string"
using namespace std;

template<typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
	// Construct a pair from two values.
	Pair(const T1& x, const T2& y) : first(x), second(y) {}

	// Construct a default pair.
	Pair() : first(T1()), second(T2()) {}

	// Construct a default pair.
	explicit Pair(const T1& x) : first(x), second(T2()) {}

	// Construct an assignable pair
	template<typename Other_T1, typename Other_T2>
	Pair(const Pair<Other_T1, Other_T2>& other)
	{
		first = other.first;
		second = other.second;
	}
};
template<>
struct Pair<string, string>
{
    string first;
    string second;
    friend ostream& operator<<(ostream& out, const Pair& pair)
    {
        out << pair.first << " -> " << pair.second;
        return out;
    }
};
template<>
struct Pair<string, Set<string>> {
    string first;
    Set<string> second;
    friend ostream& operator<<(ostream& out, const Pair& pair) {
            out << pair.first << "->";
            out << pair.second.toString();
            return out;
    }
};

#endif // PAIR_H