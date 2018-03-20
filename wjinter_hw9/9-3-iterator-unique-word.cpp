#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <boost/timer.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/range/iterator_range.hpp>

using namespace std;
using namespace boost;

int std_set();
int std_unordered_set();

//using std_unordered_set is faster as std_unordered_set 0.17902 sec and std_set 0.44522 sec.
//the reason is because it is unordered thus ordering time is neglected.
//yes, it does depend on the input size. i tested using different text.

int main()
{

	cout << "The numbers of unique words using ordered and unordered sets in the input texts of ";
    cout << "Pride and Prejudice by Jane Austen (1458)" << endl
         << "Frankenstein; Or, The Modern Prometheus by Mary Wollstonecraft Shelley (587)"<<endl
         << "Alice's Adventures in Wonderland by Lewis Carroll "<<"are the following."<<endl ;

	cout << "Number of Unique Words using std::set<string>: ";

    boost::timer t; // start timing
	cout << std_set() <<endl;

	cout << t.elapsed() << endl;;

	cout << "Number of Unique Words using std::unordered_set<string>: ";

    boost::timer w; // start timing

	cout << std_unordered_set()<<endl;

	cout << w.elapsed() << endl;;

	return 0;
}

int std_set()
{
	filesystem::path p("./text/");
	std::set<string> unique_word_amount;

	for (auto entry : boost::make_iterator_range(filesystem::directory_iterator(p), {}))
	{
		string temp;
		string path = entry.path().string();

		ifstream read(path);
		while (read >> temp)
		{
			unique_word_amount.insert(temp);
		}

		read.close();
	}

	return unique_word_amount.size();
}

int std_unordered_set()
{
	filesystem::path p("./text/");
	std::unordered_set<string> unique_word_amount;

	for (auto entry : boost::make_iterator_range(filesystem::directory_iterator(p), {}))
	{
		string temp;
		string path = entry.path().string();

		ifstream read(path);
		while (read >> temp)
		{
			unique_word_amount.insert(temp);
		}

		read.close();
	}

	return unique_word_amount.size();
}
