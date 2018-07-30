#include <iostream>
#include <regex>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int m,n;

class point {
public:
    point(int A, int B):a(A), b(B){}
    int& geta() {
        return a;
    }
    int& getb() {
        return b;
    }
    int judge() {
        if (a>=m || b>=n)
            return 1;
        if (a<0 || b<0)
            return 1;
        return 0;
    }
private:
    int a,b;
};
class edge {
public:
    edge(int fa, int fb, int seca, int secb):first(fa, fb), second(seca,secb){}
    //judge the edge is valid or not
    int judge() {
        //invalid
        if (first.judge()==1 || second.judge()==1) {
            cout << "Number out of range." << endl;
            return 0;
        }
        else if((first.geta()-second.geta() != 0 && abs(first.getb()-second.getb()) != 1) && (abs(first.geta()-second.geta()) != 1 && first.getb()-second.getb() != 0)) {
            cout << "Maze format error." <<endl;
            return 0;
        }
        //valid
        else
            return 1;
    }
    int middlea() {
        return (first.geta()+second.geta())+1;
    }
    int middleb() {
        return (first.getb()+second.getb())+1;
    }
private:
    point first;
    point second;
};

//change str to the end of last string
int toInt(string::iterator& str) {
    int num = 0;
    int i = 0;
    while (!(str[i] <'0' || str[i] >'9')) {
        num = num*10 + str[i]-'0';
        i++;
    }
    str += i+1;
    return num;
}

void output(vector<vector<char>>& matrix) {
    int row = m*2+1;
    int col = n*2+1;
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col-1; j++) {
            cout << '[' << matrix[i][j] <<"] ";
        }
        cout << '[' << matrix[i][col-1] <<']' << endl;
    }
}

int main()
{
    char temp;
    regex reg1("\\d+\\s\\d+");
    regex reg2("\\d+,\\d+ \\d+,\\d+");
    while (temp=cin.get()) {
        string str1 = {temp};
        while (temp=cin.get(),temp != '\n')
            str1 += temp;
        string str2("");
        while (temp=cin.get(),temp != '\n')
            str2 += temp;

        //if the input1 obeys the rule
        vector<string::iterator> rule_str;
        if (regex_match( str1,reg1)) {
            string::iterator ptr = str2.begin();
            char substring[100];
            while (ptr != str2.end()+1) {
                int i = 0;

                for (; ptr[i]!=';'&&ptr[i]!='\n'&&ptr[i] != 0&&i<100; i++)
                    substring[i] = ptr[i];
                ptr[i] = '\n';
                substring[i] = '\0';
                if(i>99 || !regex_match( substring, reg2)){
                    cout << "Invalid number format." << endl;
                    continue;
                }
                rule_str.push_back(ptr);
                ptr += i+1;
            }
        }
        else {
            cout << "Invalid number format." << endl;
            continue;
        }
        string::iterator str_1 = str1.begin();
        m = toInt(str_1);
        n = toInt(str_1);
        //the resource can be released now
        if (m<=0||n<=0) {
            cout << "Number out of range." << endl;
        }
        else {
            vector<vector<char>> matrix(2*m+1, vector<char>(2*n+1,'W'));
            //now the m*n
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++){
                    matrix[2*i+1][2*j+1]='R';
                }

            bool mark = true;
            for(int i=rule_str.size()-1; i>=0; i--) {
                int a = toInt(rule_str[i]);
                int b = toInt(rule_str[i]);
                int c = toInt(rule_str[i]);
                int d = toInt(rule_str[i]);
                edge e(a, b, c, d);
                if (e.judge() == 0) {
                    mark = false;
                    break;
                }
                else {
                    matrix[e.middlea()][e.middleb()]='R';
                }
            }

            if (mark)
                output(matrix);
        }

    }
    return 0;
}
