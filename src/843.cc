#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int countMatch(const string& s1, const string& s2);

struct Master {
    Master(const string& s): _s(s), _times(0) {}

    int guess(const string& s) {
        ++_times;
        cout << "Guessing times: " << _times << endl;
        return countMatch(s, _s);
    }

    string _s;
    int _times;
};

vector<vector<int>> countOccurrence(const vector<string>& wordlist);

void findSecretWord(vector<string>& wordlist, Master& master) {
    vector<string> words = wordlist;
    int nMatch = 0;
    
    for (int i=0; i<10 && nMatch<6; ++i) {
        vector<vector<int>> occurrences = countOccurrence(words);
        vector<string> nextWords;
        int bestScore = 0;
        string wordGuess = words[0];
        
        for (const string& word : words) {
            int score = 0;
            for (int j=0; j<6; ++j) {
                score += occurrences[j][word[j]-'a'];
            }
            if (score > bestScore) {
                bestScore = score;
                wordGuess = word;
            }
        }
        
        nMatch = master.guess(wordGuess);
        cout << wordGuess << " " << nMatch << endl;
        
        for (const string& word : words) {
            if (countMatch(wordGuess, word) == nMatch)
                nextWords.push_back(word);
        }
        words.swap(nextWords);
    }
}

vector<vector<int>> countOccurrence(const vector<string>& words) {
    vector<vector<int>> occurrences(6, vector<int>(26, 0));
    for (auto& word : words) {
        for (int i=0; i<6; ++i) {
            occurrences[i][word[i]-'a']++;
        }
    }
    return occurrences;
}

int countMatch(const string& s1, const string& s2) {
    int n = 0;
    for (int i=0; i<s1.size(); ++i) {
        if (s1[i] == s2[i])
            ++n;
    }
    return n;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"};
    Master m("hbaczn");
    findSecretWord(test_case, m);
    return 0;
}
