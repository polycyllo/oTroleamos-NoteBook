bool isOp(char c){
    return c=='+' || c=='-' || c == '*' || c == '/';
}
void infijaToposfija(){
    string aux,s;
    cin >> s;
    stack<char> op;
    vector<char> num;
    for(char c:s){
        
        if(isOp(c)){
            if(op.empty()){
                op.push(c);
        
            }else{
                if(c=='*' || c == '/'){
                    while(!op.empty() and (op.top()=='*' || op.top()=='/')){
                        num.pb(op.top());
                        op.pop();
                    }
                }else{
                    while(!op.empty() and (op.top()!='(')){
                        num.pb(op.top());
                        op.pop();
                    } 
                }
 
            op.push(c);
            }
        }else if(c == '('){
            op.push(c);
        }else if(c == ')'){
            while(op.top()!='('){
                num.pb(op.top());
                op.pop();
            }
            op.pop();
        }else{
            num.pb(c);
        }
    }
    while(!op.empty()){
        num.pb(op.top());
        op.pop();
    }
    for(char i:num)cout << i;
    cout << endl;
}