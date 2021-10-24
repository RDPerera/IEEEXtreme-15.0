#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int T; //number of games
    cin >> T;
    while (T--) //for each game
    {
        int N; //for each game there are N rounds
        cin >> N;

        vector<int> die1; //to keep die 1 values
        vector<int> die2; //to keep die 2 values
        int alice, bob;
        int aliceTotal = 0;
        int bobTotal = 0;
        bool currentAliceDie1 = true;
        while (N--)
        {
            cin >> alice >> bob;
            aliceTotal += alice;
            bobTotal += bob;
            if (currentAliceDie1)
            {
                die1.push_back(alice);
                die2.push_back(bob);
            }
            else
            {
                die2.push_back(alice);
                die1.push_back(bob);
            }

            if (aliceTotal != bobTotal) //change the die
            {
                currentAliceDie1 = !currentAliceDie1;
            }
        }

        int die1Count = 0;
        int die2Count = 0;

        //counting number of 6's in each vector
        for (int i = 0; i < die1.size(); ++i)
        {
            if (die1[i] == 6)
            {
                die1Count++;
            }

            if (die2[i] == 6)
            {
                die2Count++;
            }
        }

        if (die1Count > die2Count)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}