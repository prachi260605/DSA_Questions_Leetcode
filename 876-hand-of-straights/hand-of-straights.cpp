class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) {
            // not enough cards for grouping
            return false;
        }

        // Sort the array of cards
        sort(hand.begin(), hand.end());

        // Store count of every card in a map
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) {
            m[hand[i]]++;
        }

        for(int i=0; i<hand.size(); i++) {
            if (m[hand[i]] == 0) {
                // All cards of value hand[i] card were already used in another group(s)
                continue;
            }

            // Try constructing a group with starting card as hand[i]
            m[hand[i]]--;            
            int num = hand[i]+1;
            int count = groupSize-1;

            // find groupSize-1 more consecutive cards in the map
            while(count--) {
                if(m[num] == 0) {
                    // Can't find a consecutive card, return false
                    return false;
                }
                // Found a consecutive card. Decrease its count from map.
                m[num]--;
                num++; 
            }
        }
        return true;
    }
};