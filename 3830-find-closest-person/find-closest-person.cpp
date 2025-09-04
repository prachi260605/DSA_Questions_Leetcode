class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xSpeed = abs(z-x);
        int ySpeed = abs(z-y);

        if(xSpeed< ySpeed){
            return 1;
        }
        else if(xSpeed > ySpeed){
            return 2;
        }
        else return 0;
    }
};