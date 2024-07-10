class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>stk;
        for(int i=0;i<logs.size();i++)
        {
            cout<<stk.size()<<"\n";
            if(logs[i]=="../")
            {
                
                if(stk.empty()) continue;
                else stk.pop();
            }
            else if(logs[i]=="./")
            {
                continue;
            }
            else
            {
                stk.push(logs[i]);
            }
        }
        return stk.size();
    }
};