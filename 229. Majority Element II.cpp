class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        int maj = v.size()/3;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(cnt1 == 0 && v[i] != ele2)
        {
            ele1 = v[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && v[i] != ele1)
        {
            ele2 = v[i];
            cnt2 = 1;
        }
        else if(ele1 == v[i])
        {
            cnt1++;
        }
        else if(ele2 == v[i])
        {
            cnt2++;
        }
        else 
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0 ; cnt2 = 0;
    vector<int> sol;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == ele1)
        {
            cnt1++;
        }
        else if(v[i] == ele2)
        {
            cnt2++;
        }
    }
    if(cnt1 > maj)
    {
        sol.push_back(ele1);
    }
    if(cnt2 > maj)
    {
        sol.push_back(ele2);
    }
    return sol;
    }
};
