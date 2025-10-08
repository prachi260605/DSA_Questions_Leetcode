// counting sort + lower_bound
class Solution {
public:
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001]={0}, pMax=0, pMin=1e5+1;
        for(int p: potions){
            freq[p]++;
            pMin=min(pMin, p);
            pMax=max(pMax, p);
        }
        for(int p=pMin, i=0; p<=pMax; p++){
            const int f=freq[p];
            if (f==0) continue;
            fill(potions.begin()+i, potions.begin()+(i+f), p);
            i+=f;
        }
        const int n=spells.size();
        vector<int> result(n, 0);
        
        const int m=potions.size();
        const int maxPotion=potions[m-1];

        for (int i=0; i<n; i++) {
            int spell=spells[i];
            long long k = (success+spell-1)/spell;
            if (k<=maxPotion) {
                result[i]=m-(lower_bound(potions.begin(), potions.end(), k)-potions.begin());
            }
        }       
        return result;
    }
};