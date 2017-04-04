vector<string> is_balanced(vector<string> expressions)
{
        vector<string> res;
        for(int i = 0; i < expressions.size(); i++)
        {
                int maxB = 0, minB = 0;
                        minB=0;
                        maxB=0;
                        for(int j = 0; j < expressions[i].size(); j++)
                        {
                                char c = expressions[i][j];
                                if( c == '(' )
                                {
                                        maxB++;
                                        if(j == 0 || expressions[i][j-1] != ':')
                                                minB++;
                                }
                                else if( c == ')' )
                                {
                                        minB = max(0, minB - 1);
                                        if(j ==0 || expressions[i][j-1] != ':' )
                                                maxB--;
                                        if(maxB < 0)
                                                break;
                                }
                        }
                        if(maxB >= 0 && minB == 0)
                                res.push_back("YES");
                        else
                                res.push_back("NO");

        }
        return res;
}


