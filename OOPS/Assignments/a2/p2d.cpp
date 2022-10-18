#include <bits/stdc++.h>

using namespace std;

class Voter{
	static int countOfVoter;
	static int votes[7]; //spoilt ballot in 0
	int vote;
	public: Voter();
					Voter(int);
					static void appendVote(int);
					static void electionResult();
};
int Voter :: countOfVoter;
int Voter :: votes[7];

Voter :: Voter(){
	cout<<"Value of vote";
	cin>>vote;
	appendVote(vote);
}
Voter :: Voter(int x){
	vote = x;
	appendVote(x);
}
void Voter::electionResult(){
	cout<<"Declaration of election result\n";
	int maxi = 1;
	vector <int> equals(1);
	equals[0] = -1;
	int k = 0;
	for (int i = 1; i < 6; i++){
		cout<<"Candidate "<<i<<" got "<<votes[i]<<" votes\n";
		maxi = (votes[i]>votes[maxi])?i:maxi;
		if (equals[0]!= -1 && votes[maxi] > votes[equals[0]]){
			equals.resize(1);
			equals[0] = -1;
			k = 0;
		}
		if (votes[maxi] == votes[i] && maxi != i)
			equals[k] = (i);

	}
	cout<<"Invalid ballots:"<<votes[0]<<"\n";
	if (equals[0] == -1)
		cout<<"Candidate "<<maxi<<" wins the election with "<<votes[maxi]<<" votes\n";
	else	{
		cout<<"Tie between candidates "<<maxi<<" and ";
		int i;
		//
		for (i = 0; i <= k; i++)
			cout<<equals[i]<<" ";
		cout<<"\n";
	}
}
void Voter::appendVote(int x){
	countOfVoter++;
	if (x<1 || x>5)
		votes[0]++;
	else	
		votes[x]++;
}
int main(){
	int n,y;
	cout<<"Enter number of voters:";
	cin>>n;
	cout<<"Enter votes : ";
	for (int i = 0; i<n;i++){
		cin>>y;
		Voter x(y);
	}
	Voter::electionResult();
	return 0;
}
