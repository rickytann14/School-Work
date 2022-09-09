#ifndef Tweet_H
#define Tweet_H
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Tweet
{
    static void updateTweets();
    static vector<string> bagOfWords;
    static vector<Tweet*> tweets;
    static int tweetCount;
    void update();
    void removeStopWords();
    vector<int> bitVector;
    vector<string> stringSetVector;
    vector<string> rawTweet;

public:
    static vector<string> stopWords;
    Tweet(vector<string>);
    vector<int> getBitVector();
    void outputTweetSet();
    void outputRawTweet();
    string label;
};

#endif