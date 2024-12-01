class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>maps;
        unordered_map<char,int>mapt;
        for(auto sc:s){
            maps[sc]++;
        }
        for(auto tc:t){
            mapt[tc]++;
        }
        if(maps==mapt)return true;
        return false;
        
    }
};