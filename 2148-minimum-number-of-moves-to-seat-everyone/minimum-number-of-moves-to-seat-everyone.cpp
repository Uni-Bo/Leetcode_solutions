class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int c=0;
        for(int i=0;i<seats.size();i++)
        {
            while(seats[i]>students[i]) {students[i]++; c++;}
            while(seats[i]<students[i]) {students[i]--; c++;}

        }
        return c;
    }
};