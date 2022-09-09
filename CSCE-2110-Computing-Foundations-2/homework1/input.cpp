#include "input.h"

vector<vector<string> > getTweets()
{
    vector<vector<string> > tweetsString;		//a vector of strings for tweets
    string tweetsfile;
    string tempstringholder;

    //Asking for tweets input file
    cout << "What is the name of the file containing the tweets" << endl;
    cin >> tweetsfile;

    //Opening tweets file and error checking
    ifstream infile;

    cin.ignore();

    //Opening files
    infile.open(tweetsfile);

    //Error checking files
    if (infile.fail())
    {
        cout << "Sorry the tweet file could not be found. Please enter a correct file name." << endl;
        exit(EXIT_FAILURE);
    }

    //Read in all the tweets in the tweets file
    while (!infile.eof())
    {
        getline(infile, tempstringholder);
//        tempstringholder.pop_back();
        transform(tempstringholder.begin(), tempstringholder.end(), tempstringholder.begin(), ::tolower);
        int startpostion = 0;
        int endpostion = 0;
        vector<string> line;
        do {
            endpostion = tempstringholder.find(' ', endpostion);
            line.push_back(tempstringholder.substr(startpostion, endpostion - startpostion));
            startpostion = ++endpostion;
        } while (startpostion != 0);
        //Removing Stopwords function
        tweetsString.push_back(line);
    }
    return tweetsString;
}

vector<string> getStopWords()
{
    vector<string> stopWords;
    string tempstringholder;
    ifstream stopfile;
    string stopwordsfile;				//prompting and entering file

    //Asking for stopwords input file
    cout << "What is the name of the file containing the stopwords" << endl;
    cin >> stopwordsfile;

    cin.ignore();

    stopfile.open(stopwordsfile);

    if (stopfile.fail())
    {
        cout << "Sorry the stop words file could not be found. Please enter a correct file name." << endl;
        exit(EXIT_FAILURE);
    }

    //Read in all the stopwords from file and store in a vector
    while (!stopfile.eof())
    {
        getline(stopfile, tempstringholder);
        tempstringholder.pop_back();
        stopWords.push_back(tempstringholder);
    }
    return stopWords;
}