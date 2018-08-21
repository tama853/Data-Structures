#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

//struct Score
//{
//    string name;
//    int score;
//};

//does this work like in the video with Fox?
   // vector<Score> scores;
   // scores.push_back({"Bob",50});
    //scores.push_back({"Jim",50});
    
    //one data type
    //vector<int>
    //vector<vector<string>>
    //
    //map works on 2 types
    //

   // map<string, int> scores; //the first key is unique and can't have the same key give multilp outputs. Like a function. But we can have different keys have the same value

    // map<Bob, 20>
    // map<Jim, 20>
    //
    // can't have 
    // map<Bob, 20>
    // map<Bob, 50>
int main()
{
    
    map<string,int> scores;

    scores.emplace("Jim", 50);
    scores.emplace("Stacey", 50);
    scores.emplace("Bob", 50);

    string input;
    int score = scores["Jim"];
    cout << score << endl;
    cin >> input;

    if (scores.find(input) != scores.end())
    cout << scores[input];   //case sensitive



    return 0;
}

