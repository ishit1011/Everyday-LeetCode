class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceMStart = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0');
        int aliceMEnd = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0');

        int aliceDStart = (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0');
        int aliceDEnd = (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0');

        int aliceStartDay = 0, aliceEndDay = 0;
        if(aliceMStart <= 1) aliceStartDay = aliceDStart;
        else{
            int sumDays = 0;
            for(int i=0; i<aliceMStart-1; i++){
                sumDays += monthDays[i];
            }
            aliceStartDay = sumDays + aliceDStart;
        }

        if(aliceMEnd <= 1) aliceEndDay = aliceDEnd;
        else{
            int sumDays = 0;
            for(int i=0; i<aliceMEnd-1; i++){
                sumDays += monthDays[i];
            }
            aliceEndDay = sumDays + aliceDEnd;
        }

        // -----------------

        int bobMStart = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0');
        int bobMEnd = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0');

        int bobDStart = (arriveBob[3]-'0')*10 + (arriveBob[4]-'0');
        int bobDEnd = (leaveBob[3]-'0')*10 + (leaveBob[4]-'0');

        int bobStartDay = 0, bobEndDay = 0;
        if(bobMStart <= 1) bobStartDay = bobDStart;
        else{
            int sumDays = 0;
            for(int i=0; i<bobMStart-1; i++){
                sumDays += monthDays[i];
            }
            bobStartDay = sumDays + bobDStart;
        }

        if(bobMEnd <= 1) bobEndDay = bobDEnd;
        else{
            int sumDays = 0;
            for(int i=0; i<bobMEnd-1; i++){
                sumDays += monthDays[i];
            }
            bobEndDay = sumDays + bobDEnd;
        }
        
        int ans = min(aliceEndDay,bobEndDay)-max(aliceStartDay,bobStartDay)+1;

        return ans > 0 ? ans : 0;
    }
};