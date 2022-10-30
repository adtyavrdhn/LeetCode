class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double angleofMin = (6.0)*minutes;
        
        double angleofHour = 30.0*(hour==12 ? 0 : (double)hour) + (double)(minutes)*0.5;
        
        cout<<angleofHour<<" "<<angleofMin<<endl;
        
        double res = abs(angleofMin-angleofHour);
        
        return min(360-res,res);
    }
};