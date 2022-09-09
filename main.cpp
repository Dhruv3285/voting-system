#include"vote.h"
#include"election.h"
#include<fstream>
#include <iostream>
#include <vector>



int main()

{
	election e;

	fstream in("votes.txt");
	e = read_votes(in);

	

	
	auto rank = e.ranked_candidates();
	int n=1;
	for (auto i = rank.size(); i > 1;i--) {
		cout << "Round "  << n << ": " << e.vote_count()<<" " <<"votes" << endl;
		cout << "first prefrences: " << endl;
		
		rank = e.ranked_candidates();
		n++;
	for (int k = 0; k < rank.size(); k++) {
		cout<<"  " << "candidate " << rank[k].first << ":" << rank[k].second << endl;
		}
		candidate k = rank[rank.size() - 1].first;
			e.eliminate(k);
			cout << "candidate " << k << " is eliminated" << endl;
			cout << "   " << endl;
		


			if (rank[0].second > e.vote_count()/2) {
				cout << "candidate " << rank[0].first << " " << "is selected" << endl;
				break;
			
			}
			
	}
	





}

