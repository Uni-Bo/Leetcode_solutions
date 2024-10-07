class Solution {
public:
    int minLength(string s) {
        int f=1;
        set<string>set;
        set.insert("AB");
        set.insert("CD");
        while(f){
            f=0;
            for(int i=0;i<s.size();i++)
                if(set.find(s.substr(i,2))!=set.end()){
                    s.erase(i,2);
                    f=1;
                    cout<<s<<"\n";
                }
        }
        cout<<s;
    return s.size();        
    }
};