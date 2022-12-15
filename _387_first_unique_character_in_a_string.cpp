#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
/** Given a string s, find the first non-repeating character in 
 *  it and return its index. If it does not exist, return -1.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        // create a list to store candidates
        list<int> candidates;
        // create a set to store characters
        map<char, list<int>::iterator> map_of_characters;

        // read all characters of the string
        for (int i = 0; i < s.length(); i++)
        {
            char key = s[i];
            // if the character is in the map -> remove it from candidate list if it is on the list
            if (map_of_characters.count(key))
            {
                if (map_of_characters[key] != candidates.end())
                {
                    candidates.erase(map_of_characters[key]);
                }
                map_of_characters[key] = candidates.end();
            }
            else 
            {
            // if the character is not in the map -> insert charater, and the position
                map_of_characters[key] = candidates.emplace(candidates.end(), i);
            }
        }
        return candidates.empty()? -1 : candidates.front();
    }
};


int main() {
    Solution solution;
    map <string, int> m;
    m["leetcode"] = 0;
    m["loveleetcode"] = 2;
    m["aabb"] = -1;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (solution.firstUniqChar(it->first) != it->second)
        {
            cout << "Test case " + it->first + " failed!" << endl;
        }
        else {
            cout << "Test case " + it->first + " pass!" << endl;
        }
    }

    return 0;
}