class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>set;
        set.insert(dictionary.begin(),dictionary.end());
        string temp="",ans="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' '){
                ans+=temp+" ";
                temp="";
                i++;
            }

            temp=temp+sentence[i];
            //to check if the value is present in set (i.e. dictionary)
            if(set.count(temp))
            {
                while(i<sentence.size() && sentence[i]!=' ')  i++;
                if(sentence[i]==' ')
                    ans+=temp+" ";
                else
                    ans+=temp;
                temp="";
            }
        }

        if(temp.size()) ans+=temp;
        return ans;
    }

};