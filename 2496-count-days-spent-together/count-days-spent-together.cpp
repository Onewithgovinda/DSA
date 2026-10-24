
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        // Find the common starting and ending dates
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        // Days before each month
        int days[] = {0, 31, 59, 90, 120, 151,
                      181, 212, 243, 273, 304, 334};

        // Convert dates into day numbers
        int startDay = days[stoi(start.substr(0, 2)) - 1]
                     + stoi(start.substr(3));

        int endDay = days[stoi(end.substr(0, 2)) - 1]
                   + stoi(end.substr(3));

        // Count common days, including both endpoints
        return max(0, endDay - startDay + 1);
    }
};