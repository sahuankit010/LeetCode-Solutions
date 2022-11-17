class ParkingSystem {
public:
    struct park{
        int bi, med, sma;
    }p;
    ParkingSystem(int big, int medium, int small) {
        // park p;
        p.bi = big;
        p.med = medium;
        p.sma = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(p.bi==0) return false;
            p.bi--;
            return true;
        } else if(carType == 2){
            if(p.med==0) return false;
            p.med--;
            return true;
        } else{
            if(p.sma==0) return false;
            p.sma--;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */