class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int countR =0, countL = 0;
        
        for( char c: moves){
            if(c == 'L') countL++;
            else if(c=='R') countR++;
        }
        
        if(countL<countR){
            return -countL+moves.size()-countL;
        }
        
        return -countR + moves.size()-countR;
        
    }
};