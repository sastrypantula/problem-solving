// class Solution {
// public:

// int gcd(int a, int b) {

//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// bool iscoprime(int a, int b) {
//     return gcd(a, b) == 1;
// }

// int lcm(int a, int b) {
//     return (a * b) / gcd(a, b);
// }


//     vector<int> replaceNonCoprimes(vector<int>& nums) {
//       stack<int> s;
//       int n=nums.size();
//       for(int i=n-1;i>=0;i--){
//         s.push(nums[i]);
//       }
//       vector<int>result;
//       while(!s.empty() && s.size()>=2){
//         int a=s.top();
//         s.pop();
//         int b=s.top();
//         s.pop();
//         if(a==1 && b==1){
//             result.push_back(a);
//             result.push_back(b);
           
//         }
//        else if(iscoprime(a,b)){
//              result.push_back(a);
//             result.push_back(b);
          
//         }
//         else{
//             int temp=lcm(a,b);
//             s.push(temp);
//         }

//       }
//       if(!s.empty()){
//         result.push_back(s.top());
//       }
//       return result;
//     }
// };


class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (1LL * a * b) / gcd(a, b);  
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            result.push_back(num);
         
            while (result.size() >= 2) {
                int a = result.back();
                int b = result[result.size() - 2];
                int g = gcd(a, b);
                if (g == 1) break; 
                result.pop_back();
                result.pop_back();
                result.push_back(lcm(a, b)); 
            }
        }
        return result;
    }
};
