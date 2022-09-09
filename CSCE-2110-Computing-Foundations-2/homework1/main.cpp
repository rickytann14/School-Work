#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Tweet.h"
#include "cos_sim.h"
#include "input.h"

using namespace std;

int main()
{
//    vector of string vectors to store each line of input
    vector<vector<string> > input = getTweets();
//    assigns a value to vector<string> stopWords used to remove stop words
    Tweet::stopWords = getStopWords();
//    vector of set pointers to store the training tweets
    vector<Tweet*> trainingTweets;
//    vector of set pointers to stote the testing tweets
    vector<Tweet*> testingTweets;
//    integer used to iterate through input vector
    int lineCount = 0;
//    iterates through each vector in input until it finds a vector of a single element
    for (; lineCount < input.size(); lineCount++)
    {
//        breaks out of the loop when it finds the
        if(input[lineCount].size() == 1)
        {
            lineCount++;
            break;
        }
//        creates a set using the string vector at lineCount and adds the pointer to trainingTweets vector
        trainingTweets.push_back(new Tweet(input[lineCount]));
    }
//    iterates through the rest of the input vector
    for (; lineCount < input.size(); lineCount++)
    {
//        creates a set using the string vector at lineCount and adds the pointer to trainingTweets vector
        testingTweets.push_back(new Tweet(input[lineCount]));
    }

    for(int i = 0; i < testingTweets.size(); i++)
    {
        vector<double> scores;
        testingTweets[i]->outputRawTweet();
        for (int j = 0; j < trainingTweets.size(); j++)
        {
            scores.push_back(cos_sim(trainingTweets[j]->getBitVector(), testingTweets[i]->getBitVector()));
        }
        for(int j = 0; j < 5; j++)
        {
            double currentTopScore = 0;
            int scorePositin = 0;
            for(int k = 0; k < scores.size(); k++)
            {
                if(scores[k] >= currentTopScore)
                {
                    currentTopScore = scores[k];
                    scorePositin = k;
                }
            }
            cout << j+1 << " " << currentTopScore << " " << trainingTweets[scorePositin]->label << endl;
            currentTopScore = 0;
            scores[scorePositin] = -1;
            scorePositin = 0;
        }
        cout << endl;
    }
    for(int i = 0; i < trainingTweets.size(); i++)
    {
        trainingTweets[i]->outputTweetSet();
    }
}
