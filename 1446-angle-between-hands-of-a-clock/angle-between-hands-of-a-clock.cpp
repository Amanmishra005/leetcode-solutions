class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6.0;
        double HAngle = (hour % 12) * 30 + minutes * 0.5;
        double diff = abs(HAngle - minAngle);
        return min(diff , 360  - diff);
    }
};