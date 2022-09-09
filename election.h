#ifndef ELECTION_H
#define ELECTION_H
#include<vector>
#include<iostream>
#include<map>

#include"vote.h"

using namespace std;


class election
{
public:
	election();
	void add_vote(const vote& v);
	int vote_count() const;
	void eliminate(candidate c);
	vector<pair<candidate, int>> ranked_candidates() const;


private: 
	
	vector<vote>collection;
	vector<pair<candidate, int>> outcome;


};
election read_votes(istream& in);
#endif // ELECTION_H