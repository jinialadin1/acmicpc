#include <bits/stdc++.h>

std::vector<int> reversed(std::vector<int> inv){
//reverse the vector
    std::vector<int> output;
    output.clear();
    
    for(int i=inv.size()-1; i>=0; --i){
        output.push_back(inv[i]);
    }
    return output;
}

std::vector<int> vectorPlus(std::vector<int> in1, std::vector<int> in2){
    std::vector<int> answer, bigv, smallv;
    answer.clear();
    bigv.clear();
    smallv.clear();
    
    //find bigger input vector
    int size_1 = in1.size(), size_2 = in2.size();
    if(size_1>size_2){
        bigv = reversed(in1);
        smallv = reversed(in2);
    }
    else{
        bigv = reversed(in2);
        smallv = reversed(in1);
    }
    
    //check the handed over
    bool over = false;
    int i = 0;
    
    //plus two vector until the smaller one
    for(; i<smallv.size(); ++i){
        int plused = bigv[i]+smallv[i];
        if(plused>8 && over){
            over = true;
            plused -= 10;
            answer.push_back(plused+1);
        }
        else if(plused>9 && !over){
            over = true;
            plused -= 10;
            answer.push_back(plused);
        }
        else if(plused<10 && over){
            answer.push_back(plused+1);
            over = false;
        }
        else if(plused<10 && !over){
            answer.push_back(plused);
            over = false;
        }
    }
    
    //plus lefted vector
    for(; i<bigv.size(); ++i){
        if(over && bigv[i]==9){
            answer.push_back(0);
            over = true;
        }
        else if(over){
            answer.push_back(bigv[i]+1);
            over = false;
        }
        else{
            answer.push_back(bigv[i]);
            over = false;
        }
    }
    
    //check the last handed over
    if(over) answer.push_back(1);
    
    return answer;
}

int main(){
    std::vector<int> num1, num2, output;
    std::string input;
    input.clear();
    num1.clear();
    num2.clear();
    output.clear();
    
    std::getline(std::cin, input);
    
    int i=0;
    //push back the 'char' right into 'int'
    for(; input[i]!=' '; ++i)
        num1.push_back(input[i]-48);
    
    for(++i; i<input.size(); ++i)
        num2.push_back(input[i]-48);
    
    output = reversed(vectorPlus(num1, num2));
    
    for(int j=0; j<output.size(); ++j)
        std::cout<<output[j];
    std::cout<<'\n';
    
    return 0;
}
