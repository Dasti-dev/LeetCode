// LEETCODE
// 12. Integer to Roman
// make array of special cases 
class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> str = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int nun = 0,i = 0;
        string ans = "";
        while(num>0)
        {
            int nun = num / val[i];
            while(nun--)
            {
                ans+=str[i];
            }
            num = num % val[i];
            i++;
        }
        return ans;
// new approach optimised 
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
