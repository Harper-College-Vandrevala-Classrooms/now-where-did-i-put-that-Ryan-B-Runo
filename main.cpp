#include <cassert>
#include <string>

using namespace std;

string toLower(string s){
    string res;
    for(char c : s){
        res += tolower(c);
    }
    return res;
}

int find(string s, char c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int find(string s, string c) {
    if (c.empty()) { //this block not included in char version because empty chars don't exist.
        return -1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, c.length()) == c) {
            return i;
        }
    }
    return -1;
}

int find(string s, char c, bool caseInsensitive) {
    if(caseInsensitive){
        return find(toLower(s), tolower(c));
    }else{
        return find(s, c);
    }
}

int find(string s, string c, bool caseInsensitive) {
    if(caseInsensitive){
        return find(toLower(s), toLower(c));
    }else{
        return find(s, c);
    }
}

int main() {
    //testing empty strings
    assert(find("", "") == -1);
    assert(find("", "n") == -1);
    assert(find("b", "") == -1);

    //Testing one character
    assert(find("n", "n") == 0);

    //Testing same character
    assert(find("nnn", "nnn") == 0);

    //Testing oversized c
    assert(find("s", "nssssssssssssssssssssss") == -1);

    //Testing chars
    assert(find("a", 'a') == 0);
    assert(find("abc", 'b') == 1);

    //Testing numbers
    assert(find("111", 1) == -1);
    assert(find("a2a", "2") == 1);
    assert(find("a2a", '2') == 1);

    //Testing spaces
    assert(find("a2 a", " ") == 2);
    assert(find("a2 a", ' ') == 2);

    //Testing last index
    assert(find("bbba", "a") == 3);

    // Example
    assert(find("banana", "nan") == 2);

    //Testing case sensitivity
    assert(find("a2aA", "A", true) == 0);
    assert(find("a2 bCD", " B", true) == 2);
}