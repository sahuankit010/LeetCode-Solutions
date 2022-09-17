class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> maxB;
    
        int i=0, diff =0; 
        for(i=0; i<heights.size()-1; i++){ 
            diff = heights[i+1]-heights[i];
            
            
            if(diff <= 0){
                continue;
            }

            bricks -= diff; //taking the bricks needed for going to next building.
            maxB.push(diff); //adding the number of bricks used in priority queue.
            
            if(bricks < 0){
                bricks += maxB.top(); //taking back bricks from that step
                maxB.pop(); //As max bricks were removed so pop
                ladders--; //1 ladder used
            }

            if(ladders < 0) break;
        }
        
        // return the present position.
        return i;

    }
};