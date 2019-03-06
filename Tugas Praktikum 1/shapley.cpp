#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
 
const char *men_data[][6] = {
    { "V","B","A","D","E","C" },
    { "W","D","B","A","C","E" },
    { "X","B","E","C","D","A" },
    { "Y","A","D","C","B","E" },
    { "Z","B","D","A","E","C" }
};
 
const char *women_data[][6] = {
    { "A","Z","V","W","Y","X" },
    { "B","X","W","Y","V","Z" },
    { "C","W","X","Y","Z","V" },
    { "D","V","Z","Y","X","W" },
    { "E","Y","W","Z","X","V" }
};
 
typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap;
typedef map<string, string> Couples;

bool prefers(const PrefList &prefer, const string &first, const string &second)
{
    for (PrefList::const_iterator it = prefer.begin(); it != prefer.end(); ++it)
    {
        if (*it == first) return true;
        if (*it == second) return false;
    }
    return false; // no preference
}
 
void check_stability(const Couples &engaged, const PrefMap &men_pref, const PrefMap &women_pref)
{
    bool stable = true;
    for (Couples::const_iterator it = engaged.begin(); it != engaged.end(); ++it)
    {
        const string &bride = it->first;
        const string &groom = it->second;
        const PrefList &preflist = men_pref.at(groom);
 
        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it)
        {
            if (*it == bride) // he prefers his bride
                break;
            if (prefers(preflist, *it, bride) && // he prefers another woman
                prefers(women_pref.at(*it), groom, engaged.at(*it))) // other woman prefers him
            {
                cout << "\t" << *it <<
                    " prefers " << groom <<
                    " over " << engaged.at(*it) <<
                    " and " << groom <<
                    " prefers " << *it <<
                    " over " << bride << "\n";
                stable = false;
            }
        }
    }
}
 
int main()
{
    PrefMap men_pref, women_pref;
    queue<string> bachelors;
 
    // init data structures
    for (int i = 0; i < 5; ++i) // person
    {
        for (int j = 1; j < 6; ++j) // preference
        {
              men_pref[  men_data[i][0]].push_back(  men_data[i][j]);
            women_pref[women_data[i][0]].push_back(women_data[i][j]);
        }
        bachelors.push(men_data[i][0]);
    }
 
    Couples engaged; // <woman,man>
 
    while (!bachelors.empty())
    {
        const string &suitor = bachelors.front();
        const PrefList &preflist = men_pref[suitor];
 
        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it)
        {
            const string &bride = *it;
 
            if (engaged.find(bride) == engaged.end()) // she's available
            {
                engaged[bride] = suitor;
                break;
            }
 
            const string &groom = engaged[bride];
 
            if (prefers(women_pref[bride], suitor, groom))
            {
                bachelors.push(groom);
                engaged[bride] = suitor;
                break;
            }
        }
        bachelors.pop();
    }
 
    cout << "Couples:\n";
    for (Couples::const_iterator it = engaged.begin(); it != engaged.end(); ++it)
    {
        cout << "\t" << it->first << " dan " << it->second << "\n";
    }
 
}