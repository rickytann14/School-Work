#include "Tweet.h"
// Constructor that uses a string vector to create a set
Tweet::Tweet(vector<string> stringSet)
{
    bool bagOfWordsUpdated = false, found = false;
//    create a unique label
    label = "Tweet # " + to_string(tweetCount);
    rawTweet = stringSet;
    removeStopWords();
    bitVector.assign(bagOfWords.size(), 0);

//    Compares each element in string set to the universal set
    for(int i = 0; i < stringSetVector.size(); i++)
    {
        for(int j = 0; j < bagOfWords.size(); j++)
        {
            if(stringSetVector[i] == bagOfWords[j])
            {
                bitVector[j] = 1;
                found = true;
            }
        }
//        if the item is not found in the universal set it is appended
        if(!found)
        {
            Tweet::bagOfWords.push_back(stringSetVector[i]);
            bitVector.push_back(1);
            bagOfWordsUpdated = true;
        }
        found = false;
    }
//    increment tweet count used as unique label
    tweetCount++;
    if(bagOfWordsUpdated)
    {
        Tweet::updateTweets();
    }
    Tweet::tweets.push_back(this);
}

vector<int> Tweet::getBitVector()
{
    return bitVector;
}

void Tweet::outputTweetSet()
{
    cout << label << endl;
    for(int i = 0; i < stringSetVector.size(); i++)
    {
        cout << "   " << stringSetVector[i];
    }
    cout << endl << endl;
}

void Tweet::outputRawTweet()
{
    for(int i = 0; i < rawTweet.size(); i++)
    {
        cout << rawTweet[i] << " ";
    }
    cout << endl;
}

void Tweet::update()
{
    while (bagOfWords.size() - bitVector.size() > 0)
        bitVector.push_back(0);
}

void Tweet::updateTweets()
{
    for(int i = 0; i < tweets.size(); i++)
        tweets[i]->update();
}

void Tweet::removeStopWords()
{
    bool isStopWord = false;
    for(int i = 0; i < rawTweet.size(); i++)
    {
        for(int j = 0; j < stopWords.size(); j++)
        {
            if(rawTweet[i] == stopWords[j])
            {
                isStopWord = true;
            }
        }
        if(!isStopWord)
        {
            stringSetVector.push_back(rawTweet[i]);
        }
        isStopWord = false;
    }
}

vector<string> Tweet::bagOfWords;
vector<string> Tweet::stopWords;
vector<Tweet*> Tweet::tweets;
int Tweet::tweetCount = 0;