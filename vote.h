#ifndef VOTE_H
#define VOTE_H
#include<vector>
using namespace std;

typedef unsigned int candidate;
class vote
{


public:
	vote(const vector <candidate>& prefs);
	bool spent() const;
	candidate first_preference() const;
	void discard(candidate c);




private:
	vector <candidate> p;

};

#endif // VOTE_H