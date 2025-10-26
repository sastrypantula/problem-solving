class Bank {
public:
vector<long long> Balance;
    Bank(vector<long long>& balance) {
        for(int i=0;i<balance.size();i++){
            Balance.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(0<=account1-1 && account1-1<=Balance.size() && 0<=account2-1 && account2-1<=Balance.size()  && money<=Balance[account1-1]){
           Balance[account1-1]-=money;
           Balance[account2-1]+=money;
           return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(0<=account-1 && account-1<=Balance.size()){
            Balance[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(0<=account-1 && account-1<=Balance.size() && money<=Balance[account-1]){
            Balance[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */