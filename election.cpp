#include "election.h"
#include "vote.h"

#include<iostream>
#include<string>
#include <sstream>
#include <algorithm>

#include<utility>
using namespace std;

election::election() = default;
//this function adds induvidual votes to a vector called collection
void election::add_vote(const vote& v) {
	collection.push_back(v);

}

// this returns the number of votes in a collection
int election::vote_count() const {
	return collection.size();

}



//eiminates induvidual candidates from each votes and votes which are empty are eliminated. 
void election::eliminate(candidate c) {
	bool m = false; 
	for (auto i = 0; i < collection.size(); i++) {
	 
		collection[i].discard(c);

		
	}

	
collection.erase(remove_if(collection.begin(), collection.end(), [](vote& v) {return v.spent(); }), collection.end());

	

}
//  This functions counts the number of times a candidate in chosen, it laters sorts the pair list. 
vector<pair<candidate, int>> election::ranked_candidates() const {
	vector<pair<candidate, int>> outcome;
	vector<candidate> list;
	pair<candidate, int> pairs;

	typedef vector<vote>::size_type vec_size;
	vec_size k = 0;

	while (k < collection.size()) {
		list.push_back(collection[k].first_preference());
		k++;
	}
	
	for (vec_size s = 0; s < collection.size(); s++) {
		pairs.first = collection[s].first_preference();
		pairs.second = count(list.cbegin(), list.cend(), pairs.first);
		outcome.push_back(pairs);
	
	}

	
	sort(outcome.begin(), outcome.end());
    sort(outcome.begin(), outcome.end(), [](auto& one, auto& two) {
		return one.second < two.second;});
	outcome.erase(unique(outcome.begin(), outcome.end()), outcome.end());
	reverse(outcome.begin(), outcome.end());
	return outcome;

}
//reads votes from the file, stores it into vote object and that object is added into the election
election read_votes(istream& in) {
	election e;
	string line;

	while (getline(in, line)) {

		stringstream s(line);
		int num;

		vector<candidate> prefr;
		while (s >> num) {
			prefr.push_back(num);


		}
		
		e.add_vote(vote(prefr));
	}

	return e;

}

