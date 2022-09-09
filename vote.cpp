#include <iostream>
#include <vector>
#include"vote.h"
#include<algorithm>
using namespace std;


//this is the constructor 
vote::vote(const vector <candidate>& prefs) {
	p = prefs;
}

// returns true if the vote has no preferences left.
bool vote::spent() const {
	if (p.size() == 0) {
		return true;
	}
	return false;
}


//returns the current first preference of the vote. Clients may only call this member function if spent() is false.
candidate vote::first_preference() const {
	
	if (spent() == false) {   //channge made here 
		return p[0];
	}

	return 0;
}

// Candidate C is erased and removed from the vector that stores candidate prefrence. 
void vote::discard(candidate c) {
	

	p.erase(remove(p.begin(), p.end(), c), p.end());
			


}