#include <bits/stdc++.h>
using namespace std;

/*
Input
Input will consist of a series of lines. No line will be more than 80 characters long, but may contain any
number of words. Words consist of up to 20 upper and/or lower case letters, and will not be broken
across lines. Spaces may appear freely around words, and at least one space separates multiple words
on the same line. Note that words that contain the same letters but of differing case are considered to
be anagrams of each other, thus ‘tIeD’ and ‘EdiT’ are anagrams. The file will be terminated by a line
consisting of a single ‘#’.
Output
Output will consist of a series of lines. Each line will consist of a single word that is a relative ananagram
in the input dictionary. Words must be output in lexicographic (case-sensitive) order. There will always
be at least one relative ananagram.
Sample Input
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
Sample Output
Disk
NotE
derail
drIed
eye
ladder
soon
*/
const vector<int> letterInit(26, 0);//26 letters list
vector<int> getLetterInWord(string word){//update 26 letters list for one word
    vector<int> letters(letterInit);
    for(string::const_iterator iter = word.begin(); iter != word.end(); ++iter){
        ++letters[tolower(*iter) - 'a'];
    }
    return letters;
}
bool isLettersEqual(const vector<int>& a, const vector<int>& b){//compare 2 letters list
    for (int i = 0; i < 26; ++i){
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int main(){
    string word;
    vector<string> words;
    vector<vector<int> > wordLetters;//letters list for all words
    while(cin>>word, word != "#"){
        words.push_back(word);
        wordLetters.push_back(getLetterInWord(word));
    }
    vector<bool> isAnanagram(words.size(), true);
    for (int i = 0; i < words.size(); ++i){
        if (isAnanagram[i]){
            for (int j = i + 1; j < words.size(); ++j){
                if (isLettersEqual(wordLetters[i], wordLetters[j])){
                    isAnanagram[i] = false;
                    isAnanagram[j] = false;
                }
            }
        }
    }
    vector<string> results;//store all the ananagrams due to sort
    for (int i = 0; i < words.size(); ++i){
        if (isAnanagram[i]){
            results.push_back(words[i]);
        }
    }
    sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); ++i){
        cout << results[i] << endl;
    }
}
