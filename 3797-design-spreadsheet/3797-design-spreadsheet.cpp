class Spreadsheet {
public:
    vector<vector<int>>v;
    Spreadsheet(int rows) {
        for(int i=0;i<rows;i++){
            vector<int>a(26);
            for(int j=0;j<26;j++){
                a.push_back(0);
            }
            v.push_back(a);
        }
    }
    
    void setCell(string cell, int value) {
        string ch=cell.substr(1);
        int r=cell[0]-65;
        int c=stoi(ch)-1;
        v[c][r]=value;
    }
    
    void resetCell(string cell) {
        string ch=cell.substr(1);
        int r=cell[0]-65;
        int c=stoi(ch)-1;
        v[c][r]=0;
    }
    
    int getValue(string s) {
        int n=s.length();
        int id;
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                id=i;
                break;
            }
        }
        string s1=s.substr(1,id);
        string s2=s.substr(id+1);
        int val1,val2;
        if(s1[0]>=65&&s1[0]<=90){
        string ch=s1.substr(1);
        int r=s1[0]-65;
        int c=stoi(ch)-1;
        val1=v[c][r];
        }
        else val1=stoi(s1);
        if(s2[0]>=65&&s2[0]<=90){
        string ch=s2.substr(1);
        int r=s2[0]-65;
        int c=stoi(ch)-1;
        val2=v[c][r];
        }
        else val2=stoi(s2);
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */