#include <string>
#include <iostream>

using namespace std;

int main()
{
    string stop_words = "has,no,this";
    string sentence = "This sentence has no stop words";
    //getline(cin, stop_words);
    //getline(cin, sentence);

    // remove stop_words from sentence here
    stop_words+=',';
 
    
    string interim_Words; 
    int stopWordsCt=0;

    for(int i = 0; i < stop_words.length(); i++){
      if(stop_words[i]==',')
        stopWordsCt++;
    }

    string eraseWords[stopWordsCt];

    for(int i = 0; i < stopWordsCt; i++){
      interim_Words = stop_words.substr(0, stop_words.find(','));
      eraseWords[i] += interim_Words + ' ';
      stop_words.erase(0,stop_words.find(',')+1);
    }

    for(int i = 0; sentence.find(eraseWords[i]) <= sentence.length(); i++){
      for(int x = 0; x <= stopWordsCt; x++){
        if(sentence.find(eraseWords[x]) < sentence.length())
          sentence.erase(sentence.find(eraseWords[x]), eraseWords[x].length());
      }
    }

    cout << sentence << "\n";
}
// While loop is better, i just did for loop initally so I'm keeping it
    // while(sentence.find(eraseWords[x]) <= sentence.length()){
    //   sentence.erase(sentence.find(eraseWords[x], eraseWords[x].length()));
    //   x++;
    // }