class Robot {
public:
int w;
int h;
int i=0;
int j=0;
int k=0;
vector<vector<int>> dirs={{1,0},{0,-1},{-1,0},{0,1}};
    Robot(int width, int height) {
        w=width;
        h=height;
    }
 void step(int num) {
    int cycle;

    if(w == 1 || h == 1){
        cycle = w * h;
    } else {
        cycle = 2 * (w + h - 2);
    }

    num = num % cycle;

   
    if(num == 0 && cycle > 0){
        num = cycle;
    }

    while(num > 0){
        int ni = i + dirs[k][0];
        int nj = j + dirs[k][1];

        if(ni >= 0 && ni < w && nj >= 0 && nj < h){
            i = ni;
            j = nj;
            num--;
        }
        else{
            k = (k - 1 + 4) % 4;
        }
    }
}
    
    vector<int> getPos() {
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
    
    string getDir() {
        int a=dirs[k][0];
        int b=dirs[k][1];
        if(a==1 && b==0){
            return "East";
        }
           if(a==0 && b==-1){
            return "South";
        }
          if(a==-1 && b==0){
            return "West";
        }
          if(a==0 && b==1){
            return "North";
        }
        return "";

    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */