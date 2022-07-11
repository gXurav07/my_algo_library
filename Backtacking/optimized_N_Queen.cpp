#include <bits/stdc++.h>

using namespace std;

// a state in backtracking
class State{
public:
    int N;
    int queens;
    vector<int> ar;

    State(){}
    State(int n){
        N=n;
        queens=0;
        ar.assign(n,-1);
    }
    friend bool operator<(const State &left, const State &right);
    void print(){
        for(int r=0;r<N;++r){
            for(int c=0;c<N;++c){
                if(c==ar[r]) cout<<'Q';
                else cout<<'.';
                cout<<' ';
            }
            cout<<endl;
        }
    }


    // checks if the state is possible solution
    bool isSolution(){
        if(queens==N){
            return true;
        }
        return false;
    }

};

bool operator<(const State &left, const State &right){
    return left.ar<right.ar;
}

class Backtracking{
public:
    int N;
    Backtracking(int n): N(n){}

    // main function to optimize
    vector<State> getCandidates(State &s){
        vector<State> candidates;
        vector<int> validCol(N,1);

        int currentRow=-1; 
        for(int r=0;r<N;++r){
            if(s.ar[r]<0){
                currentRow=r;
                break;
            }
            else{
                validCol[s.ar[r]]=0;
            }
        }
        for(int r=0;r<currentRow;++r){
            int x = currentRow-r+s.ar[r], y = r+s.ar[r]-currentRow;
            if(x<N) validCol[x]=0;
            if(y>=0) validCol[y]=0;
        }
        for(int col=0;col<N;++col){
            if(validCol[col]){
                s.queens++;
                s.ar[currentRow]=col;
                candidates.push_back(s);
                s.queens--;
                s.ar[currentRow]=-1;
            }
        }
        


        return candidates;
    } 

    // cur : current state
    void search(State &cur, vector<State>& solutions){
        if(cur.isSolution()){
            solutions.push_back(cur);
            return;
        }

        vector<State> candidates = getCandidates(cur);
        for(State s: candidates){
            search(s,solutions);
        }
        return;
    }

    vector<State> solve(int n){
        State s(n);
        vector<State> solutions;
        search(s,solutions);
        return solutions;
    }
};





int main(){
    int n;
    cin>>n;
    Backtracking obj(n);
    vector<State> sol = obj.solve(n);
    sort(sol.begin(),sol.end());
    for( State s: sol){
        s.print();
        cout<<endl<<flush;
    }

    cout<<sol.size()<<endl;

}

/* 
In Backtracking it is important to figure out how to 
represent our states in as less space as possible 

Ex: in N-Queens problem we may want to represent our state as a 
    NxN 2D array but actually a 1D array is enough( becuse no two queens 
    can be on the same row so our array indices may represent a row)
    ( The row contains -1 if it has no queens and a positive integer C 
    if C th column of the row cntains a queen )



            for(int i: s.ar){
                cout<<i<<" ";
            }
            cout<<"-->"<<s.queens<<endl;





*/