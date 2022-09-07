#include<bits/stdc++.h>
using namespace std;

class StringCalculator{
    public :
    int add(string numbers){
        int n = numbers.size();
        if(n == 0) return 0;
        int sum =0;
        vector<string> v;

        int i=0;
        while(i<n){
            string a = "";
            while(i<n && numbers[i] != ','){
                a += numbers[i];
                i++;
            }


            try {
                if (a[0] == '-')
                {
                    throw a;
                }
                if(isalpha(a[0])){
                    char c = a[0];
                    sum += c-'a'+1;
                }
                else{
                    int c = stoi(a);
                    if(c>1000) sum+= 0;
                    else sum += c;
                }
            }
            catch (string x ) {
                v.push_back(x);
            }
            i++;
        }
        if(v.size() == 0) return sum;

        cout<<"Negatives not Allowed : ";
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;

        return -1;
    }
};

int main(){
    while(1){
        string input;
        cout<<"Enter string which you want to calculate:";
        cin>>input;

        StringCalculator obj;
        int ans = obj.add(input);

        if(ans >= 0) cout<<"Answer for above input is:"<<ans<<endl;
    }
    return 0;
}
