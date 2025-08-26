#include <iostream>
#include <string>
using namespace std;



int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    if (m > n) return -1;

    for (int i = 0; i <= n - m; i++) {
        if (haystack.substr(i, m) == needle) {
            return i;
        }
    }

    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    int index = strStr(haystack, needle);

    cout << "Haystack: " << haystack << endl;
    cout << "Needle: " << needle << endl;
    cout << "First occurrence index: " << index << endl;

    return 0;
}
