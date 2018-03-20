#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map> 
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/range/iterator_range.hpp>

using namespace std;
using namespace boost;

//clang++ -std=c++1z -I /usr/local/opt/boost/include -L /usr/local/opt/boost/lib 9-4-common-word.cpp -lboost_filesystem -lboost_system
/* My result:

The 20 most common words in the input texts of Pride and Prejudice by Jane Austen (1458)
Frankenstein; Or, The Modern Prometheus by Mary Wollstonecraft Shelley (587)
Alice's Adventures in Wonderland by Lewis Carroll are the following.
Top No.1	the 	: 9932
Top No.2	and 	: 7069
Top No.3	to 	    : 7040
Top No.4	of 	    : 7003
Top No.5	I 	    : 4726
Top No.6	a 	    : 4006
Top No.7	in 	    : 3342
Top No.8	was 	: 3124
Top No.9	that 	: 2655
Top No.10	her 	: 2386
Top No.11	my 	    : 2279
Top No.12	not 	: 1988
Top No.13	had 	: 1985
Top No.14	she 	: 1974
Top No.15	with 	: 1951
Top No.16	as 	    : 1852
Top No.17	his 	: 1772
Top No.18	you 	: 1750
Top No.19	be 	    : 1718
Top No.20	it 	    : 1681

*/
void words_count();

int main()
{
	cout << "The 20 most common words in the input texts of ";
	cout << "Pride and Prejudice by Jane Austen (1458)" << endl
         << "Frankenstein; Or, The Modern Prometheus by Mary Wollstonecraft Shelley (587)"<<endl
         << "Alice's Adventures in Wonderland by Lewis Carroll "<<"are the following."<<endl ;

	filesystem::path p("./text/");
	std::map<string, int> direc;
	std::vector<string> vec;

	for (auto entry : boost::make_iterator_range(filesystem::directory_iterator(p), {}))
	{
		string temp;
		string path = entry.path().string();
		ifstream read(path);
		while (read >> temp)
		{
			vec.push_back(temp);
		}
		read.close();
	}

	for (auto it : vec)
		direc[it]++;

	multimap<int, string, greater<int> > counter;

	transform(direc.begin(), direc.end(), std::inserter(counter, counter.begin()), [] (const std::pair<std::string, int> &pr){
	 	return std::pair<int, std::string>(pr.second, pr.first); } );

	int count = 0;
	for (auto it = counter.begin(); count < 20 && it != counter.end(); ++it, ++count)
		cout <<"Top No."<<count+1<<"\t"<<it->second << " \t: " << it->first << endl;

	return EXIT_SUCCESS;
}