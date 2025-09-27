int a,b;
void updateStack(int &a, int &b,stack<int> &st, bool &op){
    a = st.top();
    st.pop();
    b = st.top();
    st.pop();
    op = 1;
}
int posfija() {
    string s;
    getline(cin,s);
    int n = s.size();
    stack<int> st;
    for(int i = 0;i<n;i++){
        
        if(s[i] == ' ')continue;
        int newNum;
        bool op = 0;
        if(s[i]=='+'){
            updateStack(a,b,st,op);
            newNum = a+b;
        }else if(s[i] == '-'){
            updateStack(a,b,st,op);
            newNum = a-b;
          
        }else if(s[i] == '*'){
            updateStack(a,b,st,op);
            newNum = a*b;
           
        }else if(s[i] == '/'){
            updateStack(a,b,st,op);
            newNum = a/b;
        }
        if(op){
            st.push(newNum);
            continue;
        }
        //int num = s[i]-'0'; // para un digito
        // int num = 0;
        // while(i <n and s[i]>='0' and s[i]<='9'){
        //     num = num*10 + (s[i]-'0');
        //     i++;
        // }
        // st.push(num);
    }
    int ans = st.top();

    return ans;
}