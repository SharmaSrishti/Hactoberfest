class Solution {
public:
    vector<string>vec;
    void paren(int openb,int closeb,string s)
    {
        if(openb==0 && closeb==0)
        {
            
            vec.push_back(s);
            return;
        }
        if(openb>0)
        {
            paren(openb-1,closeb,s+"(");
        }
        if(openb<closeb)
        {
            paren(openb,closeb-1,s+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
       
        string s="";
    paren(n,n,s);
        return vec;
        
    }
};
